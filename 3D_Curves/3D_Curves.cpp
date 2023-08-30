#include "Shapes3D.h"
#include "Curves3D.h"
#include "Ellipse3D.h"

double Pi = acos(-1.0);
double epsilon = 1e-13;

double summ_of_all_radii_seq(std::vector< ellipse3D*> vec) {
	double summ = 0.0;
	for (int i = 0; i < vec.size(); ++i) {
		summ += (*vec[i]).getA();
	}
	return summ;
}

double summ_of_all_radii_omp(std::vector< ellipse3D*> vec) {
	double total_summ = 0.0;

	omp_set_num_threads(3);
#pragma omp parallel
	{
#pragma omp for reduction(+:total_summ)
		for (int i = 0; i < vec.size(); ++i)
			total_summ += (*vec[i]).getA();
	}
	return total_summ;
}

void vec_sort(std::vector< ellipse3D*>& vec)
{
	sort(vec.begin(), vec.end(), [](ellipse3D* A, ellipse3D* B) {
		return (*A).getA() < (*B).getA();
		});
}

int main()
{
	srand(time(NULL));

	int n = 719;

	std::vector<std::pair<curves3D, ellipse3D>> vec(n);
	for (int i = 0; i < n; ++i) {
		if ((i + 1) % 3 == 0) {
			vec[i].first = curves3D(static_cast<double>(rand() % 100) / 10.0, static_cast<double>(rand() % 100) / 10.0);
			vec[i].second = ellipse3D(static_cast<double>(n - i + 2) / 10.0, static_cast<double>(n - i + 2) / 10.0, static_cast<double>(n - i + 2) / 10.0);
		}

		else {
			vec[i].first = curves3D(static_cast<double>(rand() % 100) / 10.0, static_cast<double>(rand() % 100) / 10.0);
			vec[i].second = ellipse3D(static_cast<double>(rand() % 10), static_cast<double>(rand() % 10), static_cast<double>(rand() % 10));
		}
	}

	std::vector<double> InPoint(3);

	for (int i = 0; i < n; ++i) {
		vec[i].first.FunctionInPoint(InPoint, Pi / 4.0);
		std::cout << "curve at value of parameter t=Pi/4 x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
		vec[i].first.DerivativeInPoint(InPoint, Pi / 4.0, Pi / 4.0, epsilon, 'c');
		std::cout << "derivative of parameter t of curve at the point x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
		std::cout << "\n";

		if (abs(vec[i].second.getA() - vec[i].second.getB()) <= epsilon && abs(vec[i].second.getB() - vec[i].second.getC()) <= epsilon && vec[i].second.getA() > 0.0) {
			vec[i].second.FunctionInPoint(InPoint, Pi / 4.0, Pi / 4.0);
			std::cout << "sphere at value of parameter t=Pi/4 u=Pi/4 x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
			vec[i].second.DerivativeInPoint(InPoint, Pi / 4.0, Pi / 4.0, epsilon, 'c');
			std::cout << "derivative of parameter t of sphere at the point t=Pi/4 u=Pi/4 x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
			std::cout << "\n";
		}
		else {
			vec[i].second.FunctionInPoint(InPoint, Pi / 4.0, Pi / 4.0);
			std::cout << "ellipse at value of parameter t=Pi/4 u=Pi/4 x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
			vec[i].second.DerivativeInPoint(InPoint, Pi / 4.0, Pi / 4.0, epsilon, 'c');
			std::cout << "derivative of parameter t of ellipse at the point t=Pi/4 u=Pi/4 x=" << InPoint[0] << "\t y=" << InPoint[1] << "\t z=" << InPoint[2] << "\n";
			std::cout << "\n";
		}
	}

	std::vector<ellipse3D*> vec2;

	for (int i = 0; i < n; ++i) {
		if (abs(vec[i].second.getA() - vec[i].second.getB()) <= epsilon && abs(vec[i].second.getB() - vec[i].second.getC()) <= epsilon && vec[i].second.getA() > 0.0) {
			vec2.push_back(&vec[i].second);
		}
	}

	vec_sort(vec2);

	std::cout << "summ of all radii seq " << summ_of_all_radii_seq(vec2) << "\n";

	std::cout << "summ of all radii omp " << summ_of_all_radii_omp(vec2) << "\n";
}