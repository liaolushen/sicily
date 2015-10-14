#include <iostream>
#include <cstring>

using namespace std;

string add(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    string result = "";
    int max = len1 > len2 ? len1 : len2;
    int carry = 0;
    for (int i = 0; i < max; i++) {
        int a1 = 0;
        int a2 = 0;
        if (i < len1) {
            a1 = s1[len1 - i - 1] - '0';
        }
        if (i < len2) {
            a2 = s2[len2 - i - 1] - '0';
        }
        int s = a1 + a2 + carry;
        carry = 0;
        if (s > 9) {
            s -= 10;
            carry++;
        }
        result = string(1, s + '0') + result;
    }
    if (carry > 0) {
        result = string(1, carry + '0') + result;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        int n;
        cin >> s >> n;
        string result = s;
        if (n == 0) result = "0";
        for (int i = 1; i < n; i++) {
            result = add(result, s);
        }
        while (result[0] == '0' && result.size() > 1) result.erase(result.begin());
        cout << result << endl;
    }
}