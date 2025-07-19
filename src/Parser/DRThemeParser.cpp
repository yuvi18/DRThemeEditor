#include "DRThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QJsonObject>
#include <QObject>
#include <QString>

namespace DR::Parser {

struct Module {
    QString name;
    QJsonObject moduleConfig;
};

DRThemeParser::DRThemeParser(QObject* parent) : QObject(parent){}

void DRThemeParser::connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar) {
    connect(menuBar, &ThemeEditorMenuBar::uploadThemeTriggered, this, &Parser::DRThemeParser::handleThemeUpload);
}

void DRThemeParser::parseTheme(const QString& themeDirectoryPath) {
    QDir themeDirectory(themeDirectoryPath);

    QList<Module> modules = obtainModules(themeDirectory);
}

QList<Module> DRThemeParser::obtainModules(const QDir& themeDirectory) {
    QList<Module> modules;
    QDir modulesDirectory(themeDirectory.filePath("modules"));
    if (!modulesDirectory.exists()) {
        qWarning() << "Modules directory not found!";
    }

    for (const QFileInfo &moduleInfo : modulesDirectory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        QFile defaultFile(moduleInfo.absoluteFilePath() + "/default.json");
        if (!defaultFile.exists()) {
            qWarning() << "Missing default.json in module:" << moduleInfo.fileName();
            continue;
        }

        if (!defaultFile.open(QIODevice::ReadOnly)) {
            qWarning() << "Failed to open:" << defaultFile.fileName();
            continue;
        }

        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(defaultFile.readAll(), &err);
        if (err.error != QJsonParseError::NoError) {
            qWarning() << "JSON parse error in" << defaultFile.fileName() << ":" << err.errorString();
            continue;
        }

        Module module {.name = moduleInfo.fileName(), .moduleConfig = doc.object()};
        modules.append(module);
    }

    return modules;
}

void DRThemeParser::parseLobbyModule(const QFile& lobbyModule) {

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
