#include <iostream>
#include <string>

using namespace std;

int calculate(string longInteger, int basis) {
    int result = 0;
    for (int i = 0; i < longInteger.length(); i++) {
        result *= 10;
        result += longInteger[i] - '0';
        result %= basis;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int input[101];
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        string longInteger;
        cin >> longInteger;
        cout << '(';
        for (int i = 0; i < n; i++) {
            cout << calculate(longInteger, input[i]);
            if (i < (n-1)) {
                cout << ',';
            }
        }
        cout << ')' << endl;
    }
}

