#pragma once

#include <FileIO/ThemeModule.h>
#include <QWidget>
#include <QMap>


/// @file Contains the ThemeGenerator class


namespace DR::Generation {

/// The `ThemeGenerator` class is used to generate the various different widgets trees that are used to display themes.
/// The `ThemeGenerator` owns all of the widget trees it makes, and is responsible for the cleanup of them on exit.
class ThemeGenerator
{
public:
    ThemeGenerator() = default;

    /// Generates all relevant widget trees using the modules provided
    /// If data cannot be found for a certain widget tree froom the theme modules, a reasonable default will be used. (NOT YET IMPLEMENTED)
    ///
    /// @param themeModules The theme modules the theme will be generated off of
    void generateThemeFromModules(const QList<FileIO::ThemeModule> &themeModules);

    /// Gets the widget tree corresponding to the lobby.
    ///
    /// @return The widget which acts as the root of the tree for the lobby
    QWidget* getLobbyRoot();

private:
    /// Creates the lobby widget tree from the corresponding theme module.
    ///
    /// @param themeModule The lobby theme module
    /// @return A widget which contains the root of the lobby tree generated
    QWidget* createLobbyWidgetTree(const FileIO::ThemeModule& themeModule);

    std::unique_ptr<QWidget> lobbyRoot_;
};

} // ns DR::Generation
