#pragma once

#include "IThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QDir>
#include <QFile>
#include <QList>
#include <QMenuBar>
#include <QString>


/// @file This file contains the DRThemeParser, whose purpose is to parse theme folders.


namespace DR::Parser {

// forward declaration
class Module;

/// TODO: Docs
class DRThemeParser : public QObject, public IThemeParser {

    Q_OBJECT

public:
    DRThemeParser(QObject* parent = nullptr);

    /// TODO: Docs
    void connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar);

private slots:
    /// TODO: Docs
    void handleThemeUpload();

private:
    /// TODO: Docs
    void parseTheme(const QString& themeDirectoryPath) final;

    /// TODO: Docs
    QList<Module> obtainModules(const QDir& themeDirectory);

    /// TODO: Docs
    Module parseModule(const QString& moduleFilePath);

    /// TODO: Docs
    void parseLobbyModule(const QFile& lobbyModule);
};

} //ns DR::Parser
