#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int year;
    while (cin >> year && year != 0) {
        int bit = (int)pow(2, (year - 1960) / 10 + 2);
        double result = 0;
        int i = 1;
        while (result <= bit) result += log2(i++);
        cout << i - 2 << endl;
    }
}