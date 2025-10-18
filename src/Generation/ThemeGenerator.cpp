#include "ThemeGenerator.h"

#include <FileIO/ThemeModule.h>
#include <Generation/ThemeDefaults.h>

#include <ThemeElement/ThemeButton.h>
#include <ThemeElement/ThemeLabel.h>
#include <ThemeElement/ThemeListWidget.h>
#include <ThemeElement/ThemeTextBrowser.h>
#include <ThemeElement/ThemeTextEdit.h>

#include <QFont>
#include <QPointer>
#include <QWidget>


namespace DR::Generation {

void ThemeGenerator::generateThemeFromModules(const QList<FileIO::ThemeModule>& themeModules) {
    for (const FileIO::ThemeModule& themeModule : themeModules) {
        if (themeModule.getModuleConfig().contains("lobby")) {
            lobbyRoot_ = std::unique_ptr<QWidget>(createLobbyWidgetTree(themeModule));
            break;
        }
    }
}

QWidget* ThemeGenerator::createLobbyWidgetTree(const FileIO::ThemeModule& module){
    QWidget* lobbyRoot = new QWidget();

    lobbyRoot->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QRect geometryOfLobby = module.getGeometryOfMember("lobby");
    lobbyRoot->setMinimumSize(geometryOfLobby.size());
    lobbyRoot->setMaximumSize(geometryOfLobby.size());

    // The static analyzer will complain about memory leaks, but the QT garbage collection system will properly handle it
    ThemeElement::ThemeLabel* ui_background = new ThemeElement::ThemeLabel(lobbyRoot, module.getGeometryOfMember("lobby"), module.getImageFilePath("lobbybackground"));

    ThemeElement::ThemeButton* ui_public_server_filter = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("public_servers"), module.getImageFilePath("publicservers"));
    ThemeElement::ThemeButton* ui_favorite_server_filter = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("favorites"), module.getImageFilePath("favorites"));

    ThemeElement::ThemeButton* ui_toggle_favorite = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("add_to_fav"), module.getImageFilePath("addtofav"));

    ThemeElement::ThemeButton* ui_refresh = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("refresh"), module.getImageFilePath("refresh"));
    ThemeElement::ThemeButton* ui_connect = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("connect"), module.getImageFilePath("connect"));

    // ThemeElement::ThemeButton* ui_gallery_toggle = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("toggle_gallery"), module.getImageFilePath("toggle_gallery"));

    ThemeElement::ThemeButton* ui_config_panel = new ThemeElement::ThemeButton(lobbyRoot, module.getGeometryOfMember("config_panel"), module.getImageFilePath("lobby_config_panel"));

    ThemeElement::ThemeTextEdit* ui_version = new ThemeElement::ThemeTextEdit(lobbyRoot, module.getGeometryOfMember("version"), {});

    // TEMPORARY
    ui_version->setFrameStyle(QFrame::NoFrame);
    ui_version->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_version->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_version->setReadOnly(true);
    ui_version->setText(ThemeDefaults::VERSION_TEXT);

    // TEMPORARY
    QFont serverListFont;
    serverListFont.setFamily("Source Sans Pro");
    serverListFont.setPointSize(14);
    serverListFont.setBold(true);
    serverListFont.setStyleStrategy(QFont::PreferDefault);

    ThemeElement::ThemeListWidget* ui_server_list = new ThemeElement::ThemeListWidget(lobbyRoot, module.getGeometryOfMember("server_list"), serverListFont);

    QString serverListStyleSheet = QString("QTextBrowser { background-color: rgba(0, 0, 0, 0);\n") +
                                 "color: " + "#FFFFFF" + ";\n" + (true ? "font: bold;" : "") +
                                 "}";
    ui_server_list->setStyleSheet(serverListStyleSheet);


    // TEMPORARY
    ui_server_list->setStyleSheet("background-color: rgba(0, 0, 0, 0);"
                                   "font: bold;"
                                   "color: white;"
                                   "qproperty-alignment: AlignCenter;");

    ThemeDefaults::populateDefaultLobbyServerList(ui_server_list, module.getImageFilePath("favorite_server"), QColor(127, 127, 127, 127));


    ThemeElement::ThemeTextEdit* ui_player_count = new ThemeElement::ThemeTextEdit(lobbyRoot, module.getGeometryOfMember("player_count"), {});

    // TEMPORARY
    ui_player_count->setFrameStyle(QFrame::NoFrame);
    // ui_player_count->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ui_player_count->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_player_count->setWordWrapMode(QTextOption::NoWrap);
    ui_player_count->setReadOnly(true);
    ui_player_count->setStyleSheet("background-color: rgba(0, 0, 0, 0);"
                                   "font: bold;"
                                   "color: white;"
                                   "qproperty-alignment: AlignCenter;");

    ui_player_count->setText(ThemeDefaults::PLAYER_COUNT_TEXT);
    ui_player_count->setAlignment(Qt::AlignHCenter);

    QFont l_font;
    // Font priority
    // 1. "font_" + p_identifier
    // 2. "font_default"
    // 3. System font
    QString font_name = "Source Sans Pro";
    int f_weight = 10;
    bool is_bold = true;
    bool is_antialias = false;
    QColor l_font_color {"#FFFFFF"};

    l_font.setFamily(font_name);
    l_font.setPointSize(f_weight);
    l_font.setBold(is_bold);

    if(is_antialias) l_font.setStyleStrategy(QFont::NoAntialias);
    else{l_font.setStyleStrategy(QFont::PreferDefault);}

    ThemeElement::ThemeTextBrowser* ui_description = new ThemeElement::ThemeTextBrowser(lobbyRoot, module.getGeometryOfMember("description"), l_font);
    // TEMPORARY
    ui_description->setOpenExternalLinks(true);
    ui_description->setReadOnly(true);

    QString style_sheet_string = QString("QTextBrowser { background-color: rgba(0, 0, 0, 0);\n") +
                                 "color: " + l_font_color.name(QColor::HexArgb) + ";\n" + (is_bold ? "font: bold;" : "") +
                                 "}";
    ui_description->setStyleSheet(style_sheet_string);

    ui_description->setText(ThemeDefaults::DESCRIPTION_TEXT);

    // UI Chatbox seems legacy, so as of now there is no parsing for it. I might need to save it to the json though.
    return lobbyRoot;
}

QWidget* ThemeGenerator::getLobbyRoot()
{
    return lobbyRoot_.get();
}

}
