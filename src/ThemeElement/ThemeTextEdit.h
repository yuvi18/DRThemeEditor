#pragma once

#include <QFont>
#include <QTextEdit>
#include <QWidget>


/// @file Contains the ThemeTextEdit class


namespace DR::ThemeElement {

/// `ThemeTextEdit` is an abstraction of a QTextEdit, providing an interface that is more friendly to use and removes a lot
///  of the code duplication that would be associated with having a regular TextEdit.
class ThemeTextEdit : public QTextEdit {

public:
    /// Constructs a text edit given a font and geometry.
    explicit ThemeTextEdit(QWidget* parent, const QRect& textEditGeometry, const QFont& textFont);
};

} // ns DR::ThemeElement
