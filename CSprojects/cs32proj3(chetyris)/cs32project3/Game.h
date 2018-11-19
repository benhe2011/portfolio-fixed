#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>
// [Add other #include directives as necessary.]

class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
	void pieceRotate(Piece* currPiece, int& x, int& y);
	void shiftRight(Piece* currPiece, int& x, int& y);
	void shiftLeft(Piece* currPiece, int& x, int& y);
	Piece* pickPiece(Well& well);
    // [Add other members as necessary.]

  private:
    Well    m_well;
    Screen  m_screen;
    int     m_level;
	int     m_score;
	int     m_rLeft;
	Piece*  currPiece;
	Piece*  nextPiece;
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED
