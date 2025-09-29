#pragma once

#include <QPushButton>
#include <QWidget>


/// @file Contains the ThemeButton class


namespace DR::ThemeElement {

/// `ThemeButton` is an abstraction of a QPushButton, providing an interface that is more friendly to use and removes a lot
///  of the code duplication that would be associated with having a regular button.
class ThemeButton : public QPushButton {

public:
    // Constructs a label given an image and label geometry.
    explicit ThemeButton(QWidget* parent, const QRect& buttonGeometry, const QString& buttonImagePath);
};

} // ns DR::ThemeElement
