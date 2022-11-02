#include "filesheet.h"
#include <QLayout>

FileSheet::FileSheet(): QWidget()
{
    auto* layout = new QVBoxLayout();
    file = new QFileDialog();
    file->setNameFilter(tr("CSV (*.csv)"));
    label = new QLabel("");
    layout->addWidget(file);
    layout->addWidget(label);
    setLayout(layout);

    QObject::connect(file, SIGNAL(accepted()), this, SLOT(hasFile()));
}


void FileSheet::hasFile(){
    QStringList fileName = file->selectedFiles();
    emit(returnFile(fileName.at(0)));
}
