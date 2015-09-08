#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/sheet.jpg");
    ui->image->setPixmap(pix);
    save=new CSave(&read);
    read.load_sheet();
    read.load_offsets();
}
void MainWindow::on_open_file_clicked()
{
    read.open_file();
    ui->open_file_line->setText(read.filename_open);
    if(ui->open_file_line->text()=="")
        ui->save_file->setEnabled(false);
    else
        ui->save_file->setEnabled(true);
}
void MainWindow::on_save_file_clicked()
{
    save->save_file();
    ui->save_file_line->setText(save->filename_ssave);
    save->filename_ssave.clear();
}
MainWindow::~MainWindow()
{
    delete ui;
}
