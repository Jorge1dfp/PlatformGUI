#include "mainwindow.h"
#include <QLayout>
#include <iostream>
#include <fstream>
#include <QThread>
#include <cstring>
#include <cmath>

#define DATA_LENGTH 255
#define pi atan(1)*4
#define time 20
#define x 0
#define y 0

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    resize(1000, 500);
    auto* layout = new QVBoxLayout(this);
    tab = new QTabWidget();
    layout->addWidget(tab);
    const char* portName = "\\\\.\\COM4";
    arduino = new SerialPort(portName);
    form = new Formula();
    file = new FileSheet();
    tab->addTab(file, "File");
    tab->addTab(form, "Formula");
    setLayout(layout);
    QObject::connect(form, SIGNAL(returnValues(QString)), this, SLOT(calcMovements(QString)));
    QObject::connect(file, SIGNAL(returnFile(QString)), this, SLOT(getMovements(QString)));
    QObject::connect(this, SIGNAL(movementsReady(QString)), this, SLOT(sendMovements(QString)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::calcMovements(QString message){
    QString vals = "";
    float z, phi, theta, psi;
    float value1, value2, value3, value4, value5, value6;
    for(int i = 0; i < time; i = i +  1){
        z = 13.75;
        phi = 10*sin(.2*i);
        theta = 10*sin(.2*i);
        psi = 0;
        value1 = sqrt(pow(x + (9*sqrt(2)*(cos((pi*phi)/180)*sin((pi*psi)/180) - cos((pi*psi)/180)*sin((pi*phi)/180)*sin((pi*theta)/180)))/2 + (9*sqrt(2)*cos((pi*psi)/180)*cos((pi*theta)/180))/2 - 6.2785, 2) + pow((9*sqrt(2)*sin((pi*theta)/180))/2 - z + (9*sqrt(2)*cos((pi*theta)/180)*sin((pi*phi)/180))/2, 2) + pow(y - (9*sqrt(2)*(cos((pi*phi)/180)*cos((pi*psi)/180) + sin((pi*phi)/180)*sin((pi*psi)/180)*sin((pi*theta)/180)))/2 + (9*sqrt(2)*cos((pi*theta)/180)*sin((pi*psi)/180))/2 + 1.6823, 2));
        value2 = sqrt(pow(x + (2622639048930227*cos((pi*psi)/180)*cos((pi*theta)/180))/1125899906842624 + (4893911090260859*cos((pi*phi)/180)*sin((pi*psi)/180))/562949953421312 - (4893911090260859*cos((pi*psi)/180)*sin((pi*phi)/180)*sin((pi*theta)/180))/562949953421312 + 1.6823, 2) + pow((2622639048930227*sin((pi*theta)/180))/1125899906842624 - z + (4893911090260859*cos((pi*theta)/180)*sin((pi*phi)/180))/562949953421312, 2) + pow(y - (4893911090260859*cos((pi*phi)/180)*cos((pi*psi)/180))/562949953421312 + (2622639048930227*cos((pi*theta)/180)*sin((pi*psi)/180))/1125899906842624 - (4893911090260859*sin((pi*phi)/180)*sin((pi*psi)/180)*sin((pi*theta)/180))/562949953421312 + 6.2785, 2));
        value3 = sqrt(pow(562949953421312*x + 1829587348619264*sqrt(2) - 4893911090260859*cos((pi*psi)/180)*cos((pi*theta)/180) + 1311319524465114*cos((pi*phi)/180)*sin((pi*psi)/180) - 1311319524465114*cos((pi*psi)/180)*sin((pi*phi)/180)*sin((pi*theta)/180), 2) + pow(1311319524465114*cos((pi*phi)/180)*cos((pi*psi)/180) - 1829587348619264*sqrt(2) - 562949953421312*y + 4893911090260859*cos((pi*theta)/180)*sin((pi*psi)/180) + 1311319524465114*sin((pi*phi)/180)*sin((pi*psi)/180)*sin((pi*theta)/180), 2) + pow(562949953421312*z + 4893911090260859*sin((pi*theta)/180) - 1311319524465114*cos((pi*theta)/180)*sin((pi*phi)/180), 2))/562949953421312;
        value4 = sqrt(9.192*x - 9.192*y + 5.426*pow(cos(0.01745*phi), 2)*pow(cos(0.01745*psi), 2) + 75.57*pow(cos(0.01745*psi), 2)*pow(cos(0.01745*theta), 2) + 5.426*pow(cos(0.01745*phi), 2)*pow(sin(0.01745*psi), 2) + 5.426*pow(cos(0.01745*theta), 2)*pow(sin(0.01745*phi), 2) + 75.57*pow(cos(0.01745*theta), 2)*pow(sin(0.01745*psi), 2) - 21.41*cos(0.01745*phi)*cos(0.01745*psi) - 79.91*cos(0.01745*psi)*cos(0.01745*theta) - 21.41*cos(0.01745*phi)*sin(0.01745*psi) + 17.39*z*sin(0.01745*theta) + 79.91*cos(0.01745*theta)*sin(0.01745*psi) + pow(x, 2) + pow(y, 2) + pow(z, 2) + 75.57*pow(sin(0.01745*theta), 2) - 21.41*sin(0.01745*phi)*sin(0.01745*psi)*sin(0.01745*theta) + 5.426*pow(cos(0.01745*psi), 2)*pow(sin(0.01745*phi),2)*pow(sin(0.01745*theta), 2) + 5.426*pow(sin(0.01745*phi), 2)*pow(sin(0.01745*psi), 2)*pow(sin(0.01745*theta), 2) + 4.659*y*cos(0.01745*phi)*cos(0.01745*psi) - 17.39*x*cos(0.01745*psi)*cos(0.01745*theta) - 4.659*x*cos(0.01745*phi)*sin(0.01745*psi) - 17.39*y*cos(0.01745*theta)*sin(0.01745*psi) + 4.659*z*cos(0.01745*theta)*sin(0.01745*phi) + 21.41*cos(0.01745*psi)*sin(0.01745*phi)*sin(0.01745*theta) + 40.5*cos(0.01745*theta)*sin(0.01745*phi)*sin(0.01745*theta) + 4.659*x*cos(0.01745*psi)*sin(0.01745*phi)*sin(0.01745*theta) + 4.659*y*sin(0.01745*phi)*sin(0.01745*psi)*sin(0.01745*theta) - 40.5*pow(cos(0.01745*psi), 2)*cos(0.01745*theta)*sin(0.01745*phi)*sin(0.01745*theta) - 40.5*cos(0.01745*theta)*sin(0.01745*phi)*pow(sin(0.01745*psi), 2)*sin(0.01745*theta) + 42.25);
        value5 = sqrt(pow(x + (2622639048930229*cos((pi*psi)/180)*cos((pi*theta)/180))/1125899906842624 - (4893911090260859*cos((pi*phi)/180)*sin((pi*psi)/180))/562949953421312 + (4893911090260859*cos((pi*psi)/180)*sin((pi*phi)/180)*sin((pi*theta)/180))/562949953421312 + 1.6823, 2) + pow(y + (4893911090260859*cos((pi*phi)/180)*cos((pi*psi)/180))/562949953421312 + (2622639048930229*cos((pi*theta)/180)*sin((pi*psi)/180))/1125899906842624 + (4893911090260859*sin((pi*phi)/180)*sin((pi*psi)/180)*sin((pi*theta)/180))/562949953421312 - 6.2785, 2) + pow(z - (2622639048930229*sin((pi*theta)/180))/1125899906842624 + (4893911090260859*cos((pi*theta)/180)*sin((pi*phi)/180))/562949953421312, 2));
        value6 = sqrt(pow(y + (9*sqrt(2)*(cos((pi*phi)/180)*cos((pi*psi)/180) + sin((pi*phi)/180)*sin((pi*psi)/180)*sin((pi*theta)/180)))/2 + (9*sqrt(2)*cos((pi*theta)/180)*sin((pi*psi)/180))/2 - 1.6823, 2) + pow(z - (9*sqrt(2)*sin((pi*theta)/180))/2 + (9*sqrt(2)*cos((pi*theta)/180)*sin((pi*phi)/180))/2, 2) + pow(x - (9*sqrt(2)*(cos((pi*phi)/180)*sin((pi*psi)/180) - cos((pi*psi)/180)*sin((pi*phi)/180)*sin((pi*theta)/180)))/2 + (9*sqrt(2)*cos((pi*psi)/180)*cos((pi*theta)/180))/2 - 6.2785, 2));
        //vals = "<" + QString::number(value1) + "|" + QString::number(value2) + "|" + QString::number(value3)+ "|" + QString::number(value4) + "|" + QString::number(value5) + "|" + QString::number(value6) + ">";
        vals = "<" + QString::number(value1) + ">";
        qDebug() << vals;
        emit(movementsReady(vals));
    }
}

void MainWindow::getMovements(QString filename){
    std::ifstream in;
    in.open(filename.toStdString());
    std::string command = "";
    while(in.peek() != EOF){
        std::string record;
        getline(in, record, '\n');
        command = command + record;
    }
    in.close();
    QString str = QString::fromStdString(command);
    emit(movementsReady(str));
}

void MainWindow::sendMovements(QString message){
    std::string command = message.toStdString();
    char output[DATA_LENGTH];
    if (arduino->isConnected()) {
         char* charArray = new char[command.size() + 1];
         std::copy(command.begin(), command.end(), charArray);
         charArray[command.size()] = '\n';
         arduino->writeSerialPort(charArray, DATA_LENGTH);
         arduino->readSerialPort(output, DATA_LENGTH);
         std::cout << output << "\n";
         delete[] charArray;
    }
}

