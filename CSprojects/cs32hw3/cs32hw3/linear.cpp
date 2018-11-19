/*
#include <string>
#include <cassert>
#include <iostream>
using namespace std;


//dummy predicate function
bool somePredicate(string d) {
	return d.empty();
}
*/
































// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
	if (n == 0) {
		return true;
	}
	return somePredicate(a[0]) && allTrue(a + 1, n - 1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
	if (n == 0) {
		return 0;
	}
	int count = 0;
	
	if (!somePredicate(a[0])) {
		count++;
	}
	int rest = countFalse(a + 1, n - 1);
	return count + rest;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
	if (n == 0) {
		return -1;
	}
	
	if (!somePredicate(a[0])) {
		return 0;
	}

	int restFirst = firstFalse(a + 1, n - 1);
	
	if (restFirst != -1) {
		return restFirst + 1;
	}
	else {
		return -1;
	}
}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int n)
{
	if (n == 0) {
		return -1;
	}

	if (n == 1) {
		return 0;
	}

	int mid = n / 2;
	int fLeast = indexOfLeast(a, mid);
	int rLeast = indexOfLeast(a + mid, n - mid);

	if (a[fLeast] <= a[rLeast + mid]) {
		return fLeast;
	}
	else {
		return rLeast + mid;
	}
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2)
{
	if (n2 == 0) {
		return true;
	}
	
	if (n2 > n1) {
		return false;
	}

	bool doesInc;
		
	if (a1[0] == a2[0]) {
		doesInc = includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
	}
	else {
		doesInc = includes(a1 + 1, n1 - 1, a2, n2);
	}


	return doesInc;
}








































