#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cread.h"
#include "csave.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CRead read;
    CSave *save;
    Ui::MainWindow *ui;
private slots:
    void on_open_file_clicked();
    void on_save_file_clicked();
private:
};
#endif // MAINWINDOW_H
