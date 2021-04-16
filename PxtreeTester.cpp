#include <iostream>
#include "PxtreeTester.h"
#include "Pxtree.h"

using namespace std;

PxtreeTester::PxtreeTester() : error_(false), funcname_("") {}

// construct, destruct, count empty trees
void PxtreeTester::testa() {
	funcname_ = "PxtreeTester::testa";

	{
	// 1 mark
	Pxtree t;
	if (t.count("x") != 0)
		errorOut_("Empty tree incorrect count x",0);
	if (t.count("xyz") != 0)
		errorOut_("Empty tree incorrect count xyz",0);
	if (t.count("\0") != 0)
		errorOut_("Empty tree incorrect count \\0",0);

	}

	// and 1 mark for not crashing!

	passOut_();
}

// add: simplest tree with one node
void PxtreeTester::testb() {
	funcname_ = "PxtreeTester::testb";

	Pxtree t;
	t.add("a");
	if (t.count("a") != 1) errorOut_("single node added incorrectly",0);

	passOut_();
}

// add: only top-level nodes
void PxtreeTester::testc() {
	funcname_ = "PxtreeTester::testc";

	// 1 mark
	Pxtree t;
	t.add("a"); t.add("b"); t.add("c");
	if (t.count("a") != 1) errorOut_("a count not 1",0);
	if (t.count("b") != 1) errorOut_("b count not 1",0);
	if (t.count("c") != 1) errorOut_("c count not 1",0);

	// 1 mark
	if (t.count("d") != 0) errorOut_("d count not 0",1);
	if (t.count("abc") != 0) errorOut_("abc count not 0",1);

	passOut_();
}

// add: single path
void PxtreeTester::testd() {
	funcname_ = "PxtreeTester::testd";

	// 1 mark
	Pxtree t;
	t.add("ab");
	if (t.count("a") != 0) errorOut_("a count not 0 after add ab",0);
	if (t.count("ab") != 1) errorOut_("ab count not 1 after add ab",0);
	if (t.count("abc") != 0) errorOut_("abc count not 0 after add ab",0);

	// 1 mark
	t.add("abcd");
	if (t.count("abcd") != 1) errorOut_("abcd count not 1 after add abcd",1);
	if (t.count("abc") != 0) errorOut_("abc count not 0 after add abcd",1);
	if (t.count("ab") != 1) errorOut_("ab count not 1 after add abcd",1);
	if (t.count("a") != 0) errorOut_("a count not 0 after add abcd",1);

	passOut_();
}

// add: single path, in reverse order; identical letters
void PxtreeTester::teste() {
	funcname_ = "PxtreeTester::teste";

	// 1 mark
	Pxtree t;
	t.add("aaaa");
	if (t.count("a") != 0) errorOut_("a count not 0 after add aaaa",0);
	if (t.count("aa") != 0) errorOut_("aa count not 0 after add aaaa",0);
	if (t.count("aaa") != 0) errorOut_("aaa count not 0 after add aaaa",0);
	if (t.count("aaaa") != 1) errorOut_("aaaa count not 1 after add aaaa",0);

	// 1 mark
	t.add("aa");
	if (t.count("aaaa") != 1) errorOut_("aaaa count not 1 after add aa",1);
	if (t.count("aaa") != 0) errorOut_("aaa count not 0 after add aa",1);
	if (t.count("aa") != 1) errorOut_("aa count not 1 after add aa",1);
	if (t.count("a") != 0) errorOut_("a count not 0 after add aa",1);

	passOut_();
}

