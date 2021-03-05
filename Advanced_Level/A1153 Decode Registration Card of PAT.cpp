/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1153 Decode Registration Card of PAT
*  Date: 2021/02/25
***********************************************/
/***********************************************
* Core Mission: 
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
	string card_;
	string test_level_;
	string test_site_;
	string test_date_;
	string serial_num_;
	int score_;
	Testee(string card, int score) {
		card_ = card;
		test_level_ = card.substr(0, 1);
		test_site_ = card.substr(1, 3);
		test_date_ = card.substr(4, 6);
		serial_num_ = card.substr(10, 3);
		score_ = score;
	}
};
class TestSite {
public:
	string site_;
	int visit_num_;
	TestSite(string site) {
		site_ = site;
		visit_num_ = 0;
	}
};
vector<Testee> GetTesteesOfSpecificLevel(vector<Testee> all_testees, string level) {
	vector<Testee> testees_of_specific_level;
	for (auto i : all_testees) {
		if (i.test_level_ == level)
		{
			testees_of_specific_level.push_back(i);
		}
	}
	return testees_of_specific_level;
}

bool MyCompI(Testee a, Testee b) {
	if (a.score_ == b.score_) {
		return a.card_ < b.card_;
	}
	else {
		return a.score_ > b.score_;
	}
}
void SpecificLevelSort(vector<Testee> all_testees, string level) {
	vector<Testee> testees_of_specific_level = GetTesteesOfSpecificLevel(all_testees, level);
	if (testees_of_specific_level.size() == 0) {
		cout << "NA\n";
	}
	else {
		sort(testees_of_specific_level.begin(), testees_of_specific_level.end(), MyCompI);
		for (auto i : testees_of_specific_level) {
			cout << i.card_ << " " << i.score_ << endl;
		}
	}
	return;
}
void TotalScoreOfSpecificSite(vector<Testee> all_testees, string site) {
	int total_score = -1; int testees_num = -1;
	for (auto i : all_testees) {
		if (i.test_site_ == site)
		{
			if ((total_score == -1) || (testees_num == -1)) {
				total_score = i.score_;
				testees_num = 1;
			}
			else {
				total_score += i.score_;
				++testees_num;
			}
		}
	}
	if ((total_score == -1) || (testees_num == -1)) {
		cout << "NA\n";
	}
	else {
		cout << testees_num << " " << total_score << endl;
	}
	return;
}

int FindSite(vector<TestSite> all_sites, string site) {
	for (int i = 0; i < all_sites.size(); i++)
	{
		if (all_sites[i].site_== site) return i;
	}
	return -1;
}
bool MyCompIII(TestSite a, TestSite b) {
	if (a.visit_num_ == b.visit_num_) {
		return a.site_ < b.site_;
	}
	else {
		return a.visit_num_ > b.visit_num_;
	}
}
void TotalScoreOfSpecificDate(vector<Testee> all_testees, string date) {
	vector<TestSite> all_sites;
	for (auto i : all_testees) {
		if (i.test_date_ == date) {
			int index = FindSite(all_sites, i.test_site_);
			if (index == -1) {
				TestSite ts(i.test_site_);
				index = all_sites.size();
				all_sites.push_back(ts);
			}
			all_sites[index].visit_num_ += 1;
		}
	}
	if (all_sites.size() == 0) {
		cout << "NA\n";
	}
	else {
		sort(all_sites.begin(), all_sites.end(), MyCompIII);
		for (auto i : all_sites) {
			cout << i.site_ << " " << i.visit_num_ << endl;
		}
	}
	return;	
}

int main(void) {
	int cards_num, queries_num;
	cin >> cards_num >> queries_num;
	vector<Testee> all_testees;
	for (int i = 0; i < cards_num; i++)
	{
		string card; int score;
		cin >> card >> score;
		Testee t(card, score);
		all_testees.push_back(t);
	}
	for (int i = 0; i < queries_num; i++)
	{
		int type;
		string term;
		cin >> type >> term;
		cout << "Case " << i + 1 << ": " << type << " " << term << endl;
		switch (type)
		{
		case 1: {
			SpecificLevelSort(all_testees, term);
			break;
		}
		case 2: {
			TotalScoreOfSpecificSite(all_testees, term);
			break;
		}
		case 3: {
			TotalScoreOfSpecificDate(all_testees, term);
			break;
		}
		default:
			break;
		}
	}

	return 0;
}
 
