#include "ThemeConfigurationPane.h"

#include <QTextEdit>

namespace DR::Configuration {

ThemeConfigurationPane::ThemeConfigurationPane(QWidget *parent) : QWidget{parent} {
    setMinimumHeight(CONFIGURATION_PANE_MIN_HEIGHT);
}

} // ns DR::Configuration
