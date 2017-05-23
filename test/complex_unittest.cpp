#include <climits>  // Including max and min values for tipes

#include "gtest/gtest.h"
#include "complex.hpp"

// To use a test fixture, derive a class from testing::Test.
class ComplexTest : public testing::Test {
// Members are protected so that they can be accessed from sub-classes
 protected:
	// Complex numbers
	Complex complex1;
	Complex complex2;
	Complex complex3;
	Complex complex4;
	Complex complex5;

	ComplexTest() {
	}

	~ComplexTest() {
	}

	// virtual void SetUp() will be called before each test is run.  You
	// should define it if you need to initialize the varaibles.
	// Otherwise, this can be skipped.
	virtual void SetUp() {
		// Work around because Polynoms must be first initialize and then set
		Complex c1(1, 1);
		Complex c2(0, 1);
		Complex c3(1, 0);
		Complex c4(2, 3);
		Complex c5(7, 4);

		complex1 = c1;
		complex2 = c2;
		complex3 = c3;
		complex4 = c4;
		complex5 = c5;
	}
};

TEST_F(ComplexTest, GetReal) {
	ASSERT_EQ(1, complex1.getReal());
	ASSERT_EQ(0, complex2.getReal());
	ASSERT_EQ(1, complex3.getReal());
	ASSERT_EQ(2, complex4.getReal());
	ASSERT_EQ(7, complex5.getReal());
}

TEST_F(ComplexTest, GetImaginary) {
	ASSERT_EQ(1, complex1.getImaginary());
	ASSERT_EQ(1, complex2.getImaginary());
	ASSERT_EQ(0, complex3.getImaginary());
	ASSERT_EQ(3, complex4.getImaginary());
	ASSERT_EQ(4, complex5.getImaginary());
}

TEST_F(ComplexTest, CopyConstructor) {
	Complex numbers[5] = {complex1, complex2, complex3, complex4, complex5};
	for (int i = 0; i < 5; ++i) {
		Complex temp(numbers[i]);
		EXPECT_EQ(temp.getReal(), numbers[i].getReal());
		EXPECT_EQ(temp.getImaginary(), numbers[i].getImaginary());
	}
}

TEST_F(ComplexTest, Constructor) {
	Complex empty;
	ASSERT_EQ(empty.getReal(), 0);
	ASSERT_EQ(empty.getImaginary(), 0);

	Complex numbers[5] = {complex1, complex2, complex3, complex4, complex5};
	for (int i = 0; i < 5; ++i) {
		Complex temp(numbers[i].getReal(), numbers[i].getImaginary());
		EXPECT_EQ(temp.getReal(), numbers[i].getReal());
		EXPECT_EQ(temp.getImaginary(), numbers[i].getImaginary());
	}
}
