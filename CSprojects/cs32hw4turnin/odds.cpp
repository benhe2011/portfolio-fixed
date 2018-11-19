
void removeOdds(vector<int>& v)
{
	vector<int>::iterator it = v.begin();
	vector<int>::iterator temp = it;
	while (it != v.end()) {
		if ((*it % 2) != 0) {
			temp = v.erase(it);	
			it = temp;
		}
		else {
			it++;
		}
	}
}