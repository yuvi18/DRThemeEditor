#pragma once

#include <QJsonObject>
#include <QRect>
#include <QString>

namespace DR::FileIO {

/// A class that represents a theme module.  Theme modules consist of a json describing widget metadata for a theme,
/// and image files that those widgets use. The images can be found in the location that `moduleDirPath` refers to, and
/// json data can be found in `moduleConfig`.
class ThemeModule {
public:
    explicit ThemeModule(const QString& moduleDirPath, const QJsonObject& moduleConfig_);

    /// Acquire the geometry of a member in the theme module (should be removed later).
    QRect getGeometryOfMember(const QString& member) const;

    /// Get the module config (should be removed later... a theme package class should encapsulate all modules and grab elements)
    QJsonObject getModuleConfig() const;

    /// Get the image filepath from an image name (should be removed later... a theme package class shoudl encapsulate all modules and grab elements)
    QString getImageFilePath(const QString& imageName) const;

private:
    /// Grabs the JSONObject of a member in the theme module (will probably not be necesary once above functions are removed).
    QJsonObject findMemberInModule(const QString& member) const;

    QString moduleDirPath_;
    QJsonObject moduleConfig_;
};

} // ns DR::FileIO
