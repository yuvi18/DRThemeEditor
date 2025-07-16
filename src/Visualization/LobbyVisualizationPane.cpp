#include "LobbyVisualizationPane.h"

namespace DR::Visualization {

LobbyVisualizationPane::LobbyVisualizationPane(QWidget *parent) : QWidget{parent} {
    //TODO: Make this Configurable
    setMinimumSize(500, 600);
}

QWidget* LobbyVisualizationPane::asWidget() {
    return this;
}

} // ns DR::Visualization
