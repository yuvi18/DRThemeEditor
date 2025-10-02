#include "ThemeTextEdit.h"

namespace DR::ThemeElement {

ThemeTextEdit::ThemeTextEdit(QWidget *parent, const QRect &textEditGeometry, const QFont &textFont) : QTextEdit(parent) {
    setGeometry(textEditGeometry);
}

} //ns DR::ThemeElement

