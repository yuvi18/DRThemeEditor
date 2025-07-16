#pragma once

#include "IVisualizationPane.h"

#include <QWidget>

namespace DR::Visualization {

class LobbyVisualizationPane : public QWidget, public IVisualizationPane {

    Q_OBJECT

public:
    explicit LobbyVisualizationPane(QWidget *parent = nullptr);

    QWidget* asWidget() final;
};

} // ns DR::Visualization
