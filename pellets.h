#ifndef PELLETS_H
#define PELLETS_H


#include <QGraphicsPixmapItem>
#include<QGraphicsScene>


class pellets : public QGraphicsPixmapItem
{


public:
    pellets(int initialrow, int initailcolumn , int m);
    pellets();

    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
    void setpellet(int initialrow, int initailcolumn , int m);

private:
    int row;
    int column;



};

#endif // PELLETS_H
