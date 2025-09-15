#include "VisualizationPane.h"

namespace DR::Visualization {

VisualizationPane::VisualizationPane(QWidget* parent) {

}

void VisualizationPane::setRootWidget(QWidget* widget) {
    this->rootWidget_ = widget;
}

} //ns DR::Visualization
