#include "ChessCell.h"
#include <list>
#pragma once

class ChessDeck {
    private:
        ChessCell* deck[3][4];
        int nVisitedCells = 0;
        std::pair<int, int> dimensions;
    public:
        ChessDeck();
        void setAsVisited(std::pair<int, int> newPosition);
        void setAsUnvisited(std::pair<int, int> position);
        bool isCellVisited(int x, int y);
        int getVisitedCells() { return this->nVisitedCells; }
        int getNFutureAvailableMoves(std::pair<int, int> futurePosition);
        void printDeck();
};