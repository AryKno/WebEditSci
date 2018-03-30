/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "mainwindow.h"
#include <Qsci/qsciscintilla.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("WebEdit");
    a.setOrganizationName("Momo.inc");
    a.setOrganizationDomain("MomoInc.com");
    MainWindow w;
    w.show();
    qDebug() << "------------";

    return a.exec();
}
