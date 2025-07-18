#pragma once

#include "IVisualizationPane.h"

#include <QWidget>

namespace DR::Visualization {

///TODO: Docs
class LobbyVisualizationPane : public QWidget, public IVisualizationPane {

    Q_OBJECT

public:
    ///TODO: Docs
    explicit LobbyVisualizationPane(QWidget *parent = nullptr);

    ///TODO: Docs
    QWidget* asWidget() final;
};

} // ns DR::Visualization
