﻿#include <registrator.h>

#include <authentication_messenger.h>
#include <registration_messenger.h>

void Registrator::RunRegistrationMenu(AtmUser& atm_user) {
  SetRegistrationStatus(false);

  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();

  EnterLogin(atm_user);
  if (atm_user.IsNormalLogin()) {
    EnterPassword(atm_user);
    if (atm_user.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      SetRegistrationStatus(true);
    } else {
      notice_messenger_.ShowIncorrectFormatPassword();
    }
  } else {
    notice_messenger_.ShowIncorrectLoginFrame();
  }
}

bool Registrator::RegistrationStatus() const { return registration_status_; }

std::string Registrator::GetUserLogin() const { return login_; }

// new code
void Registrator::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ConfirmRegistration();
  if (registration_status_) {
    RunRegistrationProcedure();
  }
}

void Registrator::EnterLogin(AtmUser& atm_user) {
  AuthenticationMessenger::DisplayLoginText();
  atm_user.SetLogin(provider_.GetLoginFromUser());
}

void Registrator::EnterPassword(AtmUser& atm_user) {
  AuthenticationMessenger::DisplayPasswordText();
  atm_user.SetPassword(provider_.GetPasswordFromUser());
}

void Registrator::SetRegistrationStatus(bool registration_status) {
  registration_status_ = registration_status;
}

void Registrator::ConfirmRegistration() {
  for (;;) {
    int user_choice = menu_input_.GetDigitInputFromUser();

    if (user_choice == kStartRegistration) {
      registration_status_ = true;
      break;
    } else if (user_choice == kSymbolQuit || user_choice == kDigitQuit) {
      registration_status_ = false;
      break;
    }

    RegistrationMessenger::ShowIncorrectRegistrationConfirmation();
  }
}

void Registrator::RunRegistrationProcedure() {
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
  authenticaton_handler_.HandleAuthenticationData(login_, password_);
}

void Registrator::GetLoginStringFromUser() {
  AuthenticationMessenger::DisplayLoginText();
  login_ = user_input_.GetStringInputFromUser();
}

void Registrator::GetPasswordStringFromUser() {
  AuthenticationMessenger::DisplayPasswordText();
  password_ = user_input_.GetStringInputFromUser();
}