#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include<QTimer>
#include "player.h"
#include "pellets.h"
#include"ghost.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Create the view and the scene ****************
    QGraphicsView view;
    view.setFixedSize(960, 912);
    view.setWindowTitle("PacMAN Game");
    view.setBackgroundBrush(QBrush(Qt::black));
    QGraphicsScene scene;
    view.setScene(&scene);
    // **********************************************

    // Read board data from text file ***************
    QFile file("board.txt");
    file.open(QIODevice::ReadOnly);
    int boardData[33][36];
    QTextStream stream(&file);
    QString temp;
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 36; j++)
        {
            stream >> temp; // cin >> temp;
            boardData[i][j] = temp.toInt();
        }
    // **********************************************

    // Draw the graphics of the board ***************
    QPixmap bricksImage("Bricks.jpg");
    bricksImage = bricksImage.scaledToWidth(x);
    bricksImage = bricksImage.scaledToHeight(x);
    QPixmap foodImage("pellet.png");
    foodImage = foodImage.scaledToWidth(x/2);
    foodImage = foodImage.scaledToHeight(x/2);
    QPixmap super("pellet.png");
    super = super.scaledToWidth(x);
    super = super.scaledToHeight(x);
    QGraphicsPixmapItem boardImages[33][36];
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 36; j++)
        {
            if (boardData[i][j] == -1)
            {
                boardImages[i][j].setPixmap(bricksImage);
                boardImages[i][j].setPos(x + x * j, x + x * i);
            }

            scene.addItem(&boardImages[i][j]);
        }


    // Create the player ****************************
    Player p(1, 1, boardData);
    scene.addItem(p.getLive());
    scene.addItem(p.getScores());
    scene.addItem(p.getMode());
    scene.addItem(&p);



    //pellets
    pellets **arr=new pellets*[33];
    for(int i=0;i<33;i++)
        arr[i] = new pellets[36];

    for (int i =0 ; i< 33; i++)
    {
        for (int j =0 ; j < 36 ; j++)
        {
            if (boardData[i][j] == 0 || (266<= boardData[i][j] && boardData[i][j] <= 271) || (292<= boardData[i][j] && boardData[i][j] <= 297) || (318<= boardData[i][j] && boardData[i][j] <= 323))
           {

           }
           else if (boardData[i][j] == 158  || boardData[i][j] == 185    ||boardData[i][j] == 557    ||boardData[i][j] == 590   )
           {
               arr[i][j].setpellet(i ,j ,2);
           }
           else if (boardData[i][j] != -1)
           {
               arr[i][j].setpellet(i ,j , 1);

           }
            scene.addItem(&arr[i][j]);
        }
    }



    //Ghosts
    GHOST inky(16 , 15 ,boardData , "inky");
    GHOST blinky(16 , 17 ,boardData , "blinky");
    GHOST clyde(16 , 19 ,boardData , "clyde");
    scene.addItem(&inky);
    scene.addItem(&blinky);
    scene.addItem(&clyde);

    p.getghosts(&inky, &blinky , &clyde);


    p.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    p.setFocus();

    view.show();
    return a.exec();


//    for(int i=0;i<33;i++)
//    {
//        delete *(arr+1);
//        *(arr+i)=NULL;
//    }
//    arr= NULL;
}
