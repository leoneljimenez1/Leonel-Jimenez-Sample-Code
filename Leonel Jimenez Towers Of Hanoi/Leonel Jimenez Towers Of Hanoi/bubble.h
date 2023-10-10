#pragma once

#include <iostream>

using namespace std;

template<class TYPE>
void bubbleSort(TYPE array[], int count, int(*compare)(const TYPE& item1, const TYPE& item2)) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < count - 1; ++i)
        {
            if (compare(array[i], array[i + 1]) > 0)
            {
                TYPE temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        count--;
    }
}

template<class TYPE>
void selectionSort(TYPE arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void merge(int array[], int const left, int const mid,
    int const right)
{
    int const firstSubArray = mid - left + 1;
    int const secondSubArray = right - mid;

    // Create temp arrays
    auto* leftArray = new int[firstSubArray],
        * rightArray = new int[secondSubArray];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < firstSubArray; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < secondSubArray; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfFirstSubArray = 0, indexOfSecondSubArray = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfFirstSubArray < firstSubArray
        && indexOfSecondSubArray < secondSubArray) {
        if (leftArray[indexOfFirstSubArray]
            <= rightArray[indexOfSecondSubArray]) {
            array[indexOfMergedArray]
                = leftArray[indexOfFirstSubArray];
            indexOfFirstSubArray++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSecondSubArray];
            indexOfSecondSubArray++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfFirstSubArray < firstSubArray) {
        array[indexOfMergedArray]
            = leftArray[indexOfFirstSubArray];
        indexOfFirstSubArray++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSecondSubArray < secondSubArray) {
        array[indexOfMergedArray]
            = rightArray[indexOfSecondSubArray];
        indexOfSecondSubArray++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
        cout << endl;
}