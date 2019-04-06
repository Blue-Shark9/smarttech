#include "updater.h"
#include "installer.h"
#include "ui_updater.h"
#include <QScreen>

Updater::Updater(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Updater)
{
    ui->setupUi(this);
}

Updater::~Updater()
{
    delete ui;
}

void Updater::on_btnClose_clicked()
{
    /* close current window */
    this->close();
    Installer* instWnd = new Installer();

    /* open new window and show it */
    instWnd->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    instWnd->move(instWnd->pos() + (QGuiApplication::primaryScreen()->geometry().center() - instWnd->geometry().center()));
    instWnd->show();
}

void Updater::on_btnUpdate_clicked()
{

}

void Updater::setVersionInfo(double currentVersion, double latestVersion)
{
    ui->lblInstalled->setText("Installed version: " + QString::number(currentVersion, 'g', 4));
    ui->lblLatest->setText("Latest version: " + QString::number(latestVersion, 'g', 4));
    ui->lblStatus->setText("");

    if (currentVersion < latestVersion) {
        ui->lblStatus->setText("New version available");
    }
}

void Updater::on_btnCheck_clicked()
{

}
