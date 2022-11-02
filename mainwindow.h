#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <stdlib.h>
#include <string>
#include "serialport.h"
#include <QTabWidget>
#include "formula.h"
#include "filesheet.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void movementsReady(QString message);

private:
    QTabWidget* tab;
    SerialPort* arduino;
    static const quint16 vendor_id = 9025;
    static const quint16 product_id = 66;
    Formula* form;
    FileSheet* file;

private slots:
    void getMovements(QString filename);
    void sendMovements(QString message);
    void calcMovements(QString message);
};
#endif // MAINWINDOW_H