// complex add
void PxtreeTester::testf() {
	funcname_ = "PxtreeTester::testf";

	Pxtree t;
	createExampleTree(t);

	if (t.count("a") != 0) errorOut_("a count not 0",0);
	if (t.count("b") != 2) errorOut_("b count not 2",0);
	if (t.count("af") != 3) errorOut_("af count not 3",0);
	if (t.count("ag") != 0) errorOut_("ag count not 0",0);
	if (t.count("ah") != 2) errorOut_("ah count not 2",0);
	if (t.count("bi") != 1) errorOut_("bi count not 1",0);
	if (t.count("afk") != 1) errorOut_("afk count not 1",0);
	if (t.count("afl") != 2) errorOut_("afl count not 2",0);
	if (t.count("afm") != 4) errorOut_("afm count not 4",0);
	if (t.count("ago") != 1) errorOut_("ago count not 1",0);
	if (t.count("aflp") != 3) errorOut_("aflp count not 3",0);
	if (t.count("agop") != 1) errorOut_("agop count not 1",0);
	if (t.count("ab") != 0) errorOut_("ab count not 0",0);
	if (t.count("f") != 0) errorOut_("f count not 0",0);

	passOut_();
}

// print empty tree
void PxtreeTester::testg() {
	funcname_ = "PxtreeTester::testg";

	Pxtree t;
	if (t.print() != "") errorOut_("empty tree printed incorrectly",0);

	passOut_();
}

// print: simplest tree with one node
void PxtreeTester::testh() {
	funcname_ = "PxtreeTester::testh";

	Pxtree t;
	t.add("a");
	if (t.print() != "a 1")
		errorOut_("single node tree printed incorrectly",0);

	passOut_();
}

// print: only top-level nodes
void PxtreeTester::testi() {
	funcname_ = "PxtreeTester::testi";

	Pxtree t;
	t.add("a"); t.add("b"); t.add("c");
	if (t.print() != "a 1\nb 1\nc 1")
		errorOut_("tree with only top-level nodes printed incorrectly",0);

	passOut_();
}

// print: single path
void PxtreeTester::testj() {
	funcname_ = "PxtreeTester::testj";

	// 1 mark
	Pxtree t;
	t.add("ab");
	if (t.print() != "a 0\n  b 1")
		errorOut_("tree with ab printed incorrectly",0);

	// 1 mark
	t.add("abcd");
	if (t.print() != "a 0\n  b 1\n    c 0\n      d 1")
		errorOut_("tree with ab and abcd printed incorrectly",1);

	passOut_();
}

// more complex print
void PxtreeTester::testk() {
	funcname_ = "PxtreeTester::testk";

	Pxtree t;
	createExampleTree(t);
	if (t.print() != "a 0\n  f 3\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 1\n    o 1\n      p 1\nb 2\n  i 1")
		errorOut_("bigger tree printed incorrectly",0);

	passOut_();
}

// simplest remove
void PxtreeTester::testl() {
	funcname_ = "PxtreeTester::testl";

	Pxtree t;
	t.add("a");
	t.remove("a");
	// 1 mark
	if (t.count("a") != 0) errorOut_("a count not 0 after remove",0);
	// 1 mark
	if (t.print() != "a 0") errorOut_("tree printed incorrectly after remove",1);

	passOut_();
}

// remove from empty tree; remove non-existent entry
void PxtreeTester::testm() {
	funcname_ = "PxtreeTester::testm";

	// 1 mark
	Pxtree t;
	t.remove("a");
	if (t.count("a") != 0) errorOut_("remove from empty tree incorrect",0);
	if (t.print() != "") errorOut_("remove from empty tree incorect print",0);

	// 1 mark
	Pxtree u;
	u.add("a");
	u.remove("b");
	if (u.count("a") != 1) errorOut_("a count incorrect after remove b",1);
	if (u.count("b") != 0) errorOut_("b count incorrect after remove b",1);
	if (u.print() != "a 1") errorOut_("tree printed incorrectly after remove b",1);

	passOut_();
}

// remove decrement count correctly; not below zero
void PxtreeTester::testn() {
	funcname_ = "PxtreeTester::testn";

	// 1 mark
	Pxtree t;
	t.add("ab"); t.add("ab");
	if (t.count("ab") != 2) errorOut_("ab count not 2 after 2 adds",0);
	t.remove("ab");
	if (t.count("ab") != 1) errorOut_("ab count not 1 after 1 remove",0);
	t.remove("ab");
	if (t.count("ab") != 0) errorOut_("ab count not 0 after 2 remove",0);
	// 1 mark
	t.remove("ab");
	if (t.count("ab") != 0) errorOut_("ab count not 0 after 3 remove",1);

	passOut_();
}

