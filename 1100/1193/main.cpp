#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, f, b;
        int init[1001];
        cin >> n >> f >> b;
        int fi, bi;
        for (int i = 0; i < n; i++) {
            cin >> fi >> bi;
            if (bi == 0) init[i] = fi + f;
            else init[i] = f * 3 - fi;
        }

        sort(init, init + n);
        int remain = b % n;
        int totleTime;
        if (remain == 0) totleTime = (b / n - 1) * 2 * f + init[n - 1];
        else totleTime = (b / n) * 2 * f + init[remain - 1];

        cout << totleTime << endl;
    }
}