#include "pellets.h"
#include"player.h"




pellets::pellets(int initialrow, int initailcolumn , int m)
{


    if (m==1)
    {
        QPixmap foodImage("pellet.png");
        foodImage = foodImage.scaledToWidth(x/2);
        foodImage = foodImage.scaledToHeight(x/2);
        setPixmap(foodImage);
        row =initialrow;
        column= initailcolumn;
        setPos(x +6 + x * column, x + 6+  x * row);

    }
    else if ( m == 2)
    {
        QPixmap SuperPellet("pellet.png");
        SuperPellet = SuperPellet.scaledToWidth(x);
        SuperPellet = SuperPellet.scaledToHeight(x);
        setPixmap(SuperPellet);

        row =initialrow;
        column= initailcolumn;
        setPos(x + x * column, x + x * row);

    }
}

pellets::pellets()
{

}

void pellets::setpellet(int initialrow, int initailcolumn, int m)
{
    if (m==1)
    {
        QPixmap foodImage("pellet.png");
        foodImage = foodImage.scaledToWidth(x/2);
        foodImage = foodImage.scaledToHeight(x/2);
        setPixmap(foodImage);
        row =initialrow;
        column= initailcolumn;
        setPos(x +6 + x * column, x + 6+  x * row);

    }
    else if ( m == 2)
    {
        QPixmap SuperPellet("pellet.png");
        SuperPellet = SuperPellet.scaledToWidth(x);
        SuperPellet = SuperPellet.scaledToHeight(x);
        setPixmap(SuperPellet);

        row =initialrow;
        column= initailcolumn;
        setPos(x + x * column, x + x * row);

    }

}


void pellets::setRow(int newRow)
{
    row = newRow;
}

void pellets::setColumn(int newColumn)
{
    column = newColumn;
}

int pellets::getRow()
{
    return row;
}

int pellets::getColumn()
{
    return column;
}

