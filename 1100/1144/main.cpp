#include <iostream>

using namespace std;

int main() {
    int apples[10], height;
    for (int i = 0; i < 10; i++) {
        cin >> apples[i];
    }

    cin >> height;
    height += 30;

    int num = 0;
    for (int i = 0; i < 10; ++i) {
        if (apples[i] <= height) num++;
    }
    cout << num << endl;
}