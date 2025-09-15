#include "LobbyWidgetFactory.h"

namespace DR::Generation {

LobbyWidgetFactory::LobbyWidgetFactory(const ThemeModule &module)
{
    themeModule_ = module;
}

QWidget *LobbyWidgetFactory::buildLobbyWidget()
{
    QWidget* root = new QWidget();

    return root;
}

}
