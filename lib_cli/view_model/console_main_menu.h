﻿#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>
#include <vector>

#include <user_input_handler.h>

class ConsoleMainMenu {
 public:
  ConsoleMainMenu();

  void RunMainMenu();

  void DisplayLogOutMessage() const;
  bool UserWantAccountInfo() const;
  bool UserWantRefill() const;
  bool UserWantWithdraw() const;
  bool UserWantCreditCalculator() const;
  bool UserWantStatement() const;

  bool UserWantQuit() const;
  bool UserWantLogOut() const;

 private:
  enum MenuItems {
    kAccountInfo = 1,
    kRefill,
    kWithdrawal,
    kCreditCalculator,
    kLogOut,
    kQuit
  };

  void ProcessMenuUserInput();
  void ResetManipulationFlags();
  void ActivateMenuItem(int user_input);

  bool IsUserInputValid(int user_input) const;
  bool IsUserInputContainMenuItem() const;

  UserInputHandler user_input_handler_;

  std::vector<bool> user_item_choice_;
};

#endif  // CONSOLE_MAIN_MENU_H
