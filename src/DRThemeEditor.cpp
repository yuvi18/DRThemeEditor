#include "DRThemeEditor.h"
#include <FileIO/DRThemeParser.h>
#include "ThemeEditorMenuBar.h"
#include <Configuration/ThemeConfigurationPane.h>
#include <Generation/ThemeGenerator.h>
#include <Visualization/VisualizationPane.h>

#include <QMenu>
#include <QMenuBar>
#include <QObject>
#include <QVBoxLayout>

// forward declaration
namespace DR::FileIO {
    struct ThemeModule;
}

namespace DR {

DRThemeEditor::DRThemeEditor(QWidget *parent) : QMainWindow(parent) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setupPanes();
    setupMenuBar();

    setWindowTitle("DRThemeEditor");

    connect(&themeParser_, &FileIO::DRThemeParser::raiseThemeLoadComplete, this, &DRThemeEditor::handleThemeLoadComplete);
}

void DRThemeEditor::setupPanes() {
    QVBoxLayout* layout = new QVBoxLayout(centralWidget());
    visualizationPane_ = new Visualization::VisualizationPane(this);
    Configuration::ThemeConfigurationPane* configurationPane = new Configuration::ThemeConfigurationPane(this);

    layout->addWidget(visualizationPane_);
    layout->addWidget(configurationPane);

    layout->addStretch();
}

void DRThemeEditor::setupMenuBar() {
    DR::ThemeEditorMenuBar* menuBar = new ThemeEditorMenuBar(this);
    setMenuBar(menuBar);
    themeParser_.connectParserToThemeEditorMenuBar(menuBar);
}

void DRThemeEditor::handleThemeLoadComplete() {
    const QList<FileIO::ThemeModule>& parsedThemeModules = themeParser_.getThemeModules();
    themeGenerator_.generateThemeFromModules(parsedThemeModules);
    visualizationPane_->setRootWidget(themeGenerator_.getLobbyRoot());
}

} // ns DR
