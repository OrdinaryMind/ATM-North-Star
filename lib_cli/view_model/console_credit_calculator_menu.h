﻿#ifndef CONSOLE_CREDIT_CALCULATOR_MENU_H
#define CONSOLE_CREDIT_CALCULATOR_MENU_H

#include <string>
#include <vector>

#include <credit_payments_table.h>
#include <user_input_handler.h>

class ConsoleCreditCalculatorMenu {
 public:
  void RunCreditCalculator();
  void RequestDataForCredit();

  int CreditSum() const;
  double CreditInterestRate() const;
  int AmountOfMonths() const;
  void ShowIncorrectInputError(
      const std::vector<std::string>& error_list) const;
  void DisplayTableTitle() const;

 private:
  void RequestCreditSum();
  void RequestCreditInterestRate();
  void RequestAmountOfMonths();

  UserInputHandler user_input_handler_;
  CreditPaymentsTable payments_table_;

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;
};

#endif  // CONSOLE_CREDIT_CALCULATOR_MENU_H
