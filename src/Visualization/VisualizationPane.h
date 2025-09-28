#pragma once

#include <QLayout>
#include <QWidget>


/// @file Contains the VisualizationPane class.


namespace DR::Visualization {

/// The VisualizationPane class as the name implies is where the graphical depiction of what the theme will look like is contained.
/// The VisualizationPane class also will host (TODO) different tabs where a user can switch between different depictions of the theme.
class VisualizationPane : public QWidget {

    Q_OBJECT

public:
    VisualizationPane(QWidget *parent = nullptr);

    /// Sets the current root widget (aka. the sole widget tree that populates the layout)
    ///
    /// @param widget The widget to take the place of the old root.
    void setRootWidget(QWidget* widget);

private:
    QLayout* layout_;
    QWidget* rootWidget_;
};

} // ns DR::Visualization
