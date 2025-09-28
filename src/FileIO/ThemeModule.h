#pragma once

#include <QJsonObject>
#include <QRect>
#include <QString>

/// TODO: NAMESPACE THIS SHIT

/// TODO: UPDATE DOCUMENTATION
/// A struct that represents a theme module. Theme modules consist of a json describing widget metadata for a theme,
/// and image files that those widgets use. The images can be found in the location that `moduleDirPath` refers to, and
/// json data can be found in `moduleConfig`.
class ThemeModule {
public:
    explicit ThemeModule(const QString& moduleDirPath, const QJsonObject& moduleConfig_);

    QRect getGeometryOfMember(const QString& member) const;

    /// TODO: REMOVE
    QJsonObject getModuleConfig() const;

    QString getImageFilePath(const QString& imageName) const;

private:
    QJsonObject findMemberInModule(const QString& member) const;

    QString moduleDirPath_;
    QJsonObject moduleConfig_;
};
