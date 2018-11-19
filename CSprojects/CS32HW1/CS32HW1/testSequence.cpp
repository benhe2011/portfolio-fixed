/*

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	Sequence s;
	/*
	assert(s.empty());
	assert(s.find(42) == -1);
	assert(s.insert(42) == 0);
	assert(s.size() == 1 && s.find(42) == 0);
	*/

	/*
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

	Sequence s5;
	s5.insert(0, "a");
	s5.insert(1, "b");
	s5.insert(2, "c");
	s5.insert(3, "b");
	s5.insert(4, "e");
	s5.insert(2, "f");
	assert(s5.get(2, x) && x == "f");
	assert(s5.get(3, x) && x == "c");
	assert(s5.remove("b") == 2);
	assert(s5.size() == 4);
	assert(s5.get(0, x) && x == "a");
	assert(s5.get(1, x) && x == "f");
	assert(s5.get(3, x) && x == "e");


	cout << "Tests passed!" << endl;
	//should put end comment here
	
	Sequence s3;
	s3.insert(0, 1);
	s3.insert(1, 2);
	s3.insert(2, 3);
	s3.insert(3, 2);
	s3.insert(4, 4);
	assert(s3.remove(2) == 2);
	assert(s3.size() == 3);
	unsigned long x;
	assert(s3.get(0, x) && x == 1);
	assert(s3.get(1, x) && x == 3);
	assert(s3.get(2, x) && x == 4);

	Sequence s1;
	s1.insert(0, 1234);
	s1.insert(0, 5678);
	Sequence s2;
	s2.insert(0, 910);
	s1.swap(s2);
	assert(s1.size() == 1 && s1.find(910) == 0 && s2.size() == 2 &&
		s2.find(5678) == 0 && s2.find(1234) == 1);

	Sequence s4;
	s4.insert(0, 1112);
	s4.insert(1, 1314);
	s4.insert(2, 0);
	s4.insert(3, 1516);
	assert(s4.find(0) == 2);
	s4.remove(1112);
	assert(s4.size() == 3 && s4.find(1314) == 0 && s4.find(0) == 1 &&
		s4.find(1516) == 2);

	Sequence s5;
	s5.insert(0, 1);
	s5.insert(1, 2);
	s5.insert(2, 3);
	s5.insert(3, 2);
	s5.insert(4, 4);
	s5.insert(2, 5);
	assert(s5.get(2, x) && x == 5);
	assert(s5.get(3, x) && x == 3);
	assert(s5.remove(2) == 2);
	assert(s5.size() == 4);
	assert(s5.get(0, x) && x == 1);
	assert(s5.get(1, x) && x == 5);
	assert(s5.get(3, x) && x == 4);


	cout << "Tests passed!" << endl;

}
*/

/*
#include "Sequence.h"
#include <string>
#include <iostream>
#include <cassert>
	using namespace std;

	void test()
	{
		Sequence s;
		assert(s.insert(0, "lavash"));
		assert(s.insert(0, "tortilla"));
		assert(s.size() == 2);
		ItemType x = "injera";
		assert(s.get(0, x) && x == "tortilla");
		assert(s.get(1, x) && x == "lavash");
	}

	int main()
	{
		test();
		cout << "Passed all tests" << endl;
	}

	*/

