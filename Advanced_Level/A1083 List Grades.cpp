/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1083 List Grades
*  https://pintia.cn/problem-sets/994805342720868352/problems/994805383929905152
*  Date: 2021/02/24
***********************************************/
/***********************************************
* Core Mission: get input data and arrange student whose grade is in scope in score 
*				non-decresing order
* Point: returned value of erase function must be assigned to original iterator
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Student {
public:
	string name_;
	string id_;
	int grade_;
	Student(string name, string id, int grade) {
		name_ = name;
		id_ = id;
		grade_ = grade;
	}
};

bool MyComp(Student a, Student b) {
	return a.grade_ >= b.grade_;
}
int main(void) {
	int n; cin >> n;
	vector<Student> all_student;
	for (size_t i = 0; i < n; i++)
	{
		string name, id; int grade;
		cin >> name >> id >> grade;
		Student stu(name, id, grade);
		all_student.push_back(stu);
	}
	int min_grade, max_grade;
	cin >> min_grade >> max_grade;
	for (auto it = all_student.begin(); it < all_student.end();) {
		if ((*it).grade_ < min_grade || (*it).grade_ > max_grade) {
			it = all_student.erase(it);
		}
		else {
			++it;
		}
	}
	if (all_student.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		sort(all_student.begin(), all_student.end(), MyComp);
		for (auto i : all_student)
			cout << i.name_ << " " << i.id_ << endl;
	}
	
	return 0;
}
 
