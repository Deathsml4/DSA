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

void insertion_sort(vector<int> & arr){
	int n = arr.size();
	for (int i = 1 ; i < n ; i++){
		int last(i),first(0);
		int mid = (first + last)/2;
		while (first < last){
			if (arr[i] == arr[mid]) break;
			else if (arr[i] > arr[mid]){
				first = mid+1;
			}
			else {
				last = mid;
			}
			mid = (first + last)/2;
		}
		//cout << "Choose arr[i] = " << arr[i] << " with the key mid = " << mid << " and arr[mid] = " << arr[mid] << endl;
		int tmp = arr[i];
		for (int j = i ; j > mid ; j--){
			arr[j] = arr[j-1];
		}
		arr[mid] = tmp;
		print(arr);
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
	insertion_sort(arr);
	return 0;
}
