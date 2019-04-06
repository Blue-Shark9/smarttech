#include "installer.h"
#include "updater.h"
#include <QApplication>
#include <QScreen>

/* check version update */
bool checkUpdate(double* currentVersion, double* latestVersion)
{
    float curVer = 2.00f;
    float latVer = 2.10f;

    /* return current version and latest version */
    *currentVersion = curVer;
    *latestVersion = latVer;

    return (latVer - curVer > 0);
}


/* main function */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/icon.ico"));

    Updater updateWnd;
    Installer mainWnd;
    double currentVersion, latestVersion;

    if (checkUpdate(&currentVersion, &latestVersion)) {
        updateWnd.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        updateWnd.move(updateWnd.pos() + (QGuiApplication::primaryScreen()->geometry().center() - updateWnd.geometry().center()));

        updateWnd.setVersionInfo(currentVersion, latestVersion);
        updateWnd.show();
    } else {
        mainWnd.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        mainWnd.move(mainWnd.pos() + (QGuiApplication::primaryScreen()->geometry().center() - mainWnd.geometry().center()));
        mainWnd.show();
    }

    return app.exec();
}
