#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int minId; // 最小的Node的id
    int nodeCount; // 子Node的数量，含自己
    vector<int> adjacentNodeId; // 相邻的Node
};

struct SubTree {
    int inNodeId; // 切除后靠近root的点
    int outNodeId; // 切除后远离root的点
    int nodeCount;
    int minId;
    bool isWithRoot;
    SubTree() {}
    SubTree(int _inNodeId, int _outNodeId, int _nodeCount, int _minId, bool _isWithRoot):
        inNodeId(_inNodeId), outNodeId(_outNodeId), nodeCount(_nodeCount),
            minId(_minId), isWithRoot(_isWithRoot) {}
};

// set minId and nodeCount to Node
void setNode(vector<Node> &tree, int selfId, int fatherId) {
    tree[selfId].minId = selfId;
    tree[selfId].nodeCount = 1;
    for (vector<int>::iterator it = tree[selfId].adjacentNodeId.begin();
        it != tree[selfId].adjacentNodeId.end(); it++) {
        if (*it != fatherId) {
            setNode(tree, *it, selfId);
            tree[selfId].nodeCount += tree[*it].nodeCount;
            tree[selfId].minId = min(tree[selfId].minId, tree[*it].minId);
        }
    }
}

bool better(SubTree g, SubTree h) {
    if (g.nodeCount != h.nodeCount) return g.nodeCount > h.nodeCount;

    if (g.isWithRoot) {
        return true;
    } else {
        if (h.isWithRoot) return false;
        else return g.minId < h.minId;
    }
}

void searchAnswer(vector<Node> &tree, int rootId, int selfId, int fatherId, SubTree &result) {
    for (vector<int>::iterator it = tree[selfId].adjacentNodeId.begin();
        it != tree[selfId].adjacentNodeId.end(); it++) {
        if (*it != fatherId) {
            // 判断切下来的子树是否符合要求
            if (tree[*it].nodeCount <= tree[rootId].nodeCount/2) {
                SubTree t1(selfId, *it, tree[*it].nodeCount, tree[*it].minId, false);
                if (better(t1, result)) result = t1;
            }

            // 判断切剩的子树是否符合要求
            if ((tree[rootId].nodeCount - tree[*it].nodeCount) <= tree[rootId].nodeCount/2) {
                SubTree t2(selfId, *it, tree[rootId].nodeCount - tree[*it].nodeCount,
                    rootId, true);
                if (better(t2, result)) result = t2;
            }
            searchAnswer(tree, rootId, *it, selfId, result);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Node> gold(30001);
    int x, y;
    for (int i = 0; i < n-1; ++i) {
        cin >> x >> y;
        gold[x].adjacentNodeId.push_back(y);
        gold[y].adjacentNodeId.push_back(x);
    }

    vector<int> ans;

    SubTree result;
    int root = 1;

    for (int i = 1; i < k; ++i) {
        setNode(gold, root, 0);
        result.nodeCount = 0;
        searchAnswer(gold, root, root, 0, result);
        ans.push_back(result.nodeCount);
        int fatherId;
        int toEraseId;
        if (result.isWithRoot) {
            fatherId = result.outNodeId;
            toEraseId = result.inNodeId;
            root = gold[fatherId].minId;
        } else {
            fatherId = result.inNodeId;
            toEraseId = result.outNodeId;
        }

        for (vector<int>::iterator it = gold[fatherId].adjacentNodeId.begin();
                it != gold[fatherId].adjacentNodeId.end();) {
            if (*it == toEraseId) {
                it = gold[fatherId].adjacentNodeId.erase(it);
            } else {
                it++;
            }
        }
    }

    int size = n;
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << ' ';
        size -= *it;
    }

    cout << size << endl;
}