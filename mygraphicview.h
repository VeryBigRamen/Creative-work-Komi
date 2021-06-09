#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class MyPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyPoint(QObject *parent = 0);
    ~MyPoint();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};


#endif // MYGRAPHICVIEW_H
