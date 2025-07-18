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
/// Docs need more details
class DRThemeEditor : public QMainWindow {

    Q_OBJECT

public:
    DRThemeEditor(QWidget *parent = nullptr);

private:
    /// TODO: Docs
    void setupPanes();

    /// TODO: Docs
    void setupMenuBar();

    Parser::DRThemeParser themeParser;
};

} // ns DR
