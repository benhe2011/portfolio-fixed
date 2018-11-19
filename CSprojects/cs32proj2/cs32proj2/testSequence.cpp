#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;


int main() {
	/*
	Sequence s;
	assert(s.empty() == true);
	assert(s.insert(0, 1) == true);
	assert(s.insert(1, 2) == true);
	assert(s.insert(2, 3) == true);
	assert(s.insert(3, 4) == true);
	assert(s.insert(5, 3) == false);
	assert(s.insert(2) == 1);
	assert(s.insert(2) == 1);
	assert(s.empty() == false);

	assert(s.size() == 6);
	assert(s.erase(1) == true);
	assert(s.size() == 5);
	
	int test1;
	assert(s.get(0, test1) == true && test1 == 1);
	assert(s.get(1, test1) == true && test1 == 2);
	assert(s.get(2, test1) == true && test1 == 2);
	assert(s.get(3, test1) == true && test1 == 3);
	assert(s.get(4, test1) == true && test1 == 4);
	

	assert(s.erase(0) == true);
	assert(s.erase(5) == false);
	assert(s.get(0, test1) == true && test1 == 2);
	assert(s.get(1, test1) == true && test1 == 2);
	assert(s.get(2, test1) == true && test1 == 3);
	assert(s.get(3, test1) == true && test1 == 4);

	assert(s.set(2, 10) == true);
	assert(s.get(0, test1) == true && test1 == 2);
	assert(s.get(1, test1) == true && test1 == 2);
	assert(s.get(2, test1) == true && test1 == 10);
	assert(s.get(3, test1) == true && test1 == 4);
	assert(s.size() == 4);

	assert(s.find(2) == 0);
	assert(s.find(10) == 2);
	assert(s.find(20) == -1);
	assert(s.find(-2) == -1);



	Sequence s2(s);
	int test2;
	assert(s2.get(0, test2) == true && test2 == 2);
	assert(s2.get(1, test2) == true && test2 == 2);
	assert(s2.get(2, test2) == true && test2 == 10);
	assert(s2.get(3, test2) == true && test2 == 4);
	assert(s2.size() == 4);


	assert(s2.find(2) == 0);
	assert(s2.find(10) == 2);
	assert(s2.find(20) == -1);
	assert(s2.find(-2) == -1);

	Sequence s6;
	s6.swap(s2);
	int test6;
	assert(s6.get(0, test6) == true && test6 == 2);
	assert(s6.get(1, test6) == true && test6 == 2);
	assert(s6.get(2, test6) == true && test6 == 10);
	assert(s6.get(3, test6) == true && test6 == 4);
	assert(s6.size() == 4);


	assert(s6.find(2) == 0);
	assert(s6.find(10) == 2);
	assert(s6.find(20) == -1);
	assert(s6.find(-2) == -1);

	//testing remove function
	assert(s6.remove(2) == 2);
	assert(s6.remove(10) == 1);
	assert(s6.remove(35) == 0);
	assert(s6.size() == 1);
	assert(s6.get(0, test6) == true && test6 == 4);

	Sequence s3;
	s3.insert(0, 30);
	s3.insert(1, 21);
	s3.insert(2, 63);
	s3.insert(3, 42);
	s3.insert(4, 17);
	s3.insert(5, 63);
	s3.insert(6, 17);
	s3.insert(7, 29);
	s3.insert(8, 8);
	s3.insert(9, 32);
	s3.insert(10, 17);
	s3.insert(11, 63);
	s3.insert(12, 29);

	Sequence s4;
	s4.insert(0, 63);
	s4.insert(1, 17);
	s4.insert(2, 29);
	s4.insert(3, 8);

	Sequence s5;
	s5.insert(0, 17);
	s5.insert(1, 63);
	s5.insert(2, 29);

	assert(subsequence(s3, s4) == 5);
	assert(subsequence(s3, s5) == 10);

	Sequence seq1;
	seq1.insert(0, 30);
	seq1.insert(1, 21);
	seq1.insert(2, 63);
	seq1.insert(3, 42);
	seq1.insert(4, 17);
	seq1.insert(5, 63);

	Sequence seq2;
	seq2.insert(0, 42);
	seq2.insert(1, 63);
	seq2.insert(2, 84);
	seq2.insert(3, 19);

	Sequence combSeq;
	
	interleave(seq1, seq2, combSeq);

	assert(combSeq.get(0, test2) == true && test2 == 30);
	assert(combSeq.get(1, test2) == true && test2 == 42);
	assert(combSeq.get(2, test2) == true && test2 == 21);
	assert(combSeq.get(3, test2) == true && test2 == 63);
	assert(combSeq.get(4, test2) == true && test2 == 63);
	assert(combSeq.get(5, test2) == true && test2 == 84);
	assert(combSeq.get(6, test2) == true && test2 == 42);
	assert(combSeq.get(7, test2) == true && test2 == 19);
	assert(combSeq.get(8, test2) == true && test2 == 17);
	assert(combSeq.get(9, test2) == true && test2 == 63);

	Sequence seq3;
	Sequence seq4;

	interleave(seq3, seq4, combSeq);
	assert(combSeq.empty() == true);

	//testing that aliasing will still make it work properly
	interleave(seq1, seq2, seq1);
	assert(seq1.get(0, test2) == true && test2 == 30);
	assert(seq1.get(1, test2) == true && test2 == 42);
	assert(seq1.get(2, test2) == true && test2 == 21);
	assert(seq1.get(3, test2) == true && test2 == 63);
	assert(seq1.get(4, test2) == true && test2 == 63);
	assert(seq1.get(5, test2) == true && test2 == 84);
	assert(seq1.get(6, test2) == true && test2 == 42);
	assert(seq1.get(7, test2) == true && test2 == 19);
	assert(seq1.get(8, test2) == true && test2 == 17);
	assert(seq1.get(9, test2) == true && test2 == 63);
	

	cout << "Tests passed" << endl;
	*/

	// Create Sequence and insert values
	Sequence s;
	assert(s.empty());
	assert(s.insert(0, "a"));
	assert(s.insert(1, "b"));
	assert(s.insert(2, "c"));
	assert(s.insert(3, "d"));
	assert(s.insert(4, "e"));
	assert(s.size() == 5);
	assert(!s.empty());
	cout << "139" << endl;
	// Verify that the values were inserted correctly
	string value = "";
	s.get(0, value);
	assert(value == "a");
	s.get(1, value);
	assert(value == "b");
	s.get(2, value);
	assert(value == "c");
	s.get(3, value);
	assert(value == "d");
	s.get(4, value);
	assert(value == "e");
	cout << "152" << endl;
	// Insert strings at the beginning, middle, and end of the Sequence
	// Verify size each time a string is inserted
	assert(s.insert(0, "beginning"));
	assert(s.size() == 6);
	assert(s.insert(3, "middle"));
	assert(s.size() == 7);
	assert(s.insert(7, "end"));
	assert(s.size() == 8);
	cout << "161" << endl;
	// Create different Sequence and insert different values
	// Sequence has different size than the other
	Sequence x;
	assert(x.insert(0, "f"));
	assert(x.insert(1, "h"));
	assert(x.insert(2, "j"));
	assert(x.insert(3, "l"));
	assert(x.insert(4, "n"));
	assert(x.insert(5, "p"));
	assert(x.size() == 6);
	cout << "172" << endl;
	// Swap Sequences and verify sizes were swapped
	s.swap(x);
	assert(s.size() == 6);
	assert(x.size() == 8);
	s.swap(x);
	assert(s.size() == 8);
	assert(x.size() == 6);
	cout << "180" << endl;
	assert(x.insert("g") == 1);
	assert(x.insert("i") == 3);
	assert(x.insert("k") == 5);
	assert(x.insert("m") == 7);
	assert(x.size() == 10);
	cout << "186" << endl;
	assert(s.erase(0));
	assert(s.erase(2));
	assert(s.erase(5));
	assert(s.size() == 5);
	cout << "191" << endl;
	assert(x.set(4, "i"));
	assert(x.set(5, "i"));
	assert(x.size() == 10);
	cout << "195" << endl;
	assert(x.remove("i") == 3);
	assert(x.size() == 7);
	cout << "198" << endl;
	assert(s.find("c") == 2);
	assert(s.find("a") == 0);
	assert(s.find("x") == -1);
	assert(s.find("e") == 4);
	cout << "203" << endl;
	Sequence p(s);

	// Print to confirm copy of sequence s
	p.get(0, value);
	cout << value << endl;
	p.get(1, value);
	cout << value << endl;
	p.get(2, value);
	cout << value << endl;
	p.get(3, value);
	cout << value << endl;
	p.get(4, value);
	cout << value << endl;
	p.get(5, value);
	cout << value << endl;
	p.get(6, value);
	cout << value << endl;
	p.get(7, value);
	cout << value << endl;
	cout << "223" << endl;
	cout << "-----------" << endl;

	// Print to confirm sequence s
	s.get(0, value);
	cout << value << endl;
	s.get(1, value);
	cout << value << endl;
	s.get(2, value);
	cout << value << endl;
	s.get(3, value);
	cout << value << endl;
	s.get(4, value);
	cout << value << endl;
	s.get(5, value);
	cout << value << endl;
	s.get(6, value);
	cout << value << endl;
	s.get(7, value);
	cout << value << endl;
	cout << "243" << endl;
	cout << "-----------" << endl;

	// Print to confirm sequence x
	x.get(0, value);
	cout << value << endl;
	x.get(1, value);
	cout << value << endl;
	x.get(2, value);
	cout << value << endl;
	x.get(3, value);
	cout << value << endl;
	x.get(4, value);
	cout << value << endl;
	x.get(5, value);
	cout << value << endl;
	x.get(6, value);
	cout << value << endl;
	x.get(7, value);
	cout << value << endl;
	x.get(8, value);
	cout << value << endl;
	x.get(9, value);
	cout << value << endl;

	cout << "-----------" << endl;

	Sequence a;
	a.insert(0, "a");
	a.insert(1, "c");
	a.insert(2, "e");

	Sequence b;
	b.insert(0, "b");
	b.insert(1, "d");
	b.insert(2, "f");

	Sequence c;

	interleave(a, b, c);
	interleave(a, b, a);

	// Print to confirm sequence a
	a.get(0, value);
	cout << value << endl;
	a.get(1, value);
	cout << value << endl;
	a.get(2, value);
	cout << value << endl;

	// Print to confirm sequence b
	b.get(0, value);
	cout << value << endl;
	b.get(1, value);
	cout << value << endl;
	b.get(2, value);
	cout << value << endl;

	cout << "-----------" << endl;

	// Print to confirm sequence c
	c.get(0, value);
	cout << value << endl;
	c.get(1, value);
	cout << value << endl;
	c.get(2, value);
	cout << value << endl;
	c.get(3, value);
	cout << value << endl;
	c.get(4, value);
	cout << value << endl;
	c.get(5, value);
	cout << value << endl;

	cout << "-----------" << endl;

	Sequence u;
	u.insert(0, "1");
	u.insert(1, "3");
	u.insert(2, "5");
	u.insert(3, "7");
	u.insert(4, "8");
	u.insert(5, "9");

	Sequence v;
	v.insert(0, "2");
	v.insert(1, "4");
	v.insert(2, "6");

	Sequence w;

	interleave(u, v, w);

	// Print to confirm sequence w
	w.get(0, value);
	cout << value << endl;
	w.get(1, value);
	cout << value << endl;
	w.get(2, value);
	cout << value << endl;
	w.get(3, value);
	cout << value << endl;
	w.get(4, value);
	cout << value << endl;
	w.get(5, value);
	cout << value << endl;
	w.get(6, value);
	cout << value << endl;
	w.get(7, value);
	cout << value << endl;
	w.get(8, value);
	cout << value << endl;

	cout << "-----------" << endl;

	Sequence seq1;
	seq1.insert(0, "13");
	seq1.insert(1, "2");
	seq1.insert(2, "13");
	seq1.insert(3, "4");
	seq1.insert(4, "1");
	seq1.insert(5, "8");

	Sequence seq2;
	seq2.insert(0, "13");
	seq2.insert(1, "4");
	seq2.insert(2, "1");

	Sequence seq3;
	seq3.insert(0, "5");
	seq3.insert(1, "4");
	seq3.insert(2, "1");

	assert(subsequence(seq1, seq2) == 2);
	assert(subsequence(seq1, seq2) != 0);
	assert(subsequence(seq1, seq3) == -1);

	cout << "Passed all tests!" << endl;
	
}
