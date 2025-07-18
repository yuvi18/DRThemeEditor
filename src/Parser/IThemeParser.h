#pragma once

#include <Qstring>

namespace DR::Parser {

class IThemeParser {

public:
    virtual ~IThemeParser() = default;

    virtual void parseTheme(QString themeDirectoryPath) = 0;
};

} // ns DR::Parser
