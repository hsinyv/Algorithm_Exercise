/***********************************************
* Program Ability Test Advanced Level Practice
*  No.A1062 Talent and Virtue (25 ·Ö)
* https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944
*  Date: 2021/02/21
***********************************************/
/***********************************************
* Core Mission: divide persons to different group according to theirs talent and virtue grades, 
*				and arrange them in grade non-increasing order 
* Point:  classify and sort
* Note: the only mistake I made is in transfering condition of question to judge condition.
*		Original question requires both grades is not below the lower bound, i.e. someone who has 
*		one grade, at least,do not pass the line could not be ranked. 
*		Logical predicate has changed from 'and' to 'or'.
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
enum Identity{SAGE, NOBLE, FOOL, SMALL, NON};
class Person{
public:
	string id;
	int talent_grade_;
	int virtue_grade_;
	int total_grade_;
	Person(string i, int v, int t) {
		id = i;
		talent_grade_ = t;
		virtue_grade_ = v;
		total_grade_ = t + v;
	}
	friend ostream& operator<<(ostream& out, Person p) {
		out << p.id << " " << p.virtue_grade_ << " " << p.talent_grade_ << endl;
		return out;
	}
};

Identity Judge(Person p, int min, int max) {
	if (p.talent_grade_  < min || p.virtue_grade_  < min) return NON;
	if (p.talent_grade_ >= max && p.virtue_grade_ >= max) return SAGE;
	if (p.talent_grade_  < max && p.virtue_grade_ >= max) return NOBLE;
	if (p.talent_grade_  < max && p.virtue_grade_  < max && p.virtue_grade_ >= p.talent_grade_) 
		return FOOL;
	return SMALL;
}

bool MyCom(Person a, Person b) {
	if (a.total_grade_ == b.total_grade_) {
		if (a.virtue_grade_ == b.virtue_grade_) {
			return a.id < b.id;
		}
		else return a.virtue_grade_ > b.virtue_grade_;
	}
	else return a.total_grade_ > b.total_grade_;
}

int main(void) {
	int n, min, max, person_num = 0;
	cin >> n >> min >> max;
	vector<Person> sage;
	vector<Person> noble;
	vector<Person> fool;
	vector<Person> small;
	for (size_t i = 0; i < n; i++)
	{
		string id; int t;  int v;
		cin >> id >> v >> t;
		Person p(id, v, t);
		switch (Judge(p, min, max)) {
		case SAGE: {
			sage.push_back(p); person_num++;
			break;
		}
		case NOBLE: {
			noble.push_back(p); person_num++;
			break;
		}
		case FOOL: {
			fool.push_back(p); person_num++;
			break;
		}
		case SMALL: {
			small.push_back(p); person_num++;
			break;
		}
		default: break;
		}
	}
	sort(sage.begin(), sage.end(), MyCom);
	sort(noble.begin(), noble.end(), MyCom);
	sort(fool.begin(), fool.end(), MyCom);
	sort(small.begin(), small.end(), MyCom);
	cout << person_num << endl;
	for (Person p : sage) cout << p;
	for (Person p : noble) cout << p;
	for (Person p : fool) cout << p;
	for (Person p : small) cout << p;
	return 0;
}
 
