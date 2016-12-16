#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "atm_user.h"
#include "information_screen.h"
#include "console_editor.h"

class AccountInformator {
 public:
  void DisplayAccountInformation(AtmUser &atm_user);

 private:
  InformationScreen screen_;
  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_INFORMATOR_H
