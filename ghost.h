#ifndef GHOST_H
#define GHOST_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class GHOST: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
private:
    int row;
    int column;
    int initialrow;
    int initialcolumn;
    int data[33][36];
     QTimer *time;
public:
    GHOST(int initialRow, int initialColumn, int d[33][36], QString n);
    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
    void resetpos();
    void collisions();


public slots:
    void movement();


};

#endif
