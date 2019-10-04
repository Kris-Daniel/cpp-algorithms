#include <iostream>
#define LOG(x) std::cout << x << std::endl;

void mergeSort(int* arr, int len);
int* mergeSortEntry(int* arrToSort, int len);
void makeHalfArr(int* fullArr, int* newArr, int start, int end);
int* merge(int* leftPart, int leftLen, int* rightPart, int rightLen);

int main()
{
	int arr[11] = { 4, 6, 2, 1, 11, 5, 3, 10, 8, 9, 7 };
	int len = sizeof(arr) / sizeof(int);
	mergeSort(arr, len);

	LOG("Result of MergeSort: ");
	for (int i = 0; i < len; i++) {
		LOG(arr[i]);
	}
	std::cin.get();
}

void mergeSort(int* arr, int len) {
	int* sortedArray = mergeSortEntry(arr, len);

	for (int i = 0; i < len; i++) {
		arr[i] = sortedArray[i];
	}
}

int* mergeSortEntry(int* arrToSort, int len) {
	if (len <= 1) {
		return arrToSort;
	}

	int mid = len / 2;
	int* ptr = &mid;
	int rightArrLen = len - mid;


	int* leftArr = new int[mid];
	int* rightArr = new int[rightArrLen];
	makeHalfArr(arrToSort, leftArr, 0, mid);
	makeHalfArr(arrToSort, rightArr, mid, len);

	/*delete[] leftArr;
	delete[] rightArr;*/

	return merge(
		mergeSortEntry(leftArr, mid),
		mid,
		mergeSortEntry(rightArr, rightArrLen),
		rightArrLen
	);
}

void makeHalfArr(int* fullArr, int* newArr, int start, int end)
{
	int i, j;
	for (i = start, j = 0; i < end; i++, j++) {
		newArr[j] = fullArr[i];
	}
}

int* merge(int* leftPart, int leftLen, int* rightPart, int rightLen)
{
	int iLeft = 0;
	int iRight = 0;
	int intsInLeft = 0;
	int intsInRight = 0;

	int maxLen = leftLen + rightLen;
	int* result = new int[maxLen];
	int resultIndex = 0;

	while (iLeft < leftLen && iRight < rightLen) {
		if (leftPart[iLeft] < rightPart[iRight]) {
			result[resultIndex] = leftPart[iLeft];
			resultIndex++;
			iLeft++;
		}
		else {
			result[resultIndex] = rightPart[iRight];
			resultIndex++;
			iRight++;
		}
	}

	for (; iLeft < leftLen; iLeft++, resultIndex++)
		result[resultIndex] = leftPart[iLeft];
	for (; iRight < rightLen; iRight++, resultIndex++)
		result[resultIndex] = rightPart[iRight];
	return result;
}