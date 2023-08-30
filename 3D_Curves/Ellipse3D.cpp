#include "Ellipse3D.h"

ellipse3D::ellipse3D()
{
	a = b = c = 0.0;
}

ellipse3D::ellipse3D(double A, double B, double C)
{
	a = A;
	b = B;
	c = C;
}

ellipse3D::ellipse3D(ellipse3D& other)
{
	a = other.a;
	b = other.b;
	c = other.c;
}

ellipse3D& ellipse3D::operator=(ellipse3D const& other)
{
	a = other.a;
	b = other.b;
	c = other.c;
	return *this;
}

void ellipse3D::FunctionInPoint(std::vector<double>& InPoint, double t, double u)
{
	InPoint[0] = a * cos(u) * cos(t);
	InPoint[1] = b * cos(u) * sin(t);
	InPoint[2] = c * sin(u);
}

void ellipse3D::DerivativeInPoint(std::vector<double>& InPoint, double t, double u, double h, char letter)
{
	if (letter == 'l')
	{
		InPoint[0] = (a * (cos(u) * cos(t) - cos(u) * cos(t-h))) / h;
		InPoint[1] = (a * (cos(u) * sin(t) - cos(u) * sin(t-h))) / h;
		InPoint[2] = 0.0;
	}
	if (letter == 'r')
	{
		InPoint[0] = (a * (cos(u) * cos(t + h) - cos(u) * cos(t))) / h;
		InPoint[1] = (a * (cos(u) * sin(t + h) - cos(u) * sin(t))) / h;
		InPoint[2] = 0.0;
	}
	if (letter == 'c')
	{
		InPoint[0] = (a * (cos(u) * cos(t + h) - cos(u) * cos(t - h))) / (2.0 * h);
		InPoint[1] = (a * (cos(u) * sin(t + h) - cos(u) * sin(t - h))) / (2.0 * h);
		InPoint[2] = 0.0;
	}
}

double ellipse3D::getA()
{
	return a;
}

double ellipse3D::getB()
{
	return b;
}

double ellipse3D::getC()
{
	return c;
}
