#include "cread.h"
#include <QDebug>
CRead::CRead(QWidget *parent) : QMainWindow(parent)
{}
void CRead::open_file()
{
    line.clear();
    filename_open=QFileDialog::getOpenFileName(this,tr("Otwórz plik źródłowy"),"/home/",tr("Pliki txt (*.txt)"));
    QFile file(filename_open);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        line=stream.readLine();
        data.push_back(line);
    }
    col1=data[0].split("\t");
    col2=data[1].split("\t");
    col3=data[2].split("\t");
    col4=data[3].split("\t");
    col5=data[4].split("\t");
    col6=data[5].split("\t");
    qDebug()<<col1;
    qDebug()<<col2;
    qDebug()<<col3;
    qDebug()<<col4;
    qDebug()<<col5;
    qDebug()<<col6;
    sizze=data.size();
    line.clear();
    file.close();
}
void CRead::load_sheet()
{
    QFile sheet(filename_sheet);
    if(!sheet.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,tr("ERROR"),"Nie znaleziono szablonu...");
        return;
    }
    sheet.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream str(&sheet);
    while(!str.atEnd())
    {
        line=str.readLine();
        data2.push_back(line);
    }
    sheet_size=data2.size();
    head_2=data2[sheet_size-1]+"\n";
    head_1=data2[sheet_size-2]+"\n";
    sheet.close();
}
void CRead::load_offsets()
{
    QFile offsets(filename_offsets);
    if(!offsets.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,tr("ERROR"),"Nie znaleziono pliku z offsetami...");
        return;
    }
    offsets.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream str(&offsets);
    while(!str.atEnd())
    {
        line2=str.readLine();
        data3.push_back(line2);
    }
    ocol1=data3[0].split("\t");
    ocol2=data3[1].split("\t");
    offsets.close();
}
