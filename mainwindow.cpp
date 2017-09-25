#include "mainwindow.h"
#include <QPen>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // specify app window geometry. 1920x1080 screen rez yields a 0.56 pixel ratio
    setGeometry(56,100,600,600);

    // set up the scene
    // traditionally, member objects start with the letter 'm'
    mGraphicsScene = new QGraphicsScene(0, 0, 400, 400);

    // set up the view
    mGraphicsView = new QGraphicsView(mGraphicsScene, this);
    mGraphicsView->setGeometry(0, 0, 600, 600);
    mGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    mGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    // add a blue box that is the size of the scene
    QPen pen;
    pen.setColor(QColor(Qt::blue));
    pen.setWidth(2);
    mGraphicsScene->addRect(0, 0, mGraphicsScene->width(), mGraphicsScene->height(), pen);

    // these ints will go out of scope after constructor is called because they are not
    // defined in the mainwindow class declaration of the mainwindow.h file:
    int x = 100, y = 100, w = 10, h = 10;

    // add a black circle known as mEllipseItem to the scene
    mEllipseItem = new QGraphicsEllipseItem(x,y,w,h);
    pen.setColor(QColor(Qt::black));
    pen.setWidth(1);
    mEllipseItem->setPen(pen);
    mGraphicsScene->addItem(mEllipseItem);

    // how often we update the scene, in milliseconds:
    mUpdateIntervalMS = 60;

    // start the signal/slot timer, which invokes gameTick() every mUpdateIntervalMS milliseconds
    startGameLoopTimer();
}

MainWindow::~MainWindow()
{
    // this is the destructor code for the MainWindow object
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
    // associate the signal timeout() to the slot gameTick(), and start our update timer
    QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(gameTick()));
    mTimer.start(mUpdateIntervalMS);
}

void MainWindow::gameTick()
{
    // this code makes whatever changes to the scene you want to make, every gametick.
    // if you want to change what the animation does, you can do that here, or add new
    // functions (methods) and call them from here.

    // Change this code to make the circle stay within the blue box! :-D You could have
    // the circle just stop moving when it reaches the edge of the scene at x,y == 400,400
    // or you could make the circle change direction somehow when x or y get outside of
    // the range of 0 to 400.  Or think of some other way the circle should move!

    // you can uncomment the following line to produce console output every gametick.
    // this will generate around 16 messages per second at 60ms gametick.
    //qDebug() << "MainWindow::gameTick(): invoked\n";

    mEllipseItem->setX(mEllipseItem->x()+1);
    mEllipseItem->setY(mEllipseItem->y()+1);
    mGraphicsScene->advance();
}