// more complex remove
void PxtreeTester::testo() {
	funcname_ = "PxtreeTester::testo";

	// 1 mark
	Pxtree t;
	createExampleTree(t);
	t.remove("agn");
	if (t.count("agn") != 0) errorOut_("agn count incorrect after remove",0);
	t.remove("ago");
	if (t.count("ago") != 0) errorOut_("ago count incorrect after remove",0);
	t.remove("agop");
	if (t.count("agop") != 0) errorOut_("agop count incorrect after remove",0);
	t.remove("agopq");
	if (t.count("agopq") != 0) errorOut_("agopq count incorrect after remove",0);
	t.remove("af");
	if (t.count("af") != 2) errorOut_("af count incorrect after remove",0);
	t.remove("bi");
	if (t.count("bi") != 0) errorOut_("bi count incorrect after remove", 0);
	t.remove("b");
	if (t.count("b") != 1) errorOut_("b count incorrect after remove", 0);

	// 1 mark
	Pxtree u;
	createExampleTree(u);
	u.remove("agn");
	if (u.print() != "a 0\n  f 3\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 1\n      p 1\nb 2\n  i 1")
		errorOut_("print incorrect after remove agn",1);
	u.remove("ago");
	if (u.print() != "a 0\n  f 3\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 1\nb 2\n  i 1")
		errorOut_("print incorrect after remove ago",1);
	u.remove("agop");
	if (u.print() != "a 0\n  f 3\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 0\nb 2\n  i 1")
		errorOut_("print incorrect after remove agop",1);
	u.remove("agopq");
	if (u.print() != "a 0\n  f 3\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 0\nb 2\n  i 1")
		errorOut_("print incorrect after remove agopq",1);
	u.remove("af");
	if (u.print() != "a 0\n  f 2\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 0\nb 2\n  i 1")
		errorOut_("print incorrect after remove af",1);
	u.remove("bi");
	if (u.print() != "a 0\n  f 2\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 0\nb 2\n  i 0")
		errorOut_("print incorrect after remove bi",1);
	u.remove("b");
	if (u.print() != "a 0\n  f 2\n    k 1\n    l 2\n      p 3\n    m 4\n  h 2\n  g 0\n    n 0\n    o 0\n      p 0\nb 1\n  i 0")
		errorOut_("print incorrect after remove bi",1);

	passOut_();
}

// basic copy con
void PxtreeTester::testp() {
	funcname_ = "PxtreeTester::testp";

	// 1 mark
	Pxtree t1;
	t1.add("a");
	Pxtree t2(t1);
	if (t2.count("a") != 1) errorOut_("copy does not have same count",0);
	if (t1.print() != t2.print()) errorOut_("copy print different",0);

	// 1 mark
	t1.add("a");
	if (t2.count("a") != 1) errorOut_("sticky copy count",1);
	if (t1.print() == t2.print()) errorOut_("sticky copy print",1);

	passOut_();
}

// copy con bigger tree
void PxtreeTester::testq() {
	funcname_ = "PxtreeTester::testq";

	// 1 mark
	Pxtree t1;
	createExampleTree(t1);
	Pxtree t2(t1);
	if (t2.count("a") != 0) errorOut_("a count incorrect in copy",0);
	if (t2.count("b") != 2) errorOut_("b count incorrect in copy",0);
	if (t2.count("c") != 0) errorOut_("c count incorrect in copy",0);
	if (t2.count("af") != 3) errorOut_("af count incorrect in copy",0);
	if (t2.count("ah") != 2) errorOut_("ah count incorrect in copy",0);
	if (t2.count("bi") != 1) errorOut_("bi count incorrect in copy",0);
	if (t2.count("afm") != 4) errorOut_("afm count incorrect in copy",0);
	if (t2.count("aflp") != 3) errorOut_("aflp count incorrect in copy",0);
	if (t2.count("ago") != 1) errorOut_("ago count incorrect in copy",0);
	if (t2.count("agop") != 1) errorOut_("agop count incorrect in copy",0);
	if (t2.print() != t1.print()) errorOut_("copy print different",0);

	// 1 mark
	t2.add("b");
	if (t1.count("b") != 2) errorOut_("sticky copy count",1);
	if (t1.print() == t2.print()) errorOut_("sticky copy print",1);

	passOut_();
}

