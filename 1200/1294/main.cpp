#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
        result %= c;
    }
    cout << result << endl;
}