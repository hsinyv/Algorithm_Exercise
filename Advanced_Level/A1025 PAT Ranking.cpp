#include <iostream>
#include <fstream>
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
typedef vector<int> vt;
typedef map<string, int> mt;
typedef pair<string, int> pt;
typedef vector<pt> vp;

class student {
public:
	string id;
	int score;
	int final_rank;
	int pos;
	int pos_rank;
	student(string ID, int SCORE, int POS, int PR);
};

vp map_sort_by_value(mt m) {
	vector<pt> v;
	for (auto it : m)
		v.push_back(it);
	sort(v.begin(), v.end(), [](pt a, pt b) {return a.second > b.second; });
	return v;
}

student::student(string ID, int SCORE, int POS, int PR) {
	id = ID;
	score = SCORE;
	pos = POS;
	pos_rank = PR;
	final_rank = -1;
	return;
}
bool my_compare(student a, student b) {
	//first key: score, second key: id
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return a.id < b.id;
	}
}
int main() {
	int sum, pos_sum, pos_id;
	vector<student> stu; //store all the students
	cin >> sum;	//test pos count
	string id; int score;
	for (int i = 0; i < sum; i++) {
		mt a;	//get id and score of one student and store these in a map
		cin >> pos_sum; //cases in one pos count
		pos_id = i + 1;

		for (int i = 0; i < pos_sum; i++) {
			cin >> id >> score;
			a[id] = score;	//add it in the map <a>
		}

		vp v = map_sort_by_value(a);	//sort the map by value
		vector<student> temp;
		for (int i = 0; i < v.size(); i++) {	//store all the students in the test pos to summary vector
			student s(v[i].first, v[i].second, pos_id, i + 1);	//built a student instance
			 temp.push_back(s);
		}
		for (int i = 1; i < temp.size(); i++) {
			//deal with the rank for the same score student
			if (temp[i].score == temp[i - 1].score) {
				temp[i].pos_rank = temp[i - 1].pos_rank;
				if (temp[i].id < temp[i - 1].id) {
					swap(temp[i], temp[i - 1]);
				}
			}
			
		}
		stu.insert(stu.end(), temp.begin(),temp.end());	//add it in to summary vector <stu>
	}
	sort(stu.begin(), stu.end(), my_compare);
	//sort the summary vector <stu> by member's score

	//assign the final_rank
	stu[0].final_rank = 1;
	for (int i = 1; i < stu.size(); i++) {
		stu[i].final_rank = i + 1;
		//deal with the rank for the same score student
		if (stu[i].score == stu[i - 1].score) {
			stu[i].final_rank = stu[i - 1].final_rank;
		}
	
	}
	
	/*ofstream out("out.txt");
	out << stu.size() << endl;
	for (auto it : stu) {
		out << it.id << " " << it.final_rank << " " << it.pos << " " << it.pos_rank << " " << it.score << endl;
	}
	out.close();
	system("pause");*/
	cout << stu.size() << endl;
	for (auto it : stu) {
		cout << it.id << " " << it.final_rank << " " << it.pos << " " << it.pos_rank << endl;
	}
	//system("pause");
	return 0;
}
