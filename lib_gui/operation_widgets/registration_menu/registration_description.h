﻿#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

class QWidget;
class QRect;
class RegistrationDescriptionLabel;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 public slots:
  void ChangeGeometry(const DeltaSize& delta_size) override;

 private:
  RegistrationDescriptionLabel* description_label_ = nullptr;
};

#endif  // REGISTRATION_DESCRIPTION_H
