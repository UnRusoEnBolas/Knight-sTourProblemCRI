#include "ChessHorse.h"
#include <algorithm>
#include <iostream>

ChessHorse::ChessHorse(ChessDeck* deck, std::pair<int, int> startingCoordinates) {
	this->deck = deck;
	this->visitedPositions.push_front(startingCoordinates);
	this->deck->setAsVisited(startingCoordinates);
}

void ChessHorse::moveTo(std::pair<int, int> newPosition) {
	this->visitedPositions.push_front(newPosition);
	this->deck->setAsVisited(newPosition);
}

void ChessHorse::undoMove() {
	this->deck->setAsUnvisited(this->visitedPositions.front());
	this->visitedPositions.pop_front();
}

std::list<Move> ChessHorse::getVisitableCells() {
	std::list<Move> candidateMoves;
	std::pair<int,int> offsets[8] = {
		std::pair<int,int>(2, 1),
		std::pair<int,int>(1, 2),
		std::pair<int,int>(-1, 2),
		std::pair<int,int>(-2, -1),
		std::pair<int,int>(-2, 1),
		std::pair<int,int>(-1, -2),
		std::pair<int,int>(1, -2),
		std::pair<int,int>(2, -1)
	};
	std::pair<int, int> currentPosition = this->visitedPositions.front();

	for (int i = 0; i < 8; i++) {
		std::pair<int, int> candidatePosition(currentPosition.first + offsets[i].first, currentPosition.second + offsets[i].second);
		if (candidatePosition.first >= 0 && candidatePosition.first < 3 && candidatePosition.second >= 0 && candidatePosition.second < 4) {
			if (!this->deck->isCellVisited(candidatePosition.first, candidatePosition.second)) {
				Move m;
				m.destination = candidatePosition;
				m.nFutureMoves = this->deck->getNFutureAvailableMoves(candidatePosition);
				candidateMoves.push_back(m);
			}
		}
	}

	candidateMoves.sort([](const Move& a, const Move& b) { return a.nFutureMoves < b.nFutureMoves; });

	return candidateMoves;
}