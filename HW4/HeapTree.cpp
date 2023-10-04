#include <iostream>
#include <vector>

using namespace std;

class HeapTree {
private:
    int data[100];
    int n = 0;
public:
    HeapTree() {}
    
    HeapTree(int data) {
        this->data[0] = data;
        n++;
    }
    
    void print() {
        for (int i = 0 ; i < n ; i++) {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
    
    void swim(int k) {
        if (k <= 0) return;
        int k1 = (k-1)/2;
        if(data[k] > data[k1]) {
            int tmp = data[k];
            data[k] = data[k1];
            data[k1] = tmp;
            swim(k1);
        }
    }
    
    void sink(int k) {
        int k1 = k*2 + 1;
        if (k1 >= n) return;
        if (data[k] < data[k1]) {
            if (k1+1 < n && data[k1] < data[k1+1]) {
                k1++;
            }
            
            int tmp = data[k];
            data[k] = data[k1];
            data[k1] = tmp;
            sink(k1);
            return;
        }
        
        if (k1+1 < n && data[k] < data[k1+1]) {
            int tmp = data[k];
            data[k] = data[k1+1];
            data[k1+1] = tmp;
            sink(k1+1);
            return;
        }
    }
    
    void insert(int data) {
        this->data[n++] = data;
        swim(n-1);
    }
    
    void _delete(int k) {
        int tmp = this->data[k];
        data[k] = data[n-1];
        data[n-1] = data[k];
        data[n-1] = 0;
        n--;
        sink(k);
        swim(k);
    }
    
    void remove(int data) {
        for (int i = 0 ; i < n ; i ++) {
            if (this->data[i] == data) {
                _delete(i);
            }
        }
    }
    
    int popHead() {
        int tmp = data[0];
        _delete(0);
        return tmp;
    }
    
    vector<int> heapSort() {
        vector<int> res;
        while (n >= 1) {
            int tmp = popHead();
            res.push_back(tmp);
        }
        return res;
    }    
};

int main()
{
    HeapTree* ht = new HeapTree(34);
    ht->insert(12);
    ht->insert(44);
    ht->insert(32);
    ht->insert(23);
    ht->insert(50);
    ht->insert(1);
    ht->print();
    vector<int> arr = ht->heapSort();
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}