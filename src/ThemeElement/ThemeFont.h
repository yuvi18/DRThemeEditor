#pragma once

#include <QColor>
#include <QFont>
#include <QString>


/// @file Contains the ThemeFont class


namespace DR::ThemeElement {

/// `ThemeFont` is an abstraction of a QFont, providing an interface that is more friendly to use and removes a lot
/// of the code duplication that would be associated with having a regular label. The class includes an additional member
/// variables related to the theme: color.

class ThemeFont : public QFont {

public:
    /// Constructs a font given a font name, weight, boldness, antialiasness, and color.
    explicit ThemeFont(const QString& fontName, int fontWeight, bool isBold, bool isAntialias, const QColor& fontColor);

    /// Get the font color
    ///
    /// @return A font color
    QColor getFontColor() const;

private:
    QColor fontColor_;
};


} // ns DR::ThemeElement
