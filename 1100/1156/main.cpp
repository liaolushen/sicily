#include <iostream>
#include <stack>

using namespace std;

struct Node {
	char value;
	int leftNode, rightNode;
} tree[1001];

int isRoot[1001];

int getRoot() {
	for (int i = 1; i <= 1000; ++i) {
		if (isRoot[i] == 2) return i;
	}
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= 1000; ++i) {
			isRoot[i] = 0;
		}

		for (int i = 1; i <= n; ++i) {
			int id;
			cin >> id;
			cin >> tree[id].value
				>> tree[id].leftNode
				>> tree[id].rightNode;
			if (isRoot[id] != 1) isRoot[id] = 2;
			if (tree[id].leftNode != 0) isRoot[tree[id].leftNode] = 1;
			if (tree[id].rightNode != 0) isRoot[tree[id].rightNode] = 1;
		}

		stack<int> right;

		int root = getRoot();

		while (root) {
			cout << tree[root].value;
			if (tree[root].rightNode != 0) right.push(tree[root].rightNode);
			if (tree[root].leftNode != 0) {
				root = tree[root].leftNode;
			} else {
				if (!right.empty()) {
					root = right.top();
					right.pop();
				} else {
					cout << endl;
					break;
				}
			}
		}
	}
}