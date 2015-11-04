#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    string name;
    int lastScore;
    int classScore;
    bool isLeader;
    bool isWest;
    int thesisNum;
    int scholar;
    Student() {}
    Student(string _name,
        int _lastScore,
        int _classScore,
        char _isLeader,
        char _isWest,
        int _thesisNum) {
        name = _name;
        lastScore = _lastScore;
        classScore = _classScore;
        isLeader = (_isLeader == 'Y') ? true : false;
        isWest = (_isWest == 'Y') ? true : false;
        int thesisNum = _thesisNum;

        scholar = 0;
        if (lastScore > 80 && thesisNum > 0) scholar += 8000;
        if (lastScore > 85 && classScore > 80) scholar += 4000;
        if (lastScore > 90) scholar += 2000;
        if (lastScore > 85 && isWest) scholar += 1000;
        if (classScore > 80 && isLeader) scholar += 850;
    }
};

int main() {
    int N;
    cin >> N;
    string name;
    int lastScore;
    int classScore;
    char isLeader;
    char isWest;
    int thesisNum;

    string bestName;
    int bestScholar = -1;
    int totalScholar = 0;
    while (N--) {
        cin >> name >> lastScore >>  classScore
        >> isLeader >> isWest >> thesisNum;
        Student s = Student(name, lastScore, classScore, isLeader, isWest, thesisNum);
        totalScholar += s.scholar;
        if (s.scholar > bestScholar) {
            bestName = s.name;
            bestScholar = s.scholar;
        }
    }
    cout << bestName << endl;
    cout << bestScholar << endl;
    cout << totalScholar << endl;
}