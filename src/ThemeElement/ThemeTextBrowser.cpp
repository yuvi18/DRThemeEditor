#include "ThemeTextBrowser.h"

namespace DR::ThemeElement {

ThemeTextBrowser::ThemeTextBrowser(QWidget *parent, const QRect &textBrowserGeometry, const QFont &textFont) : QTextBrowser(parent) {
    setGeometry(textBrowserGeometry);
    setFont(textFont);
}

} // ns DR::ThemeElement
