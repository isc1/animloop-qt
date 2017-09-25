# animloop-qt

![alt text](animloop-qt-1.jpg "animloop-qt screenshot")

**This code is a simple example of one way to do a minimal QGraphicsScene animation in Qt.  This does not use QML.**

In this example, a circle moves downwards and to the right.  The blue box depicts the boundary of the QGraphicsScene, and the window dimensions are about what the QGraphicsView dimensions are.  A 60ms signal/slot timer is used to fire off each tick of the animation loop.  

For beginners, play with the setGeometry values for the scene and the view in mainwindow.cpp to get an idea of how they relate to each other, when scrollbars appear, etc.  What happens when you make the scene bigger than the view?  What happens when you make the window smaller than the view, and/or the scene?  Change the values and see what happens.  Also notice that the circle will still be rendered in the view, even when it leaves the dimensions the scene had when it was instantiated.

Another fun task for beginners would be to make the circle "bounce" off the scene boundary, so that it stays within the blue box, or add other circles, or otherwise change the animation somehow.

This code is copyright 2017 isc1 and is free for anyone to use under the MIT license.  This code was written on Desktop Qt 5.9.0 MinGW 32-bit, and may not build on later versions of Qt without modification.

**THIS CODE IS UNSUPPORTED and no one is available to respond to questions or comments about it.**

If you are new to Qt, try these links (which are unaffiliated with this project):
[https://wiki.qt.io/Basic_Qt_Programming_Tutorial](https://wiki.qt.io/Basic_Qt_Programming_Tutorial) nice tut with screenshots!

[https://ics.com/blog/getting-started-qt-and-qt-creator-windows](https://ics.com/blog/getting-started-qt-and-qt-creator-windows) nice walkthrough with screenshots by ics, (totally unrelated to isc1)
[https://doc.qt.io/qtcreator/creator-getting-started.html](https://doc.qt.io/qtcreator/creator-getting-started.html) official getting started page

[https://doc.qt.io/qt-5/gettingstarted.html](https://doc.qt.io/qt-5/gettingstarted.html) Qt 5 getting started info

Finally, if you are getting started with Qt, you owe it to yourself to check out VoidRealm's tutorial videos.  Many of them are older, so they might have some outdated info, but his videos are excellent, and he is still making Qt videos which are more current, including the new QML declarative stuff!
[https://www.youtube.com/watch?v=6KtOzh0StTc&list=PL2D1942A4688E9D63](https://www.youtube.com/watch?v=6KtOzh0StTc&list=PL2D1942A4688E9D63)