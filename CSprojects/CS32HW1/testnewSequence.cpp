#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	/*
	Sequence s;
	assert(s.empty());
	assert(s.find(42) == -1);
	assert(s.insert(42) == 0);
	assert(s.size() == 1 && s.find(42) == 0);
	


	assert(s.empty());
	assert(s.find("laobing") == -1);
	assert(s.insert("laobing") == 0);
	assert(s.size() == 1 && s.find("laobing") == 0);

	Sequence s3;
	s3.insert(0, "a");
	s3.insert(1, "b");
	s3.insert(2, "c");
	s3.insert(3, "b");
	s3.insert(4, "e");
	assert(s3.remove("b") == 2);
	assert(s3.size() == 3);
	string x;
	assert(s3.get(0, x) && x == "a");
	assert(s3.get(1, x) && x == "c");
	assert(s3.get(2, x) && x == "e");

	Sequence s1;
	s1.insert(0, "paratha");
	s1.insert(0, "focaccia");
	Sequence s2;
	s2.insert(0, "roti");
	s1.swap(s2);
	assert(s1.size() == 1 && s1.find("roti") == 0 && s2.size() == 2 &&
		s2.find("focaccia") == 0 && s2.find("paratha") == 1);

	Sequence s4;
	s4.insert(0, "dosa");
	s4.insert(1, "pita");
	s4.insert(2, "");
	s4.insert(3, "matzo");
	assert(s4.find("") == 2);
	s4.remove("dosa");
	assert(s4.size() == 3 && s4.find("pita") == 0 && s4.find("") == 1 &&
		s4.find("matzo") == 2);


	cout << "Tests passed!" << endl;
	*/

	Sequence a(1000);   // a can hold at most 1000 items
	Sequence b(5);      // b can hold at most 5 items
	Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
	ItemType v = 12;

	// No failures inserting 5 items into b
	for (int k = 0; k < 5; k++)
		assert(b.insert(v) != -1);

	// Failure if we try to insert a sixth item into b
	assert(b.insert(v) == -1);

	// When two Sequences' contents are swapped, their capacities are
	// swapped as well:
	a.swap(b);
	assert(a.insert(v) == -1 && b.insert(v) != -1);

}