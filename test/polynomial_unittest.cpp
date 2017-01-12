#include <climits> // Including max and min values for tipes

#include "gtest/gtest.h"
#include "polynomial.hpp"

// To use a test fixture, derive a class from testing::Test.
class PolynomialTest : public testing::Test {
// Members are protected so that they can be accessed from sub-classes
protected:
	// Declares the variables your tests want to use.
	int degree1 = 3;
	int degree2 = 2;
	double* coef1;
	double* coef2;
	double* coef3;
	// Polinoms
	Polynomial polinom1;
	Polynomial polinom2;
	Polynomial polinom3;

	PolynomialTest () {

	}

	// virtual void SetUp() will be called before each test is run.  You
  	// should define it if you need to initialize the varaibles.
  	// Otherwise, this can be skipped.
  	virtual void SetUp() {
		degree1 = 3;
		degree2 = 2;
		coef1 = new double[degree1 + 1];
		coef2 = new double[degree2 + 1];
		for (int i = 0; i < degree1 + 1; ++i) {
			coef1[i] = i + 1;
		}
		for (int i = 0; i < degree2 + 1; ++i) {
			coef2[i] = i + 1;
		}

		coef3 = new double[1];
		coef3[0] = 1.0;
		coef2[0] = -2;

		// Work around because Polynoms must be first initialize and then set
		Polynomial p1(degree1, coef1);
		Polynomial p2(degree2, coef2);
		Polynomial p3(0,coef3);
		polinom1 = p1;
		polinom2 = p2;
		polinom3 = p3;
	}

	// TearDown() is invoked immediately after a test finishes.  Here we
  	virtual void TearDown() {
		delete[] coef1;
		delete[] coef2;
		delete[] coef3;
	}

	~PolynomialTest() {

	}

};

TEST_F (PolynomialTest, GetDegree) {
	// We dont look at the coeficient so that doesnt matter now
	ASSERT_EQ(3, polinom1.getDegree());
	ASSERT_EQ(2, polinom2.getDegree());
	ASSERT_EQ(0, polinom3.getDegree());
	Polynomial polinom4(5, coef1);
	ASSERT_EQ(5, polinom4.getDegree());
	Polynomial polinom5(100, coef1);
	ASSERT_EQ(100, polinom5.getDegree());
	Polynomial polinom6(1000, coef1);
	ASSERT_EQ(1000, polinom6.getDegree());
	// Big number doesnt work because there is to much space to alocate
	//Polynomial polinom7(100, coef1);
	//ASSERT_EQ(100, polinom7.getDegree());

}

TEST_F (PolynomialTest, GetCoefficient) {
	for (int i = 0; i < degree1 + 1; ++i) {
		ASSERT_EQ(coef1[i], polinom1[i]);
	}
	for (int i = 0; i < degree2 + 1; ++i) {
		ASSERT_EQ(coef2[i], polinom2[i]);
	}
	ASSERT_EQ(0, polinom3.getDegree());
	ASSERT_EQ(1.0, polinom3[0]);
}

TEST_F (PolynomialTest, CopyConstructor) {

	Polynomial polinom4(polinom1);
	ASSERT_EQ(degree1, polinom4.getDegree());
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(polinom1[i], polinom4[i]);
	}

	Polynomial polinom5(polinom2);
	ASSERT_EQ(degree2, polinom5.getDegree());
	for (int i = 0; i < degree2 + 1; ++i) {
		EXPECT_EQ(polinom2[i], polinom5[i]);
	}

	Polynomial polinom6(polinom3);
	ASSERT_EQ(0, polinom6.getDegree());
	EXPECT_EQ(1.0, polinom6[0]);
}

