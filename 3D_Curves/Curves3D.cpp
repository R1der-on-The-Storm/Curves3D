#include "Curves3D.h"

curves3D::curves3D()
{
	a = b = 0.0;
}

curves3D::curves3D(double A, double B)
{
	a = A;
	b = B;
}

curves3D::curves3D(curves3D& other)
{
	a = other.a;
	b = other.b;
}

curves3D& curves3D::operator=(curves3D const& other)
{
	a = other.a;
	b = other.b;
	return *this;
}

void curves3D::FunctionInPoint(std::vector<double>& InPoint, double t, double u)
{
	InPoint[0] = a * cos(t);
	InPoint[1] = a * sin(t);
	InPoint[2] = b * t;
}

void curves3D::DerivativeInPoint(std::vector<double>& InPoint, double t, double u, double h, char letter)
{
	if (letter == 'l')
	{
		InPoint[0] = (a * (cos(t) - cos(t - h))) / h;
		InPoint[1] = (a * (sin(t) - sin(t - h))) / h;
		InPoint[2] = (b * t - b * (t - h)) / h;
	}
	if (letter == 'r')
	{
		InPoint[0] = (a * (cos(t + h) - cos(t))) / h;
		InPoint[1] = (a * (sin(t + h) - sin(t))) / h;
		InPoint[2] = (b * (t + h) - b * t) / h;
	}
	if (letter == 'c')
	{
		InPoint[0] = (a * (cos(t + h) - cos(t - h))) / (2.0 * h);
		InPoint[1] = (a * (sin(t + h) - sin(t - h))) / (2.0 * h);
		InPoint[2] = (b * (t + h) - b * (t - h)) / (2.0 * h);
	}
}

double curves3D::getA()
{
	return a;
}

double curves3D::getB()
{
	return b;
}

double curves3D::getC()
{
	return c;
}
