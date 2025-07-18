#include "DRThemeParser.h"

#include <QDebug>
#include <QDir>
#include <QString>

namespace DR::Parser {

DRThemeParser::DRThemeParser() {}

void DRThemeParser::parseTheme(QString themeDirectoryPath) {
    QDir themeDirectory(themeDirectoryPath);

    QFile lobbyModule{themeDirectory.filePath("modules/lobby/default.json")};
    parseLobbyModule(lobbyModule);
}

void DRThemeParser::parseLobbyModule(QFile& lobbyModule) {
    qInfo() << "TODO";
}

}
