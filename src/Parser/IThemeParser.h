#pragma once

#include <QString>

namespace DR::Parser {

class IThemeParser {

public:
    virtual ~IThemeParser() = default;

    virtual void parseTheme(QString themeDirectoryPath) = 0;
};

} // ns DR::Parser
