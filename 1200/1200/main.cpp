#include <iostream>
#include <algorithm>

using namespace std;

int sticks[100];

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
        }
        sort(sticks, sticks + n);
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1) {
                cout << sticks[n-1] << endl;
            } else if (sticks[i] != sticks[i + 1]) {
                cout << sticks[i] << endl;
                break;
            }
        }
    }
}