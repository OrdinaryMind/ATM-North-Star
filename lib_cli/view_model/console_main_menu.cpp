﻿#include <console_main_menu.h>

#include <main_menu_messenger.h>
#include <submenu_input_handler.h>

void ConsoleMainMenu::RunMainMenu() {
  MainMenuMessenger::ShowMainMenu();
  ProcessMenuUserInput();
}

bool ConsoleMainMenu::UserWantQuit() const { return user_want_quit_; }

bool ConsoleMainMenu::UserWantLogOut() const { return user_want_log_out_; }

void ConsoleMainMenu::ProcessMenuUserInput() {
  for (;;) {
    ResetManipulationFlags();

    user_input_ = user_input_handler_->GetDigitInputFromUser();

    if (IsUserInputContainMenuItem(user_input_)) {
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleMainMenu::ResetManipulationFlags() {
  user_want_quit_ = false;
  user_want_log_out_ = false;
  user_input_contain_menu_item_ = false;
}

bool ConsoleMainMenu::IsUserInputContainMenuItem(int user_input) {
  user_input_contain_menu_item_ = false;

  if (user_input == kAccountInfo) {
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kRefill) {
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kCreditApplication) {
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kWithdrawal) {
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kStatement) {
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kLogOut) {
    user_want_log_out_ = true;
    user_input_contain_menu_item_ = true;
  }
  if (user_input == kQuit) {
    user_want_quit_ = true;
    user_input_contain_menu_item_ = true;
  }

  return user_input_contain_menu_item_;
}
