#include "ThemeModule.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QRect>

ThemeModule::ThemeModule(const QString& moduleDirPath, const QJsonObject& moduleConfig_)
    : moduleDirPath_(moduleDirPath), moduleConfig_(moduleConfig_) {}

QRect ThemeModule::getGeometryOfMember(const QString& member) const {
    /// TODO: DO BETTER BEHAVIOR OTHER THAN RETURNING EMPTY RECT

    const QJsonObject memberObject = findMemberInModule(member);

    // Extract the "position"
    if (!memberObject.contains("position") || !memberObject["position"].isObject()) {
        return QRect(); // No geometry info
    }

    const QJsonObject positionData = memberObject["position"].toObject();
    const int x      = positionData.value("x").toInt();
    const int y      = positionData.value("y").toInt();
    const int width  = positionData.value("width").toInt();
    const int height = positionData.value("height").toInt();

    return QRect(x, y, width, height);
}

QJsonObject ThemeModule::getModuleConfig() const {
    return moduleConfig_;
}

QString ThemeModule::getImageFilePath(const QString& imageName) const {
    /// FMT able to be used here?
    return moduleDirPath_ + "/" + imageName + ".png";
}

///TODO: FIX
QJsonObject ThemeModule::findMemberInModule(const QString &member) const
{
    // Make sure "lobby" exists and is an object
    if (!moduleConfig_.contains("lobby") || !moduleConfig_["lobby"].isObject()) {
        throw std::runtime_error("'lobby' missing or not an object");
    }

    const QJsonObject lobbyObj = moduleConfig_["lobby"].toObject();

    if (!lobbyObj.contains(member) || !lobbyObj[member].isObject()) {
        throw std::runtime_error(
            QString("Member '%1' not found in lobby").arg(member).toStdString()
            );
    }

    return lobbyObj[member].toObject();
}

