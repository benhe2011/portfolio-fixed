#ifndef WELL_INCLUDED
#define WELL_INCLUDED

class Screen;

const int WELL_W = 10;
const int WELL_D = 18;

class Well
{
  public:
	Well();
	void display(Screen& screen, int x, int y);
	void dispPiece(Screen& screen, int x, int y);
	void clearWell();
	int clearRows();
	char wellVal(int row, int col) const;
	void setVal(char val, int row, int col);
	void imprint();

private:
	char m_well[WELL_D + 1][WELL_W + 2];
};

#endif // WELL_INCLUDED
