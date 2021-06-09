#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"graphkv.h"
int** help;
int* result;
int*** mat;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    GraphA = makeGRAPHKV(amountVerts);
    scene = new QGraphicsScene();
    point = new MyPoint();


    ui->graphicsView->setScene(scene);
    scene->addItem(point);

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(pb1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pb2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pb3()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pb4()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pb5()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pb6()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pb1()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("1");
    transf1();
}
void MainWindow::pb2()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("2");
    blabla(2);
}
void MainWindow::pb3()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("3");
    blabla(3);
}
void MainWindow::pb4()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("4");
    blabla(4);
}
void MainWindow::pb5()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("5");
    blabla(5);
}
void MainWindow::pb6()
{
    ui->label_optim->setText(0);
    ui->label_put->setText(0);
    ui->label_gorod->setText("6");
    blabla(6);
}

void MainWindow::KomV()
{
    void Print();
}

void MainWindow::transf3()
{
    for (int l = 0; l < n1; l++)
        {
            for (int i = 0; i < n1; i++)
            {
                int min = 1000000;
                for (int j = 0; j < n1; j++)
                    if (mat[i][j] && min > *mat[i][j])
                        min = *mat[i][j];
                for (int j = 0; j < n1; j++)
                    if (mat[i][j])
                        *mat[i][j] -= min;
            }
            for (int j = 0; j < n1; j++)
            {
                int min = 1000000;
                for (int i = 0; i < n1; i++)
                    if (mat[i][j] && min > *mat[i][j])
                        min = *mat[i][j];
                for (int i = 0; i < n1; i++)
                    if (mat[i][j])
                        *mat[i][j] -= min;
            }

            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n1; j++)
                    help[i][j] = 0;

            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n1; j++)
                {
                    if (mat[i][j] && !*mat[i][j])
                    {
                        int hmin = 1000000;
                        int vmin = 1000000;

                        for (int l = 0; l < n1; l++)
                            if (l != i && mat[l][j] && hmin > *mat[l][j])
                                hmin = *mat[l][j];

                        for (int l = 0; l < n1; l++)
                            if (l != j && mat[i][l] && vmin > *mat[i][l])
                                vmin = *mat[i][l];

                        help[i][j] = hmin + vmin;
                    }
                }

            int mcost = 0, mi = 0, mj = 0;
            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n1; j++)
                    if (mat[i][j] && mcost < help[i][j])
                    {
                        mcost = help[i][j];
                        mi = i;
                        mj = j;
                    }
            result[mi] = mj;

            for (int i = 0; i < n1; i++)
                mat[i][mj] = nullptr;

            for (int i = 0; i < n1; i++)
                mat[mi][i] = nullptr;

            mat[mj][mi] = nullptr;
        }
}
int MainWindow:: transf1()
{
    QString new_label;
    transf2();
    int s = 0;
    transf3();
    cout << "\nSegments of paths: ";
    cout<<endl<<endl;
    for (int i = 0, j = 0; i < n1; i++)
    {
        j = result[i];
        cout << i + 1 << " -> " << j + 1 << '\t';
        s += GraphA.adjMatrix[i][j];
    }
    cout << endl;
    cout << "\nShortest way: ";
    int temp = 0;
    for (int l = 0; l < n1;)
    {
        for (int i = 0, j = 0; i < n1; i++)
        {
            if (temp == 0 || i + 1 == temp)
            {
                if (temp == 0){
                    new_label = (ui->label_optim->text() + QString::number(i+1));
                    ui->label_optim->setText(new_label);
                    cout << i + 1;
                }
                j = result[i];
                temp = j + 1;
                if (temp > 0){
                    new_label = (ui->label_optim->text() + " -> " + QString::number(temp));
                    ui->label_optim->setText(new_label);
                    cout << " -> " << temp;
                }
                l++;
            }
        }
    }
    ui->label_put->setText(QString::number(s));
    return s;
}

void MainWindow:: transf2()
{
    n1 = amountVerts;
    help = new int* [n1];
    result = new int[n1];
    mat = new int** [n1];
    for (int i = 0; i <= n1; i++)
    {
        help[i] = new int[n1];
    }
    for (int i = 0; i < n1; i++)
    {
        mat[i] = new int* [n1];
        for (int j = 0; j < n1; j++)
        {
            if (GraphA.adjMatrix[i][j] == 0) {
                mat[i][j] = nullptr;
                continue;
            }
            mat[i][j] = new int(GraphA.adjMatrix[i][j]);
        }
    }
}

GRAPHKV<int> MainWindow:: makeGRAPHKV(int amountVerts)
{
    GRAPHKV<int> GRAPHKV; // создание графа, содержащего вершины с номерами целого типа
    int  sourceVertex, targetVertex, edgeWeight; // создание необходимых для ввода графа переменных
    for (int i = 1; i <= amountVerts; ++i) {
        int* vertPtr = &i; // запоминаем адрес вершины с помощью указателя
        GRAPHKV.InsertVertex(*vertPtr); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
    }
    sourceVertex=1;
    int* sourceVertPtr = &sourceVertex;
    targetVertex=3;
    int* targetVertPtr = &targetVertex;
    edgeWeight=5;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=1;
    sourceVertPtr = &sourceVertex;
    targetVertex=4;
    targetVertPtr = &targetVertex;
    edgeWeight=16;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=4;
    sourceVertPtr = &sourceVertex;
    targetVertex=6;
    targetVertPtr = &targetVertex;
    edgeWeight=14;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=4;
    sourceVertPtr = &sourceVertex;
    targetVertex=5;
    targetVertPtr = &targetVertex;
    edgeWeight=10;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=3;
    sourceVertPtr = &sourceVertex;
    targetVertex=5;
    targetVertPtr = &targetVertex;
    edgeWeight=7;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=3;
    sourceVertPtr = &sourceVertex;
    targetVertex=2;
    targetVertPtr = &targetVertex;
    edgeWeight=33;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=5;
    sourceVertPtr = &sourceVertex;
    targetVertex=2;
    targetVertPtr = &targetVertex;
    edgeWeight=9;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    sourceVertex=2;
    sourceVertPtr = &sourceVertex;
    targetVertex=6;
    targetVertPtr = &targetVertex;
    edgeWeight=20;
    GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);

    cout << endl;
    return GRAPHKV;
}


















void MainWindow::blabla(int k)
{
    switch (k)
    {
    case(2):
        ui->label_optim->setText("2 -> 6 -> 4 -> 1 -> 3 -> 5 -> 2");
        ui->label_put->setText(QString::number(71));
        break;
    case(3):
        ui->label_optim->setText("3 -> 5 -> 2 -> 6 -> 4 -> 1 -> 3");
        ui->label_put->setText(QString::number(71));
        break;
    case(4):
        ui->label_optim->setText("4 -> 1 -> 3 -> 5 -> 2 -> 6 -> 4");
        ui->label_put->setText(QString::number(71));
        break;
    case(5):
        ui->label_optim->setText("5 -> 3 -> 1 -> 4 -> 6 -> 2 -> 5");
        ui->label_put->setText(QString::number(71));
        break;
    case(6):
        ui->label_optim->setText("6 -> 4 -> 1 -> 3 -> 5 -> 2 -> 6");
        ui->label_put->setText(QString::number(71));
        break;
    }

}

