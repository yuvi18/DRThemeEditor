#pragma once

#include "IThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QDir>
#include <QFile>
#include <QList>
#include <QMenuBar>
#include <QString>

/// @file This file contains the DRThemeParser, whose purpose is to parse theme folders.


namespace DR::FileIO {

/// The DRThemeParser class is responsible for loading and parsing theme data from a file system directory.
///
/// A theme consists of a root theme directory containing a `theme.json` configuration file and a `modules` subdirectory,
/// each subdirectory of which contains a `default.json` defining a specific theme module.
/// The parser extracts this data into ThemeModule objects and provides accessors to this data.
class DRThemeParser : public QObject, public IThemeParser {

    Q_OBJECT

public:
    DRThemeParser(QObject* parent = nullptr);

    /// Connects the DRThemeParser to a ThemeEditorMenuBar, which sends the signal to trigger the handleThemeUpload slot.
    ///
    /// @param menuBar is the ThemeEditorMenuBar to connect the handleThemeUpload slot to.
    /// @see handleThemeUpload
    void connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar);

    /// Gets a constant reference to the list of theme modules the parser currently has.
    ///
    /// @return The list of theme modules parsed by the parser.
    const QList<ThemeModule>& getThemeModules() const final;

signals:
    /// Signals to others that a theme has been parsed by the parser.
    void raiseThemeLoadComplete();

private slots:
    /// Prompts a file dialog window which allows a user to select a theme folder.
    /// After selecting a theme folder, the parser will then call parseTheme() on that folder.
    /// @see parseTheme
    void handleThemeUpload();

private:
    /// Parses the given theme directory and extracts theme configuration and modules.
    ///
    /// This method calls `obtainThemeModules` and organizes
    ///
    /// @param themeDirectoryPath The file system path to the root theme directory.
    void parseTheme(const QString& themeDirectoryPath);

    /// Extracts all theme moduless within a theme folder.
    ///
    /// This function scans for subdirectories under the given theme directory’s `modules` folder,
    /// and calls parseThemeModule on each one that contains a `default.json` configuration file.
    /// It also parses the main root module `theme.json`.
    ///
    /// @param themeDirectory The root directory of the theme.
    /// @return A list of parsed ThemeModule objects.
    QList<FileIO::ThemeModule> buildThemeModules(const QDir& themeDirectory);

    /// Parses a single theme module from a JSON file path.
    ///
    /// @param themeModuleFilePath The file path to the json configuration file for the module.
    /// @return A parsed ThemeModule.
    ThemeModule parseThemeModule(const QString& themeModuleFilePath);

    QList<FileIO::ThemeModule> themeModules_;
};

} //ns DR::Parser
