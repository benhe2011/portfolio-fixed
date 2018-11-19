/*
#include <iostream>
using namespace std;
*/
































bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
	if (sr == er && sc == ec) {
		return true;
	}
	maze[sr][sc] = ',';

	bool dirN = false, dirE = false, dirS = false, dirW = false;

	if (maze[sr - 1][sc] == '.') {
		dirN = pathExists(maze, sr - 1, sc, er, ec);
	}
	if (maze[sr][sc + 1] == '.') {
		dirE = pathExists(maze, sr, sc + 1, er, ec);
	}
	if (maze[sr + 1][sc] == '.') {
		dirS = pathExists(maze, sr + 1, sc, er, ec);
	}
	if (maze[sr][sc - 1] == '.') {
		dirW = pathExists(maze, sr, sc - 1, er, ec);
	}
	
	if (dirN || dirE || dirS || dirW) {
		return true;
	}
	else {
		return false;
	}
}

























/*
int main()
{
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