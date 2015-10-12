#include <iostream>
#include <cstring>

using namespace std;

int mapArray[64];

int jump[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

bool isVisisted[64];

bool isFinish() {
    for (int i = 0; i < 64; i++) {
        if (isVisisted[i] == false) return false;
    }
    return true;
}

int getNextIndex(int index, int* direction) {
    int x = index%8;
    int y = index/8;
    if (x + direction[0] < 0 || x + direction[0] > 7) return -1;
    if (y + direction[1] < 0 || y + direction[1] > 7) return -1;
    return (x + direction[0]) + (y + direction[1]) * 8;
}

int getCMPN(int index) {
    if (index == -1) {
        return 0;
    } else {
        int sum = 0;
        for (int i = 0; i < 8; ++i) {
            int nextIndex = getNextIndex(index, jump[i]);
            if (nextIndex != -1 && !isVisisted[nextIndex]) sum++;
        }
        return sum;
    }
}

void getJumpPri(int index, int* jumpPri) {
    int cmpn[8];
    for (int i = 0; i < 8; ++i) {
        cmpn[i] = getCMPN(getNextIndex(index, jump[i]));
    }

    for (int i = 0; i < 8; ++i) {
        int index = 0;
        for (int j = 1; j < 8; ++j) {
            if (cmpn[index] <= -1) {
                index = j;
            } else if (cmpn[index] == 0) {
                if (cmpn[j] > 0) index = j;
            } else {
                if (cmpn[j] > 0 && cmpn[j] < cmpn[index]) index = j;
            }
        }
        jumpPri[i] = index;
        cmpn[index] = -1;
    }
}

bool dfs(int index) {
    isVisisted[index] = true;
    if (isFinish()) return true;

    int jumpPri[8];
    getJumpPri(index, jumpPri);

    for (int i = 0; i < 8; i++) {
        int toJump = getNextIndex(index, jump[jumpPri[i]]);
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
        for (int i = 0; i < 64; ++i) {
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