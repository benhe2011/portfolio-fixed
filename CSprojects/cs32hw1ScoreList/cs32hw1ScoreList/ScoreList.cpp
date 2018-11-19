#include "ScoreList.h"

ScoreList::ScoreList() {} // Create an empty score list.

bool ScoreList::add(unsigned long score) {
	// If the score is valid (a value from 0 to 100) and the score list
	// has room for it, add it to the score list and return true.
	// Otherwise, leave the score list unchanged and return false.
	bool canAdd = true;

	if (score >= 0 && score <= 100) {
		m_sequence.insert(score);
	}
	else {
		canAdd = false;
	}

	return canAdd;
}

bool ScoreList::remove(unsigned long score) {
	// Remove one instance of the specified score from the score list.
	// Return true if a score was removed; otherwise false.
	bool canRemove = true;

	int r = m_sequence.find(score);
	canRemove = m_sequence.erase(r);

	return canRemove;
}

int ScoreList::size() const {  // Return the number of scores in the list.
	return m_sequence.size();
}

unsigned long ScoreList::minimum() const {
	// Return the lowest score in the score list.  If the list is
	// empty, return NO_SCORE.

	unsigned long min = 100;
	unsigned long seqEl;

	if (!(m_sequence.empty())) {
		for (int i = 0; i < m_sequence.size(); i++) {
			m_sequence.get(i, seqEl);
			if (min > seqEl) {
				min = seqEl;
			}
		}
	}
	else {
		min = NO_SCORE;
	}

	return min;
}

unsigned long ScoreList::maximum() const {
	// Return the highest score in the score list.  If the list is
	// empty, return NO_SCORE.
	unsigned long max = 0;
	unsigned long seqEl;

	if (!(m_sequence.empty())) {
		for (int i = 0; i < m_sequence.size(); i++) {
			m_sequence.get(i, seqEl);
			if (max < seqEl) {
				max = seqEl;
			}
		}
	}
	else {
		max = NO_SCORE;
	}

	return max;
}