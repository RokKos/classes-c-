#include "sorts.hpp"

bool compare(const int a, const int b) {
	return a > b;
}

void swapElem(int* array, const int addr1, const int addr2) {
	int temp = array[addr1];
	array[addr1] = array[addr2];
	array[addr2] = temp;
}

void showArray(const int* array, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

bool isSorted(const int* array, const int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (compare(array[i], array[i + 1])) {
			return false;
		}
	}
	return true;
}

void selectionSort(int* array, const int size) {
	for (int i = 0; i < size; ++i) {
		int minimal = array[i];
		int index = i;
		for (int j = i + 1; j < size; ++j) {
			if (compare(minimal, array[j])) {
				minimal = array[j];
				index = j;
			}
		}
		swapElem(array, i, index);
	}
}

void insertionSort(int* array, const int size) {
	for (int i = 1; i < size; ++i) {
		bool flag = true;
		for (int j = i - 1; j >= 0; --j) {
			if (compare(array[i], array[j])) {
				int temp = array[i];
				for (int k = i; k > j; --k) {
					array[k] = array[k - 1];
				}
				array[j + 1] = temp;
				flag = false;
				break;
			}
		}
		if (flag) {
			int temp = array[i];
			for (int k = i; k > 0; --k) {
				array[k] = array[k - 1];
			}
			array[0] = temp;
		}
	}
}

void shellSort(int* array, const int size) {
	int h = 1;  // Determing how long will subsequence be
	while (h < size/3) {
		h = 3 * h + 1;
	}

	while(h > 0) {
		for (int i = h; i < size; ++i) {
			for(int j = i; j >= h; j -= h) {
				if (compare(array[j-h], array[j])) {
					swapElem(array, j-h, j);
				}
			}
		}
		h /= 3;
	}
}
