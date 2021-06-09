#include "mygraphicview.h"


MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

MyPoint::~MyPoint()
{

}
QRectF MyPoint::boundingRect() const
{
    return QRectF(0,0,100,100);
}
void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x1 = -230, y1 = -80, x2 = 20, y2 = -145, x3 = 200, y3 = -100, x4 = 240, y4 = 50, x5 = 160, y5 = 160, x6 = -40, y6 = 60;

    painter->setBrush(Qt::green);
    painter->drawLine(x1+25, y1+25, x2+25, y2+25);
    painter->drawLine(x2+25, y2+25, x3+25, y3+25);
    painter->drawLine(x3+25, y3+25, x4+25, y4+25);
    painter->drawLine(x4+25, y4+25, x5+25, y5+25);
    painter->drawLine(x5+25, y5+25, x6+25, y6+25);
    painter->drawLine(x1+25, y1+25, x6+25, y6+25);
    painter->drawLine(x2+25, y2+25, x5+25, y5+25);
    painter->drawLine(x4+25, y4+25, x6+25, y6+25);
    painter->drawEllipse(QRectF(x1, y1, 50, 50));
    painter->drawEllipse(QRectF(x2, y2, 50, 50));
    painter->drawEllipse(QRectF(x3, y3, 50, 50));
    painter->drawEllipse(QRectF(x4, y4, 50, 50));
    painter->drawEllipse(QRectF(x5, y5, 50, 50));
    painter->drawEllipse(QRectF(x6, y6, 50, 50));
    painter->setPen(Qt::black);
    painter->drawText(x1+22, y1+28, "1");
    painter->drawText(x2+22, y2+28, "4");
    painter->drawText(x3+22, y3+28, "6");
    painter->drawText(x4+22, y4+28, "2");
    painter->drawText(x5+22, y5+28, "5");
    painter->drawText(x6+22, y6+28, "3");
    painter->setPen(Qt::gray);
    painter->drawText(((x1+x2)/2)+20,((y1+y2)/2)+15, "16");
    painter->drawText(((x2+x3)/2)+25,((y2+y3)/2)+20, "14");
    painter->drawText(((x3+x4)/2)+28,((y3+y4)/2)+25, "20");
    painter->drawText(((x4+x5)/2)+18,((y4+y5)/2)+23, "9");
    painter->drawText(((x5+x6)/2)+10,((y5+y6)/2)+15, "7");
    painter->drawText(((x1+x6)/2)+25,((y1+y6)/2)+20, "5");
    painter->drawText(((x2+x5)/2)+20,((y2+y5)/2)+15, "10");
    painter->drawText(((x4+x6)/2)-10,((y4+y6)/2)+22, "33");


        Q_UNUSED(option);
        Q_UNUSED(widget);
}

/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
