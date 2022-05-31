#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include<QtCore>
#include<QTimer>
#include<QList>
#include"pellets.h"
#include"ghost.h"
#include <QDebug>
#define x 24



class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int live =3;
    int score= 0;
    int i = 0;
    int row;
    int column;
    int data[33][36];


    QString L;
    QString S;
    QString button=" ";
    QString m = "Normal";


    QTimer *timer;
    QTimer *pac;
    QTime time;


    QGraphicsTextItem* Live;
    QGraphicsTextItem* Scores;
    QGraphicsTextItem* Mode;
    QGraphicsTextItem game;

    GHOST *Inky;
    GHOST *Blinky;
    GHOST *Clyde;



public: 


    QGraphicsTextItem* getLive();
    QGraphicsTextItem* getScores();
    QGraphicsTextItem* getMode();

    Player(int initialRow, int initialColumn, int d[33][36]);
    void changeplayer();
    void setRow(int newRow);
    void setColumn(int newColumn);
    int getRow();
    int getColumn();
    void setTexts();
    void collision();
    void resetpos();
    void getghosts(GHOST* inky, GHOST* blinky, GHOST* clyde);

private slots:
    void keyPressEvent(QKeyEvent *event);
    void moving();
    void pacmouth();
};
#endif // PLAYER_H
