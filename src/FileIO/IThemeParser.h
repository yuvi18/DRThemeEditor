#pragma once

#include "ThemeModule.h"

#include <QString>

namespace DR::FileIO {


/// @file The interface that defines a theme parser


class IThemeParser {

public:
    virtual ~IThemeParser() = default;

    /// Gets the lobby module if the parser has obtained one.
    ///
    /// @return an optional ThemeModule
    virtual std::optional<ThemeModule> getLobbyThemeModule() = 0;
};

} // ns DR::FileIO
