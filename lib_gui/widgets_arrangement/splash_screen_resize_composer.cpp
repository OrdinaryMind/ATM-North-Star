﻿#include <splash_screen_resize_composer.h>

#include <QtCore/qmath.h>
#include <QFrame>
#include <QPushButton>

void SplashScreenResizeComposer::SetGeometry(const QRect& splash_screen,
                                             const QRect& exit_button,
                                             const QRect& version_label,
                                             const QRect& company_name_label,
                                             const QRect& time_date_label,
                                             const QRect& atm_label,
                                             const QRect& text_label,
                                             const QRect& frame) {
  splash_screen_ = splash_screen;
  exit_button_ = exit_button;
  version_label_ = version_label;
  company_name_label_ = company_name_label;
  time_date_label_ = time_date_label;
  atm_label_ = atm_label;
  text_label_ = text_label;
  frame_ = frame;
}

void SplashScreenResizeComposer::ResizeFrame(QFrame* frame) {
  frame->setGeometry(frame_.x(), frame->y(), frame_.width() + extra_width_,
                     frame_.height() + extra_height_);
}

void SplashScreenResizeComposer::ResizeExitButton(QPushButton* exit_button) {
  ComputeExtraButtonParameters();

  exit_button->setGeometry(exit_button_.x(), exit_button_.y(),
                           exit_button_.width() + extra_button_width_,
                           exit_button_.height() + extra_button_height_);
}

void SplashScreenResizeComposer::ResizeMinimizeButton(
    QPushButton* minimize_button) {
  ComputeExtraButtonParameters();

  minimize_button->setGeometry(
      minimize_button->x(), minimize_button->y(),
      minimize_button->width() + extra_button_width_,
      minimize_button->height() + extra_button_height_);
}

void SplashScreenResizeComposer::SetExtraWidth(int extra_width) {
  extra_width_ = extra_width - splash_screen_.width();
}

void SplashScreenResizeComposer::SetExtraHeight(int extra_height) {
  extra_height_ = extra_height - splash_screen_.height();
}

void SplashScreenResizeComposer::ComputeExtraButtonParameters() {
  extra_button_width_ = qCeil(extra_width_ / 100);
  extra_button_height_ = qCeil(extra_height_ / 100);
}