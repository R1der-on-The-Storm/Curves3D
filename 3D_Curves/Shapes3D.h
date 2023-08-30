#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include <algorithm>
class shapes3D {
public:
	virtual void FunctionInPoint(std::vector<double>& InPoint, double t, double u) = 0;
	virtual void DerivativeInPoint(std::vector<double>& InPoint, double t, double u, double h, char letter) = 0;
	virtual double getA() = 0;
	virtual double getB() = 0;
	virtual double getC() = 0;
};