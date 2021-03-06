#include "polynomial.hpp"

Polynomial::Polynomial() {
  this->degree = 0;
  coeffcients = new double[1];
  coeffcients[0] = 0;
}

Polynomial::Polynomial(int _degree, double* _coeffcients) {
  assert(_degree >= 0);
  this->degree = _degree;
  coeffcients = new double[_degree + 1];  // there is n+1 coeffcients
  for (int i = 0; i < _degree + 1; ++i) {
    coeffcients[i] = _coeffcients[i];
  }
}

Polynomial::Polynomial(const Polynomial& rhs) {
  assert(rhs.getDegree() >= 0);
  this->degree = rhs.getDegree();
  coeffcients = new double[this->degree + 1];
  for (int i = 0; i < this->degree + 1; ++i) {
    coeffcients[i] = rhs[i];
  }
}

Polynomial::~Polynomial() {
  if (this->degree > 0) {
    delete[] coeffcients;
  }
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
  int newDegre = rhs.getDegree();
  // Check if size has changed
  if (this->degree != newDegre) {
    this->degree = newDegre;
    // Erase previus array and create new one
    delete[] coeffcients;
    coeffcients = new double[this->degree + 1];
  }
  // If size didn't changed then just overvrite previus values
  for (int i = 0; i < this->degree + 1; ++i) {
    coeffcients[i] = rhs[i];
  }
  return *this;
}

const double& Polynomial::operator[](int i) const {
  assert(i >= 0 && i <= this->degree);
  return coeffcients[i];
}

// Because it is not constant reference and method is also not constant
// You get reference to value and you can read and also write into this variable
double& Polynomial::operator[](int i) {
  assert(i >= 0 && i <= this->degree);
  return coeffcients[i];
}

int Polynomial::getDegree() const { return this->degree; }

std::ostream& operator<<(std::ostream& output, const Polynomial& x) {
  int n = x.getDegree();
  output << "Degree: " << n << " \n";
  output << "Coeffcients: ";
  for (int i = 0; i < n + 1; ++i) {
    output << x[i] << "x^" << i << " ";
  }
  return output;
}

const Polynomial operator+(const Polynomial& rhs1, const Polynomial& rhs2) {
  Polynomial result(rhs1);
  if (rhs1.getDegree() < rhs2.getDegree()) {
    result = rhs2;
    for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
      result[i] += rhs1[i];
    }
  } else {
    for (int i = 0; i < rhs2.getDegree() + 1; ++i) {
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
  double* newCoef = new double[newDegree + 1];
  for (int i = 0; i < newDegree + 1; ++i) {
    newCoef[i] = 0;
  }

  Polynomial result(newDegree, newCoef);

  for (int i = 0; i < rhs1.getDegree() + 1; ++i) {
    for (int j = 0; j < rhs2.getDegree() + 1; ++j) {
      result[i + j] += rhs1[i] * rhs2[j];
    }
  }
  // Clean dinamycal array so that doesnt come to the memory leak
  delete[] newCoef;

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

const Polynomial Polynomial::operator()(const int k) const {
  assert(k >= 0);

  if (k > this->degree) {
    // Corner case
    Polynomial p;
    return p;
  }

  int newDegree = this->degree - k;
  double* newCoef = new double[newDegree + 1];
  for (int i = k; i < this->degree + 1; ++i) {
    // Set on rigth position
    newCoef[i - k] = coeffcients[i];
    double t = 1;
    for (int j = i - k + 1; j < i + 1; ++j) {
      t *= j;
    }
    // Multiply by all derivates
    newCoef[i - k] *= t;
  }
  // Create new Polynom and return it
  Polynomial result(newDegree, newCoef);
  delete[] newCoef;

  return result;
}

const double Polynomial::operator()(const int k, const double x) const {
  assert(k >= 0);

  if (k > this->degree) {
    return 0;
  }

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
  delete[] newCoef;
  return result;
}

const double Polynomial::computeZero(double x) const {
  const double tolerance = 0.000000001;  // 10^-9
  double valueOfPolynom = 0.0;
  double valueOfDerivate = 0.0;
  while (true) {
    valueOfPolynom = (*this)(0, x);
    valueOfDerivate = (*this)(1, x);
    if (fabs(valueOfPolynom) <= tolerance ||
        fabs(valueOfDerivate) <= tolerance) {
      break;
    }
    x = x - valueOfPolynom / valueOfDerivate;
  }
  // If value of dervate is smaller than tolerance then result is not valid
  assert(!(fabs(valueOfDerivate) <= tolerance) &&
         !(fabs(valueOfDerivate) <= fabs(valueOfPolynom)));
  // If passes this assert then result is valid
  return x;
}
