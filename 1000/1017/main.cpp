#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Invest {
    int month;
    double money;
} invest[12];

double getSum(double rate, int investSum, int endMonth) {
    double sum = 0.0;
    for (int i = 0; i < investSum; i++) {
        sum += invest[i].money * pow((rate + 1), (endMonth - invest[i].month + 1.0));
    }
    return sum;
}

int main() {
    int N, index = 0;
    while (cin >> N && N != -1) {
        for (int i = 0; i < N; i++) {
            cin >> invest[i].month >> invest[i].money;
        }

        int endMonth;
        double totleMoney;
        cin >> endMonth >> totleMoney;

        double highRate = 1.0;
        double lowRate = 0.0;
        double currentSum, currentRate;
        while (true) {
            currentRate = (highRate + lowRate) / 2;
            currentSum = getSum(currentRate, N, endMonth);
            if (abs(currentSum - totleMoney) < 1e-6) break;
            if (currentSum > totleMoney) highRate = currentRate;
            else lowRate = currentRate;
        }
        if (++index > 1) cout << endl;
        cout << "Case " << index << ": " << fixed << setprecision(5) << currentRate << endl;
    }
}