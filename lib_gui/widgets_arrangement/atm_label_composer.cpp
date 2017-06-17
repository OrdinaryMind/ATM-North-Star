﻿#include <atm_label_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QLabel>

void AtmLabelComposer::ComposeLabel(QLabel* atm_label,
                                    int main_widget_width,
                                    int main_widget_height) {
  ComputeFontSize(main_widget_width, main_widget_height);
}

void AtmLabelComposer::ComputeFontSize(int main_widget_width,
                                       int main_widget_height) {
  int font_growth = (main_widget_width - main_widget_height) / 3;
  final_font_size_ = kInitFontSize + font_growth;

  if (final_font_size_ < kInitFontSize) final_font_size_ = kInitFontSize;
  if (final_font_size_ > kFontSizeLimit) final_font_size_ = kFontSizeLimit;
}
