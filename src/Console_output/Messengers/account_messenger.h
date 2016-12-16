#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include "console_editor.h"

#include <sstream>
#include <string>

class AccountMessenger {
 public:
  void DisplayStrip() const;
  void DisplayInfoLine(const std::string &info_title,
                       const std::string &info_line) const;

  inline std::string LoginText() const { return "Login: "; }
  inline std::string PasswordText() const { return "Password: "; }
  inline std::string BalanceText() const { return "Balance: $"; }
  inline std::string CreditText() const { return "Credit: $"; }
  inline std::string PaymentText() const { return "Monthly payment: $"; }
  inline std::string TermText() const { return "Credit term: "; }

 private:
  static const int kNTimes = 45;
  static const int kSleep = 100;

  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_MESSENGER_H