TEST_F (PolynomialTest, AssigmentOperator) {
	Polynomial polinom4 = polinom1;
	ASSERT_EQ(degree1, polinom4.getDegree());
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(polinom1[i], polinom4[i]);
	}

	Polynomial polinom5(polinom2);
	ASSERT_EQ(degree2, polinom5.getDegree());
	for (int i = 0; i < degree2 + 1; ++i) {
		EXPECT_EQ(polinom2[i], polinom5[i]);
	}

	Polynomial polinom6 = polinom3;
	ASSERT_EQ(0, polinom6.getDegree());
	EXPECT_EQ(1.0, polinom6[0]);
}

TEST_F (PolynomialTest, OperatorPlus) {
	// Testing polynom + polynom

	Polynomial pol4 = polinom1 + polinom1;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(2*(i + 1),pol4[i]);
	}
	Polynomial pol5 = polinom1 + polinom2;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == degree1) {
			EXPECT_EQ(coef1[i],pol5[i]);
		} else {
			EXPECT_EQ(coef1[i] + coef2[i],pol5[i]);
		}
	}
	Polynomial pol6 = polinom1 + polinom3;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == 0) {
			EXPECT_EQ(i + 2,pol6[i]);
		} else {
			EXPECT_EQ((i + 1),pol6[i]);
		}
	}
	Polynomial pol7 = polinom3 + polinom3;
	EXPECT_EQ(2.0,pol7[0]);

	// Testing polynom + int
	// polynom + double
	// int + polynom
	// double + polynom
	Polynomial pol8 = polinom1 + 2.5;
	Polynomial pol9 = 2.5 + polinom1;
	Polynomial pol10 = polinom1 + 3;
	Polynomial pol11 = 3 + polinom1;
	for (int i = 0; i < degree1 + 1; ++i) {
		if (i == 0) {
			EXPECT_EQ(i + 3.5,pol8[i]);
			EXPECT_EQ(i + 3.5,pol9[i]);
			EXPECT_EQ(i + 4,pol10[i]);
			EXPECT_EQ(i + 4,pol11[i]);
		} else {
			EXPECT_EQ(i + 1,pol8[i]);
			EXPECT_EQ(i + 1,pol9[i]);
			EXPECT_EQ(i + 1,pol10[i]);
			EXPECT_EQ(i + 1,pol11[i]);
		}
	}
	Polynomial pol12 = polinom3 + 1.0;
	Polynomial pol13 = 1.0 + polinom3;
	Polynomial pol14 = polinom3 + 2;
	Polynomial pol15 = 2 + polinom3;
	EXPECT_EQ(2.0,pol12[0]);
	EXPECT_EQ(2.0,pol13[0]);
	EXPECT_EQ(3,pol14[0]);
	EXPECT_EQ(3,pol15[0]);
}

TEST_F (PolynomialTest, OutputOperator) {
	// Output streams
	std::ostringstream out1;
	std::ostringstream out2;
	std::ostringstream out3;
	out1 << polinom1;
	EXPECT_EQ( "Degree: 3 \nCoeffcients: 1x^0 2x^1 3x^2 4x^3 ", out1.str());
	out2 << polinom2;
	EXPECT_EQ( "Degree: 2 \nCoeffcients: -2x^0 2x^1 3x^2 ", out2.str());
	out3 << polinom3;
	EXPECT_EQ( "Degree: 0 \nCoeffcients: 1x^0 ", out3.str());
}

