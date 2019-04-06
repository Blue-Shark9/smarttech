#include "installer.h"
#include "ui_installer.h"
#include "options.h"
#include <QScreen>
#include <QMessageBox>

Installer::Installer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Installer)
{
    ui->setupUi(this);
}

Installer::~Installer()
{
    delete ui;
}

void Installer::on_btnInstall_clicked()
{
    install();
}

void Installer::on_btnOption_clicked()
{
    /* close current installer window */
    this->close();

    /* show the option window */
    Options* optionWnd =  new Options();
    optionWnd->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    optionWnd->move(optionWnd->pos() + (QGuiApplication::primaryScreen()->geometry().center() - optionWnd->geometry().center()));
    optionWnd->show();
}

void Installer::on_btnClose_clicked()
{
    QApplication::quit();
}

void Installer::install()
{
    QMessageBox msgbox;
    msgbox.setText("Installation done.");
    msgbox.exec();

    this->close();
}
