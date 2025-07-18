#pragma once

#include "IThemeParser.h"
#include "ThemeEditorMenuBar.h"

#include <QFile>
#include <QMenuBar>
#include <QString>

namespace DR::Parser {

/// TODO: Docs
class DRThemeParser : public QObject, public IThemeParser {

    Q_OBJECT

public:
    DRThemeParser(QObject* parent = nullptr);

    /// TODO: Docs
    void connectParserToThemeEditorMenuBar(ThemeEditorMenuBar* menuBar);

private slots:
    /// TODO: Docs
    void handleThemeUpload();

private:
    /// TODO: Docs
    void parseTheme(QString themeDirectoryPath) final;

    /// TODO: Docs
    void parseLobbyModule(QFile& lobbyModule);
};

} //ns DR::Parser
