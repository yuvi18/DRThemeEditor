#include "DRThemeEditor.h"
#include "Configuration/ThemeConfigurationPane.h"
#include "Visualization/IVisualizationPane.h"
#include "Visualization/LobbyVisualizationPane.h"

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
}

} // ns DR
