#ifndef FILESHEET_H
#define FILESHEET_H

#include <QObject>
#include <QWidget>
#include <QFileDialog>
#include <QLabel>

class FileSheet: public QWidget
{
    Q_OBJECT
public:
    FileSheet();
signals:
    void returnFile(QString file);
private:
    QFileDialog* file;
    QLabel* label;
private slots:
    void hasFile();
};

#endif // FILESHEET_H
