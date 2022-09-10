#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define SIZE 10
#define MIN_N -100
#define MAX_N 100
#define ABS(X) (((X)>0)?(X):-(X))

//Функции для создания, заполнения и печати массивов из прошлых заданий
template<typename T>
T* createArray(T *ar, int size) {
	ar = new T[size] { };
	return ar;
}

template<typename T>
void printArray(T *ar, int size) {
	for (int i = 0; i < size; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

template<typename T>
void fillArray(T *ar, int size) {
	for (int i = 0; i < size; i++)
		ar[i] = MIN_N + (MAX_N - MIN_N) * ((double) rand() / RAND_MAX);
}

/*
 * Задание 1. Написать функцию, реализующую алгоритм
 линейного поиска заданного ключа в одномерном массиве.
 *
 */
int linearSearch(int *ar, int size, int key) {
	for (int i = 0; i < size; i++)
		if (ar[i] == key)
			return i;
	return -1;
}

/*Написать функцию, реализующую алгоритм
 бинарного поиска заданного ключа в одномерном массиве.
 *
 */
/*template<typename T>
 void swap(T &a, T &b) {
 T t { };
 t = a;
 a = b;
 b = t;
 }*/

template<typename T>
void swap(T *ar, int i, int j) {
	T t { };
	t = ar[i];
	ar[i] = ar[j];
	ar[j] = t;
}

void sort(int *ar, int size) {
	bool sorted { };
	while (!sorted) {
		sorted = 1;
		for (int i = 0; i < size; i++) {
			if (ar[i] > ar[i + 1]) {
				sorted = 0;
				swap(ar, i, i + 1);
			}
		}
	}
}

int search(int *ar, int left, int right, int key) {
	if (ABS(right - left) <= 1) {
		if (ar[left] == key)
			return left;
		if (ar[right] == key)
			return right;
		return -1;
	}
	int mid { left + (right - left) / 2 };
	if (ar[mid] == key)
		return mid;
	if (ar[mid] > key) {
		return search(ar, left, mid, key);
	}
	if (ar[mid] < key) {
		return search(ar, mid, right, key);
	}
}

int binarySearch(int *ar, int size, int key) {
	if (size == 0)
		return -1;
	sort(ar, size);
	return search(ar, 0, size, key);
}

/*
 * Написать функцию для перевода числа, запи-
 санного в двоичном виде, в десятичное представление.
 *
 */
int binToDec(int bin) {
	int r { }, d { 1 };
	while (bin) {
		if (bin % 10)
			r += d;
		d *= 2;
		bin /= 10;
	}
	return r;
}

int main() {
	/*srand(time(NULL));
	 int *array { };
	 array = createArray(array, SIZE);
	 fillArray(array, SIZE);
	 printArray(array, SIZE);
	 int k { };
	 cout << "Enter search key: " << endl;
	 cin >> k;
	 cout << "With linear search: " << linearSearch(array, SIZE, k) << endl;
	 sort(array, SIZE);
	 cout << "Sorted array:" << endl;
	 printArray(array, SIZE);
	 cout << "With binary search: " << binarySearch(array, SIZE, k) << endl;
	 cout << endl;*/
	int b { };
	cout << "Enter a number in binary" << endl;
	cin >> b;
	cout << "In decimal it's " << binToDec(b) << endl;

	return 0;
}
