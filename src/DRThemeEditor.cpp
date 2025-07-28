#include "DRThemeEditor.h"
#include "ThemeEditorMenuBar.h"
#include "Configuration/ThemeConfigurationPane.h"
#include "Visualization/IVisualizationPane.h"
#include "Visualization/LobbyVisualizationPane.h"

#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>

namespace DR {

DRThemeEditor::DRThemeEditor(QWidget *parent) : QMainWindow(parent) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setupPanes();
    setupMenuBar();

    setWindowTitle("DRThemeEditor");
}

void DRThemeEditor::setupPanes() {
    QVBoxLayout* layout = new QVBoxLayout(centralWidget());
    Visualization::IVisualizationPane* visualizationPane = new Visualization::LobbyVisualizationPane(this);
    Configuration::ThemeConfigurationPane* configurationPane = new Configuration::ThemeConfigurationPane(this);

    layout->addWidget(visualizationPane->asWidget());
    layout->addWidget(configurationPane);
}

void DRThemeEditor::setupMenuBar() {
    DR::ThemeEditorMenuBar* menuBar = new ThemeEditorMenuBar(this);
    setMenuBar(menuBar);
    themeParser.connectParserToThemeEditorMenuBar(menuBar);
}

} // ns DR
