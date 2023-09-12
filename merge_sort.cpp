#include <iostream>

using namespace std;

const int ARR_SIZE = 10;
int a[ARR_SIZE];
//int a[10];



void merge(int first, int mid, int last){
    int L_len = mid-first+1;
    int R_len = last - mid;
    int L[L_len];
    int R[R_len];
    int i(0),j(0),k(first);
    for (int h = 0 ; h < L_len ; h++){
        L[h] = a[first + h];
    } 
    for (int h = 0 ; h < R_len ; h++){
        R[h] = a[mid+1+h];
    }
    while (i < L_len && j < R_len){
        if (L[i] < R[j]){
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < L_len){
        a[k] = L[i];
        k++;
        i++;
    }
    while (j < R_len){
        a[k] = R[j];
        k++;
        j++;
    }
    
}

void devide(int first, int last){
    if (first < last){
    int mid = (first + last)/2;
    devide(first, mid);
    devide(mid+1,last);
    merge(first, mid, last);
    }
}

void print(){
    for (int i = 0 ; i < ARR_SIZE ; i++){
        cout << a[i] << " " ;
    }
}

int main()
{
    for (int i = 0 ; i < ARR_SIZE ; i++){
        cin >> a[i];
    }
    devide(0,9);
    print();

    return 0;
}

