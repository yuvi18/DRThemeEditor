#pragma once

#include <QMenuBar>

namespace DR {

/// TODO: Docs
class ThemeEditorMenuBar : public QMenuBar {

    Q_OBJECT

public:
    explicit ThemeEditorMenuBar(QWidget *parent = nullptr);

signals:
    /// TODO: Docs
    void uploadThemeTriggered();
};

} // ns DR
