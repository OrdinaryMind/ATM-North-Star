#include "primary_credit_operations.h"

static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;

bool PrimaryCreditOperations::MaxCreditCalculation(CashOperator &cash_operator,
                                                   const string &user_login,
                                                   int maximal_sum_of_credit) {
  int amount_of_credit_months =
      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser();

  cash_operator.SetAmountOfCreditMonth(amount_of_credit_months);

  utility_.ClearScreen();

  credit_messenger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);
  double pay_per_month =
      CalculateCredit(maximal_sum_of_credit, amount_of_credit_months);

  string menu_text = credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      menu_text, credit_messenger_.ShowEnter());

  return SuggestTheCredit(choice, maximal_sum_of_credit, pay_per_month,
                          cash_operator);
}

bool PrimaryCreditOperations::IndividualCreditCalculation(
    CashOperator &cash_operator, const string &user_login,
    int maximal_sum_of_credit) {
  utility_.ClearScreen();

  int user_sum_of_credit =
      secondary_credit_operation_.GetIndividualSumOfCreditFromUser(
          maximal_sum_of_credit);

  int amount_of_credit_months =
      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser();

  cash_operator.SetAmountOfCreditMonth(amount_of_credit_months);

  utility_.ClearScreen();

  credit_messenger_.ShowIndividualCreditInfo(user_login, user_sum_of_credit);

  double pay_per_month =
      CalculateCredit(user_sum_of_credit, amount_of_credit_months);

  string loan_confirmation_menu_text =
      credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      loan_confirmation_menu_text, credit_messenger_.ShowEnter());

  return SuggestTheCredit(choice, user_sum_of_credit, pay_per_month,
                          cash_operator);
}

double PrimaryCreditOperations::CalculateCredit(int sum, int amount_of_months) {
  double rate = (sum * kRatePerYear) / kFullRate;
  double pay_per_month = (sum / amount_of_months) + (rate / kOneYear);
  credit_messenger_.ShowCalculationOfCredit(pay_per_month, amount_of_months);
  return pay_per_month;
}

bool PrimaryCreditOperations::SuggestTheCredit(
    const int choice, const int sum_of_credit, const int pay_per_month,
    CashOperator &cash_operator) const {
  if (choice == kEnroll) {
    cash_operator.GetAssignACredit(sum_of_credit);
    cash_operator.AssignAMonthlyPayment(pay_per_month);
    return secondary_credit_operation_.EnrollACredit();
  } else if (choice == kRepeal) {
    cash_operator.GetAssignACredit(0);
    cash_operator.AssignAMonthlyPayment(0.0);
    cash_operator.SetAmountOfCreditMonth(0);
    return secondary_credit_operation_.RepealACredit();
  } else if (choice == kExit) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_operation_.ShowIncorrectDataMessage();
  }
}