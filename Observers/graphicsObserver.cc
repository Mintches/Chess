#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "graphicsObserver.h"
#include "../subject.h"

//#include "king.txt"
using namespace std;

GraphicsObserver::GraphicsObserver(Subject *sub): w{Xwindow(500, 500)}, sub{sub} {}

void GraphicsObserver::notify() {
    int arr[25][25];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) w.fillRectangle(i * 50 + 50, j * 50 + 50, 50, 50, Xwindow::MediumSlateBlue);
            else w.fillRectangle(i * 50 + 50, j * 50 + 50, 50, 50, Xwindow::LightSkyBlue);
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char state = sub->getState(i, j);
            if (state == ' ' || state == '_') continue;
            int colour = Xwindow::White;
            if (state > 'Z') {
                colour = Xwindow::Black;
                state -= 'a' - 'A';
            }
            cout << state << "\n";
            ifstream myfile;
            if (state == 'K') myfile.open("help.txt");
            else if (state == 'Q') myfile.open("help.txt");
            else if (state == 'N') myfile.open("knight.txt");
            else if (state == 'B') myfile.open("bishop.txt");
            else if (state == 'R') myfile.open("rook.txt");
            else myfile.open("pawn.txt");
            for (int k = 0; k < 25; k++) {
                for (int l = 0; l < 25; l++) {
                    int a;
                    myfile >> a;
                    arr[k][l] = a;
                }
            }
            w.drawImage(i * 50 + 62, j * 50 + 62, arr, colour);
            myfile.close();
        }
    }
    
}

GraphicsObserver::~GraphicsObserver() {}