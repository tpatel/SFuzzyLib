#ifndef TERM_H
#define TERM_H

#include <string>
#include <vector>
#include "Range.h"

class Term {
	public:
		Term(std::string name, Range* range);
		Term(std::string name, Range* range, double adaptationCoef);
		virtual ~Term();
		
		void addRange(Range* range);
		void addRange(double begin, double kernelBegin,
					  double kernelEnd, double end,
					  double highValue);
		std::string getName();
		double getAdaptationCoef();
		Range* getRange(int index);
		
		double getValue(double x);
		
		void addAdaptationCoef(double coef);
		void computeAdapationCoef(double x);
		
	private:
		std::string name;
		std::vector<Range*> ranges;
		double adaptationCoef;
};

#endif
