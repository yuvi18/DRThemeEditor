#include "ThemeListWidget.h"

namespace DR::ThemeElement {

ThemeListWidget::ThemeListWidget(QWidget *parent, const QRect &listWidgetGeometry, const QFont &textFont) : QListWidget(parent) {
    setGeometry(listWidgetGeometry);
}

} //ns DR::ThemeElement

