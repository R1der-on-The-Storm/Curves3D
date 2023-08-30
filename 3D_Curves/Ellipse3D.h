#include "Shapes3D.h"
#pragma once
class ellipse3D : public shapes3D {
	double a;
	double b;
	double c;
public:
	ellipse3D();
	ellipse3D(double A, double B, double C);
	ellipse3D(ellipse3D& other);
	ellipse3D& operator=(ellipse3D const& other);
	void FunctionInPoint(std::vector<double>& InPoint, double t, double u ) override;
	void DerivativeInPoint(std::vector<double>& InPoint, double t, double u, double h, char letter) override;
	double getA() override;
	double getB() override;
	double getC() override;
};

// parametric equation of ellipse
// x(t,u)=a*cos(u)*cos(t)
// y(t,u)=b*cos(u)*sin(t)
// z(t,u)=c*sin(u)