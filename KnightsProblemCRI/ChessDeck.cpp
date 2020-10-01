#include "ChessDeck.h"
#include <iostream>

ChessDeck::ChessDeck() {
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 4; y++) {
            this->deck[x][y] = new ChessCell(x, y);
        }
    }
}

void ChessDeck::setAsVisited(std::pair<int, int> newPosition) {
    this->nVisitedCells++;
    this->deck[newPosition.first][newPosition.second]->setAsVisited(this->nVisitedCells);
}

void ChessDeck::setAsUnvisited(std::pair<int, int> position) {
    this->nVisitedCells--;
    this->deck[position.first][position.second]->setAsNotVisited();
}

bool ChessDeck::isCellVisited(int x, int y) {
    return this->deck[x][y]->isVisited();
}

int ChessDeck::getNFutureAvailableMoves(std::pair<int, int> futurePosition) {
    int futureMoves = 0;
    std::pair<int, int> offsets[8] = {
        std::pair<int,int>(2, 1),
        std::pair<int,int>(1, 2),
        std::pair<int,int>(-1, 2),
        std::pair<int,int>(-2, -1),
        std::pair<int,int>(-2, 1),
        std::pair<int,int>(-1, -2),
        std::pair<int,int>(1, -2),
        std::pair<int,int>(2, -1)
    };

    for (int i = 0; i < 8; i++) {
        std::pair<int, int> candidatePosition(futurePosition.first + offsets[i].first, futurePosition.second + offsets[i].second);
        if (candidatePosition.first >= 0 && candidatePosition.first < 3 && candidatePosition.second >= 0 && candidatePosition.second < 4) {
            if (!this->isCellVisited(candidatePosition.first, candidatePosition.second)) {
                futureMoves++;
            }
        }
    }

    return futureMoves;
}

void ChessDeck::printDeck() {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 4; y++)
        {
            if (this->deck[x][y]->isVisited()) {
                std::cout << "["<<this->deck[x][y]->getVisitedIndex() << "] ";
            } else {
                std::cout << "[-] ";
            }
        }
        std::cout << "\n";
    }
}