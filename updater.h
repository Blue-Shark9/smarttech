#ifndef UPDATER_H
#define UPDATER_H

#include <QWidget>

namespace Ui {
class Updater;
}

class Updater : public QWidget
{
    Q_OBJECT

public:
    explicit Updater(QWidget *parent = nullptr);
    ~Updater();

    void setVersionInfo(double currentVersion, double latestVersion);

private slots:
    void on_btnClose_clicked();

    void on_btnUpdate_clicked();

    void on_btnCheck_clicked();

private:
    Ui::Updater *ui;
};

#endif // UPDATER_H
