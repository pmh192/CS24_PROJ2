// Ryan Wiener, Porter Haet, 2/16/17

#include "word.h"

word::word()
{
	totalCount = 0;
	data = "";
}

word::word(string dat)
{
	totalCount = 0;
	data = dat;
}

word* word::getLeft()
{
	return n.left;
}

word* word::getRight()
{
	return n.right;
}

void word::insert(word w)
{
	if (w.data > this->data)
	{
		if (n.right)
		{
			n.right->insert(w);
		}
		else
		{
			n.right = &w;
		}
	}
	else if (w.data < this->data)
	{
		if (n.left)
		{
			n.left->insert(w);
		}
		else
		{
			n.left = &w;
		}
	}
}

string word::getWord()
{
	return data;
}

word* word::get(string dat)
{
	if (dat == this->data)
	{
		return this;
	}
	if (dat > this->data)
	{
		if (n.right)
		{
			return n.right->get(dat);
		}
		else
		{
			return 0;
		}
	}
	if (n.left)
	{
		return n.left->get(dat);
	}
	else
	{
		return 0;
	}
}

list<file>* word::getFiles() {
	return &files; 
}

int word::getFileTotal() {
	return files.length(); 
}

double word::getWordAverage() {
	return (double) getFileTotal() / totalCount;
}

void word::incrementTotalCount() {
	totalCount++;
}

bool word::operator==(const word& other) {
	return data == other.data; // only compare the string and not the list of files
}

int word::getHashCode() {
	int code = 0;
	// only hash the first four characters
	for (int i = 0; i < 4 && i < data.length(); i++) {
		int twentysix = 26;
		for (int n = 0; n < i; n++) { twentysix *= 26; }

		code += twentysix * (data[i] % 26);
	}
	return code;
}

void word::print()
{
	if (n.left)
	{
		n.left->print();
	}
	cout << this->data << endl;
	if (n.right)
	{
		n.right->print();
	}
}
