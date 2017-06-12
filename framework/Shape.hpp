#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <math.h>

class Shape{
	public:
	virtual float area(int a, int b, int c) = 0;
	virtual float volume(int a, int b, int c) = 0;
};

#endif
