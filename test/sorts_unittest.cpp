#include <string>

#include "gtest/gtest.h"
#include "sorts.hpp"

int bigArr[101] = {37, 7, 31, 64, 23, 32, 6, 54, 52, 8, 74, 24, 35, 66, 46, 9,
 73, 62, 16, 96, 45, 68, 21, 1, 44, 71, 22, 61, 55, 40, 49, 60, 14, 10, 75, 89,
 100, 13, 98, 58, 95, 2, 59, 97, 79, 27, 101, 47, 18, 87, 76, 50, 28, 83, 82,
 41, 56, 19, 11, 69, 67, 4, 78, 91, 99, 5, 12, 26, 51, 70, 92, 39, 94, 38, 15,
 86, 3, 81, 34, 88, 72, 48, 85, 20, 77, 84, 80, 25, 53, 43, 29, 63, 42, 30, 33,
 17, 57, 90, 93, 36, 65};


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

	int* sameArr = new int[10];
	for (int i = 0; i < 10; ++i) {
		sameArr[i] = 10;
	}

	ASSERT_EQ(true, isSorted(sameArr, 10));

	delete[] sameArr;
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

	int* sameArr = new int[10];
	for (int i = 0; i < 10; ++i) {
		sameArr[i] = 10;
	}
	selectionSort(sameArr, 10);
	ASSERT_EQ(true, isSorted(sameArr, 10));

	selectionSort(bigArr, 100);
	ASSERT_EQ(true, isSorted(bigArr, 100));

	delete[] sameArr;
	delete[] smallArr;
	delete[] arr;
}

TEST(Sorts, insertionSort) {
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	insertionSort(arr, 10);
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

	insertionSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, arr[i]);
	}

	int* smallArr = new int[1];
	smallArr[0] = 1;
	insertionSort(smallArr, 1);
	ASSERT_EQ(1, smallArr[0]);

	int* sameArr = new int[10];
	for (int i = 0; i < 10; ++i) {
		sameArr[i] = 10;
	}
	insertionSort(sameArr, 10);
	ASSERT_EQ(true, isSorted(sameArr, 10));

	insertionSort(bigArr, 100);
	ASSERT_EQ(true, isSorted(bigArr, 100));

	delete[] sameArr;
	delete[] smallArr;
	delete[] arr;
}


TEST(Sorts, shellSort) {
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	shellSort(arr, 10);
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

	shellSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(i, arr[i]);
	}

	int* smallArr = new int[1];
	smallArr[0] = 1;
	shellSort(smallArr, 1);
	ASSERT_EQ(1, smallArr[0]);

	int* sameArr = new int[10];
	for (int i = 0; i < 10; ++i) {
		sameArr[i] = 10;
	}
	shellSort(sameArr, 10);
	ASSERT_EQ(true, isSorted(sameArr, 10));

	shellSort(bigArr, 100);
	ASSERT_EQ(true, isSorted(bigArr, 100));

	delete[] sameArr;
	delete[] smallArr;
	delete[] arr;
}
