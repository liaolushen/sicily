#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;
    for (int i = 1; i < s1.length(); i++) {
        for (int j = 0; j < s2.length() - 1; j++) {
            if (s1[i] == s2[j] && s1[i - 1] == s2[j + 1]) ans++;
        }
    }

    cout << (int) pow(2.0, ans);
}