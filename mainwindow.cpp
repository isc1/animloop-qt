#include "mainwindow.h"
#include <QPen>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 1920x1080 yields a 0.56 pixel ratio
    setGeometry(56,100,600,600);

    mGraphicsScene = new QGraphicsScene(0, 0, 400, 400);

    mGraphicsView = new QGraphicsView(mGraphicsScene, this);
    mGraphicsView->setGeometry(0, 0, 600, 600);
    mGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    mGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    QPen pen;
    pen.setColor(QColor(Qt::blue));
    pen.setWidth(2);
    // add a blue rectangle which indicates the boundaries of the scene. (we think?)
    // ...why can graphical objects exist & be rendered outside the dimensions of the scene?
    // if you watch the animation at runtime, the circle will pass outside the border of
    // the blue box, and yet is still rendered in the view...
    mGraphicsScene->addRect(0, 0, mGraphicsScene->width(), mGraphicsScene->height(), pen);

    // these ints will go out of scope after constructor is called because they are not
    // defined in the mainwindow class declaration of the mainwindow.h file:
    int x = 100, y = 100, w = 10, h = 10;
    mEllipseItem = new QGraphicsEllipseItem(x,y,w,h);
    pen.setColor(QColor(Qt::black));
    pen.setWidth(1);
    mEllipseItem->setPen(pen);
    mGraphicsScene->addItem(mEllipseItem);

    mUpdateIntervalMS = 60;

    startGameLoopTimer();
}

MainWindow::~MainWindow()
{
    if (mGraphicsView != NULL)
    {
        delete mGraphicsView;
        mGraphicsView = NULL;
    }
    if (mGraphicsScene != NULL)
    {
        delete mGraphicsScene;
        mGraphicsScene = NULL;
    }
}

void MainWindow::startGameLoopTimer()
{
    //start our update loop
    QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(gameTick()));
    mTimer.start(mUpdateIntervalMS);
}

void MainWindow::gameTick()
{
    //qDebug() << "MainWindow::gameTick(): invoked\n";

    mEllipseItem->setX(mEllipseItem->x()+1);
    mEllipseItem->setY(mEllipseItem->y()+1);
    mGraphicsScene->advance();
}

/// TAKE OUT THIS RANDOM STUFF IF YOU ARE NOT GOING TO USE IT:
///
///

// random:  returns a random int between 0 and "biggest" inclusive
// for example random(100) returns an int between 0 and 100
int MainWindow::random(int biggest)
{
    return qrand() % (biggest + 1);
}

// randomRange: return a number between smallest and biggest
// you can supply positive or negative ints, just make sure smallest < biggest
// for example calling it with 10,20 will give you a random int betwen 10 and 20
// supplying -30,20 will give a random int between -30 and 20
int MainWindow::randomRange(int smallest, int biggest)
{
    if ( smallest < biggest)
    {
        return (qrand() % (biggest - (smallest + 1))) + smallest;
    }
    else
    {
        return 0;
    }
}
