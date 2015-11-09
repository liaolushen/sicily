#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char checkDigit;
    string isbn;
    int weight;
    while (cin >> isbn) {
        weight = 10;
        int sum = 0;
        for (int i = 0; i < isbn.size(); i++) {
            if (isbn[i] != '-') {
                sum += weight * (isbn[i] - '0');
                weight--;
            }
        }
        sum %= 11;
        sum = (11 - sum) % 11;
        if (sum == 10) checkDigit = 'X';
        else checkDigit = '0' + sum;
        cout << isbn << '-' << checkDigit << endl;
    }
}