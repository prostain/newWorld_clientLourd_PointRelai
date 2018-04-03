#include "mainwindow.h"
#include "ui_mainwindow.h"
//#define URL2 "http://gthom.btsinfogap.org/newWorld/jsonListeDesCdes.php"
//#define URLENRPREPARED "http://gthom.btsinfogap.org/newWorld/preparerLDC.php"
#include <QUrl>
#include <QUrlQuery>
#include <QJsonArray>
#include<QJsonObject>
#include<QCheckBox>
#include <QJsonDocument>
#include <QNetworkReply>

MainWindow::MainWindow(QNetworkAccessManager *pmyNWM, QString theName, QString theSurname, QString theIdentifiant, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myNWM=pmyNWM;
    name=theName;
    surname=theSurname;
    id=theIdentifiant;
    ui->labelIdentifiant->setText(id);
    ui->labelNom->setText(name);
    ui->labelPrenom->setText(surname);
    /***********/
    //verif du user et du pass
    //QUrl serviceUrl(URL2);
    //QUrl donnees;
    //QUrlQuery query;

}

MainWindow::~MainWindow()
{
    delete ui;
}
