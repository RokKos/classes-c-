#include <string>

#include "gtest/gtest.h"
#include "sorts.hpp"

TEST(Sorts, compare) {
	ASSERT_EQ(true, compare(1, 0));
	ASSERT_EQ(false, compare(0, 1));
	ASSERT_EQ(false, compare(-1, 0));
	ASSERT_EQ(true, compare(9999, 9998));
	ASSERT_EQ(false, compare(-1000, 1000));
	ASSERT_EQ(false, compare(1, 1));
}

TEST(Sorts, swapElem) {
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	swapElem(arr, 0, 1);
	ASSERT_EQ(1, arr[0]);
	ASSERT_EQ(0, arr[1]);

	swapElem(arr, 0, 6);
	ASSERT_EQ(6, arr[0]);
	ASSERT_EQ(1, arr[6]);

	swapElem(arr, 2, 8);
	swapElem(arr, 5, 7);
	swapElem(arr, 3, 9);
	swapElem(arr, 1, 3);
	swapElem(arr, 5, 7);
	swapElem(arr, 7, 0);

	ASSERT_EQ(7, arr[0]);
	ASSERT_EQ(9, arr[1]);
	ASSERT_EQ(8, arr[2]);
	ASSERT_EQ(0, arr[3]);
	ASSERT_EQ(4, arr[4]);
	ASSERT_EQ(5, arr[5]);
	ASSERT_EQ(1, arr[6]);
	ASSERT_EQ(6, arr[7]);
	ASSERT_EQ(2, arr[8]);
	ASSERT_EQ(3, arr[9]);

	delete[] arr;
}

TEST(Sorts, showArray) {
	testing::internal::CaptureStdout();
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}
	showArray(arr, 10);
	std::string ouput = testing::internal::GetCapturedStdout();

	ASSERT_EQ("0 1 2 3 4 5 6 7 8 9 \n", ouput);

	swapElem(arr, 0, 1);
	swapElem(arr, 0, 6);
	swapElem(arr, 2, 8);
	swapElem(arr, 5, 7);
	swapElem(arr, 3, 9);
	swapElem(arr, 1, 3);
	swapElem(arr, 5, 7);
	swapElem(arr, 7, 0);

	testing::internal::CaptureStdout();
	showArray(arr, 10);

	ouput = testing::internal::GetCapturedStdout();

	ASSERT_EQ("7 9 8 0 4 5 1 6 2 3 \n", ouput);
	delete[] arr;
}

TEST(Sorts, isSorted) {
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	ASSERT_EQ(true, isSorted(arr, 10));

	swapElem(arr, 0, 1);
	swapElem(arr, 0, 6);
	swapElem(arr, 2, 8);
	swapElem(arr, 5, 7);
	swapElem(arr, 3, 9);
	swapElem(arr, 1, 3);
	swapElem(arr, 5, 7);
	swapElem(arr, 7, 0);

	ASSERT_EQ(false, isSorted(arr, 10));

	int* smallArr = new int[1];
	ASSERT_EQ(true, isSorted(smallArr, 1));

	delete[] smallArr;
	delete[] arr;
}

TEST(Sorts, selectionSort) {
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	selectionSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, arr[i]);
	}

	swapElem(arr, 0, 1);
	swapElem(arr, 0, 6);
	swapElem(arr, 2, 8);
	swapElem(arr, 5, 7);
	swapElem(arr, 3, 9);
	swapElem(arr, 1, 3);
	swapElem(arr, 5, 7);
	swapElem(arr, 7, 0);

	selectionSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, arr[i]);
	}

	int* smallArr = new int[1];
	smallArr[0] = 1;
	selectionSort(smallArr, 1);
	ASSERT_EQ(1, smallArr[0]);

	delete[] smallArr;
	delete[] arr;
}

