#include "logingui.h"
#include "./ui_logingui.h"

loginGUI::loginGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginGUI)
{
    ui->setupUi(this);
}

loginGUI::~loginGUI()
{
    delete ui;
}
