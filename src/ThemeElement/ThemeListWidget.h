#pragma once

#include <QFont>
#include <QListWidget>
#include <QWidget>


/// @file Contains the ThemeListWidget class


namespace DR::ThemeElement {

/// `ThemeListWidget` is an abstraction of a QListWidget, providing an interface that is more friendly to use and removes a lot
///  of the code duplication that would be associated with having a regular ListWidget.
class ThemeListWidget : public QListWidget {

public:
    /// Constructs a text edit given a font and geometry.
    explicit ThemeListWidget(QWidget* parent, const QRect& listWidgetGeometry, const QFont& textFont);
};

} // ns DR::ThemeElement
