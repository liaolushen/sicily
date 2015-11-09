#include <iostream>
#include <cstring>

using namespace std;

string bigAdd(string s1, string s2) {
    int maxLen = s1.length() > s2.length() ? s1.length() : s2.length();
    string result = "";
    int carry = 0;
    for (int i = 0; i < maxLen; ++i) {
        int a1 = 0, a2 = 0;
        if (i < s1.length()) {
            a1 = s1[s1.length()-1-i] - '0';
        }

        if (i < s2.length()) {
            a2 = s2[s2.length()-1-i] - '0';
        }

        int a = a1 + a2 + carry;
        carry = a / 10;
        a %= 10;
        char tmp = '0' + a;
        result = tmp + result;
    }
    if (carry > 0) result = "1" + result;
    while (result[0] == '0' && result.length() > 1) {
        result = string(result.begin()+1, result.end());
    }
    return result;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        string result;
        string number;
        cin >> result;
        while (--N) {
            cin >> number;
            result = bigAdd(result, number);
        }
        cout << result << endl;
    }
}