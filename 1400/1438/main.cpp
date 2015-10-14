#include <iostream>


using namespace std;

int goods[20001];

void exch(int *num, int index1, int index2) {
    int tmp = num[index1];
    num[index1] = num[index2];
    num[index2] = tmp;
}

int partition(int *num, int lo, int hi) {
    int pivot = lo;
    int loPtr = lo;
    int hiPtr = hi + 1;
    while (true) {
        while (num[--hiPtr] <= num[pivot]) if (hiPtr == lo) break;
        while (num[++loPtr] >= num[pivot]) if (loPtr == hi) break;
        if (loPtr >= hiPtr) break;
        exch(num, loPtr, hiPtr);
    }
    exch(num, pivot, hiPtr);
    return hiPtr;
}

void quickSort(int *num, int lo, int hi) {
    if (lo >= hi) return;
    int pivot = partition(num, lo, hi);
    quickSort(num, lo, pivot-1);
    quickSort(num, pivot+1, hi);
}

int main() {
    int N;
    cin >> N;
    while(N--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> goods[i];
        }
        quickSort(goods, 0, n-1);
        int discount = 0;
        for (int i = 2; i < n; i += 3) {
            discount += goods[i];
        }
        cout << discount << endl;
    }
}