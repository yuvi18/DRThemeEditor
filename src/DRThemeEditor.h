#ifndef DRTHEMEEDITOR_H
#define DRTHEMEEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class DRThemeEditor;
}
QT_END_NAMESPACE

class DRThemeEditor : public QMainWindow
{
    Q_OBJECT

public:
    DRThemeEditor(QWidget *parent = nullptr);
    ~DRThemeEditor();

private:
};
#endif // DRTHEMEEDITOR_H
