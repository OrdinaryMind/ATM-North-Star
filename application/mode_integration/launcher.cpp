﻿#include <launcher.h>

#include <QApplication>

#include <gui_mode.h>
#include <splash_screen.h>

Launcher::Launcher() : initial_menu_(new cli::InitialMenu) {}

void Launcher::LaunchConsoleMode() {
  SplashScreen splash_screen;
  splash_screen.ShowSplashScreen();
  initial_menu_->RunInitialMenu();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  gui::GuiMode gui_mode;
  gui_mode.RunInitialScreen();
  application.exec();
}