#include "player.h"
#include<QtCore>
#include<QTimer>
#include<QDebug>
#include<QFont>





Player::Player(int initialRow, int initialColumn, int d[33][36])
{


    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 36; j++)
            data[i][j] = d[i][j];

    QPixmap playerImageright("pacman.png");
    playerImageright = playerImageright.scaledToWidth(x);
    playerImageright = playerImageright.scaledToHeight(x);
    setPixmap(playerImageright);

    row = initialRow;
    column = initialColumn;
    setPos(x + x * column, x + x * row);


    timer = new QTimer(this);
    connect (timer,SIGNAL(timeout()), this , SLOT(moving()));
    timer->start(250);

    pac= new QTimer(this);
    connect (pac, SIGNAL(timeout()), this , SLOT(pacmouth()));
    pac->start(100);

    Live = new QGraphicsTextItem();
    Live->setPos(0,820);
    Live->setDefaultTextColor("white");
    Live->setScale(1.5);
    L = QString::number(live);
    Live->setPlainText("lives: " + L);


    Scores = new QGraphicsTextItem();
    Scores->setPos(0, 0);
    Scores->setDefaultTextColor("white");
    Scores->setScale(1);
    S = QString::number(score);
    Scores->setPlainText("Score :" + S);


    Mode = new QGraphicsTextItem();
    Mode->setPos(500,0);
    Mode->setDefaultTextColor("white");
    Mode->setScale(1);
    Mode->setPlainText("Mode: " + m);

    game.setPos(426,456);
    game.setDefaultTextColor("yellow");
    game.setScale(3);


    S = QString::number(score);
    L = QString::number(live);

}


QGraphicsTextItem *Player::getLive()
{
    return Live;
}

QGraphicsTextItem *Player::getScores()
{
    return Scores;
}

QGraphicsTextItem *Player::getMode()
{
    return Mode;
}


//texts
void Player::setTexts()
{

    L = QString::number(live);
    Live->setPlainText("lives: " + L);


    S = QString::number(score);
    Scores->setPlainText("Score :" + S);


    Mode->setPlainText("Mode: " + m);

}


//player directions
void Player::changeplayer()
{

    if (button=="up")
    {

        QPixmap playerImageup("pacmanUp.png");
        playerImageup = playerImageup.scaledToWidth(x);
        playerImageup = playerImageup.scaledToHeight(x);
        setPixmap(playerImageup);

    }
    else if (button=="down")
    {
        QPixmap playerImagedown("pacmanDown.png");
        playerImagedown = playerImagedown.scaledToWidth(x);
        playerImagedown = playerImagedown.scaledToHeight(x);
        setPixmap(playerImagedown);

    }
    else if (button=="right")
    {
        QPixmap playerImageright("pacman.png");
        playerImageright = playerImageright.scaledToWidth(x);
        playerImageright = playerImageright.scaledToHeight(x);
        setPixmap(playerImageright);

    }
    else if (button=="left")
    {
        QPixmap playerImageleft("pacmanLeft.png");
        playerImageleft = playerImageleft.scaledToWidth(x);
        playerImageleft = playerImageleft.scaledToHeight(x);
        setPixmap(playerImageleft);

    }
}


void Player::setRow(int newRow)
{
    row = newRow;
}
void Player::setColumn(int newColumn)
{
    column = newColumn;
}
int Player::getRow()
{
    return row;
}
int Player::getColumn()
{
    return column;
}


//collission
void Player::collision()
{
    QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(pellets))
            {
                if (data[row][column]== 158 || data[row][column]== 185 ||data[row][column]== 557 ||data[row][column]== 590)
                {
                    score+=50;
                    m="Invisible";
                    time = QTime::currentTime();
                }
                else
                    score += 10;

                if (score== 5870)   //won the game
                {
                    game.setPlainText("You Won!");
                    scene()->addItem(&game);
                    timer->stop();
                    pac->stop();

                }

                scene()->removeItem(items[i]);

            }
            else if (typeid(*items[i]) == typeid(GHOST))
            {
                if (m == "Normal")
                {
                    live--;
                    resetpos();
                    Inky->resetpos();
                    Blinky->resetpos();
                    Clyde->resetpos();
                    if (live == 0) //game over
                    {
                        game.setPos(355,320);
                        game.setDefaultTextColor("yellow");
                        game.setScale(3);
                        game.setPlainText("Game over!");
                        game.setFont(QFont("emulogic" , 3));
                        timer->stop();
                        pac->stop();
                        scene()->addItem(&game);
                    }

                }

                else if (m=="Invisible")
                {

                }

            }
            setTexts();
        }
}

void Player::resetpos()
{
    row = 1;
    column= 1;
    setPos(x + x * column, x + x * row);
}

void Player::getghosts(GHOST *inky, GHOST *blinky, GHOST *clyde)
{
    Inky= inky;
    Blinky= blinky;
    Clyde= clyde;
}


//arrows movement
void Player::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Up) && data[row - 1][column] != -1)
    {
        button="up";
        changeplayer();
        row--;
    }
    else if ((event->key() == Qt::Key_Down)&& data[row + 1][column] != -1)
    {
        button="down";
        changeplayer();

        row++;
    }
    else if ((event->key() == Qt::Key_Right)&& data[row][column + 1] != -1)
    {
        button="right";
        changeplayer();

        column++;
        if (data[row][column]==311)
        {
            column=0;
        }
    }
    else if ((event->key() == Qt::Key_Left)&& data[row][column - 1] != -1)
    {
        button="left";
        changeplayer();

        column--;
        if (data[row][column]==278)
        {
            column=35;
        }
    }


    setPos(x + x *column, x + x * row);
    collision();

}



//continuous movement
void Player:: moving ()
{
    if (button =="up" && data[row - 1][column] != -1)
    {
        row--;
    }
    else if (button =="down" && data[row + 1][column] != -1)
    {
        row++;
    }
    else if (button =="right" && data[row][column + 1] != -1)
    {
        column++;
        if (data[row][column]==311)
        {
            column=0;
        }
    }
    else if (button =="left" && data[row][column - 1] != -1)
    {
        column--;
        if (data[row][column]==278)
        {
            column=35;
        }
    }
    setPos(x + x *column, x + x * row);

    //collision
    collision();

    if (QTime::currentTime().second() - time.second() == 10)
        m="Normal";

}


//mouth animation
void Player::pacmouth()
{
    if (i%2==0)
    {
        QPixmap playerImageclosed("pacmanclosed.png");
        playerImageclosed = playerImageclosed.scaledToWidth(x);
        playerImageclosed = playerImageclosed.scaledToHeight(x);
        setPixmap(playerImageclosed);
    }
    else
        changeplayer();
    i++;
    if (i>100)
        i=0;

}
