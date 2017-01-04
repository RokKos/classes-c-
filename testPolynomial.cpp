#include <iostream>
using std::cout;
using std::endl;
#include "polynomial.hpp"

int main() {
	int degre1 = 3;
	double* coef1 = new double[degre1 + 1];
	for (int i = 0; i < degre1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	Polynomial pol1(degre1, coef1);
	Polynomial pol2(pol1);
	Polynomial pol3 = pol1;
	cout << "Degre of pol3: " << pol3.getDegree() << endl;
	cout << "pol2 a_2: " << pol2[2] << endl;
	cout << pol1 << endl;


	delete[] coef1;
	return 0;
}
