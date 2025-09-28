#pragma once

#include <FileIO/DRThemeParser.h>
#include <Generation/ThemeGenerator.h>
#include <Visualization/VisualizationPane.h>

#include <QMainWindow>


/// @file Contains the DRThemeEditor, the main window of the application


// forward declarations
namespace DR::FileIO {

class DRThemeParser;

} // ns DR::FileIO

namespace DR {

/// The `DRThemeEditor` is the main window for the theme editor application. This class is the container for the
/// configuration pane and the visualization pane.
/// The `DRThemeEditor` also owns the parser, which allows users to open a theme to edit.
class DRThemeEditor : public QMainWindow {

    Q_OBJECT

public:
    DRThemeEditor(QWidget *parent = nullptr);

private:
    /// Sets up the default panes for the application (configuration and visualization)
    void setupPanes();

    /// Sets up the ThemeEditorMenuBar for this application.
    void setupMenuBar();

    FileIO::DRThemeParser themeParser_;
    Generation::ThemeGenerator themeGenerator_;
    Visualization::VisualizationPane* visualizationPane_;

private slots:
    /// This function is called whenever the themeParser_ finishes loading a theme.
    /// After the theme parser loads a theme, the modules are passed to the generator, where the resulting widget trees are generated.
    /// Finally, the visualization pane is given the "lobby" widget tree, as a default starting point for the user.
    void handleThemeLoadComplete();
};

} // ns DR
