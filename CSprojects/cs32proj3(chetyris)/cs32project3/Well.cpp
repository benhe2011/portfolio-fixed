#include "Well.h"
#include "UserInterface.h"

Well::Well() {
	char temp[WELL_D + 1][WELL_W + 2] = {
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' }, 
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@' },
	{ '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@' },
	};

	for (int row = 0; row < (WELL_D + 1); row++) {
		for (int col = 0; col < (WELL_W + 2); col++) {
			m_well[row][col] = temp[row][col];
		}
	}
}

void Well::display(Screen& screen, int x, int y)
{
	for (int row = y; row < y + (WELL_D + 1); row++) {
		for (int col = x; col < x + (WELL_W + 2); col++) {
			screen.gotoXY(col, row);
			screen.printChar(m_well[row - y][col - x]);
		}
	}
	screen.gotoXY(WELL_W + 2, WELL_D);
}

//displays only the bounding block of the current piece based on the location of the basis
//this was made because the display function is too slow at immediately displaying the piece
void Well::dispPiece(Screen& screen, int x, int y) {
	for (int row = y; row < y + 4; row++) {
		for (int col = x; col < x + 4; col++) {
			if (row >= 0 && col >= 0 && (row - y) >= 0 && (col - x) >= 0 && row < (WELL_D + 1) && col < (WELL_W + 2) && m_well[row][col] != '@' && m_well[row][col] != '$' && m_well[row][col] != '*') {
				screen.gotoXY(col, row);
				screen.printChar(m_well[row][col]);
			}
		}
	}
	screen.gotoXY(WELL_W + 2, WELL_D);
}

void Well::clearWell() {
	for (int row = 0; row < WELL_D; row++) {
		for (int col = 1; col < (WELL_W + 1); col++) {
			m_well[row][col] = ' ';
		}
	}
}

//deletes all completed rows of characters and returns the number of rows that were deleted
int Well::clearRows() {
	bool isComplete = true;
	int cleared = 0;
	int finRow = WELL_D - 1;
	for (int row = 0; row < WELL_D; row++) {
		isComplete = true;
		for (int col = 1; col < WELL_W + 1; col++) {
			if (m_well[row][col] != '$' && m_well[row][col] != '*') {
				isComplete = false;
			}
			finRow = row;
		}
		if (isComplete) {
			cleared++;
			//shift everything down
			for (int r = finRow; r > 0; r--) {
				for (int c = 1; c < WELL_W + 1; c++) {
					m_well[r][c] = m_well[r - 1][c];
				}
			}
			//fill the top row with ' ' characters
			for (int c = 1; c < WELL_W + 1; c++) {
				m_well[0][c] = ' ';
			}
			row = 0;
		}
	}
	return cleared;
}

char Well::wellVal(int row, int col) const{
	return m_well[row][col];
}

void Well::setVal(char val, int row, int col) {
	m_well[row][col] = val;
}

//when a piece reaches its resting spot, convert the characters to dollar signs and the piece should become part of the background
void Well::imprint() {
	for (int row = 0; row < (WELL_D + 1); row++) {
		for (int col = 0; col < (WELL_W + 2); col++) {
			if (m_well[row][col] == '#') {
				m_well[row][col] = '$';
			}
		}
	}
}
