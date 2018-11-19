#include "ScoreList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	ScoreList sl;
	assert(sl.size() == 0);
	assert(sl.add(0) == true);
	assert(sl.add(10) == true);
	assert(sl.add(20) == true);
	assert(sl.add(30) == true);
	assert(sl.add(40) == true);
	assert(sl.add(50) == true);
	assert(sl.add(60) == true);
	assert(sl.add(70) == true);
	assert(sl.add(80) == true);
	assert(sl.add(90) == true);
	assert(sl.add(100) == true);
	assert(sl.add(101) == false);
	assert(sl.size() == 11);
	assert(sl.remove(50) == true);
	assert(sl.remove(70) == true);
	assert(sl.remove(55) == false);
	assert(sl.size() == 9);
	assert(sl.minimum() == 0);
	assert(sl.maximum() == 100);
	assert(sl.remove(100) == true);
	assert(sl.remove(0) == true);
	assert(sl.size() == 7);
	assert(sl.minimum() == 10);
	assert(sl.maximum() == 90);

	ScoreList sl2;
	assert(sl2.minimum() == NO_SCORE);
	assert(sl2.maximum() == NO_SCORE);

	cout << "All Tests Passed!" << endl;
}