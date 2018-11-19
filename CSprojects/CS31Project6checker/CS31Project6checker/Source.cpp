#include <iostream>
#include <string>
using namespace std;

void deleteCapitals(char * p) {
	char * i = p;
	while (*p != '\0') {
		if (isupper(*p)) {
			i = p;
			while (*i != '\0') {
				*i = *(i + 1);
				i++;
			}
		}
		else {
			p++; //only move forward if there are no more 
				 //capital letters
		}

	}
}


int main()
{
	char msg[100] = "HaPPY Days Are Here Again!";
	deleteCapitals(msg);
	cout << msg << endl;        // prints:   appy ays re ere gain!
}


/*
int* minimart(int* a, int* b) //returns earliest pointer
{
	if (*a < *b)
		return a;
	else
		return b;
}

void swap1(int* a, int *b) //switch pointer addresses--does nothing because pointers are passed by value not by reference
{
	int* temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int *b) //switch int values of pointer addresses
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int array[6] = { 5, 3, 4, 17, 22, 19 };

	int* ptr = minimart(array, &array[2]); //ptr = array[2]
	ptr[1] = 9; //array changed to { 5, 3, 4, 9, 22, 19 }
	ptr += 2; //ptr = array[4]
	*ptr = -1; //array changed to { 5, 3, 4, 9, -1, 19 }
	*(array + 1) = 79; //array changed to { 5, 79, 4, 9, -1, 19 }

	cout << "diff=" << &array[5] - ptr << endl; //prints out 1

	swap1(&array[0], &array[1]); //array = { 5, 79, 4, 9, -1, 19 }
	swap2(array, &array[2]); //array changed to { 4, 79, 5, 9, -1, 19 }

	for (int i = 0; i < 6; i++)
		cout << array[i] << endl;

	return(0);
}
//should print out: 4
//                  79
//                  5
//                  9 
//                  -1 
//                  19

*/
 /*#include <iostream>
using namespace std;

int fibonacci(int n)
{
	int tmp;
	int a = 1;
	int b = 1;

	for (int i = 0; i < n - 2; i++)
	{
		tmp = a + b;
		a = b;
		b = tmp;
	}
	return b;
}

int* computeFibonacciSequence(int& n)
{
	int arr[8];//0x008ff774
	n = 8;
	for (int k = 0; k < n; k++)
	{
		arr[k] = fibonacci(k);
	}
	return arr;
}


int main()
{
	int m;
	int* ptr = computeFibonacciSequence(m);
	for (int i = 0; i < m; i++)
	{
		cout << ptr[i] << ' ';
	}
	return(0);
}

*/