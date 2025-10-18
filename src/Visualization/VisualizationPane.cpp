#include "VisualizationPane.h"

namespace DR::Visualization {

VisualizationPane::VisualizationPane(QWidget* parent) : QWidget(parent), layout_(new QVBoxLayout(this)), rootWidget_(nullptr) {
    layout_->setContentsMargins(0,0,0,0);
}

void VisualizationPane::setRootWidget(QWidget* widget) {
    if (rootWidget_) {
        layout_->removeWidget(rootWidget_);

        // The Visualization Pane should not own the resources of the root widget. That is the Theme Generator's job.
        rootWidget_->setParent(nullptr);
    }

    rootWidget_ = widget;
    layout_->addWidget(rootWidget_);
}

} //ns DR::Visualization
