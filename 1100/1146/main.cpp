#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, M;
    int result[1001] = {0};
    cin >> T >> M;
    int t, v;
    while (M--) {
        cin >> t >> v;
        for (int i = T; i >= t; i--) {
            if (result[i] < result[i - t] + v) result[i] = result[i - t] + v;
        }
    }
    cout << result[T] << endl;
}