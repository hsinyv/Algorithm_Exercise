/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1041 Be Unique
*  https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: find the first unique number in the given sequence. So number of appearence and
*	order in the sequence of every number should be recorded. In other words, numbers who appears
*	only once should be recored by their position in sequence.
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

class Number {
public:
	int number_;
	int occurrence_;
	Number(int number) {
		number_ = number;
		occurrence_ = 1;
	}
	void Appear_() {
		++occurrence_;
	}
};

int find_num(vector<Number> number_candidates, int t) {
	for (int i = 0; i < number_candidates.size(); i++)
	{
		if (number_candidates[i].number_ == t) return i;
	}
	return -1;
}

int main(void) {
	int n;	scanf("%d", &n);
	vector<Number> number_candidates;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		int index = find_num(number_candidates, t);
		if (index == -1) {
			Number number(t);
			number_candidates.push_back(number);
		}
		else {
			number_candidates[index].Appear_();
		}
	}
	for (auto it = number_candidates.begin(); it < number_candidates.end();) {
		if ((*it).occurrence_ > 1) {
			it = number_candidates.erase(it);
			//DO NOT forget to assign the return value to original iterator
		}
		else{
			++it;
		}
	}
	if (number_candidates.size() == 0) printf("None\n");
	else printf("%d\n",(number_candidates[0]).number_);

	return 0;
}
 
