/*
#include <iostream>
#include <stack>

using namespace std;

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
	stack <Coord> cs;

	Coord endPt(er, ec);

	maze[sr][sc] = ','; 
	cs.push(Coord(sr, sc));
	Coord currPt(sr, sc);

	while (!cs.empty()) {
		currPt = cs.top();
		cs.pop();
		//cout << "Popped: (" << currPt.r() << ", " << currPt.c() << ")" << endl;
		if (currPt.r() == endPt.r() && currPt.c() == endPt.c()) {
			return true;
		}

		if (maze[currPt.r() - 1][currPt.c()] == '.') {
			cs.push(Coord(currPt.r() - 1, currPt.c()));
			maze[currPt.r() - 1][currPt.c()] = ','; 
		}
		if(maze[currPt.r()][currPt.c()-1] == '.') {
			cs.push(Coord(currPt.r(), currPt.c()-1));
			maze[currPt.r()][currPt.c()-1] = ',';
		}
		if (maze[currPt.r() + 1][currPt.c()] == '.') {
			cs.push(Coord(currPt.r() + 1, currPt.c()));
			maze[currPt.r() + 1][currPt.c()] = ',';
		}
		if (maze[currPt.r()][currPt.c() + 1] == '.') {
			cs.push(Coord(currPt.r(), currPt.c() + 1));
			maze[currPt.r()][currPt.c() + 1] = ',';
		}
	}
	return false;
}



int main() {
	char maze1[10][10] = {
	{ 'X','X','X','X','X','X','X','X','X','X' },
	{ 'X','.','.','.','.','.','.','.','.','X' },
	{ 'X','X','X','X','X','.','X','.','X','X' },
	{ 'X','.','.','.','X','.','X','.','.','X' },
	{ 'X','.','X','.','.','.','X','.','.','X' },
	{ 'X','.','X','X','X','.','X','X','X','X' },
	{ 'X','X','X','.','.','.','.','X','.','X' },
	{ 'X','.','X','X','.','X','X','X','.','X' },
	{ 'X','.','.','.','.','X','.','.','.','X' },
	{ 'X','X','X','X','X','X','X','X','X','X' }
	};

	if (pathExists(maze1, 6, 5, 1, 8))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;

	char maze2[10][10] = {
	{ 'X','X','X','X','X','X','X','X','X','X' },
	{ 'X','.','.','.','.','.','.','.','.','X' },
	{ 'X','X','X','X','X','X','X','X','X','X' },
	{ 'X','.','.','.','X','.','X','.','.','X' },
	{ 'X','.','X','.','.','.','X','.','.','X' },
	{ 'X','.','X','X','X','.','X','X','X','X' },
	{ 'X','X','X','.','.','.','.','X','.','X' },
	{ 'X','.','X','X','.','X','X','X','.','X' },
	{ 'X','.','.','.','.','X','.','.','.','X' },
	{ 'X','X','X','X','X','X','X','X','X','X' }
	};

	if (pathExists(maze2, 6, 5, 1, 8))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;
}
*/