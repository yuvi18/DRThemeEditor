#pragma once

//Fix includes to use angle brackets later
#include "../FileIO/ThemeModule.h"
#include <QWidget>
#include <QMap>

namespace DR::Generation {

/// TODO: Docs
class LobbyGenerator
{
public:
    explicit LobbyGenerator(const ThemeModule &module);

    /// TODO: Docs
    QWidget* getLobbyRoot();

private:
    ThemeModule themeModule_;
    QWidget* lobbyRoot_;
};

} // ns DR::Generation
