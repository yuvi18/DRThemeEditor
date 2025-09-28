#pragma once

#include "ThemeModule.h"

#include <QString>

namespace DR::FileIO {


/// @file The interface that defines a theme parser


class IThemeParser {

public:
    virtual ~IThemeParser() = default;

    /// Gets the list of theme modules parsed by the parser.
    ///
    /// @return A constant reference list of theme modules.
    virtual const QList<ThemeModule>& getThemeModules() const = 0;
};

} // ns DR::FileIO
