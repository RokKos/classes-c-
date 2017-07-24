#ifndef _SRC_SORTS_HPP_
#define _SRC_SORTS_HPP_

// System includes
#include <iostream>
// User includes

/**
 * @file sorts.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent grpup of differend sorts with helping functions.
 */


/**
 * @brief Compares two values together
 * @param Two values that it compares
 * @returns True if a is bigger than b else false
 */
bool compare(const int a, const int b);

/**
 * @brief Swaps two values in array
 * @param Array where we swap and positions
 */
void swapElem(int* array, const int addr1, const int addr2);

/**
 * @brief Print out array in readeable form
 * @param Array to output.
 */
void showArray(const int* array, const int size);

/**
 * @brief Check if array is sorted asscendignly
 * @param Array to check.
 */
bool isSorted(const int* array, const int size);

/**
 * @brief Elementary sort that orders array by placing minimum value on first
 * place and then second minimal value on second place and so on.
 * @param Array to sort.
 */
void selectionSort(int* array, const int size);

/**
 * @brief Elementary sort that orders array by inserting element at riht place
 * @param Array to sort.
 */

void insertionSort(int* array, const int size);

/**
 * @brief Elementary sort that orders array by h-sorting h long subsequence.
 * @param Array to sort.
 */

void shellSort(int* array, const int size);

#endif  // _SRC_SORTS_HPP_
