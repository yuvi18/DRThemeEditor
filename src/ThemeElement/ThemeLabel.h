#pragma once

#include <QLabel>
#include <QRect>
#include <QString>
#include <QWidget>


/// @file Contains the ThemeLabel class


namespace DR::ThemeElement {

/// `ThemeLabel` is an abstraction of a QLabel, providing an interface that is more friendly to use and removes a lot
///  of the code duplication that would be associated with having a regular label.
class ThemeLabel : public QLabel {

public:
    /// Constructs a label given an image and label geometry.
    explicit ThemeLabel(QWidget* parent, const QRect& labelGeometry, const QString& labelImagePath);
};

} // ns DR::ThemeElement
