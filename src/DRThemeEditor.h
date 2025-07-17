#pragma once

#include <QMainWindow>


/// @file Contains the DRThemeEditor, the main window of the application


namespace DR {

/// The `DRThemeEditor` is the main window for the theme editor application. This class is the container for the
/// configuration pane and the visualization pane.
class DRThemeEditor : public QMainWindow {

    Q_OBJECT

public:
    DRThemeEditor(QWidget *parent = nullptr);
};

} // ns DR
