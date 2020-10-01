#include "ChessDeck.h"
#include "ChessHorse.h"
#include <iostream>

bool backtrackToSolve(ChessDeck* deck, ChessHorse* horse) {

    if (deck->getVisitedCells() == 12) return true;

    std::list<Move> visitableCells = horse->getVisitableCells();
    std::list<Move>::iterator it = visitableCells.begin();

    for (int moveIdx = 0; moveIdx < visitableCells.size(); moveIdx++) {
        it = visitableCells.begin();
        std::advance(it, moveIdx);
        horse->moveTo(it->destination);
        if (backtrackToSolve(deck, horse)) return true;
    }
    horse->undoMove();
    return false;
}

int main() {
    ChessDeck deck = ChessDeck();
    ChessHorse horse = ChessHorse(&deck, std::pair<int, int>(0, 0));

    if (backtrackToSolve(&deck, &horse)) {
        deck.printDeck();
    }

    int exit;
    std::cout << "Press any letter + Enter to exit..." << "\n";
    std::cin >> exit;
    return 0;
}