// basic copy asg
void PxtreeTester::testr() {
	funcname_ = "PxtreeTester::testr";

	// 1 mark
	Pxtree t1;
	Pxtree t2;
	t1.add("a");
	t2 = t1;
	if (t2.count("a") != 1) errorOut_("count incorrect after copy",0);
	if (t1.print() != t2.print()) errorOut_("copy print different",0);

	// 1 mark
	t1.add("b");
	if (t2.count("b") != 0) errorOut_("sticky copy count",1);
	if (t1.print() == t2.print()) errorOut_("sticky copy print",1);

	passOut_();
}

// copy asg bigger tree; self-assign
void PxtreeTester::tests() {
	funcname_ = "PxtreeTester::tests";

	// 1 mark
	Pxtree t1;
	createExampleTree(t1);
	Pxtree t2;
	t2 = t1;
	if (t2.count("a") != 0) errorOut_("a count incorrect in copy",0);
	if (t2.count("b") != 2) errorOut_("b count incorrect in copy",0);
	if (t2.count("c") != 0) errorOut_("c count incorrect in copy",0);
	if (t2.count("af") != 3) errorOut_("af count incorrect in copy",0);
	if (t2.count("ah") != 2) errorOut_("ah count incorrect in copy",0);
	if (t2.count("bi") != 1) errorOut_("bi count incorrect in copy",0);
	if (t2.count("afm") != 4) errorOut_("afm count incorrect in copy",0);
	if (t2.count("aflp") != 3) errorOut_("aflp count incorrect in copy",0);
	if (t2.count("ago") != 1) errorOut_("ago count incorrect in copy",0);
	if (t2.count("agop") != 1) errorOut_("agop count incorrect in copy",0);
	if (t2.print() != t1.print()) errorOut_("copy print different",0);
	t2.add("bi");
	if (t1.count("bi") != 1) errorOut_("sticky copy count",0);
	if (t1.print() == t2.print()) errorOut_("sticky copy print",0);

	// 1 mark
	{
	Pxtree u;
	u.add("ab"); u.add("b");
	u = u;
	if (u.count("ab") != 1) errorOut_("self-assign lead to error",1);
	if (u.count("b") != 1) errorOut_("self-assign lead to error",1);
	u.remove("ab"); u.remove("b");
	if (u.count("ab") != 0) errorOut_("self-assign lead to error",1);
	if (u.count("b") != 0) errorOut_("self-assign lead to error",1);
	}

	passOut_();
}

// mem test
void PxtreeTester::testt() {
	funcname_ = "PxtreeTester::testt";

	for(int i = 0; i < 10; i++) {

		Pxtree t;
		t.add("aa"); t.add("b"); t.print();
		t.remove("aa"); t.print();

		for(int j=0; j<10; j++) {
			int *p = new int[10];
			delete p;
		}

		Pxtree u;
		createExampleTree(u);
		u.remove("a"); u.remove("agop"); u.print();

		for(int j=0; j<10; j++) {
			int *p = new int[10];
			delete p;
		}
	}

	passOut_();
}

// simple autocomplete
void PxtreeTester::testu() {
	funcname_ = "PxtreeTester::testu";

	Pxtree t;
	t.add("a");
	t.add("ab"); t.add("ab"); t.add("ab");
	t.add("ac"); t.add("ac");
	if (t.autoComplete("a") != "ab")
		errorOut_("autocomplete should return ab",0);

	passOut_();
}

