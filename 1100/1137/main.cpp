#include <iostream>

using namespace std;

int d[30001];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    int result = 0;
    int tmpResult;
    int minNum;
    int maxNum;
    for (int i = 0; i < n; i++) {
        tmpResult = 0;
        minNum = maxNum = d[i];
        for (int j = i; j < n; j++) {
            if (d[j] < minNum) minNum = d[j];
            if (d[j] > maxNum) maxNum = d[j];
            if (maxNum - minNum <= k) tmpResult++;
            else break;
        }
        if (tmpResult > result) result = tmpResult;
    }
    cout << result << endl;
}