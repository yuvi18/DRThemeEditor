#pragma once

#include <QWidget>

namespace DR::Configuration {

class ThemeConfigurationPane : public QWidget {

    Q_OBJECT

public:
    explicit ThemeConfigurationPane(QWidget *parent = nullptr);

private:
    static constexpr unsigned int CONFIGURATION_PANE_MIN_HEIGHT = 100;
};

} // ns DS::Configuration
