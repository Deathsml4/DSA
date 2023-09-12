#include <iostream>
#include <vector>

using namespace std;

int cnt = 1;
void print(vector<int> arr){
	int n = arr.size();
	cout << "Step " << cnt++ << ": ";
	for (int i = 0 ; i < n ; i ++){
		cout << arr[i] <<  " ";
	}
	cout << endl;
}

void selection_sort(vector<int> & arr){
	int n = arr.size();
	for (int i = 0 ; i < n ; i ++){
		int min = arr[i];
		int key = i;
		for (int j = i+1 ; j < n ; j ++){
			if (arr[j] < min){
				min = arr[j];
				key = j;
			}
		}
		swap(arr[i],arr[key]);
		print(arr);
	}
}

int main(){
	int n,k;
	while (cin >> n){
	if (n < 0){
		break;
	}
	//cin >> n;
	vector<int> arr;
	for (int i = 0 ; i < n ; i++){
		cin >> k;
		arr.push_back(k);
	}
	selection_sort(arr);
	for (int i = 0 ; i < n ; i++){
		arr.pop_back();
	}
	cnt = 1;
	}
	return 0;
}
