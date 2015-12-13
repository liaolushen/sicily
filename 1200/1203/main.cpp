#include <iostream>
#include <cstring>

using namespace std;

long long mul(long long left, long long right, long long power) {
    long long result;

    result = 0;
    while (left >= 1) {
        if (left & 1) {
            result += right;
        }
        right <<= 1;
        if (right > power) {
            right %= power;
        }
        left >>= 1;
    }
    if (result > power) {
      result %= power;
    }
    return result;
}

long long cube(long long base, long long power) {
    return mul(mul(base, base, power), base, power);
}

int main() {
    int N;
    cin >> N;
    string num;
    while (N--) {
        cin >> num;
        int len = num.size();
        long long result;
        switch (num[len-1]-'0') {
            case 1:
                result = 1;
                break;
            case 3:
                result = 7;
                break;
            case 7:
                result = 3;
                break;
            case 9:
                result = 9;
        }
        long long power = 10;
        long long rem = num[len-1] - '0';
        for (int current_bits = len -2; current_bits >= 0; current_bits--) {
            rem += power * (num[current_bits] - '0');
            power *= 10;
            while (cube(result, power) != rem) {
                result += power / 10;
            }
        }
        cout << result << endl;
    }
    return 0;
}