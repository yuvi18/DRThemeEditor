#include "VisualizationPane.h"

namespace DR::Visualization {

VisualizationPane::VisualizationPane(QWidget* parent) {
    layout_ = new QVBoxLayout(this);
    layout_->setContentsMargins(0,0,0,0);
}

void VisualizationPane::setRootWidget(QWidget* widget) {
    rootWidget_ = widget;
    rootWidget_->setParent(this);
    layout_->addWidget(rootWidget_);
}

} //ns DR::Visualization
