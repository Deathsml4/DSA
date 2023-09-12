#include <iostream>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void print(int*arr, int low, int high) {
	for (int i = low; i <= high; i++){
		cerr << arr[i] << " ";
	}
	cerr << endl;
}

int partition(int* arr, int low, int high) {
	cerr << "\nBefore :";
	print(arr, low, high);
	int pivot_value = arr[(low + high)/2];
	cerr << "Select " << pivot_value << " as a pivot\n";
	int left = low, right = high, cnt = 1;
	while (left < right) {
		while (arr[left] < pivot_value) {
			left ++;
		}
		while (arr[right] > pivot_value) {
			right --;
		}
		if (left >= right){
			break;
		}
		swap(arr[left], arr[right]);
		if (arr[left] != pivot_value) {
			left ++;
		}
		if (arr[right] != pivot_value) {
			right --;
		}
		if (arr[right] == pivot_value && arr[left] == pivot_value && left < right) {
			//left ++;
			right --;
		}
		cerr << "Step " << cnt++ << ": "; 
		print(arr, low, high);
	}
	cerr << "After :";
	print(arr, low, high);
	return left;
}

void quick_sort(int* arr, int low, int high) {
	if (low < high) {
		int pivot = partition (arr, low, high);
		cerr << "Vi tri : Low " << low << " : High " << high << " : Pivot " <<  pivot << endl;
		
		if (pivot-1 > low) quick_sort(arr, low, pivot - 1);
		if (pivot+1 < high) quick_sort(arr, pivot + 1, high);
	}
}

void print_arr (int* arr, int n){
	for (int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0 ; i <  n ; i++){
		cin >> arr[i];
	}
	quick_sort (arr, 0, n-1);
	print_arr (arr, n);
	return 0;
}
