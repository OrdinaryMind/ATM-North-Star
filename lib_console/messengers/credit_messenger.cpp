﻿#include <console_editor_duplicate.h>
#include <credit_messenger.h>
#include <text_writer.h>

void CreditMessenger::RefuseACreditBasedOnAnotherCredit() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# Sorry, but you have already credit in our bank.\n"
      "# You can't get a second credit, while your first\n"
      "# credit is not complete.\n");
}

void CreditMessenger::RefuseACreditBasedOnCash(int sum_of_cash) const {
  ConsoleEditorDuplicate::ClearScreen();

  ConsoleEditorDuplicate::WriteTextWithInterrupt("# We checked your balance.\n",
                                                 kHalfASecond);

  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "# Available cash = $" + std::to_string(sum_of_cash) + "\n" +
          "# Sorry, for getting a credit your balance must be "
          "$1000 or more.\n",
      kHalfASecond);
}

void CreditMessenger::NotifyAboutCredit() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# You can get a credit in our bank if your\n"
      "# balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "# our bank may refuse you in getting a credit\n"
      "# without giving any reason.\n"
      "# Nowadays, all credits are set on 14% per year\n"
      "# The credit depend from sum on account at the moment.\n");

  ConsoleEditorDuplicate::WriteText(
      "\n#####################\n"
      "#   Continue?       #\n"
      "#                   #\n"
      "#   1. Yes          #\n"
      "#   2. No           #\n"
      "#                   #\n"
      "#####################\n\n"
      "Enter: ");
}

void CreditMessenger::ShowCreditConditions(int maximal_sum_of_credit) const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximal credit sum for you is:\n",
      kHalfASecond);

  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
  ConsoleEditorDuplicate::WriteText("\n");
  ConsoleEditorDuplicate::WriteText(" \t\t\t | $");
  std::string convertible_string_value =
      ConsoleEditorDuplicate::ConvertValueToString(maximal_sum_of_credit);
  ConsoleEditorDuplicate::WriteText(convertible_string_value);
  ConsoleEditorDuplicate::WriteText(" |\n");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
  ConsoleEditorDuplicate::WriteText("\n");

  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "\n# Do you prefer get all sum or you want to change\nthe sum of "
      "credit?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of credit\n"
      "# 3. Exit credit menu\n",
      kHalfASecond);
  ConsoleEditorDuplicate::WriteText("# Enter: ");
}

void CreditMessenger::SuggestToConfirmACredit() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Do you confirm the credit?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\tEnter: ");
}

void CreditMessenger::EnrollACredit() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# The credit was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.\n");
}

void CreditMessenger::RepealACreadit() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Credit is repealed...\n");
}

void CreditMessenger::ShowInfoAboutCreditSum() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "The entered sum should:\n\n"
      "\t- not exceed the allowed credit.\n"
      "\t- be greater than minimal sum of credit equal $500.\n");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditSum() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "Enter the desired sum of credit: $");
}

void CreditMessenger::ShowError(const std::string& error_message) const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes(" . ", 20);
  ConsoleEditorDuplicate::WriteText("\n    ");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("Error! " +
                                                      error_message);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes(" . ", 20);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::Sleep(500);
}

void CreditMessenger::ShowDataConfirmation() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes(":", 20);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(":: Data confirmed ::");
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes(":", 20);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::Sleep(750);
}

void CreditMessenger::ShowInfoAboutCreditTerm() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\nThe entered credit term should:\n\n"
      "\t- not exceed 60 months ( 5 years )\n"
      "\t- be greater than minimal credit term equal 6 months.\n");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditTerm() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "Enter the desired term of credit: $");
}

void CreditMessenger::ShowIncorrectCashInformation(int cash) const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 65);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteText(" Balance: $" + std::to_string(cash) + " ");
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", 65);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
}

void CreditMessenger::UnavailableCreditState() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteSymbolsNTimes("#", 65);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      " # Sorry, credit section is not available at the moment,\n"
      " # Try later . . .\n");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("#", 65);
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
}
