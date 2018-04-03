#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
//#define URL "http://172.16.63.116/~rbayeux/newWorld/login.php"
#define URL "http://127.0.0.1/~rbayeux/New-World/appliMobile/jsons/login.php"
//penser à l'https


DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    myNWM.setCookieJar(&cookieJar);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_pushButtonCancel_clicked()
{
    reject();
}

void DialogLogin::on_pushButtonConnect_clicked()
{
    //verif du user et du pass
    QUrl serviceUrl(URL);
    QUrl donnees;
    QUrlQuery query;
    query.addQueryItem("username", ui->lineEditLogin->text());
    query.addQueryItem("password",ui->lineEditPassword->text());
    donnees.setQuery(query);
    QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove("?").toLatin1());

    QNetworkRequest request(serviceUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply1 = myNWM.post(request,postData);
    while(!reply1->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray response_data = reply1->readAll();
    ui->label_3->setText(response_data);
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
    //qDebug()<<jsonResponse.object();
    //qDebug()<<jsonResponse.object().count();
    if(jsonResponse.object().count()==6)//0.1.2 et nom prenom identifiant
    {
        //recupération des infos
        nom=jsonResponse.object()["nom"].toString();
        prenom=jsonResponse.object()["prenom"].toString();
        identifiant=jsonResponse.object()["idUser"].toString();
        //si c'est bon
        accept();
    }
    else
    {
        ui->label->setStyleSheet("color:red;");
        ui->label_2->setStyleSheet("color:red;");
    }
    //nettoyage de reply1
    reply1->deleteLater();
    //sinon on indique que ce n'est pas bon
}
