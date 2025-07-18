#include "DRThemeEditor.h"
#include "Configuration/ThemeConfigurationPane.h"
#include "Parser/DRThemeParser.h"
#include "Visualization/IVisualizationPane.h"
#include "Visualization/LobbyVisualizationPane.h"

#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>

namespace DR {

DRThemeEditor::DRThemeEditor(QWidget *parent) : QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    Visualization::IVisualizationPane* visualizationPane = new Visualization::LobbyVisualizationPane(this);
    Configuration::ThemeConfigurationPane* configurationPane = new Configuration::ThemeConfigurationPane(this);

    layout->addWidget(visualizationPane->asWidget());
    layout->addWidget(configurationPane);

    setCentralWidget(central);
    setWindowTitle("DRThemeEditor");

    QMenu* test = menuBar()->addMenu("File");
    test->addAction("Upload Theme");
}

} // ns DR
