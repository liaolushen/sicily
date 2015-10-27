#include <iostream>

using namespace std;

// n + (n + 1) + ... + (n + k) = s
// (2n + k)(k + 1) = 2s

int main() {
    int N;
    cin >> N;
    int index, num;
    while (N--) {
        int result = 0;
        cin >> index >> num;
        num *= 2;
        for (int k = 1; (k + 1) * (k + 1) < num; k++) {
            if (num % (k + 1) == 0) {
                int tmp = num / (k + 1) - k;
                if (tmp % 2 == 0) result++;
            }
        }
        cout << index << ' ' << result << endl;
    }
}