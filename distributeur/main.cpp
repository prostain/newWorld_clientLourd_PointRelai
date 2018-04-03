#include "mainwindow.h"
#include "dialoglogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin dialogLogin;
    //en full screen it's better
    dialogLogin.setWindowState(dialogLogin.windowState()|Qt::WindowFullScreen);//or WindowMaximized
    if(dialogLogin.exec()==QDialog::Accepted)
    {
        MainWindow w(&dialogLogin.myNWM,dialogLogin.nom,dialogLogin.prenom,dialogLogin.identifiant);
        w.setWindowState(dialogLogin.windowState()|Qt::WindowFullScreen);
        w.show();
        return a.exec();
    }
    else
    {
        return (-1);
    }

}
