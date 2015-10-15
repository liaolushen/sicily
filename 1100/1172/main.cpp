#include <iostream>
#include <cstring>

using namespace std;

struct Point {
    int row;
    int col;
};

/**
* 0 indicate is safe
* 1 indicate is danger
* 2 indicate is occupied
*/
int board[1001][1001];
int boardRow, boardCol;

Point queens[100];
Point knights[100];
Point pawns[100];

void queenToAttack(Point queen) {
    int dir[8][2] = {{1, 1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < 8; i++) {
        int row = queen.row;
        int col = queen.col;
        while (true) {
            row += dir[i][0];
            col += dir[i][1];
            if (row <= 0 || col <= 0 || row > boardRow || col > boardCol) break;
            if (board[row][col] == 2) break;
            if (board[row][col] == 0) board[row][col] = 1;
        }
    }
}

void knightToAttack(Point knight) {
    int dir[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    for (int i = 0; i < 8; i++) {
        int row = knight.row;
        int col = knight.col;
        row += dir[i][0];
        col += dir[i][1];
        if (row <= 0 || col <= 0 || row > boardRow || col > boardCol) continue;
        if (board[row][col] == 0) board[row][col] = 1;
    }
}

int main() {
    int index = 0;
    while (cin >> boardRow >> boardCol && boardRow != 0 && boardCol != 0) {
        for (int i = 1; i <= boardRow; i++) {
            for (int j = 1; j <= boardCol; j++) {
                board[i][j] = 0;
            }
        }
        int queenSize, knightSize, pawnSize;
        cin >> queenSize;
        for (int i = 0; i < queenSize; ++i) {
            cin >> queens[i].row >> queens[i].col;
            board[queens[i].row][queens[i].col] = 2;
        }
        cin >> knightSize;
        for (int i = 0; i < knightSize; ++i) {
            cin >> knights[i].row >> knights[i].col;
            board[knights[i].row][knights[i].col] = 2;
        }
        cin >> pawnSize;
        for (int i = 0; i < pawnSize; ++i) {
            cin >> pawns[i].row >> pawns[i].col;
            board[pawns[i].row][pawns[i].col] = 2;
        }

        for (int i = 0; i < queenSize; ++i) queenToAttack(queens[i]);
        for (int i = 0; i < knightSize; ++i) knightToAttack(knights[i]);

        int safeSize = 0;
        for (int i = 1; i <= boardRow; i++) {
            for (int j = 1; j <= boardCol; j++) {
                if (board[i][j] == 0) safeSize++;
            }
        }
        cout << "Board " << ++index << " has " << safeSize << " safe squares." << endl;
    }
}