// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <string>
#include <list>
#include <cctype>
#include <utility>  // for swap
#include <iostream>
#include <functional>

using namespace std;

const int HASH_TABLE_SIZE = 49999;
const int PRIMES[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

// This class does the real work of the implementation.

struct Node {
	long id;
	string word;
	Node* next;
};

class DictionaryImpl
{
public:
	DictionaryImpl();
	~DictionaryImpl();
	void insert(string word);
	void lookup(string letters, void callback(string)) const;
	unsigned long hash(const string& word) const;
private:
	Node* m_words[HASH_TABLE_SIZE];
};

DictionaryImpl::DictionaryImpl() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		m_words[i] = nullptr; 
	}
}
 
DictionaryImpl::~DictionaryImpl() {
	Node* destroyer = nullptr;
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		Node* currNode = m_words[i];
		while (currNode != nullptr) {
			destroyer = currNode;
			currNode = currNode->next;
			delete destroyer;
		}
	}
}


unsigned long DictionaryImpl::hash(const string& word) const {
	unsigned long hashID = 1;
	for (int i = 0; i < word.size(); i++) {
		hashID *= PRIMES[word[i] - 'a'];
	}

	return hashID;
}


void DictionaryImpl::insert(string word)
{
	removeNonLetters(word);
	if (word.empty()) {
		return; 
	}

	unsigned long hashedWord = hash(word);
	unsigned int index = hashedWord % HASH_TABLE_SIZE;
	Node* currNode = m_words[index];

	if (currNode == nullptr) {
		Node* loc = new Node;
		loc->id = hashedWord;
		loc->word = word; 
		loc->next = nullptr;
		m_words[index] = loc;
	}
	else {
		while (currNode->next != nullptr) {
			currNode = currNode->next;
		}
		Node* loc = new Node;
		loc->id = hashedWord;
		loc->word = word;
		loc->next = nullptr;
		currNode->next = loc; 
	}

}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
	if (callback == nullptr)
		return;

	removeNonLetters(letters);
	if (letters.empty())
		return;

	unsigned long hashedWord = hash(letters);

	Node* currBucket = m_words[hashedWord % HASH_TABLE_SIZE];
		
	while (currBucket != nullptr) {
		if (hashedWord == currBucket->id) {
			callback(currBucket->word);
		}		
		
		currBucket = currBucket->next;
	}
}

void removeNonLetters(string& s)
{
	string::iterator to = s.begin();
	for (string::const_iterator from = s.begin(); from != s.end(); from++)
	{
		if (isalpha(*from))
		{
			*to = tolower(*from);
			to++;
		}
	}
	s.erase(to, s.end());  // chop everything off from "to" to end.
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
	m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
	delete m_impl;
}

void Dictionary::insert(string word)
{
	m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
	m_impl->lookup(letters, callback);
}
