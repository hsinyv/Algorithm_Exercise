/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1141 PAT Ranking of Institutions
*  Date: 2021/02/25
***********************************************/
/***********************************************
* Core Mission: define a good architectured DS
* Point:  
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

class Testee {
public:
	string id_;
	int score_;
	string school_;
	Testee(string id, int score, string school) {
		id_ = id;
		score_ = score;
		school_ = school;
	}
};
class Institute {
public:
	string school_;
	int rank_;
	int score_sum_basic_;
	int score_sum_advanced_;
	int score_sum_top_;
	int total_weighted_score_;
	int num_testees;
	Institute(string school) {
		school_ = school;
		rank_ = 0;
		score_sum_basic_ = 0;
		score_sum_advanced_ = 0;
		score_sum_top_ = 0;
		total_weighted_score_ = 0;
		num_testees = 0;
	}
	bool AddNewTestee(Testee t) {
		if (t.school_ != school_) return false;
		char test_level = t.id_[0];
		switch (test_level) {
		case 'B': {
			++num_testees;
			score_sum_basic_ += t.score_;
			break;
		}
		case 'A': {
			++num_testees;
			score_sum_advanced_ += t.score_;
			break;
		}
		case 'T': {
			++num_testees;
			score_sum_top_ += t.score_;
			break;
		}
		default:break;
		}
		return true;
	}
	void CalculateTWS() {
		total_weighted_score_ = (score_sum_basic_ / 1.5) + score_sum_advanced_ + (score_sum_top_ * 1.5);
		return;
	}
};

void AddNewTestee(Testee &t, vector<Institute>& all_institutes) {
	int index = -1;
	for (size_t i = 0; i < all_institutes.size(); i++)
	{
		if ((all_institutes[i]).school_ == t.school_) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		Institute institute(t.school_);
		index = all_institutes.size();
		all_institutes.push_back(institute);
	}
	all_institutes[index].AddNewTestee(t);
}

bool MyComp(Institute a, Institute b) {
	if (a.total_weighted_score_ == b.total_weighted_score_) {
		if (a.num_testees == b.num_testees) {
			return a.school_ < b.school_;
		}
		else {
			return a.num_testees < b.num_testees;
		}
	}
	else {
		return a.total_weighted_score_ > b.total_weighted_score_;
	}
}

int main(void) {
	int n; cin >> n;
	vector<Institute> all_institutes;
	for (size_t i = 0; i < n; i++)
	{
		string id; int score; string school;
		cin >> id >> score >> school;
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		Testee t(id, score, school);
		AddNewTestee(t, all_institutes);
	}
	for (auto &i : all_institutes) {
		i.CalculateTWS();
	}
	sort(all_institutes.begin(), all_institutes.end(), MyComp);
	int prev_TWS = all_institutes[0].total_weighted_score_;
	int rank = 1;
	int cnt = 1;
	for (auto &i : all_institutes) {
		if (i.total_weighted_score_ < prev_TWS) rank = cnt;
		i.rank_ = rank;
		prev_TWS = i.total_weighted_score_;
		++cnt;
	}
	cout << all_institutes.size() << endl;
	for (auto institute : all_institutes) {
		cout << institute.rank_ << " " << institute.school_ << " " << institute.total_weighted_score_\
			<< " " << institute.num_testees << endl;
	}
	
	return 0;
}
 
