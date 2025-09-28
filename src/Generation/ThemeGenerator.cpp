#include "ThemeGenerator.h"

#include "../FileIO/ThemeModule.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>


namespace DR::Generation {

void ThemeGenerator::generateThemeFromModules(const QList<FileIO::ThemeModule>& themeModules) {
    for (const FileIO::ThemeModule& themeModule : themeModules) {
        if (themeModule.getModuleConfig().contains("lobby")) {
            lobbyRoot_ = std::unique_ptr<QWidget>(createLobbyWidgetTree(themeModule));
            break;
        }
    }
}

QWidget* ThemeGenerator::createLobbyWidgetTree(const FileIO::ThemeModule& module){
    QWidget* lobbyRoot = new QWidget();

    lobbyRoot->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QRect geometryOfLobby = module.getGeometryOfMember("lobby");
    lobbyRoot->setMinimumSize(geometryOfLobby.size());
    lobbyRoot->setMaximumSize(geometryOfLobby.size());

    //Turn to functions later

    QLabel* ui_background = new QLabel(lobbyRoot);

    ui_background->setGeometry(module.getGeometryOfMember("lobby"));
    ui_background->setStyleSheet("border-image:url(\"" + module.getImageFilePath("lobbybackground") + "\")");

    QPushButton* ui_public_server_filter = new QPushButton(lobbyRoot);
    QPushButton* ui_favorite_server_filter = new QPushButton(lobbyRoot);

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

    return lobbyRoot;
}

QWidget* ThemeGenerator::getLobbyRoot()
{
    return lobbyRoot_.get();
}

}
