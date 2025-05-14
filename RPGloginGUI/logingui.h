#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class loginGUI;
}
QT_END_NAMESPACE

class loginGUI : public QMainWindow
{
    Q_OBJECT

public:
    loginGUI(QWidget *parent = nullptr);
    ~loginGUI();

private:
    Ui::loginGUI *ui;
};
#endif // LOGINGUI_H
