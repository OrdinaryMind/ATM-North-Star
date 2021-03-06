﻿#include "user_input_handler.h"

#include <iostream>

int UserInputHandler::GetDigitInputFromUser() {
  user_string_ = GetStringInputFromUser();

  if (IsContainOnlyDigits()) {
    int user_value = GetDigitsFromString();
    return user_value;
  }

  return kInvalidInput;
}

double UserInputHandler::GetDoubleDigitFromUser() {
  user_string_ = GetStringInputFromUser();
  if (IsConvertableToDouble()) {
    double user_value = GetDoubleDigitsFromString();
    return user_value;
  }
  return kInvalidInput;
}

std::string UserInputHandler::GetStringInputFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool UserInputHandler::IsContainOnlyDigits() {
  bool is_contain_only_digits = true;

  if (IsStringBeginWithNull()) {
    is_contain_only_digits = false;
  }

  for (unsigned int i = 0; i < user_string_.size(); ++i) {
    if (!isdigit(user_string_[i])) {
      is_contain_only_digits = false;
    }
  }
  return is_contain_only_digits;
}

int UserInputHandler::GetDigitsFromString() {
  if (user_string_.length() > kMaximalStringLength) {
    return kInvalidInput;
  }

  try {
    return std::stoi(user_string_);
  } catch (const std::invalid_argument&) {
    return kInvalidInput;
  } catch (const std::out_of_range&) {
    return kInvalidInput;
  }
}

bool UserInputHandler::IsConvertableToDouble() {
  bool is_convertable_to_double = true;

  if (IsStringBeginWithNull()) {
    is_convertable_to_double = false;
  }

  for (unsigned int i = 0; i < user_string_.size(); ++i) {
    if (!IsSymbolAcceptable(i)) {
      is_convertable_to_double = false;
    }
  }

  return is_convertable_to_double;
}

bool UserInputHandler::IsSymbolAcceptable(int index) {
  bool is_symbol_acceptable = true;

  if (IsComma(index)) {
    user_string_.replace(index, 1, ".");
  }

  if (!isdigit(user_string_[index]) && !IsDot(index)) {
    is_symbol_acceptable = false;
  }

  return is_symbol_acceptable;
}

bool UserInputHandler::IsDot(int index) { return user_string_[index] == '.'; }

bool UserInputHandler::IsComma(int index) { return user_string_[index] == ','; }

void UserInputHandler::SubstituteCommaByDot() {}

double UserInputHandler::GetDoubleDigitsFromString() {
  if (user_string_.length() > kMaximalStringLength) {
    return kInvalidInput;
  }

  try {
    return std::stod(user_string_);
  } catch (std::invalid_argument) {
    return kInvalidInput;
  } catch (std::out_of_range) {
    return kInvalidInput;
  }
}

bool UserInputHandler::IsStringBeginWithNull() {
  if (user_string_[0] == '0') {
    return true;
  }
  return false;
}
