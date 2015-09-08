#include "csave.h"
CSave::CSave(CRead *_read, QWidget *parent) : QMainWindow(parent)
{
  read=_read;
}
void CSave::save_file()
{
  ppsizze=0;
  psizze=0;
  psizze=read->sizze;
  ppsizze=psizze/48;
  ppssizze=psizze%48;
  if(ppssizze!=0)
  ppsizze=ppsizze+1;
  j=0;
  i=-1;
  while(j!=ppsizze)
  {
    if(filename_ssave.isEmpty())
      filename_ssave=QFileDialog::getSaveFileName(this,tr("Wskaż plik do zapisu..."),"/home/",tr("Pliki Altium SchDoc()"));
    if(filename_ssave.isEmpty())
      return;
    QFile file(filename_ssave+QString::number(j,10)+".SchDoc");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
    QTextStream stream(&file);
    l=0;
    while(l!=(read->sheet_size-2))
    {
      text1=read->data2[l]+"\n";
      stream<<text1;
      l++;
    }
    i++;
    k=0;
    while(i!=read->sizze)
    {
      conditions();
      if((k>=0&&k<=20)||(k>49&&k<=69))
        text2="|RECORD=28|INDEXINSHEET=1|OWNERPARTID=-1|LOCATION.X="+off1a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off1b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=4|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line1+" \n"
        "|RECORD=28|INDEXINSHEET=2|OWNERPARTID=-1|LOCATION.X="+off2a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off2b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line2+"\n"
        "|RECORD=28|INDEXINSHEET=3|OWNERPARTID=-1|LOCATION.X="+off3a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off3b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line3+"\n"
        "|RECORD=28|INDEXINSHEET=4|OWNERPARTID=-1|LOCATION.X="+off4a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off4b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line4+"\n"
        "|RECORD=28|INDEXINSHEET=5|OWNERPARTID=-1|LOCATION.X="+off5a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off5b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=5|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line5+"\n"
        "|RECORD=28|INDEXINSHEET=6|OWNERPARTID=-1|LOCATION.X="+off6a+"|LOCATION.Y="+loc_y_1_string+"|CORNER.X="+off6b+"|CORNER.Y="+loc_y_2_string+"|AREACOLOR=16777215|FONTID=8|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line6+"\n";
      if((k>=20&&k<=48)||(k>=69&&k<=97))
        text2="|RECORD=28|INDEXINSHEET=13|OWNERPARTID=-1|LOCATION.X="+off1aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off1bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=4|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line1+" \n"
        "|RECORD=28|INDEXINSHEET=14|OWNERPARTID=-1|LOCATION.X="+off2aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off2bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line2+"\n"
        "|RECORD=28|INDEXINSHEET=15|OWNERPARTID=-1|LOCATION.X="+off3aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off3bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line3+"\n"
        "|RECORD=28|INDEXINSHEET=16|OWNERPARTID=-1|LOCATION.X="+off4aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off4bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=6|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line4+"\n"
        "|RECORD=28|INDEXINSHEET=17|OWNERPARTID=-1|LOCATION.X="+off5aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off5bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=5|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line5+"\n"
        "|RECORD=28|INDEXINSHEET=18|OWNERPARTID=z-1|LOCATION.X="+off6aa+"|LOCATION.Y="+loc_y_11_string+"|CORNER.X="+off6bb+"|CORNER.Y="+loc_y_22_string+"|AREACOLOR=16777215|FONTID=8|ALIGNMENT=0|WORDWRAP=T|CLIPTORECT=T|TEXT="+line6+"\n";
      stream<<text2;
      i++;
      k++;
      if((k%48)==0)break;
    }
    stream<<read->head_1;
    stream<<read->head_2;
    file.close();
    read->data.clear();
    j++;
  }
  text3.clear();
  mess();
}
void CSave::conditions()
{
  loc_y_1_string=QString::number(loc_y[k],10);
  loc_y_2_string=QString::number(corn_y[k],10);
  loc_y_11_string=QString::number(loc_y[k],10);
  loc_y_22_string=QString::number(corn_y[k],10);
  line1.clear();line2.clear();line3.clear();line4.clear();line5.clear();line6.clear();
  if(i<read->sizze)
  {
    line1=read->col1.at(i);
    line2=read->col2.at(i);
    line3=read->col3.at(i);
    line4=read->col4.at(i);
    line5=read->col5.at(i);
    line6=read->col6.at(i);
    off1a=read->ocol1[0];
    off2a=read->ocol1[1];
    off3a=read->ocol1[2];
    off4a=read->ocol1[3];
    off5a=read->ocol1[4];
    off6a=read->ocol1[5];
    off1aa=read->ocol1[6];
    off2aa=read->ocol1[7];
    off3aa=read->ocol1[8];
    off4aa=read->ocol1[9];
    off5aa=read->ocol1[10];
    off6aa=read->ocol1[11];
    off1b=read->ocol2[0];
    off2b=read->ocol2[1];
    off3b=read->ocol2[2];
    off4b=read->ocol2[3];
    off5b=read->ocol2[4];
    off6b=read->ocol2[5];
    off1bb=read->ocol2[6];
    off2bb=read->ocol2[7];
    off3bb=read->ocol2[8];
    off4bb=read->ocol2[9];
    off5bb=read->ocol2[10];
    off6bb=read->ocol2[11];
  }
}
void CSave::mess()
{
  QString siz=QString::number(ppsizze,10);
  QMessageBox::information(this,tr("INFO"),"Utworzono "+siz+" plików");
}
