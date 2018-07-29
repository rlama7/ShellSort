/**
 * @file 		ShellSort.cpp
 * @author		Ratna Lama
 * @date		07/29/2018
 * @brief 		A program to implement Shell Sort
 * 
 * @Algorithm :	
 * Key word: Almost Sorted (n/2)
 * Insertion sort subarrays of entries at equally spaced indices
 * Initial separation between indices by (n/2)
 * Sort each subarrays separately using insertion sort
 * Halve this value each pass
 * Sort each subarrasy separately using insertion sort
 * Repeat until the separation is 1
 * Final step: Insertion sor the entire array.
 * 
 * 
 */

#include <iostream>
#include <string>		// c++ style string
using namespace std;

// Function Prototype
template<typename ItemType>
void ShellSort(ItemType Array[], int size);


int main() {
	// Sort String using ShellSort
	string my_Array[8] = {"X", "R", "T", "B", "L", "R", "P", "A"};
	ShellSort(my_Array, 8);
	cout << "[";
	for(auto s : my_Array) {
		cout << s << " ";
	}
	cout << "]";
	cout << "\n------------------------------------------------------\n" << endl;
	
	// Sort exam score using ShellSort 
	double score[10] = {99.9, 101.1, 89.7, 75.5, 63.5, 88.8, 79.9, 90.5, 50.0, 63.7};
	ShellSort(score, 10);
	cout << "[";
	for (int i=0; i<10; i++) {
		cout << score[i] << " ";
	}
	cout << "]";
	cout << "\n------------------------------------------------------\n" << endl;
		
	return 0;
} // end main


template<typename ItemType>
void ShellSort(ItemType Array[], int size) {
	for (int h = size /2; h>0; h = h/2) {
		for (int unsorted = h; unsorted < size; unsorted++) {
			ItemType nextItem = Array[unsorted];
			int loc = unsorted;
			while ((loc >= h) && (Array[loc-h] > nextItem)) {
				Array[loc] = Array[loc-h];
				loc = loc-h;
			}
			Array[loc] = nextItem;
		}
	}
} // end ShellSort()