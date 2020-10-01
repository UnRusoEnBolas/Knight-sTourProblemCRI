#include <list>
#include <utility>
#include "ChessDeck.h"
#pragma once

struct Move {
	int nFutureMoves;
	std::pair<int, int> destination;
};

class ChessHorse {
	private:
		ChessDeck* deck;
		std::list<std::pair<int, int>> visitedPositions;
	public:
		ChessHorse(ChessDeck* deck, std::pair<int, int> startingCoordinates);
		void moveTo(std::pair<int,int> newPosition);
		void undoMove();
		std::list<Move> getVisitableCells();
		//std::list<std::pair<int, int>>getVisitableCells_OnlyRemaining();
};