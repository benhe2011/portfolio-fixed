#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

class Well;
class Screen;

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

class Piece {
public:
	Piece(Well& pwell, char id);
	virtual ~Piece() {}
	//display the piece with the top left corner of the box at specified location in the screen
	void statusBlock(Screen& screen) const;
	void makeBlock(int x, int y);
	void clearBlock(int x, int y);
	bool conflict(int x, int y) const;

	//performs whatever special action the piece has--for normal pieces nothing happens
	virtual void specialMove() {
		return;
	}

	virtual void specialMove(int sr, int sc, int minR, int maxR, int minC, int maxC) {
		return;
	}

	//rotations differ for each piece
	virtual void rotatePiece() = 0;

	//sets the shape and orientation by modifying each element
	void setBlock(
		char v00, char v10, char v20, char v30,
		char v01, char v11, char v21, char v31,
		char v02, char v12, char v22, char v32,
		char v03, char v13, char v23, char v33 
	);

	//modifying the current piece orientation
	void setOrient(int orientation);
	int getOrient() const;

	//base corner (top left) modifications
	//void setBasis(int x, int y);
	int getBaseX() const;
	int getBaseY() const;

	//get pointer to m_well
	Well* getWell() const;

	//get piece id
	char getID() const{
		return m_id;
	}

	void setID(char id) {
		m_id = id;
	}


private:
	char m_block[4][4];
	int m_orientation;
	Well* m_well;
	int m_x;
	int m_y;
	char m_id;
};

class Piece_I : public Piece {
public:
	Piece_I(Well& pwell);
	~Piece_I(){}
	virtual void rotatePiece();
};

class Piece_L : public Piece {
public:
	Piece_L(Well& pwell);
	~Piece_L() {}
	virtual void rotatePiece();
};

class Piece_J : public Piece {
public:
	Piece_J(Well& pwell);
	~Piece_J() {}
	virtual void rotatePiece();
};

class Piece_T : public Piece {
public:
	Piece_T(Well& pwell);
	~Piece_T() {}
	virtual void rotatePiece();
};

class Piece_O : public Piece {
public:
	Piece_O(Well& pwell);
	~Piece_O() {}
	virtual void rotatePiece();
};

class Piece_S : public Piece {
public:
	Piece_S(Well& pwell);
	~Piece_S() {}
	virtual void rotatePiece();
};

class Piece_Z : public Piece {
public:
	Piece_Z(Well& pwell);
	~Piece_Z() {}
	virtual void rotatePiece();
};

class Piece_VAPOR : public Piece {
public:
	Piece_VAPOR(Well& pwell);
	~Piece_VAPOR() {}
	virtual void rotatePiece();
	virtual void specialMove();
};

class Piece_FOAM : public Piece {
public:
	Piece_FOAM(Well& pwell);
	~Piece_FOAM() {}
	virtual void rotatePiece();
	virtual void specialMove(int sr, int sc, int minR, int maxR, int minC, int maxC);
};

class Piece_CRAZY : public Piece {
public:
	Piece_CRAZY(Well& pwell);
	~Piece_CRAZY() {}
	virtual void rotatePiece();
};


#endif // PIECE_INCLUDED
