#ifndef FORMULA_H
#define FORMULA_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Formula: public QWidget
{
    Q_OBJECT
public:
    Formula();
signals:
    void returnValues(QString values);
private:
    QLabel* A;
    QLineEdit* inputA;
    QLabel* theta;
    QLineEdit* inputtheta;
    QLabel* phi;
    QLineEdit* inputphi;
    QLabel* psi;
    QLineEdit* inputpsi;
    QLabel* time;
    QLineEdit* inputtime;
    QPushButton* enter;
    QLabel* info;
private slots:
    void hasValues();
};

#endif // FORMULA_H
