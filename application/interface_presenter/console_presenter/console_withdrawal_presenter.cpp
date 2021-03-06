﻿#include <console_withdrawal_presenter.h>

#include <atm_interactor.h>
#include <cash_operation_validator.h>

void ConsoleWithdrawalPresenter::RunWithdrawalMenu() {
  console_withdrawal_menu_.RunWithdrawalMenu();

  if (console_withdrawal_menu_.UserWantQuit()) {
    user_want_quit_ = true;
  } else if (console_withdrawal_menu_.UserWantMainMenu()) {
    user_want_main_menu_ = true;
  } else {
    ProduceWithdrawalOperation();
  }
}

bool ConsoleWithdrawalPresenter::UserWantQuit() const {
  return user_want_quit_;
}

bool ConsoleWithdrawalPresenter::IsSumSuitable() const {
  bool is_withdrawal_correct = CashOperationValidator::IsWithdrawalCorrect(
      console_withdrawal_menu_.SumOfWithdrawal());

  bool is_withdrawal_acceptable = AtmInteractor::IsWithdrawalAcceptable(
      console_withdrawal_menu_.SumOfWithdrawal());

  return is_withdrawal_correct && is_withdrawal_acceptable;
}

bool ConsoleWithdrawalPresenter::IsPasswordCorrect() const {
  return AtmInteractor::IsPasswordCorrect(
      console_withdrawal_menu_.GetPasswordFromUser());
}

void ConsoleWithdrawalPresenter::PerformWithdrawal() const {
  AtmInteractor::WithdrawCash(console_withdrawal_menu_.SumOfWithdrawal());
  console_withdrawal_menu_.ShowSuccessfulWithdrawal();
}

void ConsoleWithdrawalPresenter::ProduceWithdrawalOperation() const {
  if (IsSumSuitable() && IsPasswordCorrect()) {
    PerformWithdrawal();
  } else {
    console_withdrawal_menu_.ShowIncorrectWithdrawal();
  }
}
