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
class Student{
	public:
	string id;
	string name;
	string gender;
	int age;
	void add();
	void print();
};

void Student::add(){
	cin >> id >> name >> gender >> age;
}
void Student::print(){
	cout << id << " " << name << " " << gender << " " << age << endl;
}
int main() {
	int case_num;
	cin >> case_num;
	int stu_num;
	while(cin >> stu_num){
		Student *a = new Student[stu_num];
		for(int i = 0 ; i < stu_num; i++){
			a[i].add();
		}
		string find_id;
		cin >> find_id;
		for(int i = 0 ; i < stu_num; i++){
			if(a[i].id == find_id) a[i].print();
		}
		delete []a;
	}
	return 0;
}
