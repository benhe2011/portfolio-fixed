
void removeBad(list<Movie*>& li)
{
	list<Movie*>::iterator it;
	list<Movie*>::iterator temp;
	it = li.begin();
	while (it != li.end()) {
		if ((*it)->rating() < 50) {
			delete (*it);
			temp = li.erase(it);
			it = temp;
		}
		else {
			it++;
		}
	}
}
