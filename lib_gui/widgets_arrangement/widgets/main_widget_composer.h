﻿#ifndef MAIN_WIDGET_COMPOSER_H
#define MAIN_WIDGET_COMPOSER_H

#include <QFrame>
#include <QLabel>
#include <QWidget>

#include <delta_size.h>
#include <geometry_composer.h>

class MainWidgetComposer {
 public:
  MainWidgetComposer();

  void SetMainFrame(QFrame* main_frame);
  void ComposeMenu(QWidget* widget);
  void SetTimeAndDate(QLabel* time_label, QLabel* date_label);
  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void SetDefaultComposing();
  void TuneTimeAndDateLabels(QLabel* time_label, QLabel* date_label);
  void ComposeTimeAndDate(QLabel* time_label, QLabel* date_label);

  GeometryComposer menu_composer_;
  GeometryComposer label_composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // MAIN_WIDGET_COMPOSER_H