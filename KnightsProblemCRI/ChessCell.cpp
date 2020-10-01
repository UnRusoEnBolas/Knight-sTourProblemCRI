#include "ChessCell.h"

ChessCell::ChessCell(int x, int y) {
    this->x = x;
    this->y = y;
}

std::pair<int,int> ChessCell::getCoordinates() {
    return std::pair<int, int>(this->x, this->y);
}

bool ChessCell::isVisited() {
    return this->visited;
}

int ChessCell::getVisitedIndex() {
    return this->visitedIndex;
}

int ChessCell::setAsVisited(int index) {
    this->visitedIndex = index;
    this->visited = true;
    return this->visitedIndex;
}

void ChessCell::setAsNotVisited() {
    this->visitedIndex = -1;
    this->visited = false;
}