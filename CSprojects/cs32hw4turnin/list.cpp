
void listAll(string path, const File* f)  // two-parameter overload
{
	path += '/' + f->name();

	cout << path << endl;

	if (f->files() == nullptr) {
		return;
	}

	for (vector<File*>::const_iterator it = f->files()->begin(); it != f->files()->end(); it++) {
		listAll(path, *it);
	}
}