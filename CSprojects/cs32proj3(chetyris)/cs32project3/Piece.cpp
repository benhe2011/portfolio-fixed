#include "Piece.h"
#include "Well.h"
#include "UserInterface.h"

Piece::Piece(Well& pwell, char id) {
	m_well = &pwell;
	m_orientation = 0;
	m_x = 0;
	m_y = 0;
	m_id = id;
}

void Piece::statusBlock(Screen& screen) const {
	
	for (int row = 4; row < 8; row++) {
		screen.gotoXY(16, row);
		screen.printStringClearLine("");
		for (int col = 16; col < 20; col++) {
			screen.gotoXY(col, row);
			screen.printChar(m_block[row - 4][col - 16]);
		}
	}
}

void Piece::makeBlock(int x, int y) {
	m_x = x;
	m_y = y;
	for (int row = y; row < y + 4; row++) {
		for (int col = x; col < x + 4; col++) {
			if (row >= 0 && col >= 0 && row < (WELL_D + 1) && (row - y) >= 0 && col < (WELL_W + 2) && (col - x) >= 0 && m_block[row - y][col - x] != ' ' && m_well->wellVal(row, col) != '@') {
				m_well->setVal(m_block[row - y][col - x], row, col);
			}
		}
	}
}

void Piece::clearBlock(int x, int y) {
	for (int row = y; row < y + 4; row++) {
		for (int col = x; col < x + 4; col++) {
			if (row >= 0 && col >= 0 && row < (WELL_D + 1) && (row - y) >= 0 && col < (WELL_W + 2) && (col - x) >= 0 && m_well->wellVal(row, col) == '#') {
				m_well->setVal(' ', row, col);
			}
		}
	}
}

bool Piece::conflict(int x, int y) const {
	bool isCon = false;
	for (int row = y; row < y + 4; row++) {
		for (int col = x; col < x + 4; col++) {
			if (row >= 0 && col >= 0 && row < (WELL_D + 1) && (row - y) >= 0 && col < (WELL_W + 2) && (col - x) >= 0 && m_block[row - y][col - x] != ' ' && m_well->wellVal(row, col) != ' ') {
				isCon = true;
				break;
			}
		}
		if (isCon) {
			break;
		}
	}
	return isCon;
}

void Piece::setBlock(
	char v00, char v10, char v20, char v30,
	char v01, char v11, char v21, char v31,
	char v02, char v12, char v22, char v32,
	char v03, char v13, char v23, char v33
) {
	m_block[0][0] = v00;
	m_block[0][1] = v10;
	m_block[0][2] = v20;
	m_block[0][3] = v30;

	m_block[1][0] = v01;
	m_block[1][1] = v11;
	m_block[1][2] = v21;
	m_block[1][3] = v31;

	m_block[2][0] = v02;
	m_block[2][1] = v12;
	m_block[2][2] = v22;
	m_block[2][3] = v32;

	m_block[3][0] = v03;
	m_block[3][1] = v13;
	m_block[3][2] = v23;
	m_block[3][3] = v33;
}

int Piece::getOrient() const{
	return m_orientation;
}

void Piece::setOrient(int orientation) {
	m_orientation = orientation;
}

int Piece::getBaseX() const{
	return m_x;
}
int Piece::getBaseY() const{
	return m_y;
}

Well* Piece::getWell() const {
	return m_well;
}

