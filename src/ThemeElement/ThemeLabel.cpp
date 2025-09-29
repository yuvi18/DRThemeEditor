#include "ThemeLabel.h"

namespace DR::ThemeElement {

ThemeLabel::ThemeLabel(QWidget* parent, const QRect& labelGeometry, const QString& labelImagePath) : QLabel(parent)
{
    setGeometry(labelGeometry);
    setStyleSheet("border-image:url(\"" + labelImagePath + "\")");
}

} //ns DR::ThemeElement

