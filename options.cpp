#include "options.h"
#include "ui_options.h"
#include "installer.h"
#include <QScreen>
#include <QMessageBox>
#include <QFileDialog>

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_btnCancel_clicked()
{
    /* close current window */
    this->close();
    Installer* instWnd = new Installer();

    /* open new window and show it */
    instWnd->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    instWnd->move(instWnd->pos() + (QGuiApplication::primaryScreen()->geometry().center() - instWnd->geometry().center()));
    instWnd->show();
}

void Options::on_btnInstall_clicked()
{
    install();
}

void Options::on_btnBrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Please select path to install"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->txtPath->setText(dir);
}

void Options::on_btnClose_clicked()
{
    QWidget::close();
}

void Options::install()
{
    QMessageBox msgbox;
    msgbox.setText("Installation done.");
    msgbox.exec();

    this->close();
}