TEST_F (PolynomialTest, OperatorMult) {
	// Testing polynom * polynom
	double* rez1 = new double[7]{1,4,10,20,25,24,16};
	Polynomial pol4 = polinom1 * polinom1;
	for (int i = 0; i < 7; ++i) {
		EXPECT_EQ(rez1[i],pol4[i]);
	}

	double* rez2 = new double[6]{-2,-2,1,4,17,12};
	Polynomial pol5 = polinom1 * polinom2;
	for (int i = 0; i < 6; ++i) {
		EXPECT_EQ(rez2[i],pol5[i]);
	}

	double* rez3 = new double[5]{4,-8,-8,12,9};
	Polynomial pol6 = polinom2 * polinom2;
	for (int i = 0; i < 5; ++i) {
		EXPECT_EQ(rez3[i],pol6[i]);
	}

	Polynomial pol7 = polinom1 * polinom3;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(coef1[i],pol7[i]);
	}
	Polynomial pol8 = polinom3 * polinom3;
	EXPECT_EQ(1.0,pol8[0]);

	// Testing polynom * int
	// polynom * double
	// int * polynom
	// double * polynom
	Polynomial pol9 = polinom1 * 2.5;
	Polynomial pol10 = 2.5 * polinom1;
	Polynomial pol11 = polinom1 * 3;
	Polynomial pol12 = 3 * polinom1;
	for (int i = 0; i < degree1 + 1; ++i) {
		EXPECT_EQ(coef1[i] * 2.5, pol9[i]);
		EXPECT_EQ(coef1[i] * 2.5, pol10[i]);
		EXPECT_EQ(coef1[i] * 3, pol11[i]);
		EXPECT_EQ(coef1[i] * 3, pol12[i]);
	}
	Polynomial pol13 = polinom3 * 1.0;
	Polynomial pol14 = 1.0 * polinom3;
	Polynomial pol15 = polinom3 * 2;
	Polynomial pol16 = 2 * polinom3;
	EXPECT_EQ(1.0, pol13[0]);
	EXPECT_EQ(1.0, pol14[0]);
	EXPECT_EQ(2, pol15[0]);
	EXPECT_EQ(2, pol16[0]);
}

TEST_F (PolynomialTest, Derivate) {
	// Testing derivate

	// pol1' -> first derivate
	Polynomial pol4 = polinom1(1);
	//double* rez2 = new double[4]{2,6,12}; actual values
	for (int i = 0; i < degree1; ++i) {
		EXPECT_EQ(coef1[i+1] * (i+1), pol4[i]);  // rez2[i] can compare to this
	}

	Polynomial pol5 = polinom2(1);
	for (int i = 0; i < degree2; ++i) {
		EXPECT_EQ(coef2[i+1] * (i+1), pol5[i]);
	}

	// When derivate is largen the degree
	Polynomial pol6 = polinom3(1);
	EXPECT_EQ(0, pol6[0]);
	Polynomial pol7 = polinom3(2);
	EXPECT_EQ(0, pol7[0]);
	Polynomial pol10 = polinom2(3);
	EXPECT_EQ(0, pol10[0]);
	Polynomial pol11 = polinom1(4);
	EXPECT_EQ(0, pol11[0]);

	// pol1'' -> second derivate
	Polynomial pol8 = polinom1(2);
	for (int i = 0; i < degree1 - 1; ++i) {
		EXPECT_EQ(coef1[i+2] * (i+1) * (i+2), pol8[i]);
	}

	Polynomial pol9 = polinom2(2);
	for (int i = 0; i < degree2 - 1; ++i) {
		EXPECT_EQ(coef2[i+2] * (i+1) * (i+2), pol9[i]);
	}

	// Values at first derivate
	EXPECT_EQ(62, polinom1(1, 2));
	EXPECT_EQ(20, polinom2(1, 3));
	EXPECT_EQ(0, polinom3(1, 3));

	// Values at second derivate
	EXPECT_EQ(54, polinom1(2, 2));
	EXPECT_EQ(6, polinom2(2, 1000));
	EXPECT_EQ(0, polinom3(2, 100));

	// Values at third derivate
	EXPECT_EQ(24, polinom1(3, 2));
	EXPECT_EQ(0, polinom2(3, 1000));
	EXPECT_EQ(0, polinom3(3, 100));
}

TEST_F (PolynomialTest, computeZero) {
	const double tolerance = 0.00000001;  // 10^-8
	EXPECT_TRUE(fabs(-0.605829586 - polinom1.computeZero(0.75)) < tolerance );
	EXPECT_TRUE(fabs(0.548583770 - polinom2.computeZero(2)) < tolerance);
}
