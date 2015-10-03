#include <iostream>
#include <cstdlib>
#include <stack>
#include <map>

using namespace std;

struct Employee {
	int id;
	int salary;
	int height;
	int boss;
	int subordinates;
};

Employee employees[30001];

int partition(Employee* employees, int lo, int hi) {
	int loPtr = lo;
	int hiPtr = hi+1;
	while (true) {
		while (employees[++loPtr].salary >= employees[lo].salary) {
			if (loPtr >= hi) break;
		}

		while (employees[--hiPtr].salary <= employees[lo].salary) {
			if (hiPtr <= lo) break;
		}

		if ( loPtr >= hiPtr) break;
		Employee tmp = employees[loPtr];
		employees[loPtr] = employees[hiPtr];
		employees[hiPtr] = tmp;
	}
	Employee tmp = employees[lo];
	employees[lo] = employees[hiPtr];
	employees[hiPtr] = tmp;

	return hiPtr;
}

void qsort(Employee* employees, int lo, int hi) {
	if (hi > lo) {
		int pivot = partition(employees, lo, hi);
		qsort(employees, lo, pivot-1);
		qsort(employees, pivot+1, hi);
	}
}

int main() {
	int N;
	cin >> N;
	while(N--) {
		int m, q;
		cin >> m >> q;
		for (int i = 0; i < m; i++) {
			cin >> employees[i].id
				>> employees[i].salary
				>> employees[i].height;
			employees[i].subordinates = 0;
			employees[i].boss = 0;
		}
		// 将所有职员按工资排序
		qsort(employees, 0, m-1);

		map<int, int> idToIndex;

		stack<int> toFindBoss;
		for (int i = m-1; i >= 0; --i) {
			while (!toFindBoss.empty() &&
				employees[toFindBoss.top()].height <= employees[i].height) {
				employees[toFindBoss.top()].boss = employees[i].id;
				employees[i].subordinates += employees[toFindBoss.top()].subordinates+1;
				toFindBoss.pop();
			}
			toFindBoss.push(i);
			idToIndex[employees[i].id] = i;
		}

		for (int i = 0; i < q; ++i) {
			int id;
			cin >> id;

			cout << employees[idToIndex[id]].boss << ' '
			<< employees[idToIndex[id]].subordinates << endl;
		}
	}
}