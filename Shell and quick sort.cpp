#include <iostream>
#include <ctime>

using namespace std;

void randomFunc(int* arr, int size);
void randomFunc1(int* arr, int size);
void output(int* arr, int size);
void fromKeyboard(int* arr, int size);
int choice();

void ShellSort(int* arr, int size);
void quickSort(int* arr, int left, int right, int& quickSortComp, int& quickSortPerm, int size);
void countingSort(int* arr, int size);
void radixsort(int* arr, int size);

int radixPerm = 0;


int main() {


	int size;
	cout << "Shell sort\nInput a size of array: ";
	cin >> size;
	while (size < 0) {
		cout << "Enter correct size: ";
		cin >> size;
	}
	int* arr = new int[size];
	int forChoice = choice();
	(forChoice == 1) ? randomFunc(arr, size) : fromKeyboard(arr, size);
	output(arr, size);
	ShellSort(arr, size);
	output(arr, size);
	cout << endl;
	delete[]arr;

	cout << "Quick sort\nInput a size of array: ";
	cin >> size;
	while (size < 0) {
		cout << "Enter correct size: ";
		cin >> size;
	}
	int* arr1 = new int[size];
	forChoice = choice();
	(forChoice == 1) ? randomFunc(arr1, size) : fromKeyboard(arr1, size);
	output(arr1, size);
	int quickSortComp = 0;
	int quickSortPerm = 0;
	quickSort(arr1, 0, size - 1, quickSortComp, quickSortPerm, size);
	output(arr1, size);

	cout << "Comparison: " << quickSortComp << endl;
	cout << "Permurations: " << quickSortPerm << endl;
	cout << endl;
	delete[]arr1;

	return 0;
}


void randomFunc(int* arr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50;
	}
}


void output(int* arr, int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

void fromKeyboard(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << i << " element: ";
		cin >> arr[i];
	}
}

int choice() {
	int choice;
	cout << "How do you want to enter numbers (1-random, 2-from keyboard): ";
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "Enter correct number: ";
		cin >> choice;
	}
	return choice;
}

//Shell sort
void ShellSort(int* arr, int size) {
	int temp;
	int countComp = 0;
	int countPerm = 0;
	for (int k = 4; k > 0; k = k / 2) {
		for (int i = k; i < size; i++) {
			temp = arr[i];
			int j = 0;
			for (j = i; j >= k; j = j - k) {
				countComp++;
				if (temp < arr[j - k]) {
					arr[j] = arr[j - k];
					countPerm++;
					output(arr, size);
				}
				else { break; }
			}
			arr[j] = temp;
		}
	}
	cout << "Comparison: " << countComp << endl;
	cout << "Permurations: " << countPerm << endl;
}

//Quick sort 
void quickSort(int* arr, int left, int right, int& quickSortComp, int& quickSortPerm, int size) {

	int l_hold = left;
	int r_hold = right;
	int middle = left + (right - left) / 2;
	int pivot = arr[middle];

	int i = left;
	int j = right;
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		quickSortComp++;
		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			quickSortPerm++;
			i++;
			j--;
		}
	}
	output(arr, size);
	if (left < j) {
		quickSort(arr, left, j, quickSortComp, quickSortPerm, size);
	}

	if (right > i) {
		quickSort(arr, i, right, quickSortComp, quickSortPerm, size);
	}

}