#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Node{
	string op;
	int magic[2][4];

	Node(string _op, int _magic[][4]) {
		op = _op;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				magic[i][j] = _magic[i][j];
			}
		}
	}
};

int target[2][4];

void operationA(int magic[][4]) {
	for (int i = 0; i < 4; ++i) {
		int tmp = magic[0][i];
		magic[0][i] = magic[1][i];
		magic[1][i] = tmp;
	}
}

void operationB(int magic[][4]) {
	int tmp1 = magic[0][3];
	int tmp2 = magic[1][3];
	for (int i = 3; i > 0; --i) {
		magic[0][i] = magic[0][i-1];
		magic[1][i] = magic[1][i-1];
	}
	magic[0][0] = tmp1;
	magic[1][0] = tmp2;
}

void operationC(int magic[][4]) {
	int tmp = magic[0][1];
	magic[0][1] = magic[1][1];
	magic[1][1] = magic[1][2];
	magic[1][2] = magic[0][2];
	magic[0][2] = tmp;
}

bool isSame(int magic[][4], int target[][4]) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (magic[i][j] != target[i][j]) return false;
		}
	}
	return true;
}

bool isContain(Node n, vector<Node> v) {
	for (vector<Node>::iterator it = v.begin() ; it != v.end(); ++it) {
		if (isSame(it->magic, n.magic)) return true;
	}
	return false;
}


int main() {
	int N;
	while (cin >> N && N > -1) {
		vector<Node> v;
		int magic[2][4]  = {{1, 2, 3, 4}, {8, 7, 6, 5}};

		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> target[i][j];
			}
		}

		v.push_back(Node("", magic));
		int start = 0;
		Node currentNode = v[start];

		while (!isSame(currentNode.magic, target) && currentNode.op.length() <= N) {
			Node aNode = Node(currentNode.op, currentNode.magic);
			operationA(aNode.magic);
			aNode.op = currentNode.op + "A";
			if (!isContain(aNode, v)) v.push_back(aNode);

			Node bNode = Node(currentNode.op, currentNode.magic);
			operationB(bNode.magic);
			bNode.op = currentNode.op + "B";
			if (!isContain(bNode, v)) v.push_back(bNode);

			Node cNode = Node(currentNode.op, currentNode.magic);
			operationC(cNode.magic);
			cNode.op = currentNode.op + "C";
			if (!isContain(cNode, v)) v.push_back(cNode);

			currentNode = v[++start];
		}

		if (currentNode.op.length() > N) {
			cout << -1 << endl;
		} else {
			cout << currentNode.op.length() << ' ' << currentNode.op << endl;
		}
	}
}