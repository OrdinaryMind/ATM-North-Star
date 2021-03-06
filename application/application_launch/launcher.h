﻿#ifndef LAUNCHER_H
#define LAUNCHER_H

class ConsoleInitialPresenter;
class MainWidgetPresenter;

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

  void DisplayErrorReport() const;

 private:
  ConsoleInitialPresenter* console_initial_presenter_ = nullptr;
  MainWidgetPresenter* graphical_initial_presenter_ = nullptr;
};

#endif  // LAUNCHER_H
