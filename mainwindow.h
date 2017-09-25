#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView *mGraphicsView;
    QGraphicsScene *mGraphicsScene;
    QGraphicsEllipseItem *mEllipseItem;
    void startGameLoopTimer();
    QTimer mTimer;
    long mUpdateIntervalMS;

private slots:
    void gameTick();
};

#endif // MAINWINDOW_H
