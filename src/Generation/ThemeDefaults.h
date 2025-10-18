#pragma once

#include <QBrush>
#include <QColor>
#include <QIcon>
#include <QListWidget>
#include <QString>

namespace DR::Generation::ThemeDefaults {

inline const QString VERSION_TEXT       = "Version: 0.0.0";
inline const QString PLAYER_COUNT_TEXT  = "Connected: 0/0";
inline const QString DESCRIPTION_TEXT =
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur vitae nunc eget libero laoreet accumsan. Suspendisse potenti. Integer ut felis eget ligula bibendum tincidunt.\n\n"
    "Praesent lacinia, justo vitae tincidunt blandit, risus erat vehicula neque, a consequat urna erat in odio. Sed euismod, velit vel fermentum porttitor, odio justo aliquet sapien, sed feugiat orci erat sed justo.\n\n"
    "Vivamus tempor magna non sapien varius, ut imperdiet massa vulputate. Aenean sit amet libero eu lorem malesuada vulputate. Proin in mi vel nunc sodales vulputate.";

inline void populateDefaultLobbyServerList(QListWidget* lobbyServerList, const QString& favoriteIconFilePath, const QBrush& favoriteColor){
    // TODO: Better error handling
    if (!lobbyServerList) {
        throw std::runtime_error("Shouldn't be calling populateDefaultLobbyServerList without a lobbyServerList!");
    }

    lobbyServerList->clear();

    const QIcon favoriteIcon = QPixmap(favoriteIconFilePath);

    for (int i = 0; i < 40; i++) {
        auto *item = new QListWidgetItem;
        item->setText(QString("Test Server %1").arg(i));
        item->setData(Qt::UserRole, false);

        if (i < 5) {
            item->setIcon(favoriteIcon);
            item->setBackground(favoriteColor);
            item->setData(Qt::UserRole, true);
        }

        lobbyServerList->addItem(item);
    }
}

}
