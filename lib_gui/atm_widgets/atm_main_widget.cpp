﻿#include <atm_main_widget.h>

#include <QCursor>
#include <QIcon>
#include <QPixmap>
#include <QResizeEvent>

#include <delta_size.h>
#include <exit_dialog.h>
#include <geometry.h>
#include <graphical_initial_menu.h>
#include <initial_property_installer.h>
#include <main_frame.h>
#include <splash_screen_frame.h>

AtmMainWidget::AtmMainWidget(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle("ATM");
  SetInitialSettings();
  SetInitialMainWidgetProperties();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {}

void AtmMainWidget::SetCompanyName(const QString& company_name) {
  splash_screen_->SetCompanyName(company_name);
}

QFrame* AtmMainWidget::GetMainFrame() const { return main_frame_; }

void AtmMainWidget::ProcessLoginButtonClick() { emit LoginButtonClicked(); }

void AtmMainWidget::ProcessRegistrationButtonClick() {
  emit RegistrationButtonClicked();
}

void AtmMainWidget::ProcessInitialMenuOpening() { emit ShowInitialMenu(); }

void AtmMainWidget::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmMainWidget::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
      break;
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
      CheckSplashScreenCondition();
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeDeltaSize();
  ComposeWidgets();
  emit GeometryChanged(DeltaSize(delta_width_, delta_height_));
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObjects();
  SetImages();
  setMinimumSize(kAppWidth, kAppHeight);
}

void AtmMainWidget::InitializeObjects() {
  exit_dialog_ = new ExitDialog(this);
  main_frame_ = new MainFrame(this);
  splash_screen_ = new SplashScreenFrame(main_frame_);
  initial_menu_ = new GraphicalInitialMenu(main_frame_);
}

void AtmMainWidget::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmMainWidget::SetInitialMainWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kAppWidth, kAppHeight, InitialPropertyInstaller::kResize);
  setStyleSheet("background-color:black;");
  exit_dialog_->setModal(true);
}

void AtmMainWidget::SetConnections() {
  connect(initial_menu_, SIGNAL(LoginButtonClicked()),
          SLOT(ProcessLoginButtonClick()));
  connect(initial_menu_, SIGNAL(RegistrationButtonClicked()),
          SLOT(ProcessRegistrationButtonClick()));
  connect(this, SIGNAL(ShowInitialMenu()), initial_menu_, SLOT(ShowMenu()));

  connect(this, SIGNAL(SplashScreenEnterPressed()), splash_screen_,
          SLOT(Close()));
  connect(splash_screen_, SIGNAL(FrameClosed()), initial_menu_,
          SLOT(ShowFirstTime()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
}

void AtmMainWidget::ComposeWidgets() {
  main_widget_composer_.ComposeMainFrame(main_frame_);
  main_widget_composer_.ComposeInitialMenu(initial_menu_);
  main_widget_composer_.ComposeSplashScreen(splash_screen_);
}

void AtmMainWidget::ComputeDeltaSize() {
  delta_width_ = width() - Geometry::InitialScreenWidth();
  delta_height_ = height() - Geometry::InitialScreenHeight();
  main_widget_composer_.SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  main_frame_->SetDeltaSize(delta_width_, delta_height_);
  initial_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
}

void AtmMainWidget::CheckSplashScreenCondition() {
  if (!is_splash_screen_closed_) {
    emit SplashScreenEnterPressed();
    is_splash_screen_closed_ = true;
  }
}
