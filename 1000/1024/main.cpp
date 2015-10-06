#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Path {
	int from;
	int to;
	int length;

	Path(int f, int t, int l) {
		from = f;
		to = t;
		length = l;
	}
};

struct City {
	int length;
	bool isvisited;
	vector<Path> localPath;
} city[10001];

int main() {
	int N, K;
	while (cin >> N >> K) {
		// init
		int maxLength = -1;
		for (int i = 0; i <= 10001; ++i) {
			city[i].length = 0;
			city[i].isvisited = false;
			city[i].localPath.clear();
		}

		for (int i = 0; i < N-1; ++i) {
			int f, t, l;
			cin >> f >> t >> l;
			city[f].localPath.push_back(Path(f, t, l));
			city[t].localPath.push_back(Path(t, f, l));
		}

		stack<Path> toVisit;
		Path currentPath(0, 0, 0);
		int currentCity = K;
		while (currentCity != 0) {
			city[currentCity].isvisited = true;
			if (currentPath.from != 0) {
				city[currentCity].length = city[currentPath.from].length + currentPath.length;
			} else {
				city[currentCity].length = 0;
			}
			if (city[currentCity].length > maxLength) maxLength = city[currentCity].length;

			while (!city[currentCity].localPath.empty()) {
				toVisit.push(city[currentCity].localPath.back());
				city[currentCity].localPath.pop_back();
			}

			do {
				if (!toVisit.empty()) {
					currentPath = toVisit.top();
					toVisit.pop();
					currentCity = currentPath.to;
				} else {
					currentCity = 0;
				}
			} while (currentCity != 0 && city[currentCity].isvisited);
		}
		cout << maxLength << endl;
	}
}