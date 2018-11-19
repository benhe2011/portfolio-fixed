#include <iostream>
#include "Sequence.h"
using namespace std;

Sequence::Sequence() {
	m_items = 0;           //this sets up an empty doubly-linked circular linked Sequence with a dummy node
	m_head = new Node;     //so the m_head should point to a newly-created node that points to itself in both directions
	m_head->next = m_head;
	m_head->prev = m_head;
}

Sequence::Sequence(const Sequence& other) {
	m_items = 0;                             
	m_head = new Node;                       //creates new Node with m_head ponting to it similar to the default constructor
	m_head->next = m_head;                   
	m_head->prev = m_head;
	int i = 0;                               //create index for going through other to copy each node into the new Sequence
	Node* tempNode = (other.m_head)->next;   //first element of the Sequence is at m_head->next

	while (tempNode != other.m_head) {       //cycle through the other Sequence and copy the value of that sequence into this one using insert member function
		insert(i, tempNode->value);
		i++;
		tempNode = tempNode->next;

	}
}

Sequence& Sequence::operator=(const Sequence& other) {
	if (this != &other){
		Sequence temp(other);
		swap(temp);
	}
	return *this;
}

Sequence::~Sequence() {
	Node* temp = m_head->next;      //temp is used to navigate through the Sequence
	Node* killMe = temp;            //while killMe is used to delete each Node in the Sequence

	while (temp != m_head) {        //cycle through the Sequence
		killMe = temp;             
		temp = temp->next;          //move onto the next Node before deleting this one otherwise the rest of the list will be lost
		delete killMe;
	} 
	delete m_head;                  //finally, delete the dummy node that the m_head points to
}

bool Sequence::empty() const {    
	bool isEmpty = false;       //if there are no items in the Sequence, then it's empty
	
	if (m_items == 0) {
		isEmpty = true;
	}
	return isEmpty;
}

int Sequence::size() const {  //just returns the number of items in the Sequence
	return m_items;
}

bool Sequence::insert(int pos, const ItemType& value) {   
	bool canInsert = true;
	Node* posNode = m_head->next;              //pointer used to navigate through the Sequence until reaching Node at pos
	
	if (pos <= size() && pos >= 0) {           //circular doubly-linked list with dummy node
		Node* newNode = new Node;              //need to create new Node each time you add onto list
		
		for (int i = 0; i < pos; i++) {        //locate the address of the Node at pos
			posNode = posNode->next;
		}
		newNode->next = posNode;               //inserts the new Node--works with all conditions--empty, beginning, end, middle
		newNode->prev = posNode->prev;
		newNode->value = value;
		(posNode->prev)->next = newNode;
		posNode->prev = newNode;
		m_items++;                             //keep track of the size of the Sequence with m_items
	}
	else {
		canInsert = false;                     //if you try to insert a Node outside of the Sequence, do nothing and return false
	}
	return canInsert;
}

int Sequence::insert(const ItemType& value) { 
	Node* currNode = m_head->next;            //using this pointer to move through the Sequence
	int insertPos = 0;                        //using this index to determine where to insert the new Node

	while (currNode != m_head) {     
		if (value <= currNode->value) {       //loop keeps moving through the Sequence and updating the location of insertPos until it finds a good place, then breaks out of loop
			break;
		}
		else {
			currNode = currNode->next;
			insertPos++; 
		}
	}
	insert(insertPos, value);                 //call insert function once location is known
	return insertPos;
}

bool Sequence::erase(int pos) {
	Node* posNode = m_head->next;             //using this pointer to navigate Sequence
	bool canErase = true;

	if (pos < size() && pos >= 0) {
		for (int i = 0; i < pos; i++) {       //locate the address of the node at pos
			posNode = posNode->next;
		}
		posNode->prev->next = posNode->next;
		posNode->next->prev = posNode->prev;
		delete posNode;                       //making sure there are no memory leaks
		m_items--;
	}
	else {
		canErase = false;                     //cannot erase if pos is outside of the Sequence
	}
	return canErase;
}

int Sequence::remove(const ItemType& value) {
	int removed = 0;              //tracking number of erased Nodes
	int p = 0;

	while (p != -1) {
		p = find(value);         //keeps finding all the values until there are no more and it prints -1
		if (p != -1) {
			erase(p);
			removed++;
		}
	}
	return removed;
}

bool Sequence::get(int pos, ItemType& value) const {
	bool canGet = true;
	Node* posNode = m_head->next;

	if (pos < size() && pos >= 0) {
		for (int i = 0; i < pos; i++) {    //locate the address of the Node at pos
			posNode = posNode->next;
		}
		value = posNode->value;
	}
	else {
		canGet = false;                   //can't get if the pos is outside of the Sequence
	}
	return canGet;
}

