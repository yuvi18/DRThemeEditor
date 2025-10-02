#pragma once

#include <QFont>
#include <QTextBrowser>
#include <QWidget>


/// @file Contains the ThemeTextBrowser class


namespace DR::ThemeElement {

/// `ThemeTextBrowser` is an abstraction of a QTextBrowser, providing an interface that is more friendly to use and removes a lot
///  of the code duplication that would be associated with having a regular TextBrowser.
class ThemeTextBrowser : public QTextBrowser {

public:
    /// Constructs a text browser given a font and geometry.
    explicit ThemeTextBrowser(QWidget* parent, const QRect& textBrowserGeometry, const QFont& textFont);
};

} // ns DR::ThemeElement
