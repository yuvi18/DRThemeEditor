#include "LobbyGenerator.h"

#include <QWidget>


namespace DR::Generation {

LobbyGenerator::LobbyGenerator(const ThemeModule &module)
{
    themeModule_ = module;
    lobbyRoot_ = new QWidget();

}

QWidget* LobbyGenerator::getLobbyRoot()
{
    return lobbyRoot_;
}

}
