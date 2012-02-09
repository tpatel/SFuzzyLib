#include <iostream>
#include <cassert>
#include "Range.h"

using namespace std;

int main() {
	cout << "Beginning of the tests" << endl;
	
	Range r(0.2, 1, 2, 3, 10);
	
	assert(r.getBegin()==0.2);
	assert(r.getKernelBegin()==1);
	assert(r.getKernelEnd()==2);
	assert(r.getEnd()==3);
	
	assert(r.getValue(0.6)==5.);
	assert(r.getValue(2.25)==7.5);
	
	cout << "Tests succeded !" << endl;
}	
