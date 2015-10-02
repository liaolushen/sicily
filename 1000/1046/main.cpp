#include <iostream>
#include <string>

using namespace std;

struct Path {
  int begin;
  int end;
  double value;
};

void pathSort(Path* pathList, int size) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = i+1; j < size; ++j) {
			if (pathList[i].value < pathList[j].value) {
				Path tmp = pathList[i];
				pathList[i] = pathList[j];
				pathList[j] = tmp;
			} else if (pathList[i].value == pathList[j].value) {
				if ((pathList[i].end - pathList[i].begin) <
					(pathList[j].end - pathList[j].begin)) {
					Path tmp = pathList[i];
					pathList[i] = pathList[j];
					pathList[j] = tmp;
				} else if ((pathList[i].end - pathList[i].begin) ==
					(pathList[j].end - pathList[j].begin)) {
					if (pathList[i].begin > pathList[j].begin) {
						Path tmp = pathList[i];
						pathList[i] = pathList[j];
						pathList[j] = tmp;
					}
				}
			}
		}
	}
}

int insertPath(Path* pathList, Path newPath, int required, int size) {
	if (required == 0) {
		return 0;
	}

	if (size < required) {
		pathList[size] = newPath;
		size++;
		pathSort(pathList, size);
		return size;
	}

	if (pathList[size-1].value < newPath.value) {
		pathList[size-1] = newPath;
		pathSort(pathList, size);
	} else if (pathList[size-1].value == newPath.value) {
		if ((pathList[size-1].end - pathList[size-1].begin) <
			(newPath.end - newPath.begin)) {
			pathList[size-1] = newPath;
			pathSort(pathList, size);
		} else if ((pathList[size-1].end - pathList[size-1].begin) ==
			(newPath.end - newPath.begin)) {
			if (pathList[size-1].begin > newPath.begin) {
				pathList[size-1] = newPath;
				pathSort(pathList, size);
			}
		}
	}
	return size;
}

int main() {
	int T;
	cin >> T;
	for (int index = 1; index <= T; ++index) {
		int N, required, distance;
		cin >> N >> required >> distance;
		int line[301];
		for (int i = 0; i < N; ++i) {
			cin >> line[i];
		}

		Path pathList[101];
		int size = 0;

		for (int i = distance; i <= N; ++i) {
			for (int j = 0; j <= N-i; ++j) {
				Path newPath;
				newPath.begin = j+1;
				newPath.end = j+i;
				newPath.value = 0;
				for (int s = 0; s < i; ++s) {
					newPath.value += (double) line[j+s];
				}
				newPath.value /= i;
				
				size = insertPath(pathList, newPath, required, size);
			}
		}

		cout << "Result for run " << index << ":" << endl;
		for (int i = 0; i < size; ++i) {
			cout << pathList[i].begin << "-" << pathList[i].end << endl;
		}

	}
	return 0;
}
