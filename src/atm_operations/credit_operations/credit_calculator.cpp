﻿#include "credit_calculator.h"

int CreditCalculator::CalculateMaxCreditSum(int cash) {
  return max_credit_sum_ = multiplier_ * cash;
}

void CreditCalculator::SetCreditSum(int credit_sum) {
  credit_sum_ = credit_sum;
}

void CreditCalculator::SetCreditTerm(int months) { credit_term_ = months; }

void CreditCalculator::CalculateCredit() {}