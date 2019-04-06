#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:
    void on_btnCancel_clicked();

    void on_btnInstall_clicked();

    void on_btnBrowse_clicked();

    void on_btnClose_clicked();

    void install();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
