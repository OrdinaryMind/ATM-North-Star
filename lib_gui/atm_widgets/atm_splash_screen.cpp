﻿#include <atm_splash_screen.h>
#include <ui_atm_splash_screen.h>

#include <QApplication>
#include <QCoreApplication>
#include <QCursor>
#include <QIcon>
#include <QKeyEvent>
#include <QList>
#include <QPixmap>
#include <QPoint>
#include <QString>
#include <QTimer>

#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <painter.h>
#include <space_block_filter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>
#include <widget_color.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      exit_dialog_(new ExitDialog(this)) {
  ui->setupUi(this);
  exit_dialog_->setModal(true);

  setWindowTitle("ATM splash screen");
  InitializeObjects();
  SetWidgetAppearance();
  BlockSpace();
  SetInitialSettings();
  PaintWidgets();
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

void AtmSplashScreen::SetSplashScreenAppearance(
    const QString& main_color,
    const QString& secondary_color,
    const QString& additional_color) {
  color_designer_.ConfigureWidgetColorSet(
      WidgetColor(main_color, secondary_color, additional_color));

  PaintWidgets();

  exit_dialog_->SetExitDialogAppearance(main_color, secondary_color,
                                        additional_color);
}

void AtmSplashScreen::SetAtmBlinkColor(const QString& color_one,
                                       const QString& color_two) {
  color_swapper_->SetSwapColors(color_one, color_two);
}

void AtmSplashScreen::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
  exit_dialog_->SetBackgroundColor(background_color);
}

void AtmSplashScreen::UnlockFixedGeometry() { setMinimumSize(0, 0); }

void AtmSplashScreen::BlinkAtmLabelColor() {
  color_swapper_->SwapColors(ui->atm_label, color_swapper_->SwapColorOne(),
                             color_swapper_->SwapColorTwo());
}

void AtmSplashScreen::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void AtmSplashScreen::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmSplashScreen::MaximizeButtonClicked() { emit SizeWindowModified(); }

void AtmSplashScreen::ResizeWindow() {
  if (!is_full_screen_) {
    this->showFullScreen();
    is_full_screen_ = true;
  } else {
    this->showNormal();
    is_full_screen_ = false;
  }
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
      ProcessKeyEnterPressing();
      break;
    case Qt::Key_Return:
      ProcessKeyEnterPressing();
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::resizeEvent(QResizeEvent*) {
  ComputeNewGeometry();
  ResizeWidgets();
}

void AtmSplashScreen::SetInitialSettings() {
  SetCompanyName("");
  setMinimumSize(600, 400);

  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
}

void AtmSplashScreen::SetWidgetAppearance() {
  InitialPropertyInstaller::SetInitialProperties(
      this, 600, 400, InitialPropertyInstaller::kResize);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::PaintWidgets() {
  QList<QLabel*> label_list = {ui->atm_company_name_label, ui->text_label,
                               ui->timedate_label, ui->version_label};
  QList<QPushButton*> button_list = {ui->exit_button, ui->minimize_button,
                                     ui->maximize_button};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(label_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(frame_list);
}

void AtmSplashScreen::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(BlinkAtmLabelColor()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
  connect(ui->exit_button, SIGNAL(clicked(bool)), SLOT(ShowExitWidget()));
  connect(this, SIGNAL(EnterIsPressed()), SLOT(UnlockFixedGeometry()));
  connect(ui->maximize_button, SIGNAL(clicked(bool)),
          SLOT(MaximizeButtonClicked()));
  connect(this, SIGNAL(SizeWindowModified()), SLOT(ResizeWindow()));
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

void AtmSplashScreen::BlockSpace() {
  ui->exit_button->installEventFilter(new SpaceBlockFilter(ui->exit_button));
  ui->minimize_button->installEventFilter(
      new SpaceBlockFilter(ui->minimize_button));
  ui->maximize_button->installEventFilter(
      new SpaceBlockFilter(ui->maximize_button));
}

void AtmSplashScreen::ProcessKeyEnterPressing() {
  emit PassPositionWhenEnterPressed(this->geometry());
  emit EnterIsPressed();
}

void AtmSplashScreen::ComputeNewGeometry() {
  composer_.ComputeSizeIncrease(width(), height());
}

void AtmSplashScreen::ResizeWidgets() {
  composer_.ComposeFrame(ui->frame);
  composer_.ComposeVersionLabel(ui->version_label);
  composer_.ComposeSplashScreenLabels(
      ui->timedate_label, ui->atm_company_name_label, ui->text_label);
  composer_.ComposeAtmLabel(ui->atm_label);
}
