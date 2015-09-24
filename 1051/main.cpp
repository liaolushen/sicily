#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	double diameter;
	int revolutions;
	double usedTime;
	int index = 0;

	cin >> diameter >> revolutions >> usedTime;
	while(revolutions) {
		index++;
		double miles;
		double MPH;
		miles = (3.1415926*diameter*revolutions)/(5280*12);
		MPH = miles/(usedTime/3600);
		cout << "Trip #" << index << ": ";
		cout << setiosflags(ios::fixed) << setprecision(2) << miles << ' ' << MPH << endl;
		cin >> diameter >> revolutions >> usedTime;
	}

	return 0;
}