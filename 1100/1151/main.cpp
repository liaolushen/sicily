#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    string op;
    int magic[8];
    Node(string _op, int _magic[]) {
        op = _op;
        for (int i = 0; i < 8; ++i) {
            magic[i] = _magic[i];
        }
    }
};

bool isVisit[40320];// 是否已经遍历的记录

// 阶乘
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 康托展开
int cantor(int num[]) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        int n = num[i];
        for (int j = 0; j < i; ++j) {
            if (num[j] < num[i]) {
                n--;
            }
        }
        result += (n-1)*factorial(7-i);
    }
    return result;
}

// 操作Ａ
void operationA(int origin[], int result[]) {
    result[0] = origin[4]; result[1] = origin[5];
    result[2] = origin[6]; result[3] = origin[7];
    result[4] = origin[0]; result[5] = origin[1];
    result[6] = origin[2]; result[7] = origin[3];
}

// 操作Ｂ
void operationB(int origin[], int result[]) {
    result[1] = origin[0]; result[2] = origin[1];
    result[3] = origin[2]; result[0] = origin[3];
    result[5] = origin[4]; result[6] = origin[5];
    result[7] = origin[6]; result[4] = origin[7];
}

// 操作Ｃ
void operationC(int origin[], int result[]) {
    result[0] = origin[0]; result[3] = origin[3];
    result[4] = origin[4]; result[7] = origin[7];
    result[1] = origin[5]; result[2] = origin[1];
    result[6] = origin[2]; result[5] = origin[6];
}

int main() {
    int N;
    while (cin >> N && N != -1) {
        memset(isVisit, false, sizeof(isVisit));// isVisit全部初始化为false
        queue<Node> v;// 使用队列来进行BFS
        int targetMagic[8];
        for (int i = 0; i < 8; ++i) {
            cin >> targetMagic[i];
        }
        int target = cantor(targetMagic);// 获取目标状态的康托展开值
        int beginMagic[8] = {1, 2, 3, 4, 8, 7, 6, 5};// 初始状态
        v.push(Node("", beginMagic));
        isVisit[cantor(beginMagic)] = true;

        // Begin BFS
        while (!v.empty()) {
            if (cantor(v.front().magic) == target || v.front().op.size() > N) break;// 如果得出结果或者已超过Ｎ的值，跳出循环
            int num[8];

            operationA(v.front().magic, num);
            if (!isVisit[cantor(num)]) {
                v.push(Node(v.front().op+"A", num));// 如果未遍历到这个值，则将其放入队列
                isVisit[cantor(num)] = true;// 设置已经遍历
            }

            operationB(v.front().magic, num);
            if (!isVisit[cantor(num)]) {
                v.push(Node(v.front().op+"B", num));
                isVisit[cantor(num)] = true;
            }

            operationC(v.front().magic, num);
            if (!isVisit[cantor(num)]) {
                v.push(Node(v.front().op+"C", num));
                isVisit[cantor(num)] = true;
            }

            v.pop();
        }

        if (v.empty()) {
            cout << -1 << endl;
        } else if (v.front().op.size() > N) {
            cout << -1 << endl;
        } else {
            cout << v.front().op.size() << ' ' << v.front().op << endl;
        }
    }
    return 0;
}