bool Sequence::set(int pos, const ItemType& value) {
	bool canSet = true;
	Node* posNode = m_head->next;

	if (pos < size() && pos >= 0) {
		for (int i = 0; i < pos; i++) {    //locate the address of the Node at pos
			posNode = posNode->next;
		}
		posNode->value = value;
	}
	else {
		canSet = false;                   //can't set if the pos is outside of the Sequence
	}
	return canSet;
}

int Sequence::find(const ItemType& value) const {
	int pos = 0;
	Node* posNode = m_head->next;

	while (posNode != m_head) {             //just cycles through the Sequence while incrementing pos tracker variable until value matches and returns the pos variables
		if (posNode->value == value) {
			break;
		}
		else {
			pos++;
			posNode = posNode->next;
		}
	}
	if (pos == size()) {                   //if the value never appears in the Sequence, pos is set to -1 to be returned
		pos = -1;
	}
	return pos;
}

void Sequence::swap(Sequence& other) {      
	Node* temp = m_head;                  //just switch the m_heads because then the heads will point to the rest of the list
	m_head = other.m_head;
	other.m_head = temp;
	
	int temp2 = m_items;                  //also need to make sure the sizes are switched otherwise the swap wouldn't make any sense
	m_items = other.m_items;
	other.m_items = temp2;
}


int subsequence(const Sequence& seq1, const Sequence& seq2) {
	ItemType seq1Curr;                                 //these two variables are used to 
	ItemType seq2Curr;                                 //track the Nodes in both parameter sequences
	int subStart = -1;                                 //this the variable that will be returned, it is initialized to -1 because if seq2 is not a subsequence, subStart is supposed to return -1
	int subTemp = 0;                                   //this variable is used to tentatively hold a location where a sub might be happening but isn't sure yet
	bool isSub = false;                                //used to check whether or not to set the subStart to the subTemp
	int i = 0;

	seq2.get(0, seq2Curr);                             //in the beginning, the seq2Curr will be the beginning of the seq2

	for (i = 0; i < seq1.size(); i++) {
		seq1.get(i, seq1Curr);                         //in the outer for loop, each element of the seq1 is being checked to see if it matches with the first element of seq2
		if (seq1Curr == seq2Curr) {                    //if and when a match is found, subTemp records the location, 
			subTemp = i;                               //then another for loop is started to compare each element of seq2 to the element in seq1 starting from the location of the first match
			for (int j = 0; j < seq2.size(); j++) {
				seq1.get(i, seq1Curr);
				seq2.get(j, seq2Curr);
				if (seq1Curr != seq2Curr) {
					isSub = false;
					seq2.get(0, seq2Curr);
					break;                             //if at any point within the size of seq2 there is a mismatch, the inner for loop is broken 
				}                                      //and seq2Curr is reset to the first element of seq2 in case another potential subsequence occurs
				isSub = true;
				i++;
			}
			if (isSub) {                               //if at the end isSub is true, that means that seq2 was found inside seq1 and thus the index of subTemp is confirmed to be the beginning of the subsequence
				subStart = subTemp;
			}
		}	
	}
	return subStart;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
	int leafSize = 0;                    //leafSize is used to store the size of the smaller Sequence because that's how far the sequences will be interleaved
	int endSize = 0;                     //endSize is used to store the size of the larger Sequence because the extra elements at the end of the larger Sequence 
	bool isSeq1Larger = false;           //will just be added to the end of the interleaved part
	int i = 0;                           //indexes for tracking where to get the values from the parameter Sequences and where to insert into the resulting Sequence
	int j = 0;
	Sequence tempSeq;                    //to eliminate the problem of aliasing, a local Sequence is created and will be manipulated, then at the end it will be switched into the result Sequence
	ItemType tempVal;                    //this variable is just used to store the values of the nodes as you get them from the paremeter sequences and insert it into the temp Sequence

	if (seq1.size() > seq2.size()) {     //this is used to determine which seq is larger
		leafSize = seq2.size();          //once it's determined, the interleaving will only occur up to the size of the smaller seq
		endSize = seq1.size();
		isSeq1Larger = true;
	}
	else {
		leafSize = seq1.size();
		endSize = seq2.size();
		isSeq1Larger = false;
	}
	while (i < leafSize) {              //first, the parts of both seq that go up to the size of the smaller seq are interleaved
		seq1.get(i, tempVal);
		tempSeq.insert(j, tempVal);
		j++;
		seq2.get(i, tempVal);
		tempSeq.insert(j, tempVal);
		j++;
		i++;
	}
	while (i < endSize) {               //since the indexes are still existing with their values, this loop just tacks on the rest 
		if (isSeq1Larger) {             //of the larger sequence continuing off from where the indexes left off from the loop before
			seq1.get(i, tempVal);       
		}
		else {
			seq2.get(i, tempVal);
		}
		tempSeq.insert(j, tempVal);
		j++;
		i++;
	}
	result.swap(tempSeq);              //in the end, the tempSeq that the interleaving was happening to is just swapped with result, then the tempSeq is detroyed when it leaves the scope, so no memory is leaked and result now has the correct sequence
}