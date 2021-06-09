#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mygraphicview.h>
#include <QGraphicsScene>
#include"graphkv.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow  *ui;
    QGraphicsScene  *scene;
    MyPoint         *point;

    int amountVerts=6;
    int amountEdges=9;
    int n1;
    GRAPHKV<int> GraphA;
    void blabla(int k);

private slots:
    void pb1();
    void pb2();
    void pb3();
    void pb4();
    void pb5();
    void pb6();

    GRAPHKV<int> makeGRAPHKV(int amountVerts);
    void KomV();
    void transf3();
    void transf2();
    int transf1();


};

#endif // MAINWINDOW_H
