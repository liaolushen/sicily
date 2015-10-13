#include <iostream>
#include <cstring>

using namespace std;

struct ShipRate {
    int weight;
    int rate;
} shipRate[4];

int main() {
    int w, r;
    int index = 1;
    while (cin >> w >> r) {
        cout << "Set number " << index << ":" << endl;
        shipRate[0].weight = w;
        shipRate[0].rate = r;
        for (int i = 1; i <= 2; ++i) {
            cin >> w >> r;
            shipRate[i].weight = w;
            shipRate[i].rate = r;
        }
        cin >> r;
        shipRate[3].weight = 1001;
        shipRate[3].rate = r;
        int currentWeight;
        while (cin >> currentWeight && currentWeight > 0) {
            int currentRank = -1;
            for (int i = 0; i < 4; ++i) {
                if (currentWeight <= shipRate[i].weight) {
                    currentRank = i;
                    break;
                }
            }

            if (currentRank == 3) {
                cout << "Weight (" << currentWeight << ") "
                << "has best price $" << currentWeight*shipRate[currentRank].rate
                << " (add 0 pounds)" << endl;
            } else {
                int priceNow, priceNext;
                priceNow = currentWeight*shipRate[currentRank].rate;
                priceNext = (shipRate[currentRank].weight + 1) * shipRate[currentRank + 1].rate;

                if (priceNow <= priceNext) {
                    cout << "Weight (" << currentWeight << ") "
                    << "has best price $" << priceNow
                    << " (add 0 pounds)" << endl;
                } else {
                    cout << "Weight (" << currentWeight << ") "
                    << "has best price $" << priceNext
                << " (add " << (shipRate[currentRank].weight + 1) - currentWeight << " pounds)" << endl;
                }
            }
        }
        cout << endl;
        index++;
    }
}