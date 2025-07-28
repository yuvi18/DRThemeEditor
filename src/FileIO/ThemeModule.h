#pragma once

#include <QJsonObject>
#include <QString>

/// A struct that represents a theme module. Theme modules consist of a json describing widget metadata for a theme,
/// and image files that those widgets use. The images can be found in the location that `moduleDirPath` refers to, and
/// json data can be found in `moduleConfig`.
struct ThemeModule {
    QString moduleDirPath;
    QJsonObject moduleConfig;
};
