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

// TODO: Better logs / error handling.
QList<Module> DRThemeParser::obtainModules(const QDir& themeDirectory) {
    QList<Module> modules;
    QDir modulesDirectory(themeDirectory.filePath("modules"));
    if (!modulesDirectory.exists()) {
        qWarning() << "Modules directory not found!";
    }

    for (const QFileInfo &moduleInfo : modulesDirectory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        try {
            Module module = parseModule(moduleInfo.absoluteFilePath() + "/default.json");
            modules.append(module);
        }
        catch(const std::exception &) {};
    }

    // We will process modules in order of the list, and since modules in the module folder override the theme.json,
    // we want the theme.json last.
    try {
        Module mainThemeModule = parseModule(themeDirectory.absoluteFilePath("theme.json"));
        modules.append(mainThemeModule);
    }
    catch (const std::exception &) {};

    return modules;
}

// TODO: Better logs / error handling.
Module DRThemeParser::parseModule(const QString& moduleFilePathName) {
    QFile moduleFile(moduleFilePathName);
    if (!moduleFile.exists()) {
        throw std::runtime_error("Module file not found.");
    }

    if (!moduleFile.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open: " + moduleFile.fileName().toStdString());
    }

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(moduleFile.readAll(), &err);
    if (err.error != QJsonParseError::NoError) {
        throw std::runtime_error("JSON parse error in " + moduleFile.fileName().toStdString() + " : " + err.errorString().toStdString());
    }

    Module module {.name = moduleFile.fileName(), .moduleConfig = doc.object()};
    return module;
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
