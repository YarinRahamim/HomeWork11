#include <stdio.h>
#include <stdlib.h>

//Exercise 1
void swap(int *num1, int *num2);
void sortPairsArray(int *arr, int k);
//Exercise 2
void sort012(int *arr, int n);
//Exercise 3
void countSortToN(int *arr, int n);
//Exercise 4
void sortPosNeg(int *arr, int n);
//Exercise 5
void sortEvenOdd(int *arr, int n);
void sortNegPosEvenOdd(int *arr, int n);
//Exercise 6
void sortMod3(int *A, int n);
//Exercise 7
void merge_sort(int *a, int first, int last);
void merge(int *a, int p, int q, int r);
int binSearchKey(int *arr, int n, int key);
int isArrValuesSame(int *arr1, int *arr2, int n);
//Exercise 8
int numEqualsSumSmaller(int *arr, int n);
//Exercise 9
void minDiffValues(int *arr, int n, int *val1Ptr, int *val2Ptr);
//Exercise 10
int *kMin(int *arr, int n, int k);


void main()
{
	int arr[] = { 1, 7, -1, 3, 2 };
	int *brr = kMin(arr, 5, 3);
	int i;
	for (i = 0; i < 3; i++) {
		printf("%d, ", brr[i]);
	}
	getchar();
}

//Exercise 1
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void sortPairsArray(int *arr, int k)
{
	int i;
	for (i = 0; i < k; i++)
		if (arr[2 * i] > arr[2 * i + 1])
			swap(&arr[2 * i], &arr[2 * i + 1]);
}
//Exercise 2
void sort012(int *arr, int n)
{
	int zero, one, two, i;
	for (i = 0, zero = 0, one = 0, two = 0; i < n; i++) {
		if (arr[i] == 0)	zero++;
		if (arr[i] == 1)	one++;
		if (arr[i] == 2)	two++;
	}
	i = 0;
	while (zero) {
		arr[i++] = 0;
		zero--;
	}
	while (one) {
		arr[i++] = 1;
		one--;
	}
	while (two) {
		arr[i++] = 2;
		two--;
	}
}
//Exercise 3
void countSortToN(int *arr, int n)
{
	int *count = (int*)calloc(n + 1, sizeof(int));
	int i, j;
	for (i = 0; i < n; i++)
		count[arr[i]]++;
	for (i = 0, j = 0; i < n; i++) {
		while (count[i]) {
			arr[j++] = i;
			count[i]--;
		}
	}
	free(count);
}
//Exercise 4
void sortPosNeg(int *arr, int n)
{
	int i = 0, j = n - 1;
	while (i < n && arr[i] >= 0)
		i++;
	while (j >= 0 && arr[j] < 0)
		j--;
	while (i < j) {
		swap(&arr[i], &arr[j]);
		while (i < n && arr[i] >= 0)
			i++;
		while (j >= 0 && arr[j] < 0)
			j--;
	}
}
//Exercise 5
void sortEvenOdd(int *arr, int n)
{
	int i = 0, j = n - 1;
	while (i < n && arr[i] % 2 == 0)
		i++;
	while (j >= 0 && arr[j] % 2 != 0)
		j--;
	while (i < j) {
		swap(&arr[i], &arr[j]);
		while (i < n && arr[i] % 2 == 0)
			i++;
		while (j >= 0 && arr[j] % 2 != 0)
			j--;
	}
}
void sortNegPosEvenOdd(int *arr, int n)
{
	int i = 0, j = n - 1;
	while (i < n && arr[i] < 0)
		i++;
	while (j >= 0 && arr[j] >= 0)
		j--;
	while (i < j) {
		swap(&arr[i], &arr[j]);
		while (i < n && arr[i] < 0)
			i++;
		while (j >= 0 && arr[j] >= 0)
			j--;
	}
	sortEvenOdd(arr, i);
	sortEvenOdd(arr + i, n - i);
	//	{-3, -9, -2, 1, 2}
	//	  0   1   2  3  4
	//				 i
}
//Exercise 6
void sortMod3(int *A, int n)
{
	int i = 0, j = n - 1;

	while (i < n && A[i] % 3 == 0)
		i++;
	while (j >= 0 && A[j] % 3 != 0)
		j--;
	while (i < j) {
		swap(&A[i], &A[j]);
		while (i < n && A[i] % 3 == 0)
			i++;
		while (j >= 0 && A[j] % 3 != 0)
			j--;
	}

	j = n - 1;
	while (i < n && A[i] % 3 == 1)
		i++;
	while (j >= 0 && A[j] % 3 != 1)
		j--;
	while (i < j) {
		swap(&A[i], &A[j]);
		while (i < n && A[i] % 3 == 1)
			i++;
		while (j >= 0 && A[j] % 3 != 1)
			j--;
	}
}
//Exercise 7
int binSearchKey(int *arr, int n, int key)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
void merge_sort(int *a, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		merge_sort(a, first, middle);
		merge_sort(a, middle + 1, last);
		merge(a, first, middle, last);
	}
}
void merge(int *a, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	int* temp = (int*)calloc(r - p + 1, sizeof(int));
	while ((i <= q) && (j <= r))
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	while (j <= r) // if( i>q )
		temp[k++] = a[j++];
	while (i <= q) // j>r
		temp[k++] = a[i++];
	for (i = p, k = 0; i <= r; i++, k++) // copy temp[] to a[]
		a[i] = temp[k];
	free(temp);
}
int isArrValuesSame(int *arr1, int *arr2, int n)
{
	int i;
	merge_sort(arr1, 0, n - 1);
	for (i = 0; i < n; i++)
		if (binSearchKey(arr1, n, arr2[i]) == -1)
			return 0;
	return 1;
}
//Exercise 8
int numEqualsSumSmaller(int *arr, int n)
{
	int sum = 0, i;
	merge_sort(arr, 0, n - 1);
	for (i = 0; i < n; i++) {
		if (arr[i] == sum)
			return arr[i];
		sum += arr[i];
	}
	return -1;
}
//Exercise 9
void minDiffValues(int *arr, int n, int *val1Ptr, int *val2Ptr)
{
	int i, minDiff;
	merge_sort(arr, 0, n - 1);
	minDiff = arr[1] - arr[0];
	*val1Ptr = arr[0];
	*val2Ptr = arr[1];
	for (i = 2; i < n; i++) {
		if (arr[i] - arr[i - 1] < minDiff) {
			minDiff = arr[i] - arr[i - 1];
			*val1Ptr = arr[i - 1];
			*val2Ptr = arr[i];
		}
	}
}
//Exercise 10
int *kMin(int *arr, int n, int k)
{
	int i;
	int *newArr = (int*)malloc(k * sizeof(int));
	merge_sort(arr, 0, n - 1);
	for (i = 0; i < k; i++)
		newArr[i] = arr[i];
	return newArr;
}