#ifndef CSAVE_H
#define CSAVE_H
#include "cread.h"
#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QVector>
class CSave : public QMainWindow
{
    Q_OBJECT
public:
    explicit CSave(CRead *_read,QWidget *parent = 0);
    QString filename_ssave,line1,line2,line3,line4,line5,line6,loc_y_1_string,loc_y_11_string,loc_y_2_string,loc_y_22_string,text1,text2,i_string,text3;
    QString font_id_1_string,font_id_2_string,font_id_3_string,font_id_4_string,font_id_5_string,font_id_6_string,align_1_string,align_2_string,align_3_string,align_4_string,align_5_string,align_6_string;
    QString off1a,off2a,off3a,off4a,off5a,off6a,off1b,off2b,off3b,off4b,off5b,off6b;
    QString off1aa,off2aa,off3aa,off4aa,off5aa,off6aa,off1bb,off2bb,off3bb,off4bb,off5bb,off6bb,text,text4;
    CRead *read;
    int loc_y[48]={362,401,440,480,519,559,598,637,677,716,755,795,834,874,913,952,992,1031,1070,1110,47,86,125,165,204,244,283,322,362,401,440,480,519,559,598,637,677,716,755,795,834,874,913,952,992,1031,1070,1110};
    int corn_y[48]={401,440,480,519,559,598,637,677,716,755,795,834,874,913,952,992,1031,1070,1110,1149,86,125,165,204,244,283,322,362,401,440,480,519,559,598,637,677,716,755,795,834,874,913,952,992,1031,1070,1110,1149};
    int i,psizze,ppsizze,ppssizze,j,k,l;
public slots:
    void save_file();
    void conditions();
    void mess();
};
#endif // CSAVE_H
