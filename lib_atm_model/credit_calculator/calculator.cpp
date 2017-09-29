﻿#include <calculator.h>

#include <math.h>

//                     Annuity credit payment formula
//
//                                D * I / M
//                 Y = ------------------------------
//                       1 - 1 / ( 1 + I / M )^N
//
//     D - sum of credit
//     I - interest rate as coefficient (percents / 100%)
//     M - percentage payments per year equal 12 (12 months per year)
//     N - credit term in months
//

double Calculator::kY = 0.0;
int Calculator::kD = 0;
int Calculator::kN = 0;
double Calculator::kI = 0.0;

CreditPaymentsGenerator Calculator::credit_payments_generator_;

void Calculator::CalculateCredit(int credit_sum,
                                 double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  kD = credit_sum;
  kI = credit_interest_rate / 100;
  kN = amount_of_months;

  CalculateMonthlyPayment();
  credit_payments_generator_.GenerateCreditPayments(kD, kY, kI);
}

double Calculator::MonthlyPayment() { return kY; }

std::vector<double> Calculator::SumOfOwedCredit() {
  return credit_payments_generator_.SumOfOwedCredit();
}

std::vector<double> Calculator::SumOfInterestChares() {
  return credit_payments_generator_.SumOfInterestChares();
}

std::vector<double> Calculator::SumOfMainDebtPayments() {
  return SumOfMainDebtPayments();
}

void Calculator::CalculateMonthlyPayment() {
  kY = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation = kD * (kI / kM);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  double denominator = kOne + (kI / kM);
  double result = kOne - (kOne / pow(denominator, kN));
  return result;
}

void Calculator::Reset() {
  kY = 0.0;
  kD = 0;
  kN = 0;
  kI = 0.0;
}
