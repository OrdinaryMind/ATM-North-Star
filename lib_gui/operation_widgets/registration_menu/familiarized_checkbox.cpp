﻿#include <familiarized_checkbox.h>

#include <atm_color_designer.h>
#include <registration_menu_geometry.h>
#include <widget_font.h>

FamiliarizedCheckbox::FamiliarizedCheckbox(QWidget *parent)
    : QCheckBox("I'm familiarized", parent) {
  setGeometry(RegistrationMenuGeometry::FamiliarizedCheckbox());
  setFont(WidgetFont::SetFont(14));

  AtmColorDesigner::PaintSingleWidget(this);
}

FamiliarizedCheckbox::~FamiliarizedCheckbox() {}
