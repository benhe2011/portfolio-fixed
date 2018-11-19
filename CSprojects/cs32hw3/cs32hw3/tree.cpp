/*
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
*/























// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then for this value of a2            the function must return
//    "stan" "kenny" "cartman"                      1
//    "stan" "cartman" "butters"                    2
//    "kenny" "stan" "cartman"                      0
//    "kyle" "cartman" "butters"                    3
int countIncludes(const string a1[], int n1, const string a2[], int n2)
{
	if (n2 == 0) {
		return 1;
	}

	if (n2 > n1) {
		return 0;
	}

	int counter = 0;

	if (a1[0] == a2[0]) {
		counter += countIncludes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
	}

	return counter + countIncludes(a1 + 1, n1 - 1, a2, n2);
}

// Exchange two strings
void exchange(string& x, string& y)
{
	string t = x;
	x = y;
	y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < separator come before all the other elements,
// and all the elements whose value is > separator come after all
// the other elements.  Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= separator, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < separator
//   * for firstNotLess <= i < firstGreater, a[i] == separator
//   * for firstGreater <= i < n, a[i] > separator
// All the elements < separator end up in no particular order.
// All the elements > separator end up in no particular order.
void separate(string a[], int n, string separator, int& firstNotLess, int& firstGreater)
{
	if (n < 0)
		n = 0;

	// It will always be the case that just before evaluating the loop
	// condition:
	//  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
	//  Every element earlier than position firstNotLess is < separator
	//  Every element from position firstNotLess to firstUnknown-1 is
	//    == separator
	//  Every element from firstUnknown to firstGreater-1 is not known yet
	//  Every element at position firstGreater or later is > separator

	firstNotLess = 0;
	firstGreater = n;
	int firstUnknown = 0;
	while (firstUnknown < firstGreater)
	{
		if (a[firstUnknown] > separator)
		{
			firstGreater--;
			exchange(a[firstUnknown], a[firstGreater]);
		}
		else
		{
			if (a[firstUnknown] < separator)
			{
				exchange(a[firstNotLess], a[firstUnknown]);
				firstNotLess++;
			}
			firstUnknown++;
		}
	}
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(string a[], int n)
{
	if (n <= 1) {
		return;
	}

	int fNL, fG;
	separate(a, n, a[n/2], fNL, fG);

	order(a, fNL);
	order(a + fG, n - fG);
}























/*
int main() {
	string test1[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
	string test2[3] = { "stan", "kenny", "cartman" };
	string test3[3] = { "stan", "cartman", "butters" };
	string test4[3] = { "kenny", "stan", "cartman" };
	string test5[3] = { "kyle", "cartman", "butters" };
	string test6[6] = { "1", "5", "3", "2", "4", "1" };
	string test7[7] = {"5", "1", "3", "5", "2", "1", "7"};
	string test8[7] = { "5", "3", "5", "7", "2", "1", "1" };

	assert(countIncludes(test1, 7, test2, 3) == 1);
	assert(countIncludes(test1, 7, test3, 3) == 2);
	assert(countIncludes(test1, 7, test4, 3) == 0);
	assert(countIncludes(test1, 7, test5, 3) == 3);
	order(test6, 6);
	assert(test6[0] == "1" 
		&& test6[1] == "1" 
		&& test6[2] == "2" 
		&& test6[3] == "3" 
		&& test6[4] == "4" 
		&& test6[5] == "5");
	order(test1, 7);
	assert(test1[0] == "butters" 
		&& test1[1] == "cartman" 
		&& test1[2] == "cartman" 
		&& test1[3] == "kenny" 
		&& test1[4] == "kyle" 
		&& test1[5] == "kyle"
		&& test1[6] == "stan");
	order(test7, 7);
	assert(test7[0] == "1"
		&& test7[1] == "1"
		&& test7[2] == "2"
		&& test7[3] == "3"
		&& test7[4] == "5"
		&& test7[5] == "5"
		&& test7[6] == "7");
	order(test7, 7);
	assert(test7[0] == "1"
		&& test7[1] == "1"
		&& test7[2] == "2"
		&& test7[3] == "3"
		&& test7[4] == "5"
		&& test7[5] == "5"
		&& test7[6] == "7");
	order(test8, 7);
	assert(test8[0] == "1"
		&& test8[1] == "1"
		&& test8[2] == "2"
		&& test8[3] == "3"
		&& test8[4] == "5"
		&& test8[5] == "5"
		&& test8[6] == "7");

	string a[5] = { "b", "a", "d", "e", "A" };
	order(a, 5);
	for (int i = 0; i < 5; i++)
		cout << a[i] << endl;

	string b[7] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
	string c[3] = { "stan", "kenny", "cartman" };
	string d[3] = { "stan", "cartman", "butters" };
	string e[3] = { "kenny", "stan", "cartman" };
	string f[3] = { "kyle", "cartman", "butters" };
	assert(countIncludes(b, 7, c, 3) == 1);
	assert(countIncludes(b, 7, d, 3) == 2);
	assert(countIncludes(b, 7, e, 3) == 0);
	assert(countIncludes(b, 7, f, 3) == 3);

	string x[5] = { "a", "a", "a", "a", "a" };
	string y[1] = { "a" };
	assert(countIncludes(x, 5, y, 1) == 5);

	string k[5] = { "a", "b", "c", "c", "c" };
	string z[3] = { "a", "b", "c" };
	assert(countIncludes(k, 5, z, 3) == 3);

	string q[5] = { "a", "b", "c", "d", "e" };
	string r[3] = { "b", "b", "c" };
	assert(countIncludes(q, 5, q, 5) == 1);
	assert(countIncludes(q, 5, r, 3) == 0);

	string w[10] = { "a", "c", "c", "z", "a", "c", "b", "z", "a", "b" };
	string s[3] = { "a", "c", "z" };
	string g[3] = { "c", "z", "a" };
	assert(countIncludes(w, 10, s, 3) == 6);
	assert(countIncludes(w, 10, g, 3) == 7);

	cout << "tree.cpp: Tests passed" << endl;
}
*/