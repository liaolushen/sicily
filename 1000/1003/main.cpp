#include <iostream>
#include <queue>

using namespace std;

struct Player {
    queue<int> cards;
    int count;
    int lastCard;
    Player() {
        count = 1;
        lastCard = 0;
    }
};

int main() {
    int N;
    cin >> N;
    for (int index = 1; index <= N; index++) {
        Player players[10];
        int playerNum;

        // init game
        cin >> playerNum;
        int tmpCard;
        for (int i = 0; i < 52; i++) {
            cin >> tmpCard;
            players[0].cards.push(tmpCard);
        }

        // begin game
        int timeCount = 0;
        bool isFinish = false;
        while (++timeCount < 10000 && !isFinish) {
            isFinish = true;
            for (int i = 0; i < playerNum; ++i) {
                if (!players[i].cards.empty()) {
                    isFinish = false;
                    if (players[i].count != players[i].cards.front()) {
                        tmpCard = players[i].cards.front();
                        players[i].cards.pop();
                        players[i].cards.push(tmpCard);
                        
                    } else {
                        tmpCard = players[i].cards.front();
                        players[i].cards.pop();
                        if (i != playerNum - 1) {
                            players[i+1].cards.push(tmpCard);
                        }
                        players[i].lastCard = tmpCard;
                    }
                    players[i].count++;
                    if (players[i].count > 13) players[i].count -= 13;
                }
            }
        }
        cout << "Case " << index << ":";
        if (isFinish) {
            for (int i = 0; i < playerNum; i++) {
                cout << ' '<< players[i].lastCard;
            }
        } else {
            cout << " unwinnable";
        }
        cout << endl;
    }
}
