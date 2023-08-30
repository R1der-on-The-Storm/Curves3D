#include "Shapes3D.h"
#pragma once
class curves3D : public shapes3D {
	double a;
	double b;
	double c = 0.0;
public:
	curves3D();
	curves3D(double A, double B);
	curves3D(curves3D& other);
	curves3D& operator=(curves3D const& other);
	void FunctionInPoint(std::vector<double>& InPoint, double t, double u=0.0) override;
	void DerivativeInPoint(std::vector<double>& InPoint, double t, double u, double h, char letter) override;
	double getA() override;
	double getB() override;
	double getC() override;
};

// parametric equation of curve
// x(t)=a*cos(t)
// y(t)=a*sin(t)
// z(t)=b*t