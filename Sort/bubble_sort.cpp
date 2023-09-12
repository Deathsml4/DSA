#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr){
	int n = arr.size();
	for (int i = 0 ; i < n ; i ++){
		cout << arr[i] <<  " ";
	}
	cout << endl;
}

void bubble_sort(vector<int> &arr){
	int n = arr.size();
	for (int i = 0 ; i < n ; i++){
		bool swapped = 0;
		for (int j = 0 ; j < n-i-1 ; j++){
			if (arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped = 1;
			}
			print(arr);
		}
		if (!swapped){
			return;
		}
	}
}

int main(){
	int n,k;
	cin >> n;
	vector<int> arr;
	for (int i = 0 ; i < n ; i++){
		cin >> k;
		arr.push_back(k);
	}
	bubble_sort(arr);
	return 0;
}
