#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int findMinimum(const string array[], int n);
int countAllPunctuation(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
int removeDuplicatedValues(string array[], int n);
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill);
int shiftRight(string array[], int n, int amount, string placeholder);
//extra function to help with function testing by printing out the arrays
void dispString(const string array[], int n)
{
	cerr << "[";
	for (int i = 0; i < n; i++)
	{
		cerr << array[i] << " ";
	}
	cerr << "]\n";
	
	return;
}

int main() {
	//arrays to use for testing the functions
	string testString1[20] = { "jon-", "zaro'ld", "ja.cob", "k?aleb", "zachary", "jo.,sh", "l'arry", "ma\"rcus", "0.5", "3.2.0", "8d.24", "74", "89.3", "98.078w", "0", "92.", "32..0", "z", "z", "qwe" };
	string testString2[7] = { "alex", "ben", "alex", "yuan", "hong", "alex", "yuan" };
	string testString3[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta"};
	string testString4[11] = { "0.5", "3.2.0", "8d.24", "074", "89.3", "98.078w", "0", "92.", "32..0", "z", "."};
	string testString5[6] = { "", "apple", "", "potato", "apple", ""};
	string testString6[7] = { "", "", "", "", "", "", "" };
	string testString7[8] = { "b", "c", "a", "d", "A", "D", "C", "B"};
	string testString8[8] = {"why?", "the-/", "I, ", "said:", "hey'", "yay;", "\"", "-" };
	string testString9[5] = {"samwell", "jon", "margaery", "daenerys", "tyrion"};
	string testString10[4] = {"howard-", "ucla.", "howard", "ucla"};
	string testString11[4] = {"4.4.3.3", "44", "33.098", "33.098a"};
	string testString12[4] = {"happy", "days", "happy", "days"};
	
	assert(findMinimum(testString1, 0) == -1);
	assert(findMinimum(testString9, 5) == 3);
	assert(findMinimum(testString1, 8) == 2);
	assert(findMinimum(testString7, 4) == 2);
	assert(findMinimum(testString7, 8) == 4);
	
	assert(countFloatingPointValues(testString11, 4) == 2);
	assert(countFloatingPointValues(testString11, -14) == -1);
	assert(countFloatingPointValues(testString1, 20) == 5);
	assert(countFloatingPointValues(testString4, 11) == 5);
	
	assert(countAllPunctuation(testString10, 4) == 2);
	assert(countAllPunctuation(testString10, -14) == -1);
	assert(countAllPunctuation(testString1, 8) == 8);
	assert(countAllPunctuation(testString8, 8) == 9);
	
	assert(shiftRight(testString1, 7, 3, "foo") == 3);
	assert(shiftRight(testString1, 5, 25, "foo") == 5);
	
	assert(countAllPunctuation(testString8, 8) == 9);
	
	dispString(testString3, 6);
	assert(removeDuplicatedValues(testString3, 6) == 2);
	dispString(testString3, 6);
	
	dispString(testString5, 6);
	assert(removeDuplicatedValues(testString5, 6) == 3);
	dispString(testString5, 6);
	
	dispString(testString6, 7);
	assert(removeDuplicatedValues(testString6, 7) == 6);
	dispString(testString6, 7);

	dispString(testString12, 4);
	assert(removeDuplicatedValues(testString12, 4) == 2);
	dispString(testString12, 4);

	dispString(testString9, 5);
	assert(removeDuplicatedValues(testString9, 5) == 0);
	dispString(testString9, 5);

	dispString(testString2, 7);
	assert(removeDuplicatedValues(testString2, 7) == 3);
	dispString(testString2, 7);

	cerr << "All tests passed.\n";
	// findMinimum
	string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	assert(findMinimum(people, 5) == 3);
	string p[5] = { "l", "b", "k", "s", "t" };
	assert(findMinimum(p, 5) == 1);
	string p6[5] = { "l", "b", "k", "", "t" };
	assert(findMinimum(p6, 5) == 3);
	string p1[4] = { "b", "c", "a", "d" };
	assert(findMinimum(p1, 4) == 2);
	string p10[5] = { "bad", "cat", "ant", "dad", "ant" };
	assert(findMinimum(p10, 5) == 2);
	string p2[4] = { "bEn", "mIchElLe", "KaThy", "JefFery" };
	assert(findMinimum(p2, 4) == 3);
	string p3[] = { "a", "b", "c", "A", "B", "C" };
	assert(findMinimum(p3, 6) == 3);
	assert(findMinimum(p3, -1) == -1);
	assert(findMinimum(p3, 0) == -1);

	// countAllPunctuation
	string punc[4] = { "howard-", "ucla.", "howard", "ucla" };
	assert(countAllPunctuation(punc, 4) == 2);
	assert(countAllPunctuation(punc, -14) == -1);
	string punc1[4] = { "h-ow-ard-", "uc'la.", "h.oward", "uc,la" };
	assert(countAllPunctuation(punc1, 4) == 7);
	string punc2[] = { "billy!", ".h.am.", "13.20.@,", "!24/" };
	assert(countAllPunctuation(punc2, 4) == 9);
	string punc3[] = { "12.34", "0.56", "100", "1.50", "67.5" };
	assert(countAllPunctuation(punc3, 5) == 4);
	string punc4[] = { "1!2.3-4", "wh,at,", "10:0;", "bl?ah/'", "for\"" };
	assert(countAllPunctuation(punc4, 5) == 11);
	assert(countAllPunctuation(punc4, -1) == -1);
	assert(countAllPunctuation(punc4, 0) == -1);

	// countFloatingPointValues
	string nums1[4] = { "4.4.3.3", "44", "33.098", "33.098a" };
	assert(countFloatingPointValues(nums1, 4) == 2);
	assert(countFloatingPointValues(nums1, -14) == -1);
	string nums2[4] = { "1.0", "1", ".0101", "0.0123" };
	assert(countFloatingPointValues(nums2, 4) == 4);
	string nums3[] = { "40.5", "abs.5t", "4.5", "0.20.21", "10", "60.1a", "ar.er" };
	assert(countFloatingPointValues(nums3, 7) == 3);
	string nums4[] = { "4.", "4.5", "0.21", ".10" };
	assert(countFloatingPointValues(nums4, 4) == 4);
	string nums5[] = { ".a", "ab.", ".cd", "a.b" };
	assert(countFloatingPointValues(nums5, 4) == 0);
	assert(countFloatingPointValues(nums5, -1) == -1);
	assert(countFloatingPointValues(nums5, 0) == -1);
	string nums6[] = { "1.1", ".", "0.", ".9" };
	assert(countFloatingPointValues(nums6, 4) == 3);
	string nums7[] = { " 1.1", ".", "0.", " .9", "", "abc" };
	assert(countFloatingPointValues(nums7, 5) == 1);
	//cout << countFloatingPointValues(nums7, 5);

	// removeDuplicateValues
	string dup3[9] = { "will", "will", "you", "be", "you", "my", "valentine", "?", "my" };
	assert(removeDuplicatedValues(dup3, 9) == 3);
	string dup[4] = { "happy", "days", "happy", "days" };
	assert(removeDuplicatedValues(people, -5) == -1);
	assert(removeDuplicatedValues(dup, 4) == 2);
	string dup1[4] = { "happy", "happy", "days", "days" };
	assert(removeDuplicatedValues(dup1, 4) == 2);
	string dup2[8] = { "hi", "kathy", "whats", "kathy", "kathy", "up", "whats", "hi" };
	assert(removeDuplicatedValues(dup2, 8) == 4);
	string dup4[10] = { "does", "this", "does", "function", "does", "does", "really", "work", "function", "?" };
	assert(removeDuplicatedValues(dup4, 10) == 4);
	string dup5[11] = { "0.5", "3.2.0", "8d.24", "074", "89.3", "98.078w", "0", "92.", "z", "." };
	assert(removeDuplicatedValues(dup5, 11) == 0);
	string dup6[11] = { "0.5", "3.2.0", "0.5", "074", "89.3", "98.078w", "0.5", "92.", "z", "074" };
	assert(removeDuplicatedValues(dup6, 11) == 3);
	string dup7[9] = { "i", "want", "i", "want", "to", "eat", "to", "at", "bplate" };
	assert(removeDuplicatedValues(dup7, 9) == 3);
	string dup8[9] = { "i", "want", "i", "want", "to", "eat", "to", "at", "bplate" };
	string dup9[3] = { "puppy", "", "apple" };
	assert(removeDuplicatedValues(dup8, 3) == 1);
	assert(removeDuplicatedValues(dup9, 3) == 0);
	assert(removeDuplicatedValues(people, 0) == -1);
	string dup10[5] = { "puppy", "", "puppy", "apple", "" };
	assert(removeDuplicatedValues(dup10, 5) == 2);
	string dup11[6] = { "puppy", "", "apple", "", "puppy", "" };
	assert(removeDuplicatedValues(dup11, 6) == 3);
	string dup12[6] = { "", "", "", "", "", "" };
	assert(removeDuplicatedValues(dup12, 6) == 5);
	string dup13[5] = { "a", "a", "", "a", "a" };
	assert(removeDuplicatedValues(dup13, 5) == 3);
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
	assert(removeDuplicatedValues(a, 4) == 1);

	for (int i = 0; i < 6; i++) {
		cerr << a[i] << endl;
	}

	// replaceAll
	assert(replaceAll(people, 5, 'z', 'a') == 0);
	assert(replaceAll(people, -5, 'z', 'a') == -1);
	assert(replaceAll(people, 0, 'z', 'a') == -1);
	string replace[4] = { "happy", "days", "are here", "again" };
	assert(replaceAll(replace, 4, 'a', 'z') == 5);
	string r4[6] = { "does", "this", "function", "really", "work", "?" };
	assert(replaceAll(r4, 6, 'o', 'O') == 3);
	string r5[] = { "aaA", "aA", "BaaA", "Aaos" };
	assert(replaceAll(r5, 4, 'a', 'y') == 6);
	assert(replaceAll(r5, 4, 'A', 'S') == 4);

	// shiftRight
	assert(shiftRight(people, 5, 3, "foo") == 3);
	assert(shiftRight(people, -5, 3, "foo") == -1);
	assert(shiftRight(people, 5, 5, "foo") == 5);
	assert(shiftRight(people, 5, 25, "foo") == 5);
	string s1[] = { "pig", "dog", "dragon", "rooster", "rabbit", "mouse" };
	assert(shiftRight(s1, 6, 3, "animal") == 3);
	string s2[] = { "pig", "dog", "dragon", "rooster", "rabbit", "mouse", "cat", "frog" };
	assert(shiftRight(s2, 8, 4, "boo") == 4);
	assert(shiftRight(s2, 8, 0, "boo") == 0);
	assert(shiftRight(s2, 8, 20, "boo") == 8);
	assert(shiftRight(s2, 0, 4, "boo") == -1);
	assert(shiftRight(s2, 8, -20, "boo") == -1);

	string ass[] = {"alpha", "beta", "gamma", "gamma", "beta", "delta" };
	string c[] = {"one:", "two/", "three'", "alpha.", "beta", "alpha."};

	
	dispString(c, 6);
	assert(shiftRight(c, 6, 10, "bar")==6);
	dispString(c, 6);

	dispString(ass, 3);
	assert(shiftRight(ass, 3, 10, "bar")==3);
	dispString(ass, 3);



	cerr << "Yes!" << endl;
}

int findMinimum(const string array[], int n) {
	int min = 0;
	if (n <= 0){
		min = -1;
	}
	else{
		for (int i = 0; i < n; i++){
			if (array[i] < array[min]){  //for each string, if the current min is larger than the current string, then make the current string the new min.
				min = i;
			}
		}
	}

	return min;		
}

int countAllPunctuation(const string array[], int n) {
	int count = 0;
	if (n <= 0){
		count = -1;
	}
	else{
		for (int i = 0; i < n; i++){
			for (size_t j = 0; j < array[i].size(); j++) { //look through every element of every string to count all the punctuation
				switch (array[i][j]){
				case '.':
				case ',':
				case '!':
				case ';':
				case '\'':                                  //use escape sequence so that cpp recognizes that the apostrophe is one of the characters
				case '-':
				case '/':
				case ':':
				case '?':
				case '"':
					count++;
					break;
				default:
					break;
				}
			}
		}
	}

	return count;
}

int countFloatingPointValues(const string array[], int n) {
	int count = 0;
	if (n <= 0){
		count = -1;
	}
	else{
		//flag to break out of inner for loop if it's already decided that the current string is not a floating val
		bool cont = true;
		//there should only be one decimal point in a floating point val, so this bool tracks whether the one decimal is already present in a number
		bool firstDec = true;
		//if the current string is a valid floating point number, isF = true
		bool isF = true;
		for (int i = 0; i < n; i++){
			cont = true;
			isF = true;
			if (array[i] == "."){
				isF = false;
			}
			else if (array[i] == "") {
				isF = false;
			}
			else{
				firstDec = true; //all values reset for each string
				for (size_t j = 0; j < array[i].size(); j++){
					switch (array[i][j]){
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						break;
					case '.':
						if (firstDec){
							firstDec = false;
							break;
						}
						else{
							isF = false;
							cont = false; //as soon as it's known that the current string isn't a floating pt, move onto the next string in the array
							break;
						}
					default:
						isF = false;
						cont = false; //as soon as there is a letter or smth then this string should be abandoned
						break;
					}
					if (!cont){
						break;
					}
				}
			}
			if (isF){
				count++;
			}
		}
	}
	return count;
}

int removeDuplicatedValues(string array[], int n) {
	int removed = 0;
	if (n <= 0){
		removed = -1;
	}
	else{
		bool firstMatch = true;

		for (int i = 0; i < n; i++){
			firstMatch = true;
			for (int j = 0; j < n; j++){
				if (array[i] == array[j] && array[i] != "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty" && array[j] != "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty"){
					if (firstMatch){
						firstMatch = false;
					}
					else{
						removed++;
						array[j] = "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty";
						
					}
				}		
			}
		}

		//now rearrange the string
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){				
				if (array[j] == "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty" && j < i && array[i] != "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty"){
					string temp = array[j];
					array[j] = array[i];
					array[i] = temp;
				}
		
			}
		}
		for (int i = 0; i < n; i++){
			if(array[i] == "em!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()(*&^%$#@!@#$%^&*()pty"){
				array[i] = "";
			}
		}
	}
	return removed;
}

