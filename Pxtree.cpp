#include "Pxtree.h"

Pxtree::Pxtree() {
	// IMPLEMENT ME
}

Pxtree::~Pxtree() {
	// IMPLEMENT ME
}

Pxtree::Pxtree(const Pxtree& other)  {
	// IMPLEMENT ME
}

Pxtree& Pxtree::operator=(const Pxtree& other) {
	// IMPLEMENT ME
	return *this;
}

int Pxtree::count(string s) const {

	// This is done for you as an example
	// You don't need to write so many comments...

	if (c_ == '\0') { // special case: the root
		if (leftmostChild_ == nullptr) return 0;
		else return leftmostChild_->count(s); // just pass it down
	}
	else if (c_ == s[0]) { // the char at this node matches the first char of the string

		// the string s ends here
		if (s.length() == 1) return count_;

		// more char from s need to be matched, but no children
		else if (leftmostChild_ == nullptr) return 0;

		// recursively pass the remaining part of s to the child to handle
		else return leftmostChild_->count(s.erase(0,1));
	}
	else { // the char at this node doesn't match

		// just pass it to the next sibling, if none then there is no match
		if (nextSibling_ == nullptr) return 0;
		else return nextSibling_->count(s);
	}

}

void Pxtree::add(string s) {
	// IMPLEMENT ME
}

void Pxtree::remove(string s) {
	// IMPLEMENT ME
}

string Pxtree::print() const {
	// IMPLEMENT ME
	return "DUMMY STRING"; // dummy, change to something else!
}

string Pxtree::autoComplete(string s) const {
	// IMPLEMENT ME
	return "DUMMY STRING"; // dummy, change to something else!
}

void Pxtree::compact() {
	// IMPLEMENT ME
}
