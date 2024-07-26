#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H

#include "observer.h"
#include "window.h"

using namespace std;

class Subject; // forward declaration

class GraphicsObserver : public Observer {
    Xwindow w;
    Subject *sub;
    int kingarr[25][25];
    int queenarr[25][25];
    int rookarr[25][25];
    int bishoparr[25][25];
    int knightarr[25][25];
    int pawnarr[25][25];
    public:
        GraphicsObserver(Subject *sub);
        void notifyFull() override;
        void notifyChange(Move m) override;
        ~GraphicsObserver() override;
};

void fileToArr(int arr[25][25], string file);

#endif
