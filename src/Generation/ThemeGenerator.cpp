#include "ThemeGenerator.h"

#include <FileIO/ThemeModule.h>

#include <ThemeElement/ThemeButton.h>
#include <ThemeElement/ThemeLabel.h>

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
    // ui_version = new RPTextEdit("version", this);
    // ui_version->setFrameStyle(QFrame::NoFrame);
    // ui_version->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ui_version->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ui_version->setReadOnly(true);
    // ui_server_list = new QListWidget(this);
    // ui_server_list->setContextMenuPolicy(Qt::CustomContextMenu);

    // ui_server_menu = new QMenu(this);
    // ui_server_menu->addSection(tr("Server"));
    // ui_create_server = ui_server_menu->addAction(localization::getText("SERVER_FAVORITES_ADD"));
    // ui_modify_server = ui_server_menu->addAction(localization::getText("SERVER_FAVORITES_EDIT"));
    // ui_move_up_server = ui_server_menu->addAction(localization::getText("SERVER_FAVORITES_UP"));
    // ui_move_down_server = ui_server_menu->addAction(localization::getText("SERVER_FAVORITES_DOWN"));
    // ui_delete_server = ui_server_menu->addAction(localization::getText("SERVER_FAVORITES_REMOVE"));

    // ui_player_count = new RPTextEdit("player_count", this);
    // ui_player_count->setFrameStyle(QFrame::NoFrame);
    // ui_player_count->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ui_player_count->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // ui_player_count->setWordWrapMode(QTextOption::NoWrap);
    // ui_player_count->setReadOnly(true);

    // ui_description = new QTextBrowser(this);
    // ui_description->setOpenExternalLinks(true);
    // ui_description->setReadOnly(true);

    // ui_chatbox = new DRChatLog(this);
    // ui_chatbox->setOpenExternalLinks(true);
    // ui_chatbox->setReadOnly(true);

    // ui_loading_background = new AOImageDisplay(this, ao_app);
    // ui_loading_text = new RPTextEdit("loading_label", ui_loading_background);
    // ui_progress_bar = new QProgressBar(ui_loading_background);

    // ui_progress_bar->setMinimum(0);
    // ui_progress_bar->setMaximum(100);
    // ui_progress_bar->setStyleSheet("QProgressBar{ color: white; }");

    // ui_cancel = new RPButton(ui_loading_background);


    // ui_replay_list = new QListWidget(ui_gallery_background);
    // ui_replay_list->setContextMenuPolicy(Qt::CustomContextMenu);

    // ui_gallery_packages = new QComboBox(ui_gallery_background);
    // ui_gallery_categories = new QComboBox(ui_gallery_background);

    return lobbyRoot;
}

QWidget* ThemeGenerator::getLobbyRoot()
{
    return lobbyRoot_.get();
}

}
