#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <iomanip>
using namespace std;
class student {
public:
	string No;
	string name;
	string gender;
	int age;
	void add();
	void print();
};
void student::add() {
	cin >> No >> name >> gender >> age;
}
void student::print() {
	cout << No << " " << name << " " << gender << " " << age << endl;
}
int main() {
	int n1;
	while(cin >> n1){
		student *a = new student[n1];
		for (int i = 0; i < n1; i++) {
			a[i].add();
		}
		int n2;
		cin >> n2;
		for (int i = 0; i < n2; i++) {
			bool not_found = true;
			string s;
			cin >> s;
			for (int i = 0; i < n1; i++) {
				if (a[i].No == s) {
					a[i].print();
					not_found = false;
					break;
				}
			}
			if (not_found) cout << "No Answer!" << endl;		
		}
		delete []a;	
	}
	return 0;
}