/*
int main() {
	string test1[3] = {"", "", ""};
	string test2[3] = {"1", "", ""};
	string test3[3] = {"", "", " "};
	string test4[5] = {"", "23", "", "", "wer"};
	string test5[10] = {"12", "", "", "32", "", "", "ds" , "" , "afds" , ""};
	string test6[10] = { "", "", "", "", "", "", "" , "" , "afds" , "" };
	string test7[10] = { "", "", "", "", "q", "", "" , "" , "xwe" , "" };
	
	assert(allTrue(test1, 3));
	assert(!allTrue(test2, 3));
	assert(!allTrue(test3, 3));
	assert(!allTrue(test4, 5));
	assert(!allTrue(test5, 10));
	assert(!allTrue(test6, 10));
	assert(allTrue(test6, 8));
	assert(!allTrue(test7, 10));

	assert(countFalse(test1, 3) == 0);
	assert(countFalse(test2, 3) == 1);
	assert(countFalse(test3, 3) == 1);
	assert(countFalse(test4, 5) == 2);
	assert(countFalse(test5, 10) == 4);
	assert(countFalse(test6, 10) == 1);
	assert(countFalse(test7, 10) == 2);

	assert(firstFalse(test1, 3) == -1);
	assert(firstFalse(test2, 3) == 0);
	assert(firstFalse(test3, 3) == 2);
	assert(firstFalse(test4, 5) == 1);
	assert(firstFalse(test5, 10) == 0);
	assert(firstFalse(test5 + 1, 9) == 2);
	assert(firstFalse(test6, 10) == 8);
	assert(firstFalse(test7, 10) == 4);

	assert(indexOfLeast(test1, 3) == 0);
	assert(indexOfLeast(test1, 0) == -1);
	assert(indexOfLeast(test2, 3) == 1);
	assert(indexOfLeast(test3, 3) == 0);
	assert(indexOfLeast(test4, 5) == 0);
	assert(indexOfLeast(test5, 10) == 1);
	assert(indexOfLeast(test5 + 4, 6) == 0);
	assert(indexOfLeast(test6, 3) == 0);

	string a1[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
	string a2[3] = {"kyle", "kenny", "butters"};
	string a3[3] = {"kyle", "cartman", "cartman"};
	string a4[3] = {"kyle", "butters", "kenny"};
	string a5[3] = {"stan", "kenny", "kenny"};

	assert(indexOfLeast(a1, 7) == 6);
	assert(indexOfLeast(a2, 3) == 2);
	assert(indexOfLeast(a3, 3) == 1);
	assert(indexOfLeast(a4, 3) == 1);
	assert(indexOfLeast(a5, 3) == 1);

	assert(includes(a1, 7, a2, 3));
	assert(includes(a1, 7, a3, 3));
	assert(!includes(a1, 7, a4, 3));
	assert(!includes(a1, 7, a5, 3));
	
	

	// allTrue(const string a[], int n)
	//string a1[0];
	string a2[1] = { "" };
	string a3[1] = { "a" };
	string a4[2] = { "", "" };
	string a5[2] = { "", "a" };
	string a6[3] = { "", "", "" };
	string a7[3] = { "", "a", "" };
	string a8[3] = { "a", "a", "a" };
	//assert(allTrue(a1, 0));
	assert(allTrue(a2, 1));
	assert(!allTrue(a3, 1));
	assert(allTrue(a4, 2));
	assert(!allTrue(a5, 2));
	assert(allTrue(a6, 3));
	assert(!allTrue(a7, 3));
	assert(!allTrue(a8, 3));

	// countFalse(const string a[], int n)
	//string b1[0];
	string b2[1] = { "r" };
	string b3[1] = { "" };
	string b4[2] = { "", "", };
	string b5[2] = { "r", "r" };
	string b6[2] = { "", "" };
	string b7[3] = { "", "", "" };
	string b8[3] = { "r", "", "r" };
	//assert(countFalse(b1, 0) == 0);
	assert(countFalse(b2, 1) == 1);
	assert(countFalse(b3, 1) == 0);
	assert(countFalse(b4, 2) == 0);
	assert(countFalse(b5, 2) == 2);
	assert(countFalse(b6, 2) == 0);
	assert(countFalse(b7, 3) == 0);
	assert(countFalse(b8, 3) == 2);

	// firstFalse(const string a[], int n)
	//string c1[0];
	string c2[1] = { "a" };
	string c3[1] = { "" };
	string c4[2] = { "", "" };
	string c5[2] = { "", "a" };
	string c6[2] = { "a", "" };
	string c7[3] = { "", "", "" };
	string c8[3] = { "", "b", "" };
	string c9[3] = { " ", "b", "" };
	//assert(firstFalse(c1, 0) == -1);
	assert(firstFalse(c2, 1) == 0);
	assert(firstFalse(c3, 1) == -1);
	assert(firstFalse(c4, 2) == -1);
	assert(firstFalse(c5, 2) == 1);
	assert(firstFalse(c6, 2) == 0);
	assert(firstFalse(c7, 3) == -1);
	assert(firstFalse(c8, 3) == 1);
	assert(firstFalse(c9, 3) == 0);

	// indexOfLeast(const string a[], int n)
	//string d1[0];
	string d2[1] = { "x" };
	string d3[1] = { "" };
	string d4[2] = { "x", "a" };
	string d5[2] = { "a", "c" };
	string d6[3] = { "x", "a", "c" };
	string d7[3] = { "x", "a", "A" };
	string d8[4] = { "x", "a", "c", "b" };
	//assert(indexOfLeast(d1, 0) == -1);
	assert(indexOfLeast(d2, 1) == 0);
	assert(indexOfLeast(d3, 1) == 0);
	assert(indexOfLeast(d4, 2) == 1);
	assert(indexOfLeast(d5, 2) == 0);
	assert(indexOfLeast(d6, 3) == 1);
	assert(indexOfLeast(d7, 3) == 2);
	assert(indexOfLeast(d8, 4) == 1);

	// includes(const string a1[], int n1, const string a2[], int n2)
	string e[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
	string f[3] = { "kyle", "kenny", "butters" };
	string g[3] = { "kyle", "cartman", "cartman" };
	string h[3] = { "kyle", "butters", "kenny" };
	string j[3] = { "stan", "kenny", "kenny" };
	assert(includes(e, 7, f, 3));
	assert(includes(e, 7, g, 3));
	assert(includes(e, 7, e, 3));
	assert(!includes(e, 7, h, 3));
	assert(!includes(e, 7, j, 3));

	cout << "linear.cpp: Tests passed" << endl;
}
*/