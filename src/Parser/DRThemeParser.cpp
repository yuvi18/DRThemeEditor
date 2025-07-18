#include "DRThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QObject>
#include <QString>

namespace DR::Parser {

DRThemeParser::DRThemeParser(QObject* parent) : QObject(parent){}

void DRThemeParser::connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar) {
    connect(menuBar, &ThemeEditorMenuBar::uploadThemeTriggered, this, &Parser::DRThemeParser::handleThemeUpload);
}

void DRThemeParser::parseTheme(QString themeDirectoryPath) {
    QDir themeDirectory(themeDirectoryPath);

    QFile lobbyModule{themeDirectory.filePath("modules/lobby/default.json")};
    parseLobbyModule(lobbyModule);
}

void DRThemeParser::parseLobbyModule(QFile& lobbyModule) {
    qInfo() << "TODO";
}

void DRThemeParser::handleThemeUpload() {
    QString directoryPath = QFileDialog::getExistingDirectory(
        nullptr,
        "Select Theme Folder",
        "./",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );

    if (!directoryPath.isEmpty()) {
        parseTheme(directoryPath);
    }
}

}