// bigger autocomplete
void PxtreeTester::testv() {
	funcname_ = "PxtreeTester::testv";

	Pxtree t;
	createExampleTree(t);

	// 1 mark
	if (t.autoComplete("a") != "afm") errorOut_("a autocomplete incorrect",0);
	if (t.autoComplete("af") != "afm") errorOut_("af autocomplete incorrect",0);
	if (t.autoComplete("afl") != "aflp") errorOut_("afl autocomplete incorrect",0);

	// 1 mark
	if (t.autoComplete("b") != "b") errorOut_("b autocomplete incorrect",1);
	if (t.autoComplete("c") != "c") errorOut_("c autocomplete incorrect",1);

	passOut_();
}

// simplest compact; nothing to compact
void PxtreeTester::testw() {
	funcname_ = "PxtreeTester::testw";

	// 1 mark
	Pxtree t;
	t.add("a");
	string s = t.print();
	t.add("ab"); t.remove("ab");
	t.compact();
	if (t.print() != s) errorOut_("simple compact wrong",0);
	if (t.count("ab") != 0) errorOut_("compact corrupts count",0);

	// 1 mark
	Pxtree u;
	u.add("ab"); u.add("c");
	s = u.print();
	u.compact();
	if (u.print() != s) errorOut_("compact made changes when it shouldn't",1);

	passOut_();
}

// remove leftmost or rightmost child;
// multiple 0 along the path simul compact
void PxtreeTester::testx() {
	funcname_ = "PxtreeTester::testx";

	// 1 mark
	Pxtree t;
	t.add("ab"); t.add("abc"); t.add("abd"); t.add("abe");
	t.remove("abc");
	t.compact();
	if (t.print() != "a 0\n  b 1\n    d 1\n    e 1")
		errorOut_("compact incorrect after abc removed",0);
	t.remove("abe");
	t.compact();
	if (t.print() != "a 0\n  b 1\n    d 1")
		errorOut_("compact incorrect after abe removed",0);
	t.remove("abd");
	t.compact();
	if (t.print() != "a 0\n  b 1")
		errorOut_("compact incorrect after abd removed",0);

	// 1 mark
	Pxtree u;
	u.add("a"); u.add("ab"); u.add("abc"); u.add("abcd");
	u.remove("a"); u.remove("abc"); u.remove("abcd");
	u.compact();
	if (u.print() != "a 0\n  b 1") errorOut_("simul compact along path incorrect",1);

	passOut_();
}

// multiple things to compact
// compact to nothing
void PxtreeTester::testy() {
	funcname_ = "PxtreeTester::testy";

	// 1 mark
	Pxtree t;
	t.add("ab"); t.add("abc"); t.add("abcd");
	t.add("x"); t.add("xyz");

	t.remove("abc"); t.remove("abcd");
	t.remove("xyz");
	t.compact();
	if (t.print() != "a 0\n  b 1\nx 1")
		errorOut_("incorrect when 2 branches to compact",0);

	// 1 mark
	t.remove("ab"); t.remove("x");
	t.compact();
	if (t.print() != "") errorOut_("compact to empty tree incorrect",1);

	passOut_();
}

void PxtreeTester::createExampleTree(Pxtree& t) {

	t.add("af"); t.add("af");
	t.add("ah");
	t.add("agn");
	t.add("ah");
	t.add("afk");
	t.add("afl"); t.add("afl");
	t.add("aflp"); t.add("aflp"); t.add("aflp");
	t.add("afm"); t.add("afm");
	t.add("agop");
	t.add("ago");
	t.add("b"); t.add("b");
	t.add("bi");
	t.add("af");
	t.add("afm"); t.add("afm");
}

void PxtreeTester::errorOut_(const string& errMsg, unsigned int errBit) {

	cerr << funcname_ << ":" << " fail";
	cerr << errBit;
	cerr << ": " << errMsg << endl;
	error_ |= (1<<errBit);
	cerr << std::flush;
}

void PxtreeTester::passOut_() {

	if (!error_) {
		cerr << funcname_ << ":" << " pass" << endl;
	}
	cerr << std::flush;
}