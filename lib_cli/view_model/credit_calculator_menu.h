﻿#ifndef CREDIT_CALCULATOR_MENU_H
#define CREDIT_CALCULATOR_MENU_H

#include <user_input_handler.h>

class CreditCalculatorMenu {
 public:
  void RunCreditCalculator();
  void RequestDataForCredit();

  int CreditSum() const;
  double CreditInterestRate() const;
  int AmountOfMonths() const;

 private:
  void RequestCreditSum();
  void RequestCreditInterestRate();
  void RequestAmountOfMonths();

  UserInputHandler user_input_handler_;

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;
};

#endif  // CREDIT_CALCULATOR_MENU_H