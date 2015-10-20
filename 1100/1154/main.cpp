#include <algorithm>
#include <iostream>

using namespace std;

int num[1001];

int main() {
    int N, n;
    cin >> N;
    while (N--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> num[i];
        sort(num, num+n);
        for (int i = 0; i < n; ++i) cout << num[i] << endl;
    }
}