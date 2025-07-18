#pragma once

#include <QWidget>

namespace DR::Configuration {

/// TODO: Docs
class ThemeConfigurationPane : public QWidget {

    Q_OBJECT

public:
    /// TODO: Docs
    explicit ThemeConfigurationPane(QWidget *parent = nullptr);

private:
    // This can go in a preferences file later.
    static constexpr unsigned int CONFIGURATION_PANE_MIN_HEIGHT = 100;
};

} // ns DS::Configuration
