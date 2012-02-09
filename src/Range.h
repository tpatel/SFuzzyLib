#ifndef RANGE_H
#define RANGE_H

class Range {
	public:
		Range(double begin, double kernelBegin, double kernelEnd, double end,
			double highValue);
		virtual ~Range();

		double getBegin();
		double getKernelBegin();
		double getKernelEnd();
		double getEnd();
		
		double getValue(double x);
		
	private:
		double begin, kernelBegin, kernelEnd, end;
		double highValue;
};

#endif
