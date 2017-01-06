#include <iostream>
using std::cout;
using std::endl;
#include "polynomial.hpp"

int main() {
	//10.1
	int degre1 = 3;
	int degre2 = 2;
	double* coef1 = new double[degre1 + 1];
	double* coef2 = new double[degre2 + 1];
	for (int i = 0; i < degre1 + 1; ++i) {
		coef1[i] = i + 1;
	}
	for (int i = 0; i < degre2 + 1; ++i) {
		coef2[i] = i + 1;
	}
	Polynomial pol1(degre1, coef1);
	Polynomial pol2(pol1);
	Polynomial pol3 = pol1;
	cout << "Degre of pol3: " << pol3.getDegree() << endl;
	cout << "pol2 a_2: " << pol2[2] << endl;
	cout << pol1 << endl;
	//10.2
	Polynomial pol4 = pol1 + pol2;
	Polynomial pol5(degre2, coef2);
	cout << pol4 << endl;
	pol4 = pol4 + 2.5;
	cout << pol4 << endl;
	pol4 = 2.5 + pol4;
	cout << pol4 << endl;
	pol4 = pol4 + 2;
	cout << pol4 << endl;
	pol4 = 2 + pol4;
	cout << pol4 << endl;
	pol4 = pol4 + pol5;
	cout << pol4 << endl;
	//10.3
	Polynomial pol6 = pol1 * pol2;
	cout << pol6 << endl;
	cout << pol4 * pol2 << endl;
	cout << pol5 * pol1 << endl;
	cout << pol1 * 2.3 << endl;
	cout << pol1 * 3 << endl;
	cout <<  2.5 * pol1  << endl;
	cout <<  3 * pol1  << endl;
	delete[] coef1;
	delete[] coef2;
	return 0;
}
