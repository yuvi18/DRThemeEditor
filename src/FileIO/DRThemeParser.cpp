#include "DRThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QDir>
#include <QFileDialog>
#include <QObject>
#include <QString>

#include <optional>

namespace DR::FileIO {

DRThemeParser::DRThemeParser(QObject* parent) : QObject(parent){}

void DRThemeParser::connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar) {
    connect(menuBar, &ThemeEditorMenuBar::uploadThemeTriggered, this, &FileIO::DRThemeParser::handleThemeUpload);
}

std::optional<ThemeModule> DRThemeParser::getLobbyThemeModule() {
    return lobbyThemeModule_;
}

void DRThemeParser::parseTheme(const QString& themeDirectoryPath) {
    QDir themeDirectory(themeDirectoryPath);

    QList<ThemeModule> themeModules = obtainThemeModules(themeDirectory);

    lobbyThemeModule_ = findLobbyThemeModule(themeModules);
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

QList<ThemeModule> DRThemeParser::obtainThemeModules(const QDir& themeDirectory) {
    QList<ThemeModule> themeModules;
    QDir themeModulesDirectory(themeDirectory.filePath("modules"));

    for (const QFileInfo& themeModuleInfo : themeModulesDirectory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        try {
            ThemeModule themeModule = parseThemeModule(themeModuleInfo.absoluteFilePath() + "/default.json");
            themeModules.append(themeModule);
        }
        catch(const std::exception &) {};
    }

    // We will process modules in order of the list, and since modules in the module folder override the theme.json,
    // we want the theme.json last.
    try {
        ThemeModule mainThemeModule = parseThemeModule(themeDirectory.absoluteFilePath("theme.json"));
        themeModules.append(mainThemeModule);
    }
    catch (const std::exception &) {};

    return themeModules;
}

ThemeModule DRThemeParser::parseThemeModule(const QString& themeModuleFilePathName) {
    QFile themeModuleFile(themeModuleFilePathName);
    if (!themeModuleFile.exists()) {
        throw std::runtime_error("Module file not found.");
    }

    if (!themeModuleFile.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open: " + themeModuleFile.fileName().toStdString());
    }

    QJsonParseError err;
    QJsonDocument themeModuleDoc = QJsonDocument::fromJson(themeModuleFile.readAll(), &err);
    if (err.error != QJsonParseError::NoError) {
        throw std::runtime_error("JSON parse error in " + themeModuleFile.fileName().toStdString() + " : " + err.errorString().toStdString());
    }

    QString parsedModuleDirPath = QFileInfo(themeModuleFile).absolutePath();
    ThemeModule themeModule {.moduleDirPath = parsedModuleDirPath, .moduleConfig = themeModuleDoc.object()};

    return themeModule;
}

std::optional<ThemeModule> DRThemeParser::findLobbyThemeModule(const QList<ThemeModule>& themeModules) {
    for (const ThemeModule& themeModule : themeModules) {
        if (themeModule.moduleConfig.contains("lobby")) {
            return themeModule;
        }
    }

    return std::nullopt;
}

}
