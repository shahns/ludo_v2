/*
 * Board.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#include <Board.h>

Board::Board(GameType game, Renderer* renderer):renderer(renderer)
{
	loadAssets(game);
	src.x = src.y = 0;
	src.w = dest.w = 960;
	src.h = dest.h = 960;
	dest.x = dest.y = 0;
}

void Board::drawBoard() {
	renderer->draw(boardLayout, src, dest);
}

void Board::loadAssets(GameType game) {
	cout << "boardType" << endl;
	if (_GOT) {
		boardLayout = renderer->loadTexture("assets/got_board.png");
	} else {
		boardLayout = renderer->loadTexture("assets/ludo_board.png");
	}
}


Board::~Board() {
	// TODO Auto-generated destructor stub
}

