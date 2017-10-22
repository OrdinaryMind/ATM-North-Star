﻿#ifndef BACK_BUTTON_PROPERTY_H
#define BACK_BUTTON_PROPERTY_H

class BackButtonProperty {
 public:
  static double XShift();
  static double YShift();
  static double XStretch();
  static double YStretch();

 private:
  static constexpr double kXShift = 0.0;
  static constexpr double kYShift = 1.0;
  static constexpr double kXStretch = 0.07;
  static constexpr double kYStretch = 0.03;
};

#endif  // BACK_BUTTON_PROPERTY_H
