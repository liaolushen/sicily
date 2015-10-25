#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        int result = 1;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            result += tmp;
        }
        cout << result - n << endl;
    }
}