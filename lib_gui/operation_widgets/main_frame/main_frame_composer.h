﻿#ifndef MAIN_FRAME_COMPOSER_H
#define MAIN_FRAME_COMPOSER_H

#include <QFrame>
#include <QLabel>

#include <atm_color_designer.h>

class MainFrameComposer {
 public:
  void SetGeometry(QFrame* main_frame, QLabel* time_label, QLabel* date_label);

 private:
  AtmColorDesigner color_designer_;
};

#endif  // MAIN_FRAME_COMPOSER_H