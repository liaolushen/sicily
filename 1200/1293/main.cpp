#include <iostream>

using namespace std;

int calLinkLength(int num) {
    int length = 1;
    while (num != 1) {
        if (num % 2 == 0) num /= 2;
        else num = 3 * num + 1;
        length++;
    }
    return length;
}

int main() {
    int i, j;
    cin >> i >> j;
    int maxLength = 0;
    while (i <= j) {
        if (maxLength < calLinkLength(i)) maxLength = calLinkLength(i);
        i++;
    }
    cout << maxLength << endl;
}