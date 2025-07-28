#include "ThemeEditorMenuBar.h"

#include <QAction>
#include <QMenu>

namespace DR {

ThemeEditorMenuBar::ThemeEditorMenuBar(QWidget *parent) : QMenuBar(parent) {
    QMenu* fileMenu = addMenu("File");

    QAction* uploadThemeAction = fileMenu->addAction("Upload Theme");
    connect(uploadThemeAction, &QAction::triggered, this, &ThemeEditorMenuBar::uploadThemeTriggered);
}

} // ns DR
