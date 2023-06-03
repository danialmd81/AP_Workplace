#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui
{
    class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

signals:
    void newMessage(QString);

private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket *socket);

    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);

    void displayMessage(const QString &str);
    void sendMessage(QTcpSocket *socket, QString str = "");

    void on_pushButton_sendMessage_clicked();
    void on_pushButton_sendAttachment_clicked();

    void refreshComboBox();

    void on_sendButton_clicked();

private:
    Ui::Server *ui;
    QTcpServer *server;
    QSet<QTcpSocket *> socket_set;
};

#endif // MAINWINDOW_H
