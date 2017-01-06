#include "polynomial.hpp"

Polynomial::Polynomial(int _degree, double* _coeffcients){
	assert(this->degree>=0);
	this->degree = _degree;
	coeffcients = new double[_degree + 1];  // there is n+1 coeffcients
	for (int i = 0; i < _degree + 1; ++i) {
		coeffcients[i] = _coeffcients[i];
	}
}

Polynomial::Polynomial(const Polynomial& rhs){
	assert(rhs.getDegree()>=0);
	this->degree = rhs.getDegree();
	coeffcients = new double[this->degree + 1];
	for (int i = 0; i < this->degree + 1; ++i) {
		coeffcients[i] = rhs[i];
	}
}

Polynomial::~Polynomial(){
	if (this->degree > 0) {
		delete[] coeffcients;
	}
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	int newDegre = rhs.getDegree();
	// Check if size has changed
	if (this->degree != newDegre) {
		this->degree = newDegre;
		if (this->degree == 0) {
			coeffcients = (double*) NULL;
		} else {
			// Erase previus array and create new one
			delete[] coeffcients;
			coeffcients = new double[this->degree + 1];
		}
	}
	// If size didn't changed then just overvrite previus values
	for (int i = 0; i < this->degree + 1; ++i) {
		coeffcients[i] = rhs[i];
	}
	return *this;
}

const double& Polynomial::operator[](int i) const{
	assert(i>=0 && i <= this->degree);
	return coeffcients[i];
}

double& Polynomial::operator[](int i) {
	assert(i>=0 && i <= this->degree);
	return coeffcients[i];
}

int Polynomial::getDegree() const{
	return this->degree;
}

std::ostream& operator<<(std::ostream& output, const Polynomial& x) {
	int n = x.getDegree();
	output << "Degree: " << n << " \n";
	output << "Coeffcients: ";
	for (int i = 0; i < n + 1; ++i) {
		output << x[i] << " ";
	}
	return output;
}

const Polynomial operator+(const Polynomial& rhs1, const Polynomial& rhs2) {
	Polynomial result(rhs1);
	if (rhs1.getDegree() < rhs2.getDegree()) {
		result = rhs2;
		for (int i = 0; i < rhs1.getDegree()+1; ++i) {
			result[i] += rhs1[i];
		}
	} else {
		for (int i = 0; i < rhs2.getDegree()+1; ++i) {
			result[i] += rhs2[i];
		}
	}
	return result;
}

const Polynomial operator+(const Polynomial& rhs1, const double c) {
	Polynomial result(rhs1);
	result[0] += c;
	return result;
}

const Polynomial operator+(const double c, const Polynomial& rhs1) {
	Polynomial result(rhs1);
	result[0] += c;
	return result;
}

const Polynomial operator+(const Polynomial& rhs1, const int c) {
	Polynomial result(rhs1);
	result[0] += c;
	return result;
}

const Polynomial operator+(const int c, const Polynomial& rhs1) {
	Polynomial result(rhs1);
	result[0] += c;
	return result;
}

const Polynomial operator*(const Polynomial& rhs1, const Polynomial& rhs2) {
	int newDegree = rhs1.getDegree() + rhs2.getDegree();
	double* newCoef = new double[newDegree+1];
	for (int i = 0; i < newDegree + 1; ++i) {
		newCoef[i] = 0;
	}

	Polynomial result(newDegree, newCoef);

	for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
		for (int j = 0; j < rhs2.getDegree() + 1; ++j) {
			result[i+j] += rhs1[i] * rhs2[j];
		}
	}

	return result;
}

const Polynomial operator*(const Polynomial& rhs1, const double c) {
	Polynomial result(rhs1);
	for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
		result[i] *= c;
	}
	return result;
}

const Polynomial operator*(const double c, const Polynomial& rhs1) {
	Polynomial result(rhs1);
	for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
		result[i] *= c;
	}
	return result;
}

const Polynomial operator*(const Polynomial& rhs1, const int c) {
	Polynomial result(rhs1);
	for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
		result[i] *= c;
	}
	return result;
}

const Polynomial operator*(const int c, const Polynomial& rhs1) {
	Polynomial result(rhs1);
	for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
		result[i] *= c;
	}
	return result;
}

Polynomial& Polynomial::operator()(const int k) {
	assert(k >= 0);
	int newDegree = this->degree - k;
	double* newCoef = new double[newDegree + 1];
	for (int i = k; i < this->degree + 1; ++i) {
		// Set on rigth position
		newCoef[i - k] = coeffcients[i];
		double t = 1;
		for (int j = i - k + 1; j < i + 1; ++j) {
			t *= j;
		}
		// Multyplay by all derivates
		newCoef[i - k] *= t;
	}
	delete[] coeffcients;
	// Copy over new coefficients
	coeffcients = new double[newDegree + 1];
	for (int i = 0; i < newDegree + 1; ++i) {
		coeffcients[i] = newCoef[i];
	}
	this->degree = newDegree;
	return *this;
}

const double Polynomial::operator()(const int k, const double x) {
	assert(k >= 0);
	int newDegree = this->degree - k;
	double* newCoef = new double[newDegree + 1];
	for (int i = k; i < this->degree + 1; ++i) {
		// Set on rigth position
		newCoef[i - k] = coeffcients[i];
		double t = 1;
		for (int j = i - k + 1; j < i + 1; ++j) {
			t *= j;
		}
		// Multyplay by all derivates
		newCoef[i - k] *= t;
	}
	double result = 0;
	for (int i = 0; i < newDegree + 1; ++i) {
		result += newCoef[i] * pow(x, i);
	}
	return result;
}
