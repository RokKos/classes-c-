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
