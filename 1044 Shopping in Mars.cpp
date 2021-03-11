/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.1044 Shopping in Mars
*  Date: 2021/03/07
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

class PaymentSolution {
public:
	int starting_index_;
	int end_index_;
	int total_value_;
	bool exact_suffient_;
	PaymentSolution(int start, int end, int total, bool suffient) {
		starting_index_ = start + 1;
		end_index_ = end + 1;
		total_value_ = total;
		exact_suffient_ = suffient;
	}
};

bool ExactSolutionCmp(PaymentSolution a, PaymentSolution b) {
	return a.starting_index_ < b.starting_index_;
}
bool ExceedingSolutionCmp(PaymentSolution a, PaymentSolution b) {
	if (a.total_value_ == b.total_value_) {
		return a.starting_index_ < b.starting_index_;
	}
	else {
		return a.total_value_ < b.total_value_;
	}
}

int main(void) {
	int diamonds_num, payables;
	cin >> diamonds_num >> payables;
	vector<int> diamonds_value;
	for (int i = 0; i < diamonds_num; i++)
	{
		int diamond_value_input;	cin >> diamond_value_input;
		diamonds_value.push_back(diamond_value_input);
	}
	vector<PaymentSolution> exact_payment_solution;
	vector<PaymentSolution> exceeding_payment_solution;
	for (int starting_index = 0; starting_index < diamonds_num; starting_index++)
	{
		int total_value = 0;
		int traverse_index = starting_index;
		int exact_solution_found = false;
		for (traverse_index = starting_index; traverse_index < diamonds_num; traverse_index++)
		{
			total_value += diamonds_value[traverse_index];
			if (total_value == payables) {
				PaymentSolution solution(starting_index, traverse_index, total_value, true);
				exact_payment_solution.push_back(solution);
				exact_solution_found = true;
			}
			if ((!exact_solution_found) && (total_value > payables)) {
				PaymentSolution solution(starting_index, traverse_index, total_value, false);
				exceeding_payment_solution.push_back(solution);
			}
		}		
	}
	if (exact_payment_solution.size() > 0) {
		sort(exact_payment_solution.begin(), exact_payment_solution.end(), ExactSolutionCmp);
		for (auto const solution : exact_payment_solution) {
			cout << solution.starting_index_ << "-" << solution.end_index_ << endl;
		}
	}
	else {
		sort(exceeding_payment_solution.begin(), exceeding_payment_solution.end(), ExceedingSolutionCmp);
		int min_total_value = exceeding_payment_solution[0].total_value_;
		for (auto const solution : exceeding_payment_solution) {
			if (solution.total_value_ <= min_total_value) {
				cout << solution.starting_index_ << "-" << solution.end_index_ << endl;
			}
		}
	}
	
	return 0;
}
 
