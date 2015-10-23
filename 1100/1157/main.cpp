#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int hardest;
        cin >> hardest;
        int level;
        for (int i = 1; i < n; ++i) {
            cin >> level;
            if (hardest < level) hardest = level;
        }
        cout << hardest << endl;
    }
}