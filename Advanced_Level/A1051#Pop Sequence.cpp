/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1051 Pop Sequence
*  Date: 2021/03/16
***********************************************/
/***********************************************
* Core Mission: to check a pop sequence if legal for a size-specified stack
* Point: the data to push is follow a specified order, so it is easy to judge 
			if the element has been pushed
*		1) in stack:	 'pop' and compare to current element
*		2) not in stack: 'push' all elements in [max pushed element + 1, current element] range
*		operation legality will be checked when pushing or poping
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;
typedef stack<int> stack_;
int stack_max_capacity = 0;
bool Push(stack_ &s, int e) {
	if (s.size() >= stack_max_capacity) return false;
	else {
		s.push(e);
		return true;
	}
}
bool Pop(stack_ &s, int &e) {
	if (s.empty()) return false;
	else {
		e = s.top();
		s.pop();
		return true;
	}
}

int StackTop(stack_ s) {
	if (s.empty())return 0;
	else return s.top();
}

bool CheckPopSeq(vector<int> pop_seq) {
	int max_element = 0;
	int cur_element = 0;
	stack_ simulation;
	for (int i = 0; i < pop_seq.size();)
	{
		cur_element = pop_seq[i];
		if (cur_element <= max_element) {
			//cur_element is in stack
			int pop_item = 0;
			if (Pop(simulation, pop_item) == false) return false;
			if (pop_item != cur_element) return false;
			else {
				++i;
			}
		}
		else {
			//cur_element is not in stack
			for (int i = max_element + 1; i <= cur_element; i++) {
				if (Push(simulation, i) == false) return false;
			}
		}
		max_element = (cur_element > max_element) ? cur_element : max_element;
	}
	return true;
}

int main(void) {
	int len_pop_seq, num_pop_seqs;
	cin >> stack_max_capacity >> len_pop_seq >> num_pop_seqs;
	for (int i = 0; i < num_pop_seqs; i++)
	{
		vector<int> pop_seq;
		for (int i = 0; i < len_pop_seq; i++)
		{
			int item; cin >> item;
			pop_seq.push_back(item);
		}
		if (CheckPopSeq(pop_seq)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
 
