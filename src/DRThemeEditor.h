#pragma once

#include "Parser/DRThemeParser.h"
#include <QMainWindow>


/// @file Contains the DRThemeEditor, the main window of the application


// forward declarations
namespace DR::Parser {
    class DRThemeParser;
}

namespace DR {

/// The `DRThemeEditor` is the main window for the theme editor application. This class is the container for the
/// configuration pane and the visualization pane.
/// The `DRThemeEditor` also owns the parser, which allows users to open a theme to edit.
class DRThemeEditor : public QMainWindow {

    Q_OBJECT

public:
    DRThemeEditor(QWidget *parent = nullptr);

private:
    /// Sets up the default visualization panes for the application.
    /// The visualization pane inherits the IVisualizationPane interface.
    /// The configuration pane is a ThemeConfigurationPane.
    void setupPanes();

    /// Sets up the ThemeEditorMenuBar for this application.
    void setupMenuBar();

    Parser::DRThemeParser themeParser;
};

} // ns DR
