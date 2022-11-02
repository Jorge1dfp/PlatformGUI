#include "formula.h"
#include <QFormLayout>

Formula::Formula(): QWidget()
{
    A = new QLabel("Z");
    inputA = new QLineEdit("");
    theta = new QLabel("Theta");
    inputtheta = new QLineEdit();
    psi = new QLabel("Psi");
    inputpsi = new QLineEdit();
    phi = new QLabel("Phi");
    inputphi = new QLineEdit();
    time = new QLabel("Runtime");
    inputtime = new QLineEdit();
    auto* layout = new QFormLayout();
    layout->addRow(A, inputA);
    layout->addRow(theta, inputtheta);
    layout->addRow(psi, inputpsi);
    layout->addRow(phi, inputphi);
    layout->addRow(time, inputtime);
    enter = new QPushButton("Enter");
    info = new QLabel("Enter Z, Theta, Phi, and Psi in the form of amplitude*sin(theta + phase)");
    auto* layout1 = new QVBoxLayout();
    layout1->addLayout(layout);
    layout1->addWidget(info);
    layout1->addWidget(enter);
    setLayout(layout1);

    QObject::connect(enter, SIGNAL(clicked()), this, SLOT(hasValues()));
}

void Formula::hasValues(){
    QString values = A->text() + "|" + theta->text() + "|" + psi->text() + "|" + phi->text() + "|" + time->text();
    emit(returnValues(values));
}
