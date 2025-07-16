#pragma once

#include <QWidget>

namespace DR::Visualization {

class IVisualizationPane {

public:
    virtual ~IVisualizationPane();

    virtual QWidget* asWidget() = 0;
};

} // ns DR::Visualization
