#ifndef INSTALLER_H
#define INSTALLER_H

#include <QMainWindow>

namespace Ui {
class Installer;
}

class Installer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Installer(QWidget *parent = nullptr);
    ~Installer();

private slots:

    void on_btnInstall_clicked();

    void on_btnOption_clicked();

    void on_btnClose_clicked();

    void install();

private:
    Ui::Installer *ui;
};

#endif // INSTALLER_H
