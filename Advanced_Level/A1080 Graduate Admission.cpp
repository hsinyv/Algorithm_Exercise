/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1080 Graduate Admission
*  https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136
*  Date: 2021/02/24
***********************************************/
/***********************************************
* Core Mission: get input data correctly and well design the process of admission
* Point:  admission rule, particularly the applicants with same rank
* !!!
	//pay attention to consturctor of 'vector'
	//explicit vector (size_type n);
	//vector(size_type n, const value_type & val,
	//	const allocator_type & alloc = allocator_type());
	//Constructs a container with n elements. Each element is a copy of val (if provided).
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

class Applicant {
public:
	int No_;
	double exam_grade_;
	double interview_grade_;
	double final_grade_;
	vector<int> choice_;
	int rank_;
	Applicant(int No, int exam_grade, int interview_grade, int choice_num_max) {
		No_ = No;
		exam_grade_ = exam_grade;
		interview_grade_ = interview_grade;
		final_grade_ = (exam_grade + interview_grade) / 2;
		rank_ = -1;
	}
	bool GetChoice_(int choice_num_max) {
		for (size_t i = 0; i < choice_num_max; i++)
		{
			int t;
			cin >> t;
			choice_.push_back(t);
		}
		return true;
	}
};

bool MyComp(Applicant a, Applicant b) {
	if (a.final_grade_ == b.final_grade_) {
		//return a.exam_grade_ >= b.exam_grade_;
		//error:incompatible operator ???
		return a.exam_grade_ > b.exam_grade_;
	}
	else {
		return a.final_grade_ > b.final_grade_;
	}
}

void SetRank(vector<Applicant>& all_applicants) {
	int cnt = 0, rank = 0;
	double prev_final_grade = all_applicants[0].final_grade_;
	double prev_exam_grade = all_applicants[0].exam_grade_;
	double cur_final_grade = prev_final_grade;
	double cur_exam_grade = prev_exam_grade;
	for (size_t i = 0; i < all_applicants.size(); i++)
	{
		cur_final_grade = all_applicants[i].final_grade_;
		cur_exam_grade = all_applicants[i].exam_grade_;
		if ((cur_final_grade == prev_final_grade) && (cur_exam_grade == prev_exam_grade))
		{
		}
		else {
			rank = cnt;
		}
		all_applicants[i].rank_ = rank;
		prev_final_grade = cur_final_grade;
		prev_exam_grade = cur_exam_grade;
		++cnt;
	}
	return;
}

vector<vector<int>> Admission (vector<Applicant> all_appicants, vector<int> &school_quota, int school_num, int choice_num_max) {
	vector<vector<int>> admission_result;
	admission_result.resize(school_num);

	vector<int> lastest_admitted_rank(school_num, -1);
	//error: vector<int> lastest_admitted_rank(-1);
	
	for (auto applicant : all_appicants) {
		for (auto prefered_school : applicant.choice_) {
			if ((school_quota[prefered_school] > 0) || \
				(lastest_admitted_rank[prefered_school] == applicant.rank_)) {
				school_quota[prefered_school]--;
				admission_result[prefered_school].push_back(applicant.No_);
				lastest_admitted_rank[prefered_school] = applicant.rank_;
				break;
			}
		}
	}
	for (auto it = admission_result.begin(); it < admission_result.end(); ++it) {
		sort((*it).begin(), (*it).end());
	}
	/*error
	for (auto i : admission_result)
		sort(i.begin(), i.end());*/
	return admission_result;
}

int main(void) {
	int applicant_num, school_num, choice_num_max;
	cin >> applicant_num >> school_num >> choice_num_max;
	//applicants, schools, and rank are all numbered from 0
	vector<int> school_quota;
	vector<Applicant> all_applicants;
	for (size_t i = 0; i < school_num; i++)
	{
		int t;
		cin >> t;
		school_quota.push_back(t);
	}
	for (size_t i = 0; i < applicant_num; i++)
	{
		int exam_grade; int interview_grade;
		cin >> exam_grade >> interview_grade;
		Applicant a(i, exam_grade, interview_grade, choice_num_max);
		a.GetChoice_(choice_num_max);
		all_applicants.push_back(a);
	}
	sort(all_applicants.begin(), all_applicants.end(), MyComp);
	SetRank(all_applicants);
	vector<vector<int>> admission_result = \
		Admission(all_applicants, school_quota, school_num, choice_num_max);
	for (auto i : admission_result) {
		if (i.size() != 0) {
			for (auto j = 0; j < i.size(); ++j) {
				cout << i[j];
				if (j < i.size() - 1) cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
 

