#include "LobbyGenerator.h"

#include "../FileIO/ThemeModule.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>


namespace DR::Generation {

LobbyGenerator::LobbyGenerator(const ThemeModule &module)
{
    lobbyRoot_ = new QWidget();
    lobbyRoot_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QRect geometryOfLobby = module.getGeometryOfMember("lobby");
    lobbyRoot_->setMinimumSize(geometryOfLobby.size());
    lobbyRoot_->setMaximumSize(geometryOfLobby.size());

    //Turn to functions later

    QLabel* ui_background = new QLabel(lobbyRoot_);

    ui_background->setGeometry(module.getGeometryOfMember("lobby"));
    ui_background->setStyleSheet("border-image:url(\"" + module.getImageFilePath("lobbybackground") + "\")");

    QPushButton* ui_public_server_filter = new QPushButton(lobbyRoot_);
    QPushButton* ui_favorite_server_filter = new QPushButton(lobbyRoot_);

    ui_public_server_filter->setGeometry(module.getGeometryOfMember("public_servers"));
    ui_public_server_filter->setStyleSheet("QPushButton {border-image:url(\"" + module.getImageFilePath("publicservers") +
                  "\");}"
                  "QPushButton:hover {border-image:url(\"" +
                  module.getImageFilePath("publicservers_hover") + "\");}");

    ui_favorite_server_filter->setGeometry(module.getGeometryOfMember("favorites"));
    ui_favorite_server_filter->setStyleSheet("QPushButton {border-image:url(\"" + module.getImageFilePath("favorites") +
                                           "\");}"
                                           "QPushButton:hover {border-image:url(\"" +
                                           module.getImageFilePath("favorites_hover") + "\");}");
}

QWidget* LobbyGenerator::getLobbyRoot()
{
    return lobbyRoot_;
}

}
