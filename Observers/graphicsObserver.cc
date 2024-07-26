#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "graphicsObserver.h"
#include "../subject.h"
#include "../square.h"

//#include "king.txt"
using namespace std;

GraphicsObserver::GraphicsObserver(Subject *sub): w{Xwindow(500, 500)}, sub{sub} {
    fileToArr(kingarr, "king.txt");
    fileToArr(queenarr, "queen.txt");
    fileToArr(rookarr, "rook.txt");
    fileToArr(bishoparr, "bishop.txt");
    fileToArr(knightarr, "knight.txt");
    fileToArr(pawnarr, "pawn.txt");
}

void fileToArr(int arr[25][25], string file) {
    ifstream myfile;
    myfile.open(file);
    for (int k = 0; k < 25; k++) {
        for (int l = 0; l < 25; l++) {
            int a;
            myfile >> a;
            arr[k][l] = a;
        }
    }
    myfile.close();
}

void GraphicsObserver::notifyFull() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 1) w.fillRectangle(i * 50 + 50, j * 50 + 50, 50, 50, Xwindow::MediumSlateBlue);
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
            if (state == 'K') w.drawImage(i * 50 + 62, j * 50 + 62, kingarr, colour);
            else if (state == 'Q') w.drawImage(i * 50 + 62, j * 50 + 62, queenarr, colour);
            else if (state == 'N') w.drawImage(i * 50 + 62, j * 50 + 62, knightarr, colour);
            else if (state == 'B') w.drawImage(i * 50 + 62, j * 50 + 62, bishoparr, colour);
            else if (state == 'R') w.drawImage(i * 50 + 62, j * 50 + 62, rookarr, colour);
            else w.drawImage(i * 50 + 62, j * 50 + 62, pawnarr, colour);
        }
    }
}

void GraphicsObserver::notifyChange(Move m) {
    for (auto deleted : m.getDeleted()) {
        int row = deleted->getRow();
        int col = deleted->getCol();
        if ((row + col) % 2 == 0) w.fillRectangle(col * 50 + 50, row * 50 + 50, 50, 50, Xwindow::LightSkyBlue); 
        else w.fillRectangle(col * 50 + 50, row * 50 + 50, 50, 50, Xwindow::MediumSlateBlue);
    }
    for (auto added : m.getAdded()) {
        int row = added->getRow();
        int col = added->getCol();
        char state = sub->getState(row, col);
        if (state == ' ') {
            w.fillRectangle(col * 50 + 50, row * 50 + 50, 50, 50, Xwindow::LightSkyBlue);
            continue;
        }
        else if (state == '_') {
            w.fillRectangle(col * 50 + 50, row * 50 + 50, 50, 50, Xwindow::MediumSlateBlue);
            continue;
        }
        int colour = Xwindow::White;
        if (state > 'Z') {
            colour = Xwindow::Black;
            state -= 'a' - 'A';
        }
        if (state == 'K') w.drawImage(row * 50 + 62, col * 50 + 62, kingarr, colour);
        else if (state == 'Q') w.drawImage(row * 50 + 62, col * 50 + 62, queenarr, colour);
        else if (state == 'N') w.drawImage(row * 50 + 62, col * 50 + 62, knightarr, colour);
        else if (state == 'B') w.drawImage(row * 50 + 62, col * 50 + 62, bishoparr, colour);
        else if (state == 'R') w.drawImage(row * 50 + 62, col * 50 + 62, rookarr, colour);
        else w.drawImage(row * 50 + 62, col * 50 + 62, pawnarr, colour);
    }

}

GraphicsObserver::~GraphicsObserver() {}
