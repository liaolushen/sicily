#1151 解题报告

##原题大意
魔板由8个大小相同方块组成，分别用涂上不同颜色，用1到8的数字表示。
其初始状态是
1 2 3 4
8 7 6 5
对魔板可进行三种基本操作：
A操作（上下行互换）：
8 7 6 5
1 2 3 4
B操作（每次以行循环右移一个）：
4 1 2 3
5 8 7 6
C操作（中间四小块顺时针转一格）：
1 7 2 4
8 6 3 5
用上述三种基本操作，可将任一种状态装换成另一种状态。

题目会给出一种排列，利用这三种基本操作。求出最小的一系列操作能够使的魔板从初始状态到目标状态。

##数据结构
队列（queue）：使用STL提供的队列对象。

##解题思路
这题要求找出最小的求出目标状态的操作，所以优先考虑使用BFS，故使用队列结构。但是如果只是使用单纯的BFS进行查找会发现查找的量非常的大，而且会出现大量的重复查找，这样必然会导致超时的情况，所以就必须采用一些手段避免重复的查找。这里我使用的手段是康托展开，通过康托展开，我可以把一个长度为N的全排列对应到一个长度为N!的数组中，这样便可以采用数组记录的方式实现去重。

##程序源码

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

##测试数据 
4
5 8 7 6
4 1 2 3

3
8 7 6 5
1 2 3 4

2
1 2 3 4
8 7 6 5

1
5 8 7 6
4 1 2 3

-1

##复杂度分析
时间复杂度：因为已经固定了数组的大小为40320，所有时间复杂度是常量级的
空间复杂度：使用的康托展开，故空间复杂度为8!