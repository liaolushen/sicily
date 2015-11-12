#include <iostream>
#include <set>

using namespace std;

int sin[301];
set<int> result;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> sin[i];
        }
        for (int i = n; i < 1000000; i++) {
            result.clear();
            for (int j = 0; j < n; j++) {
                if (result.find(sin[j] % i) != result.end()) break;
                else result.insert(sin[j] % i);
            }
            if (result.size() == n) {
                cout << i << endl;
                break;
            }
        }
    }
}