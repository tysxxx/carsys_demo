#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>

#ifdef HISI_PLATFORM
#include "hisi_fb.h"
#endif

int main(int argc, char *argv[])
{
#ifdef HISI_PLATFORM
    //设置qt参数
    qt_run_env();
    //初始化fb
    init_fb(1920, 1080);
    //需要 usleep 一下　qt界面才能出来
    usleep(100);
#endif
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);


    QDesktopWidget *deskWgt = QApplication::desktop();
    if (deskWgt) {
        int virtualWidth = deskWgt->width();
        int virtualHeight = deskWgt->height();
        qDebug() << "virtualWidth=" << virtualWidth << "virtualHeight=" << virtualHeight;

        QRect availableRect = deskWgt->availableGeometry();
        int availableWidth = availableRect.width();
        int availableHeight = availableRect.height();
        qDebug() << "availableWidth=" << availableWidth << "availableHeight=" << availableHeight;

        QRect screenRect = deskWgt->screenGeometry();
        int screenWidth = screenRect.width();
        int screenHeight = screenRect.height();
        qDebug() << "screenWidth=" << screenWidth << "screenHeight=" << screenHeight;
    }


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
