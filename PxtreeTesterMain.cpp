#include <iostream>
//#include <string>
#include "PxtreeTester.h"

//using std::cin;
using std::cout;
using std::endl;
//using std::string;

int main(int argc, char* argv[]) {

	for(int i=1; i<argc; i++) {
		switch (argv[i][0]) {
		case 'a': { PxtreeTester t; t.testa(); } break;
		case 'b': { PxtreeTester t; t.testb(); } break;
		case 'c': { PxtreeTester t; t.testc(); } break;
		case 'd': { PxtreeTester t; t.testd(); } break;
		case 'e': { PxtreeTester t; t.teste(); } break;
		case 'f': { PxtreeTester t; t.testf(); } break;
		case 'g': { PxtreeTester t; t.testg(); } break;
		case 'h': { PxtreeTester t; t.testh(); } break;
		case 'i': { PxtreeTester t; t.testi(); } break;
		case 'j': { PxtreeTester t; t.testj(); } break;
		case 'k': { PxtreeTester t; t.testk(); } break;
		case 'l': { PxtreeTester t; t.testl(); } break;
		case 'm': { PxtreeTester t; t.testm(); } break;
		case 'n': { PxtreeTester t; t.testn(); } break;
		case 'o': { PxtreeTester t; t.testo(); } break;
		case 'p': { PxtreeTester t; t.testp(); } break;
		case 'q': { PxtreeTester t; t.testq(); } break;
		case 'r': { PxtreeTester t; t.testr(); } break;
		case 's': { PxtreeTester t; t.tests(); } break;
		case 't': { PxtreeTester t; t.testt(); } break;
		case 'u': { PxtreeTester t; t.testu(); } break;
		case 'v': { PxtreeTester t; t.testv(); } break;
		case 'w': { PxtreeTester t; t.testw(); } break;
		case 'x': { PxtreeTester t; t.testx(); } break;
		case 'y': { PxtreeTester t; t.testy(); } break;
		default: { cout<<"Options are a -- y."<<endl; } break;
	       	}
	}
	return 0;
}
