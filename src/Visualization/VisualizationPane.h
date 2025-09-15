#pragma once

#include <QWidget>


/// @file TODO


namespace DR::Visualization {

/// TODO: Docs
class VisualizationPane : public QWidget {

    Q_OBJECT

public:
    VisualizationPane(QWidget *parent = nullptr);

    /// TODO: Docs
    void setRootWidget(QWidget* widget);

private:
    QWidget* rootWidget_;
};

} // ns DR::Visualization
