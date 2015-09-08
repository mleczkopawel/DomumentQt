#ifndef CREAD_H
#define CREAD_H
#include <QMainWindow>
#include <QObject>
#include <QVector>
#include <QString>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
class CRead : public QMainWindow
{
  Q_OBJECT
public:
  explicit CRead(QWidget *parent = 0);
  QString filename_open,line,line2,head_1,head_2;
  QString filename_sheet="sheet.SchDoc";
  QString filename_offsets="offsets.txt";
  QVector <QString> data,data2,data3;
  QStringList col1,col2,col3,col4,col5,col6,ocol1,ocol2;
  int sizze,sheet_size;
public slots:
  void open_file();
  void load_sheet();
  void load_offsets();
};
#endif // CREAD_H
