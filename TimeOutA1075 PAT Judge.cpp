/***********************************************
* Program Ability Test Advanced Level Practice
*  No.A1075 PAT Judge
* https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032
*  Date: 2021/02/22
***********************************************/
/***********************************************
* Core Mission: get every submission and update user score correctly, then print the rank
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
//typedef vector<User>::iterator Vi;
vector<int> g_full_mark;

class User {
public:
	string id_;
	vector<int> submission_;
	int total_score_;
	int perfectly_solving_num;
	User(string id, int k) {
		id_ = id;
		for (size_t i = 0; i <= k; i++)
		{
			submission_.push_back(-2);
			//-1 denotes did not pass compiler
			//-2 denotes did not submit
		}
		total_score_ = 0;
		perfectly_solving_num = 0;
	}
	friend ostream& operator<<(ostream& out, User u) {
		out << u.id_ << " " << u.total_score_ << " ";
		for (size_t i = 1; i < u.submission_.size(); i++)
		{
			if (u.submission_[i] >= 0) out << u.submission_[i];
			else out << "-";
			if (i < u.submission_.size() - 1) out << " ";
			//print - for no submission
			//print 0 for compiler error
		}
		out << endl;
		return out;
	}
	//void print() {
	//	printf("%s %d ", id_.c_str(), total_score_);
	//	for (size_t i = 1; i < submission_.size(); i++)
	//	{
	//		if (submission_[i] >= 0) printf("%d", submission_[i]);
	//		else printf("-");
	//		if (i < submission_.size() - 1) printf(" ");
	//		//print - for no submission
	//		//print 0 for compiler error
	//	}
	//	printf("\n");
	//}
	void InsertSubmission(int problem_id, int score) {
		int prev_score = submission_[problem_id];	
		//get this problem's current score
		if (prev_score < score)
		{	//this submission is the best in all historical submissions of this problem
			//and operator '<' make sure that perfect solving will be recorded only once
			submission_[problem_id] = (score == -1) ? 0 : score;
			if (score >= 0)submission_[0] = 1;
			//denote that there is at least one submission pass compiler
		}
		return;
	}
	void Calculate() {
		for (size_t i = 1; i < submission_.size(); i++)
		{
			if (submission_[i] > 0) {
				//update the best score
				total_score_ += submission_[i];
				//update total score
				if (submission_[i] >= g_full_mark[i])
				{
					perfectly_solving_num++;
				}
			}
		}
		return;
	}
};

vector<User>::iterator FindUser(vector<User> &all_user, const string id, int k){
	 auto it = all_user.begin();
	 for (it = all_user.begin(); it < all_user.end(); it++) {
		 if ((*it).id_ == id) return it;
	 }
	 User u(id, k);
	 all_user.push_back(u);
	 return (all_user.end() - 1);
	 //rbegin() can not be the return value because type incompatible
	 //end() can not be the return value and compare in the place calling this function
	 //because end() is not a specific value, == is invalid.
}

void InsertSubmission(vector<User> &all_user, const string id, const int problem_id, const int score, int k) {
	vector<User>::iterator it = FindUser(all_user, id, k);

	(*it).InsertSubmission(problem_id, score);
	return;
}
bool MyCom(User a, User b) {
	if (a.total_score_ == b.total_score_) {
		if (a.perfectly_solving_num == b.perfectly_solving_num) {
			return a.id_ < b.id_;
		}
		else {
			return a.perfectly_solving_num >= b.perfectly_solving_num;
		}
	}
	else {
		return a.total_score_ >= b.total_score_;
	}
}
int main(void) {
	int n, k, m;
	//scanf("%d %d %d", &n, &k, &m);
	cin >> n >> k >> m;
	g_full_mark.push_back(-1); //occupy one pos so that index will correspond to problem id
	for (size_t i = 0; i < k; i++)
	{
		int t;
		//scanf("%d", &t);
		cin >> t; 
		g_full_mark.push_back(t);
	}
	vector<User> all_user;
	for (size_t i = 0; i < m;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     i++)
	{
		string id; int problem_id; int score;
		//id.resize(5);
		//scanf("%s %d %d", &id[0], &problem_id, &score);
		cin >> id >> problem_id >> score;
		InsertSubmission(all_user, id, problem_id, score, k);
	}

	for (auto it = all_user.begin(); it < all_user.end();) {
		//delete users without any valid submissions
		if ((*it).submission_[0] < 1)
		{
			it = all_user.erase(it);
		}
		else ++it;
	}

	for (auto &it : all_user)
		it.Calculate();
	
	sort(all_user.begin(), all_user.end(), MyCom);

	int rank = 1, cnt = 1; int prev_total_score = all_user[0].total_score_;
	for (auto i : all_user) {
		if (i.total_score_ < prev_total_score) rank = cnt;
		prev_total_score = i.total_score_;
		//printf("%d ", rank);
		cout << rank << " ";
		//i.print();
		cout << i;
		cnt++;
	}
		
	return 0;
}
 

