#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int mapArray[30];

int jump[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

bool isVisisted[30];

bool isFinish() {
    for (int i = 0; i < 30; i++) {
        if (isVisisted[i] == false) return false;
    }
    return true;
}

int getNextIndex(int index, int* direction) {
    int x = index%6;
    int y = index/6;
    if (x + direction[0] < 0 || x + direction[0] > 5) return -1;
    if (y + direction[1] < 0 || y + direction[1] > 4) return -1;
    return (x + direction[0]) + (y + direction[1]) * 6;
}

bool dfs(int index) {
    isVisisted[index] = true;
    if (isFinish()) return true;

    for (int i = 0; i < 8; i++) {
        int toJump = getNextIndex(index, jump[i]);
        if (toJump != -1 && !isVisisted[toJump]) {
            mapArray[index] = toJump;
            if (dfs(toJump)) {
                return true;
            } else {
                mapArray[index] = -1;
            }
        }
    }
    isVisisted[index] = false;
    return false;
}

int main() {
    int start;
    while (cin >> start && start > 0) {
        for (int i = 0; i < 30; ++i) {
            mapArray[i] = -1;
        }
        memset(isVisisted, false, sizeof(isVisisted));
        dfs(start-1);
        int currentNode = start - 1;
        while (true) {
            cout << currentNode+1;
            if (mapArray[currentNode] != -1) {
                cout << ' ';
                currentNode = mapArray[currentNode];
            } else {
                cout << endl;
                break;
            }
        }
    }
}