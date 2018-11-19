#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include "Piece.h"
#include <algorithm>
#include <string>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

std::string justifyR(int val) {
	std::string sVal = std::to_string(val);
	while (sVal.size() < 7) {
		sVal = " " + sVal;
	}
	return sVal;
}

Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1), m_score(0), m_rLeft(5)
{
}

void Game::play()
{
	m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]
	m_screen.gotoXY(16, 3);
	m_screen.printStringClearLine("Next piece:");

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
		waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus()
{
	
	m_screen.gotoXY(16, 8);
	m_screen.printStringClearLine("Score:     " + justifyR(m_score));
	m_screen.gotoXY(16, 9);
	m_screen.printStringClearLine("Rows left: " + justifyR(m_rLeft));
	m_screen.gotoXY(16, 10);
	m_screen.printStringClearLine("Level:     " + justifyR(m_level));
}

bool Game::playOneLevel()
{
	Timer t;
	double moveTime = std::max(1000 - (100 * (m_level)), 100);
	int x = 3;
	int y = 0;
	
	int rowsCleared;
	//set the numbers of rows needed to clear for this level
	m_rLeft = 5 * m_level;

	//pick the starting piece for the level
	currPiece = pickPiece(m_well);

	//display the well with nothing in it
	m_well.clearWell();
	m_well.display(m_screen, WELL_X, WELL_Y);
	
	//level really begins
	while (m_rLeft > 0) {
		//display all the stats
		displayStatus();
		
		//check to make sure game's not over
		if (currPiece->conflict(x, y)) {
			currPiece->makeBlock(x, y);
			m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
			delete currPiece;
			currPiece = nullptr;
			return false;
		}

		//decide what the next piece will be
		nextPiece = pickPiece(m_well);

		//display the next piece on the side
		nextPiece->statusBlock(m_screen);
		
		bool spaceBreak = false;
		bool nextIter = false;

		//for current piece, while there is no conflict after the piece moves down
		while (!(currPiece->conflict(x, y))) {
			
			//display the piece in the initial starting position
			currPiece->makeBlock(x, y);
			m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
			
			//allow for player to have some time to make their moves
			t.start();
			while (t.elapsed() < moveTime) {
				char ch;
				if (getCharIfAny(ch)) {
					switch (ch)
					{
						case 'q':
						case 'Q':
							delete currPiece;
							currPiece = nullptr;
							delete nextPiece;
							nextPiece = nullptr;
							return false;
						case ' ':
						{
							spaceBreak = true;
							break;
						}
						case ARROW_LEFT:
						{
							//if the piece is Crazy, then go the opposite direction
							if (currPiece->getID() == 'C') {
								shiftRight(currPiece, x, y);
							}
							else {
								shiftLeft(currPiece, x, y);
							}
							break;
						}
						case ARROW_UP:
						{
							pieceRotate(currPiece, x, y);
							break;
						}
						case ARROW_RIGHT:
						{
							if (currPiece->getID() == 'C') {
								shiftLeft(currPiece, x, y);
							}
							else {
								shiftRight(currPiece, x, y);
							}
							break;
						}
						case ARROW_DOWN:
						{
							//basically just jumps out of current time to the next iteration of the loop
							nextIter = true;
							t.start();
							break;
						}
						default:
						{
							//do nothing--just wait for piece to move down on its own
						}
					}
				}
				//this completely jumps out of the movetime thing so the piece is automatically placed at the bottom
				if (spaceBreak) {
					break;
				}
				//for down arrow to skip the movetime elapsing
				if (nextIter) {
					nextIter = false;
					break;
				}
			}
			
			//no more commands carried out after the time's up
			discardPendingKeys();
			
			//if valid, remove the current piece from the well (because new piece will show up at the beginning of next loop iteration)
			currPiece->clearBlock(x, y);

			//remove the cleared block from the display
			m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
			
			//if the next iteration will not occur, re-make the current piece becase the piece is in resting position
			if ((currPiece->conflict(x, y + 1))) {
				currPiece->makeBlock(x, y);
			}
			//increment y because the object is shifting downward
			y++;
		}
		
		//execute the special piece moves
		currPiece->specialMove(currPiece->getBaseY() + 1, currPiece->getBaseX() + 1, currPiece->getBaseY() - 1, currPiece->getBaseY() + 3, currPiece->getBaseX() - 1, currPiece->getBaseX() + 3);
		currPiece->specialMove();

		//once the piece has settled, imprint it into the background of the well
		m_well.imprint();

		//clear any completed rows
		rowsCleared = m_well.clearRows();

		//display the board one more time with the new piece
		m_well.display(m_screen, WELL_X, WELL_Y);

		//the next piece is now the current piece--DON'T FORGET TO RELEASE THE ALLOCATED MEMORY FROM CALLING pickPiece()
		delete currPiece;
		currPiece = nextPiece;

		//reset the values for the next piece
		x = 3;
		y = 0;
		
		//update stats
		m_rLeft -= rowsCleared;
		if (rowsCleared > 0) {
			m_score += (100 * (2 ^ ((rowsCleared)-1)));
		}

		//release memory from currPiece if the level's done
		if (m_rLeft <= 0) {
			m_rLeft = 0;
			delete currPiece;
			currPiece = nullptr;
		}
	}
	//print the updated stats
	displayStatus();
	return true;
}

void Game::shiftLeft(Piece* currPiece, int& x, int& y) {
	currPiece->clearBlock(x, y);
	m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
	if (!(currPiece->conflict(x - 1, y))) {
		x--;
	}
	currPiece->makeBlock(x, y);
	m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
}

void Game::shiftRight(Piece* currPiece, int& x, int& y) {
	currPiece->clearBlock(x, y);
	m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
	if (!(currPiece->conflict(x + 1, y))) {
		x++;
	}
	currPiece->makeBlock(x, y);
	m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
}

void Game::pieceRotate(Piece* currPiece, int& x, int& y) {
	currPiece->clearBlock(x, y);
	currPiece->rotatePiece();
	currPiece->makeBlock(x, y);
	m_well.dispPiece(m_screen, currPiece->getBaseX(), currPiece->getBaseY());
}

Piece* Game::pickPiece(Well& m_well) {
	Piece* piece = nullptr;
	switch (chooseRandomPieceType()) {
	case PIECE_I:
	{
		piece = new Piece_I(m_well);
		break;
	}
	case PieceType::PIECE_L:
	{
		piece = new Piece_L(m_well);
		break;
	}
	case PieceType::PIECE_J:
	{
		piece = new Piece_J(m_well);
		break;
	}
	case PieceType::PIECE_T:
	{
		piece = new Piece_T(m_well);
		break;
	}
	case PieceType::PIECE_O:
	{
		piece = new Piece_O(m_well);
		break;
	}
	case PieceType::PIECE_S:
	{
		piece = new Piece_S(m_well);
		break;
	}
	case PieceType::PIECE_Z:
	{
		piece = new Piece_Z(m_well);
		break;
	}
	case PieceType::PIECE_VAPOR:
	{
		piece = new Piece_VAPOR(m_well);
		break;
	}
	case PieceType::PIECE_FOAM:
	{
		piece = new Piece_FOAM(m_well);
		break;
	}
	case PieceType::PIECE_CRAZY:
	{
		piece = new Piece_CRAZY(m_well);
		break;
	}
	default:
	{
		piece = new Piece_I(m_well);
		break;
	}
	}
	return piece;
}