#include "Sequence.h"

Sequence::Sequence() {
	m_items = 0;
} // Create an empty sequence (i.e., one with no items

bool Sequence::empty() const {    // Return true if the sequence is empty, otherwise false.
	bool isEmpty = true;
	if (m_items != 0) {
		isEmpty = false;
	}

	return isEmpty;
}  

int Sequence::size() const {    // Return the number of items in the sequence.
	return m_items;
}

bool Sequence::insert(int pos, const ItemType& value) {
	// Insert value into the sequence so that it becomes the item at
	// position pos.  The original item at position pos and those that
	// follow it end up at positions one higher than they were at before.
	// Return true if 0 <= pos <= size() and the value could be
	// inserted.  (It might not be, if the sequence has a fixed capacity,
	// e.g., because it's implemented using a fixed-size array.)  Otherwise,
	// leave the sequence unchanged and return false.  Notice that
	// if pos is equal to size(), the value is inserted at the end.
	bool canInsert = true;
	if (size() < DEFAULT_MAX_ITEMS && pos >= 0) {
		m_items++;

		for (int i = (size() - 1); i > pos; i--) {
			m_sequence[i] = m_sequence[i - 1];
		}
		m_sequence[pos] = value;
	}
	else {
		canInsert = false;
	}

	return canInsert;
}

int Sequence::insert(const ItemType& value) {
	// Let p be the smallest integer such that value <= the item at
	// position p in the sequence; if no such item exists (i.e.,
	// value > all items in the sequence), let p be size().  Insert
	// value into the sequence so that it becomes the item at position
	// p.  The original item at position p and those that follow it end
	// up at positions one higher than before.  Return p if the value
	// was actually inserted.  Return -1 if the value was not inserted
	// (perhaps because the sequence has a fixed capacity and is full).
		int p = 0;

		for (int j = 0; j < size(); j++) {
			if (value < m_sequence[j]) {
				p = j;
				break;
			}
		}
		if (size() > 0 && p == 0) {
			p = size() - 1;
		}

		if ((m_items+1) <= DEFAULT_MAX_ITEMS) {
			insert(p, value);
		}
		else {
			p = -1;
		}

		return p;
}

bool Sequence::erase(int pos) {
	// If 0 <= pos < size(), remove the item at position pos from
	// the sequence (so that all items that followed that item end up at
	// positions one lower than they were at before), and return true.
	// Otherwise, leave the sequence unchanged and return false.
	bool canErase = true;

	if (pos >= 0 && pos < size() && size() > 0) {
		for (int i = pos; i < size(); i++) {
			if ((i + 1) < size()) {
				m_sequence[i] = m_sequence[i + 1];
			}
		}
		m_items--;
	}
	else {
		canErase = false;
	}

	return canErase;
}

int Sequence::remove(const ItemType& value) {
	// Erase all items from the sequence that == value.  Return the
	// number of items removed (which will be 0 if no item == value).
	
	int removedItems = 0;
	int i = 0;

	while (i < size()) {
		if (m_sequence[i] == value) {
			removedItems++;
			erase(i);
		}
		else {
			i++;
		}
	}

	return removedItems;
}

bool Sequence::get(int pos, ItemType& value) const {
	// If 0 <= pos < size(), copy into value the item at position pos
	// in the sequence and return true.  Otherwise, leave value unchanged
	// and return false.
	bool canGet = true;

	if (pos >= 0 && pos < size()) {
		value = m_sequence[pos];
	}
	else {
		canGet = false;
	}

	return canGet;
}

bool Sequence::set(int pos, const ItemType& value) {
	// If 0 <= pos < size(), replace the item at position pos in the
	// sequence with value and return true.  Otherwise, leave the sequence
	// unchanged and return false.
	bool canSet = true;

	if (pos >= 0 && pos < size()) {
		m_sequence[pos] = value;
	}
	else {
		canSet = false;
	}

	return canSet;
}

int Sequence::find(const ItemType& value) const {
	// Let p be the smallest integer such that value == the item at
	// position p in the sequence; if no such item exists, let p be -1.
	// Return p.
	int p = -1;

	for (int i = 0; i < size(); i++) {
		if (m_sequence[i] == value) {
			p = i;
			break;
		}
	}

	return p;
}

void Sequence::swap(Sequence& other){
// Exchange the contents of this sequence with the other one.
	int swapSize = 0;
	int sizeTemp = 0;
	
	ItemType swapTemp;

	if (this->size() < other.size()) {
		swapSize = other.size();
	}
	else {
		swapSize = this->size();
	}

	sizeTemp = this->size();
	this->m_items = other.size();
	other.m_items = sizeTemp;

	for (int i = 0; i < swapSize; i++) {
		swapTemp = this->m_sequence[i];
		this->m_sequence[i] = other.m_sequence[i];
		other.m_sequence[i] = swapTemp;
	}
}
