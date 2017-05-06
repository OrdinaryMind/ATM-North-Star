﻿#include "atm_splash_screen.h"
#include "ui_atm_splash_screen.h"

#include <QApplication>
#include <QCoreApplication>

#include "text_color_changer.h"
#include "timedate_changer.h"
#include "widget_centerer.h"

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmSplashScreen) {
  ui->setupUi(this);

  InitializeObjects();
  SetWidgetAppearance();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete color_swapper_;
  delete time_date_timer_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::SetTextColor(const QString& main_color,
                                   const QString additional_color) {
  TextColorChanger::ChangeLabelColor(ui->atm_company_name_label, main_color);
  TextColorChanger::ChangeLabelColor(ui->text_label, main_color);
  TextColorChanger::ChangeLabelColor(ui->timedate_label, main_color);
  TextColorChanger::ChangeLabelColor(ui->version_label, main_color);
  TextColorChanger::ChangeButtonColor(ui->exit_button, main_color,
                                      additional_color);
  TextColorChanger::ChangeFrameColor(ui->frame, main_color);
}

void AtmSplashScreen::SetAtmBlinkColor(const QString& color_one,
                                       const QString& color_two) {}

void AtmSplashScreen::ChangeTextColor() {
  color_swapper_->ChangeColor(ui->atm_label, "rgb(114, 159, 207)",
                              "rgb(32, 74, 135)");
}

void AtmSplashScreen::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Escape) {
    this->close();
  }
}

void AtmSplashScreen::SetWidgetAppearance() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
  WidgetCenterer::MoveToCenter(this);
}

void AtmSplashScreen::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(ChangeTextColor()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
}

void AtmSplashScreen::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  color_swapper_ = new TextColorSwapper();
  time_date_timer_ = new QTimer(ui->timedate_label);
}

void AtmSplashScreen::RunTimers() {
  color_swap_timer_->start(350);
  time_date_timer_->start(1000);
}
