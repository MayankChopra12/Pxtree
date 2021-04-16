#ifndef PXTREETESTER_H_
#define PXTREETESTER_H_

#include <string>
#include "Pxtree.h"

class PxtreeTester {
public:
	PxtreeTester();

	// ctor dtor
	void testa();

	// add
	void testb();
	void testc();
	void testd();
	void teste();
	void testf();

	// print
	void testg();
	void testh();
	void testi();
	void testj();
	void testk();

	// remove
	void testl();
	void testm();
	void testn();
	void testo();

	// copy con, asg
	void testp();
	void testq();
	void testr();
	void tests();

	// mem test
	void testt();

	// autocomplete
	void testu();
	void testv();

	// compact
	void testw();
	void testx();
	void testy();

private:
	void errorOut_(const std::string& errMsg, unsigned int errBit);
	void passOut_();

	void createExampleTree(Pxtree& t);

	char error_;
	std::string funcname_;
};

#endif /* PXTREETESTER_H_ */