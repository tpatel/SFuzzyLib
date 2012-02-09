#include <string>
#include <iostream>
#include "Range.h"
#include "Term.h"

using namespace std;

Term::Term(string name, Range* range, double adapationCoef) :
		name(name), adaptationCoef(adaptationCoef) {
	addRange(range);
}

Term::Term(string name, Range* range) :
		name(name) {
	addRange(range);
}

Term::~Term() {
	for(unsigned int i=0; i<ranges.size(); i++) {
		delete ranges.at(i);
	}
}

void Term::addRange(Range* range) {
	if(range != NULL) {
		ranges.push_back(range);
	}
}

void Term::addRange(double begin, double kernelBegin,
		double kernelEnd, double end,
		double highValue) {
	ranges.push_back(new Range(begin, kernelBegin,
		kernelEnd, end, highValue));
}
string Term::getName() {
	return name;
}

double Term::getAdaptationCoef() {
	return adaptationCoef;
}

Range* Term::getRange(int index) {
	return ranges.at(index);
}

double Term::getValue(double x) {
	double max = 0;
	for (unsigned int i = 0; i < ranges.size(); i++) {
		double val = ranges.at(i)->getValue(x);
		if(val > max) {
			max = val;
		}
	}
	return max;
}

void Term::addAdaptationCoef(double coef) {
	if(coef > adaptationCoef) {
		adaptationCoef = coef;
	}
}

void Term::computeAdapationCoef(double x) {
	if(ranges.size() != 1) {
		cerr << "E: Can't compute an adaptation coef when a term has more than one range." << endl;
	} else {
		adaptationCoef = ranges.at(0)->getValue(x);
	}
}
