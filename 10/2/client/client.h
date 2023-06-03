#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>

namespace Ui
{
    class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

signals:
    void newMessage(QString);

private slots:
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString &str);
    void on_sendButton_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
