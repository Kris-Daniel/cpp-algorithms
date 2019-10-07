#include <iostream>
#define Log(x) std::cout << x << std::endl

void insertionSort(int* arrToSort, int len)
{
	for (int i = 1; i < len; i++) {
		int key = arrToSort[i];
		int j = i - 1;
		while (j >= 0 && arrToSort[j] > key) {
			arrToSort[j + 1] = arrToSort[j];
			j--;
		}
		arrToSort[j + 1] = key;
	}
}

int main()
{
	int arr[10] = { 5, 3, 1, 4, 6, 8, 2, 7, 10, 9 };
	int len = sizeof(arr) / sizeof(int);
	insertionSort(arr, len);
	for (int i = 0; i < len; i++) {
		Log(arr[i]);
	}
	std::cin.get();
}
