#include "ThemeFont.h"

namespace DR::ThemeElement {

ThemeFont::ThemeFont(const QString &fontName, int fontWeight, bool isBold, bool isAntialias, const QColor &fontColor)
{
    this->setFamily(fontName);
    this->setPointSize(fontWeight);
    this->setBold(isBold);;

    if (isAntialias) {
        // TODO: Ask Winter why "isAntialias" points to "NoAntialias"
        this->setStyleStrategy(QFont::NoAntialias);;
    }
    else {
        this->setStyleStrategy(QFont::PreferDefault);
    }

    this->fontColor_ = fontColor;
}

QColor ThemeFont::getFontColor() const
{
    return fontColor_;
}

} //ns DR::ThemeElement