/*int removeDuplicatedValues(string array[], int n)
{
	int removed = 0;
	if (n <= 0)
	{
		removed = -1;
	}
	else
	{
		bool firstMatch = true;

		for (int i = 0; i < n; i++)
		{
			array[i].push_back('*');
		}
		for (int i = 0; i < n; i++)
		{
			firstMatch = true;
			for (int j = 0; j < n; j++)
			{
				if (array[i] == array[j])
				{
					if (firstMatch)
					{
						firstMatch = false;
					}
					else
					{
						removed++;
						array[j].push_back('#');

					}
				}
			}
			if (array[i][(array[i].size() - 1)] != '#')
			{
				array[i].push_back('$');
			}
		}
		int firstOpen = -1;

		//now rearrange the string
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (array[j].find_last_of('#') == (array[j].size() - 1) && j < i && array[i].find_last_of('$') == (array[i].size() - 1))
				{
					string temp = array[j];
					array[j] = array[i];
					array[i] = temp;
				}

			}
		}
		for (int i = 0; i < n; i++)
		{
			if (array[i].find_last_of('#') == (array[i].size() - 1))
			{
				array[i] = "*#";
			}
			array[i].erase((array[i].size()-2), (array[i].size()-1));
		}

	}
	return removed;
}
*/

int replaceAll(string array1[], int n, char letterToReplace, char letterToFill) {
	int replaced = 0;
	if (n <= 0) {
		replaced = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (size_t j = 0; j < array1[i].size(); j++) {
				if (array1[i][j] == letterToReplace) {
					array1[i][j] = letterToFill;
					replaced += 1;
				}
			}
		}
	}

	return replaced;
}

int shiftRight(string array[], int n, int amount, string placeholder) {
	int places = 0;
	if (n <= 0||amount < 0){
		places = -1;
	}
	else {
		if (amount >= n) {
			
			places = n;
			for (int i = 0; i < n; i++) {
				array[i] = placeholder;
			}
		}
		else {
			for (int i = 0; i < amount; i++) {
				for (int j = (n - 1); j >= 1; j--) {
					array[j] = array[(j - 1)];
				}
				array[0] = placeholder;
				places++;
			}
		}
	}
	return places;
}