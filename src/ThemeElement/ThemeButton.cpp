#include "ThemeButton.h"

#include <QFile>

namespace DR::ThemeElement {

ThemeButton::ThemeButton(QWidget* parent, const QRect& buttonGeometry, const QString& buttonImagePath) : QPushButton(parent)
{
    setGeometry(buttonGeometry);


    QString buttonHoverImagePath = buttonImagePath.left(buttonImagePath.lastIndexOf('.')) + "_hover.png";

    if (!QFile::exists(buttonHoverImagePath)) {
        buttonHoverImagePath = buttonImagePath;
    }

    setStyleSheet("QPushButton {border-image:url(\"" + buttonImagePath +
                  "\");}"
                  "QPushButton:hover {border-image:url(\"" +
                  buttonHoverImagePath + "\");}");
}

} //ns DR::ThemeElement

