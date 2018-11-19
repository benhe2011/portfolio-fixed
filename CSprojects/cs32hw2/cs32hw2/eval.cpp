#include <iostream>
#include <stack>
#include <string>
#include <cassert>
using namespace std;

//declarations of any additional functions you might have written
//to help you evaluate an expression
string removeSpace(string infix);
string IntoPost(string infix);
bool validateInfix(string infix);

int evaluate(string infix, string& postfix, bool& result)
{
	if (validateInfix(infix)) {
		stack<char> ss;
		char v1 = '.';
		char v2 = '.';
		postfix = IntoPost(infix);
		for (int i = 0; i < postfix.size(); i++) {
			if (postfix[i] == 'T' || postfix[i] == 'F') {
				ss.push(postfix[i]);
			}
			else if (!ss.empty() && (postfix[i] == '&' || postfix[i] == '|')) {
				v2 = ss.top();
				ss.pop();
				v1 = ss.top();
				ss.pop();

				if (postfix[i] == '&') {
					if (v1 == 'F' || v2 == 'F') {
						ss.push('F');
					}
					else {
						ss.push('T');
					}
				}
				else if (postfix[i] == '|') {
					if (v1 == 'F' && v2 == 'F') {
						ss.push('F');
					}
					else {
						ss.push('T');
					}
				}
			}
			else if (!ss.empty() && postfix[i] == '!') {
				v1 = ss.top();
				ss.pop();
				if (v1 == 'F') {
					ss.push('T');
				}
				else if (v1 == 'T'){
					ss.push('F');
				}
			}
		}
		if (!ss.empty() && ss.top() == 'T') {
			result = true;
		}
		else if (!ss.empty() && ss.top() == 'F') {
			result = false;
		}
		
		return 0;
	}
	else {
		return 1;
	}
}

//implementations of any additional functions you might have written
//to help you evaluate an expression
string IntoPost(string infix) {
	stack<char> ts;
	string postfix = "";
	char temp = '.';
	
	//infix = removeSpace(infix);

	for (unsigned int i = 0; i < infix.size(); i++) {
		if (infix[i] == 'T' || infix[i] == 'F') {
			postfix += infix[i];
		}
		else if (infix[i] == '(' || infix[i] == '!') {
			ts.push(infix[i]);
		}
		else if (ts.empty() && (infix[i] == '&' || infix[i] == '|')) {
			ts.push(infix[i]);
		}
		else if (!ts.empty() && (infix[i] == '&')) {
			while (!ts.empty() && ts.top() != '|' && ts.top() != '(') {
				temp = ts.top();
				ts.pop();
				postfix += temp;
			}
			ts.push(infix[i]);
		}
		else if (!ts.empty() && (infix[i] == '|')) {
			while (!ts.empty() && ts.top() != '(') {
				temp = ts.top();
				ts.pop();
				postfix += temp;
			}
			ts.push(infix[i]);
		}
		else if (!ts.empty() && infix[i] == ')') {
			while (!ts.empty() && ts.top() != '(') {
				temp = ts.top();
				ts.pop();
				postfix += temp;
			}
			if(!ts.empty()){
			temp = ts.top();
			ts.pop();
			}
			
		}
	}
	
	while (!ts.empty()) {
			temp = ts.top();
			ts.pop();
			postfix += temp;
	}

	return postfix;
}

string removeSpace(string infix) {
	string noSpace = "";
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == ' ') {
			continue;
		}
		else {
			noSpace += infix[i];
		}
	}

	return noSpace;
}

