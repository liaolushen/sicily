#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int yardMap[20][20];
int X, Y;

int getCanMoveStep(string direction) {
    int canMove = 9999;
    if (direction == "up" || direction == "down") {
        for (int i = 0; i < Y; i++) {
            int index = 0;
            for (int j = 0; j < X; j++) {
                if (yardMap[j][i] == 0) index++;
            }
            if (canMove > index) canMove = index;
        }
    } else if (direction == "left" || direction == "right") {
        for (int i = 0; i < X; i++) {
            int index = 0;
            for (int j = 0; j < Y; j++) {
                if (yardMap[i][j] == 0) index++;
            }
            if (canMove > index) canMove = index;
        }
    }
    return canMove;
}

void moveDown(int moveStep) {
    moveStep = min(moveStep, getCanMoveStep("down"));
    for (int i = 0; i < Y; i++) {
        int toMoveBoxNum = 0;
        for (int j = 0; j < moveStep; j++) {
            if (yardMap[j][i] == 1) {
                toMoveBoxNum++;
                yardMap[j][i] = 0;
            }
        }
        for (int j = moveStep; j < X; j++) {
            if (toMoveBoxNum == 0) break;
            if (yardMap[j][i] == 0) {
                yardMap[j][i] = 1;
                toMoveBoxNum--;
            }
        }
    }
}

void moveUp(int moveStep) {
    moveStep = min(moveStep, getCanMoveStep("up"));
    for (int i = 0; i < Y; i++) {
        int toMoveBoxNum = 0;
        for (int j = X - 1; j >= X - moveStep; j--) {
            if (yardMap[j][i] == 1) {
                toMoveBoxNum++;
                yardMap[j][i] = 0;
            }
        }
        for (int j = X - moveStep - 1; j >= 0; j--) {
            if (toMoveBoxNum == 0) break;
            if (yardMap[j][i] == 0) {
                yardMap[j][i] = 1;
                toMoveBoxNum--;
            }
        }
    }
}

void moveRight(int moveStep) {
    moveStep = min(moveStep, getCanMoveStep("right"));
    for (int i = 0; i < X; i++) {
        int toMoveBoxNum = 0;
        for (int j = 0; j < moveStep; j++) {
            if (yardMap[i][j] == 1) {
                toMoveBoxNum++;
                yardMap[i][j] = 0;
            }
        }
        for (int j = moveStep; j < Y; j++) {
            if (toMoveBoxNum == 0) break;
            if (yardMap[i][j] == 0) {
                yardMap[i][j] = 1;
                toMoveBoxNum--;
            }
        }
    }
}

void moveLeft(int moveStep) {
    moveStep = min(moveStep, getCanMoveStep("left"));
    for (int i = 0; i < X; i++) {
        int toMoveBoxNum = 0;
        for (int j = Y - 1; j >= Y - moveStep; j--) {
            if (yardMap[i][j] == 1) {
                toMoveBoxNum++;
                yardMap[i][j] = 0;
            }
        }
        for (int j = Y - moveStep - 1; j >= 0; j--) {
            if (toMoveBoxNum == 0) break;
            if (yardMap[i][j] == 0) {
                yardMap[i][j] = 1;
                toMoveBoxNum--;
            }
        }
    }
}

int main() {
    int dataSet = 0;
    while (cin >> X >> Y &&  X != 0 && Y != 0) {
        memset(yardMap, 0, sizeof(yardMap));
        int n, x, y;
        cin >> n;
        while (n--) {
            cin >> x >> y;
            yardMap[x][y] = 1;
        }
        string direction;
        int moveStep;
        while (cin >> direction && direction != "done") {
            cin >> moveStep;
            if (direction == "down") moveDown(moveStep);
            if (direction == "up") moveUp(moveStep);
            if (direction == "right") moveRight(moveStep);
            if (direction == "left") moveLeft(moveStep);
        }
        cout << "Data set " << ++dataSet << " ends with boxes at locations";
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (yardMap[i][j] == 1) cout << " (" << i << "," << j << ")";
            }
        }
        cout << "." << endl;
    }
}