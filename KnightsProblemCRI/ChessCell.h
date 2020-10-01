#include <utility>
#pragma once

class ChessCell {
    private:
        int x;
        int y;
        bool visited = false;
        int visitedIndex = -1;
    public:
        ChessCell(int x, int y);
        std::pair<int, int> getCoordinates();
        int setAsVisited(int index);
        void setAsNotVisited();
        bool isVisited();
        int getVisitedIndex();
};