bool validateInfix(string infix) {
	bool validEx = false;
	stack<char> par;
	
	infix = removeSpace(infix);

	if (infix[0] != '!' && infix[0] != 'T' && infix[0] != 'F' && infix[0] != '(') {
		return false;
	}
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] != 'T'
			&& infix[i] != 'F'
			&& infix[i] != '('
			&& infix[i] != ')'
			&& infix[i] != '!'
			&& infix[i] != '&'
			&& infix[i] != '|') {
			return false;
		}
		if (infix[i] == 'T' || infix[i] == 'F') {
			if ((i + 1) < infix.size()) {
				if (infix[i + 1] == 'T' 
					|| infix[i + 1] == 'F' 
					|| infix[i + 1] == '(' 
					|| infix[i + 1] == '!') {
					return false;
				}
			}
			if ((i - 1) >= 0) {
				if (infix[i - 1] == 'T' 
					|| infix[i - 1] == 'F'
					|| infix[i - 1] == ')') {
					return false;
				}
			}
			validEx = true;
		}
		else if (infix[i] == '&' || infix[i] == '|') {
			if (i == 0 || i == infix.size() - 1) {
				return false;
			}
			if (infix[(i + 1)] == '&'
				|| infix[(i + 1)] == '|'
				|| infix[(i + 1)] == ')'
				|| infix[(i - 1)] == '('
				|| infix[(i - 1)] == '&'
				|| infix[(i - 1)] == '|'
				|| infix[(i - 1)] == '!') {
				return false;
			}
		}
		else if (infix[i] == '!') {
			validEx = false;
		}
		else if (infix[i] == '(') {
			if (i == infix.size() - 1) {
				return false;
			}
			if ((i - 1) >= 0) {
				if (infix[i + 1] == '&'
					|| infix[i + 1] == '|'
					|| infix[i + 1] == ')'
					|| infix[i - 1] == 'T'
					|| infix[i - 1] == 'F'
					|| infix[i - 1] == ')') {
					return false;
				}
			}
			par.push(infix[i]);
		}
		else if (infix[i] == ')') {
			if (i == 0) {
				return false;
			}
			if (i + 1 < infix.size()) {
				if (infix[i + 1] == '!'
					|| infix[i + 1] == 'T'
					|| infix[i + 1] == 'F'
					|| infix[i + 1] == '('
					|| infix[i - 1] == '!'
					|| infix[i - 1] == '&'
					|| infix[i - 1] == '|'
					|| infix[i - 1] == '(') {
					return false;
				}
			}
			if (!par.empty()) {
				if (par.top() == '(') {
					par.pop();
				}
			}
			else {
				return false;
			}
		}
	}

	if (validEx && par.empty()) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	string test1 = "T|(F|T)";
	string test2 = "T|F|T";
	string test3 = "(())";
	string test4 = "TF";
	string test5 = "T||FT";
	string test6 = "T|F|E|T";
	string test7 = "T|F & T";
	string test8 = "!!!!!!!T";
	string test9 = "!!!!T!";
	string test10 = "T!F";
	string test11 = "!(T|F)";
	string test12 = "!T|F";
	string test13 = "T";
	string test14 = "(F)"; //evaluates to false
	string test15 = "T&(F)"; //evaluates to false
	string test16 = "T & !F";          // evaluates to true
	string test17 = "!(F | T)";         //evaluates to false
	string test18 = "!F | T";    //evaluates to true
	string test19 = "T | F & F";         //evaluates to true
	string test20 = "T & !(F | T & T | F) | !!!(F&T&F)"; 
	bool holder = false;
	string temppost = "";

	assert(evaluate(test1, temppost, holder) == 0 && temppost == "TFT||" && holder == true);
	assert(evaluate(test2, temppost, holder) == 0 && temppost == "TF|T|" && holder == true);
	assert(evaluate(test3, temppost, holder) == 1);
	assert(evaluate(test4, temppost, holder) == 1);
	assert(evaluate(test5, temppost, holder) == 1);
	assert(evaluate(test6, temppost, holder) == 1);
	assert(evaluate(test7, temppost, holder) == 0 && temppost == "TFT&|" && holder == true);
	assert(evaluate(test8, temppost, holder) == 0 && temppost == "T!!!!!!!" && holder == false );
	assert(evaluate(test9, temppost, holder) == 1);
	assert(evaluate(test10, temppost, holder) == 1);
	assert(evaluate(test11, temppost, holder) == 0 && temppost == "TF|!" && holder == false);
	assert(evaluate(test12, temppost, holder) == 0 && temppost == "T!F|" && holder == false);
	assert(evaluate(test13, temppost, holder) == 0 && holder == true);
	assert(evaluate(test14, temppost, holder) == 0 && holder == false);
	assert(evaluate(test15, temppost, holder) == 0 && holder == false);
	assert(evaluate(test16, temppost, holder) == 0 && holder == true);
	assert(evaluate(test17, temppost, holder) == 0 && holder == false);
	assert(evaluate(test18, temppost, holder) == 0 && holder == true);
	assert(evaluate(test19, temppost, holder) == 0 && holder == true);
	assert(evaluate(test20, temppost, holder) == 0 && holder == true);
	
	string pf;
	bool answer;
	assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|"  &&  answer);
	assert(evaluate("T|", pf, answer) == 1);
	assert(evaluate("F F", pf, answer) == 1);
	assert(evaluate("TF", pf, answer) == 1);
	assert(evaluate("()", pf, answer) == 1);
	assert(evaluate("T(F|T)", pf, answer) == 1);
	assert(evaluate("T(&T)", pf, answer) == 1);
	assert(evaluate("(T&(F|F)", pf, answer) == 1);
	assert(evaluate("", pf, answer) == 1);
	assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
		&& pf == "FF!TF&&|" && !answer);
	assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
	assert(evaluate("((T))", pf, answer) == 0 && pf == "T"  &&  answer);

	string b = "TFJ";
	assert(!validateInfix(b));
	assert(validateInfix("T"));
	assert(validateInfix("(F)"));
	assert(validateInfix("T&(F)"));
	assert(validateInfix("T & !F"));
	assert(validateInfix("! (F|T)"));
	assert(validateInfix("!F|T"));
	assert(validateInfix("T|F&F"));
	assert(validateInfix("T&!(F|T&T|F) |!!!(F&T&F)"));
	assert(validateInfix("T|") == false);
	assert(validateInfix("F F") == false);
	assert(validateInfix("") == false);
	assert(validateInfix("F|T|F F") == false);
	assert(validateInfix("F!") == false);
	assert(validateInfix("T !  T") == false);
	assert(validateInfix("F&T|!((F|T)&F)"));
	assert(validateInfix("F&T|(F&T))") == false);
	assert(validateInfix("F&T|F&T)") == false);
	assert(validateInfix("&FT") == false);
	assert(validateInfix("(F& |T)") == false);
	assert(validateInfix("((!F&T)|(F|T)&F)&!F"));

	assert(IntoPost("T|F|T") == "TF|T|");
	assert(IntoPost("T|(F|T)") == "TFT||");
	assert(IntoPost("T|    F") == "TF|");
	assert(IntoPost("F&T|!((F|T)&F)") == "FT&FT|F&!|");
	assert(IntoPost("!F") == "F!");
	assert(IntoPost("T& !(F|T &T|F) |!!!(F&T&F)") == "TFTT&|F|!&FT&F&!!!|");
	assert(IntoPost("!(F|T)") == "FT|!");
	assert(IntoPost("((!F&T)|(F|T)&F)&!F") == "F!T&FT|F&|F!&");
	assert(IntoPost("(!(F&T)|(F|T)&F)&!F") == "FT&!FT|F&|F!&");
	
	bool result = false;
	string temp = "holds postfix";

	//valid strings
	string mtest1 = "!(!F|T)";
	string mtest2 = "!!(!F|T)";
	string mtest3 = "!!!!!!!!!!T";
	string mtest4 = "!T|F";
	string mtest5 = "(F|T) & (T&!F)";
	string mtest6 = "(F|T) & (T&!!F)";
	string mtest7 = "F | T";

	//invalid strings
	string invalid1 = "!!(!F!|T)";
	string invalid2 = "!!(!&F|T)";
	string invalid3 = "!!(&F|T)";
	string invalid4 = "!!(!F|T&)";
	string invalid5 = "!!(!&F|T";
	string invalid6 = "!F)";
	string invalid7 = "T&";
	string invalid12 = "&T";
	string invalid8 = "TT&T";
	string invalid9 = "T&";
	string invalid10 = "";
	string invalid11 = "(F         &       F)!";
	string invalid18 = "FF";
	string invalid13 = "T(T|T)";
	string invalid14 = "F  |  !F & (T&&F) ";
	string invalid15 = "()";
	string invalid16 = "T&!(F|T&T|F)|!!!(F&T&|F)";
	string invalid17 = "!TR!";


	assert(evaluate(mtest3, temp, result) == 0 && temp == "T!!!!!!!!!!" && result == true);
	assert(evaluate(mtest4, temp, result) == 0 && temp == "T!F|" && result == false);
	assert(evaluate(mtest5, temp, result) == 0 && temp == "FT|TF!&&" && result == true);
	assert(evaluate(mtest6, temp, result) == 0 && temp == "FT|TF!!&&" && result == false);
	assert(evaluate(mtest7, temp, result) == 0 && temp == "FT|" && result == true);
	assert(evaluate(mtest1, temp, result) == 0 && temp == "F!T|!" && result == false);
	assert(evaluate(mtest2, temp, result) == 0 && temp == "F!T|!!" && result == true);


	assert(evaluate(invalid1, temp, result) == 1 && result == true);
	assert(evaluate(invalid2, temp, result) == 1 && result == true);
	assert(evaluate(invalid3, temp, result) == 1 && result == true);
	assert(evaluate(invalid4, temp, result) == 1 && result == true);
	assert(evaluate(invalid5, temp, result) == 1 && result == true);
	assert(evaluate(invalid7, temp, result) == 1 && result == true);
	assert(evaluate(invalid8, temp, result) == 1 && result == true);
	assert(evaluate(invalid9, temp, result) == 1 && result == true);
	assert(evaluate(invalid10, temp, result) == 1 && result == true);
	assert(evaluate(invalid11, temp, result) == 1 && result == true);
	assert(evaluate(invalid12, temp, result) == 1 && result == true);
	assert(evaluate(invalid13, temp, result) == 1 && result == true);
	assert(evaluate(invalid14, temp, result) == 1 && result == true);
	assert(evaluate(invalid15, temp, result) == 1 && result == true);
	assert(evaluate(invalid16, temp, result) == 1 && result == true);
	assert(evaluate(invalid17, temp, result) == 1 && result == true);
	assert(evaluate(invalid18, temp, result) == 1 && result == true);

	assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|"  &&  answer);
	assert(evaluate("T|", pf, answer) == 1);
	assert(evaluate("F F", pf, answer) == 1);
	assert(evaluate("TF", pf, answer) == 1);
	assert(evaluate("()", pf, answer) == 1);
	assert(evaluate("T(F|T)", pf, answer) == 1);
	assert(evaluate("T(&T)", pf, answer) == 1);
	assert(evaluate("(T&(F|F)", pf, answer) == 1);
	assert(evaluate("", pf, answer) == 1);
	assert(evaluate("(!!)", pf, answer) == 1);
	assert(evaluate("(!TT!(F)", pf, answer) == 1);
	assert(evaluate("(((F & T !)", pf, answer) == 1);
	assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0 && pf == "FF!TF&&|" && !answer);
	assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
	assert(evaluate("((T))", pf, answer) == 0 && pf == "T"  &&  answer);
	assert(evaluate("T", pf, answer) == 0 && pf == "T" && answer);
	assert(evaluate("(F) ", pf, answer) == 0 && pf == "F" && !answer);
	assert(evaluate(" T &(F) ", pf, answer) == 0 && pf == "TF&" && !answer);
	assert(evaluate("T & !F ", pf, answer) == 0 && pf == "TF!&" && answer);
	assert(evaluate("!(F|T)", pf, answer) == 0 && pf == "FT|!" && !answer);
	assert(evaluate("!F|T", pf, answer) == 0 && pf == "F!T|" && answer);
	assert(evaluate("T|F&F", pf, answer) == 0 && pf == "TFF&|" && answer);
	assert(evaluate("T&!(F|T&T|F)|!!!(F&T&F)", pf, answer) == 0 && pf == "TFTT&|F|!&FT&F&!!!|" && answer);
	assert(evaluate("(F & ! (!T & F & T | !!!F) ) | !F", pf, answer) == 0 && answer);
	assert(evaluate("F & T | !F", pf, answer) == 0 && answer);
	assert(evaluate("", pf, answer) == 1);
	assert(evaluate(" ", pf, answer) == 1);

	assert(evaluate("T|F&F", pf, answer) == 0);
	assert(evaluate("!F|T", pf, answer) == 0);
	assert(evaluate("!(F|T)", pf, answer) == 0);
	assert(evaluate("T&!F", pf, answer) == 0);
	assert(evaluate("T&(F)", pf, answer) == 0);
	assert(evaluate("(F)", pf, answer) == 0);

	assert(evaluate("()())()()()", pf, answer) == 1);
	assert(evaluate("!", pf, answer) == 1);
	assert(evaluate("T|F!", pf, answer) == 1);
	assert(evaluate("T&F&T|!F|T", pf, answer) == 0);
	assert(evaluate("(T&F&T!F|T", pf, answer) == 1);
	assert(evaluate("T&F&T!)F|T", pf, answer) == 1);
	assert(evaluate("(T&F&T!)F|T", pf, answer) == 1);
	assert(evaluate("T&(F&T)!F|T", pf, answer) == 1);
	assert(evaluate("T(F&T)!F|T", pf, answer) == 1);
	assert(evaluate("|T(F&T)!F|T", pf, answer) == 1);
	assert(evaluate("&T|(F&T)!F|T", pf, answer) == 1);
	assert(evaluate("T|(F&T)!F|T&", pf, answer) == 1);
	assert(evaluate("&", pf, answer) == 1);
	assert(evaluate("T&F&T|!F|T", pf, answer) == 0);

	cout << "All tests passed." << endl;
}