//I Piece Implementation
Piece_I::Piece_I(Well& pwell)
	:Piece(pwell, 'I')
{
	setBlock(
		' ', ' ', ' ', ' ',
		'#', '#', '#', '#',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_I::rotatePiece() {
	switch (getOrient()) {
		case 0: 
		{
			setBlock(
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ');
			if (conflict(getBaseX(), getBaseY())) {
				setBlock(
					' ', ' ', ' ', ' ',
					'#', '#', '#', '#',
					' ', ' ', ' ', ' ',
					' ', ' ', ' ', ' '
				);
				break;
			}
			setOrient(1);
			break;
		}
		case 1: 
		{
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', '#', '#',
				' ', ' ', ' ', ' ',
				' ', ' ', ' ', ' ');
			if (conflict(getBaseX(), getBaseY())) {
				setBlock(
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ');
				break;
			}
			setOrient(2);
			break;
		}
		case 2:
		{
			setBlock(
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ');
			if (conflict(getBaseX(), getBaseY())) {
				setBlock(
					' ', ' ', ' ', ' ',
					'#', '#', '#', '#',
					' ', ' ', ' ', ' ',
					' ', ' ', ' ', ' '
				);
				break;
			}
			setOrient(3);
			break;
		}
		case 3:
		{
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', '#', '#',
				' ', ' ', ' ', ' ',
				' ', ' ', ' ', ' ');
			if (conflict(getBaseX(), getBaseY())) {
				setBlock(
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ',
					' ', '#', ' ', ' ');
				break;
			}
			setOrient(0);
			break;
		}	
	}
}

//L Piece Implementation
Piece_L::Piece_L(Well& pwell)
	:Piece(pwell, 'L')
{
	setBlock(
		' ', ' ', ' ', ' ',
		'#', '#', '#', ' ',
		'#', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_L::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', '#', '#', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', '#', ' ',
				'#', ' ', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', ' ', '#', ' ',
			'#', '#', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', '#', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', '#', '#', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', ' ', '#', ' ',
				'#', '#', '#', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			'#', '#', '#', ' ',
			'#', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', '#', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}

//J Piece Implementation
Piece_J::Piece_J(Well& pwell)
	:Piece(pwell, 'J')
{
	setBlock(
		' ', ' ', ' ', ' ',
		' ', '#', '#', '#',
		' ', ' ', ' ', '#',
		' ', ' ', ' ', ' '
	);
}

void Piece_J::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', '#', ' ',
			' ', '#', '#', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', '#', '#', '#',
				' ', ' ', ' ', '#',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', '#', '#', '#',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', '#', ' ',
				' ', '#', '#', ' ');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			' ', '#', '#', ' ',
			' ', '#', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', '#', '#',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', '#', '#',
			' ', ' ', ' ', '#',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', '#', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}

//T Piece Implementation
Piece_T::Piece_T(Well& pwell)
	:Piece(pwell, 'T')
{
	setBlock(
		' ', '#', ' ', ' ',
		'#', '#', '#', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_T::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', '#', ' ', ' ',
			' ', '#', '#', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', ' ', ' ',
				'#', '#', '#', ' ',
				' ', ' ', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			'#', '#', '#', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', ' ', ' ',
				' ', '#', '#', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			' ', '#', ' ', ' ',
			'#', '#', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', '#', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			' ', '#', ' ', ' ',
			'#', '#', '#', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', ' ', ' ',
				'#', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}

//O Piece Implementation
Piece_O::Piece_O(Well& pwell)
	:Piece(pwell, 'O')
{
	setBlock(
		'#', '#', ' ', ' ',
		'#', '#', ' ', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_O::rotatePiece() {
	switch (getOrient()) {
	case 0:
	case 1:
	case 2:
	case 3:
	{
		setBlock(
			'#', '#', ' ', ' ',
			'#', '#', ' ', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		setOrient(0);
		break;
	}
	}
}

//S Piece Implementation
Piece_S::Piece_S(Well& pwell)
	:Piece(pwell, 'S')
{
	setBlock(
		' ', ' ', ' ', ' ',
		' ', '#', '#', ' ',
		'#', '#', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_S::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', '#', ' ', ' ',
			' ', '#', '#', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', '#', '#', ' ',
				'#', '#', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', '#', ' ',
			'#', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', ' ', ' ',
				' ', '#', '#', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			' ', '#', ' ', ' ',
			' ', '#', '#', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', '#', '#', ' ',
				'#', '#', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', '#', ' ',
			'#', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', '#', ' ', ' ',
				' ', '#', '#', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}

//Z Piece Implementation
Piece_Z::Piece_Z(Well& pwell)
	:Piece(pwell, 'Z')
{
	setBlock(
		' ', ' ', ' ', ' ',
		'#', '#', ' ', ' ',
		' ', '#', '#', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_Z::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', ' ', '#', ' ',
			' ', '#', '#', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', ' ', ' ',
				' ', '#', '#', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			'#', '#', ' ', ' ',
			' ', '#', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', '#', ' ',
				' ', '#', '#', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			' ', ' ', '#', ' ',
			' ', '#', '#', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				'#', '#', ' ', ' ',
				' ', '#', '#', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			'#', '#', ' ', ' ',
			' ', '#', '#', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', '#', ' ',
				' ', '#', '#', ' ',
				' ', '#', ' ', ' ',
				' ', ' ', ' ', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}

//VaporBomb Implementations
Piece_VAPOR::Piece_VAPOR(Well& pwell)
	:Piece(pwell, 'V')
{
	setBlock(
		' ', '#', '#', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_VAPOR::rotatePiece() {
	switch (getOrient()) {
	case 0:
	case 1:
	case 2:
	case 3:
	{
		setBlock(
			' ', '#', '#', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		setOrient(0);
		break;
	}
	}
}

void Piece_VAPOR::specialMove() {
	for (int row = getBaseY() - 2; row <= getBaseY() + 2; row++) {
		if (row < 19 && row >= 0 && (getWell()->wellVal(row, getBaseX() + 1) != '@')) {
			getWell()->setVal(' ', row, getBaseX() + 1);
		}
			if (row < 19 && row >= 0 && (getWell()->wellVal(row, getBaseX() + 2) != '@')) {
			getWell()->setVal(' ', row, getBaseX() + 2);
		}
	}
}

//FoamBomb Implementations
Piece_FOAM::Piece_FOAM(Well& pwell)
	:Piece(pwell, 'F')
{
	setBlock(
		' ', ' ', ' ', ' ',
		' ', '#', ' ', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_FOAM::rotatePiece() {
	switch (getOrient()) {
	case 0:
	case 1:
	case 2:
	case 3:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		setOrient(0);
		break;
	}
	}
}


void Piece_FOAM::specialMove(int sr, int sc, int minR, int maxR, int minC, int maxC) {
	if (sr >= minR && sr <= maxR && sc >= minC && sc <= maxC) {
		Well* well = getWell();
		well->setVal('*', sr, sc);
		if (well->wellVal(sr - 1, sc) == ' ') {
			specialMove(sr - 1, sc, minR, maxR, minC, maxC);
		}
		if (well->wellVal(sr, sc + 1) == ' ') {
			specialMove(sr, sc + 1, minR, maxR, minC, maxC);
		}
		if (well->wellVal(sr + 1, sc) == ' ') {
			specialMove(sr + 1, sc, minR, maxR, minC, maxC);
		}
		if (well->wellVal(sr, sc - 1) == ' ') {
			specialMove(sr, sc - 1, minR, maxR, minC, maxC);
		}
	}
	else {
		return;
	}
}



//CrazyShape Implementations
Piece_CRAZY::Piece_CRAZY(Well& pwell)
	:Piece(pwell, 'C')
{
	setBlock(
		'#', ' ', ' ', '#',
		' ', '#', '#', ' ',
		' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' '
	);
}

void Piece_CRAZY::rotatePiece() {
	switch (getOrient()) {
	case 0:
	{
		setBlock(
			' ', ' ', ' ', '#',
			' ', ' ', '#', ' ',
			' ', ' ', '#', ' ',
			' ', ' ', ' ', '#');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				'#', ' ', ' ', '#',
				' ', '#', '#', ' ',
				' ', ' ', ' ', ' ',
				' ', ' ', ' ', ' '
			);
			break;
		}
		setOrient(1);
		break;
	}
	case 1:
	{
		setBlock(
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ',
			' ', '#', '#', ' ',
			'#', ' ', ' ', '#');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', '#',
				' ', ' ', '#', ' ',
				' ', ' ', '#', ' ',
				' ', ' ', ' ', '#');
			break;
		}
		setOrient(2);
		break;
	}
	case 2:
	{
		setBlock(
			'#', ' ', ' ', ' ',
			' ', '#', ' ', ' ',
			' ', '#', ' ', ' ',
			'#', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				' ', ' ', ' ', ' ',
				' ', ' ', ' ', ' ',
				' ', '#', '#', ' ',
				'#', ' ', ' ', '#'
			);
			break;
		}
		setOrient(3);
		break;
	}
	case 3:
	{
		setBlock(
			'#', ' ', ' ', '#',
			' ', '#', '#', ' ',
			' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ');
		if (conflict(getBaseX(), getBaseY())) {
			setBlock(
				'#', ' ', ' ', ' ',
				' ', '#', ' ', ' ',
				' ', '#', ' ', ' ',
				'#', ' ', ' ', ' ');
			break;
		}
		setOrient(0);
		break;
	}
	}
}