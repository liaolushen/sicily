#include <iostream>

using namespace std;

int powByNine(int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= 9;
    }
    return result;
}

int main() {
    int num, tmp, index, result;
    while (cin >> num && num != 0) {
        tmp = num;
        index = 0;
        result = 0;
        while (tmp) {
            result += ((tmp % 10) > 4 ? (tmp % 10) - 1 : (tmp % 10)) * powByNine(index++);
            tmp /= 10;
        }
        cout << num << ": " << result << endl;
    }
}