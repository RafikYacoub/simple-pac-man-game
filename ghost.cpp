#include "ghost.h"
#include"player.h"


GHOST::GHOST(int initialRow, int initialColumn, int d[33][36], QString n)
{
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 36; j++)
            data[i][j] = d[i][j];

    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(movement()));


    if (n=="inky")
    {
        QPixmap inkyImage("inky.png");
        inkyImage = inkyImage.scaledToWidth(x);
        inkyImage = inkyImage.scaledToHeight(x);
        setPixmap(inkyImage);
        row = initialRow;
        column = initialColumn;
        initialrow=initialRow;
        initialcolumn=initialColumn;
        setPos(x + x * column, x + x * row);
        time->start(200);

    }
    else if (n=="clyde")
    {
        QPixmap clydeImage("clyde.png");
        clydeImage = clydeImage.scaledToWidth(x);
        clydeImage = clydeImage.scaledToHeight(x);
        setPixmap(clydeImage);
        row = initialRow;
        column = initialColumn;
        initialrow=initialRow;
        initialcolumn=initialColumn;
        setPos(x + x * column, x + x * row);
        time->start(250);

    }
    else if (n=="blinky")
    {
        QPixmap blinkyImage("blinky.png");
        blinkyImage = blinkyImage.scaledToWidth(x);
        blinkyImage = blinkyImage.scaledToHeight(x);
        setPixmap(blinkyImage);
        row = initialRow;
        column = initialColumn;
        initialrow=initialRow;
        initialcolumn=initialColumn;
        setPos(x + x * column, x + x * row);
        time->start(300);

    }


}

void GHOST::setRow(int newRow)
{
    row = newRow;
}
void GHOST::setColumn(int newColumn)
{
    column = newColumn;
}
int GHOST::getRow()
{
    return row;
}
int GHOST::getColumn()
{
    return column;
}

//void GHOST::collisions()
//{
//    QList<QGraphicsItem*> items = collidingItems();
//    for (int i = 0; i < items.size(); i++)
//      if (typeid(*items[i]) == typeid(Player))
//          resetpos();
//}

void GHOST::resetpos()
{
    setPos(x + x * initialcolumn, x + x * initialrow);
}



void GHOST::movement(){
    int r = rand() % 4;
    if(r==0 && data[row][column + 1] != -1){
        column++; //right
    }else if(r==1 && data[row][column - 1] != -1){
        column--; //left
    }else if(r==2 && data[row + 1][column] != -1){
        row++; //down
    }else if(r==3 && data[row - 1][column] != -1){
        row--;
    }
    setPos(x + x * column, x + x * row);
}
