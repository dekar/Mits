#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "packetsender.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(PacketSender *packetSender, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_button1EA5_clicked();

    void on_lineData_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    //QString COM;
    PacketSender *sender;
};
#endif // MAINWINDOW_H
