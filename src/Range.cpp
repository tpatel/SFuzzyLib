#include "Range.h"

Range::Range(double begin, double kernelBegin, double kernelEnd, double end,
			double highValue) {
	this->begin = begin;
	this->kernelBegin = kernelBegin;
	this->kernelEnd = kernelEnd;
	this->end = end;
	this->highValue = highValue;
}

Range::~Range() {
	
}

double Range::getValue(double x) {
	double res;
	if(x < begin || x > end) {
		res = 0;
	} else if(x >= kernelBegin && x <= kernelEnd) {
		res = highValue;
	} else if(x >= begin && x <= kernelBegin) { //Descending slope
		res = (x-begin) * highValue / (kernelBegin-begin);
	} else { //Ascending slope
		res = (-x+end) * highValue / (end-kernelEnd);
	}
	return res;
}

double Range::getBegin() {
	return begin;
}

double Range::getKernelBegin() {
	return kernelBegin;
}

double Range::getKernelEnd() {
	return kernelEnd;
}

double Range::getEnd() {
	return end;
}
