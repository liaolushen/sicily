#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void getPrimes(int biggestNum) {
    for (int i = 2; i <= biggestNum; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
}

int getResult(int num) {
    int fore = 0, to = 0, sum = 2;
    int result = 0;
    while (to >= fore) {
        if (sum < num) {
            sum += primes[++to];
        } else if (sum > num) {
            sum -= primes[fore++];
        } else {
            result++;
            sum += primes[++to];
        }
    }
    return result;
}

int main() {
    getPrimes(10100);
    int n;
    while (cin >> n && n != 0) {
        cout << getResult(n) << endl;
    }
}