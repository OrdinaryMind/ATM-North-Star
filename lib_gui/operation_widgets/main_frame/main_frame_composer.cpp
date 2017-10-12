﻿#include <main_frame_composer.h>

#include <main_widget_geometry.h>

void MainFrameComposer::SetGeometry(QFrame *main_frame, QLabel *time_label,
                                    QLabel *date_label) {
  main_frame->setGeometry(MainWidgetGeometry::MainFrame());
  time_label->setGeometry(MainWidgetGeometry::TimeLabel());
  date_label->setGeometry(MainWidgetGeometry::DateLabel());
}