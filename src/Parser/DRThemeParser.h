#pragma once

#include "IThemeParser.h"

#include <QFile>
#include <QString>

namespace DR::Parser {

class DRThemeParser : public IThemeParser {

public:
    DRThemeParser();

    void parseTheme(QString themeDirectoryPath) final;

private:
    void parseLobbyModule(QFile& lobbyModule);
};

} //ns DR::Parser
