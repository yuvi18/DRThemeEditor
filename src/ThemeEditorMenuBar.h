#pragma once

#include <QMenuBar>


/// @file Contains the ThemeEditorMenuBar, the menu bar for the main application..


namespace DR {

/// Creates the menu bar used by DRThemeEditor
/// The menu bar currently only consists of upload functionality to import a theme.
class ThemeEditorMenuBar : public QMenuBar {

    Q_OBJECT

public:
    explicit ThemeEditorMenuBar(QWidget *parent = nullptr);

signals:
    /// The public signal emitted from this class whenever the upload action is taken.
    void uploadThemeTriggered();
};

} // ns DR
