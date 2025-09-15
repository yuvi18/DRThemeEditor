#pragma once

//Fix includes to use angle brackets later
#include "../FileIO/ThemeModule.h"
#include <QWidget>
#include <QMap>

namespace DR::Generation {

/// Builds a hierarchy of Qt widgets from a ThemeModule (images + JSON layout).
class LobbyWidgetFactory
{
public:
    explicit LobbyWidgetFactory(const ThemeModule &module);

    /// Create the root widget for this lobby module.
    QWidget *buildLobbyWidget();

private:
    ThemeModule themeModule_;
};

} // ns DR::Generation
