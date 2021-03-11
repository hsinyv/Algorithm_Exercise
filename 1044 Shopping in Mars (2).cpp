/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.1044 Shopping in Mars
*  Date: 2021/03/07
***********************************************/
/***********************************************
* version 2 solve 2 test case which are time out for version 1 and 1 test case left 
* for which program outputs wrong answer
* After checking carefully, a statement "--i" was typed in wrongly as "++i"
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
	PaymentSolution() {
	}
	PaymentSolution(int start, int end, int total, bool suffient) {
		starting_index_ = start;
		end_index_ = end;
		total_value_ = total;
		exact_suffient_ = suffient;
	}
	void SetSolution(int start, int end, int total, bool suffient) {
		starting_index_ = start;
		end_index_ = end;
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
	//scanf("%d %d", &diamonds_num, &payables);
	cin >> diamonds_num >> payables;
	vector<int> diamonds_value;
	for (int i = 0; i < diamonds_num; i++)
	{
		int diamond_value_input;	
		//scanf("%d", &diamond_value_input);
		cin >> diamond_value_input;
		diamonds_value.push_back(diamond_value_input);
	}
	vector<PaymentSolution> exact_payment_solution;
	vector<PaymentSolution> exceeding_payment_solution;

	//find the first solution
	int total_value = 0;
	bool exact_solution_found = false;
	PaymentSolution prev_solution;
	for (int i = 0; i < diamonds_num; i++)
	{
		total_value += diamonds_value[i];
		if (total_value == payables) {
			exact_solution_found = true;
			prev_solution.SetSolution(0, i, total_value, true);
			exact_payment_solution.push_back(prev_solution);
			break;
		}
		if (total_value > payables) {
			prev_solution.SetSolution(0, i, total_value, false);
			exceeding_payment_solution.push_back(prev_solution);
			break;
		}
	}

	for (int starting_index = 1; starting_index < diamonds_num; starting_index++)
	{
		total_value = prev_solution.total_value_ - diamonds_value[starting_index - 1];
		if (total_value == payables) {
			exact_solution_found = true;
			PaymentSolution solution(starting_index, prev_solution.end_index_, total_value, true);
			exact_payment_solution.push_back(solution);
			prev_solution = solution;
		}
		else if (total_value < payables) {
			//add forward diamond
			for (int i = prev_solution.end_index_ + 1; i < diamonds_num; i++) {
				total_value += diamonds_value[i];
				if (total_value == payables) {
					exact_solution_found = true;
					PaymentSolution solution(starting_index, i, total_value, true);
					exact_payment_solution.push_back(solution);
					prev_solution = solution;
					break;
				}
				if (total_value > payables) {
					PaymentSolution solution(starting_index, i, total_value, false);
					if (!exact_solution_found) {
						exceeding_payment_solution.push_back(solution);
					}
					prev_solution = solution;
					break;
				}
			}
		}
		else {
			//minus backward diamond
			for (int i = prev_solution.end_index_; i >= starting_index; --i)
			{
				total_value -= diamonds_value[i];
				if (total_value < payables) {
					PaymentSolution solution(starting_index, i, total_value + diamonds_value[i], false);
					if (!exact_solution_found) {
						exceeding_payment_solution.push_back(solution);
					}
					prev_solution = solution;
					break;
				}
				if (total_value == payables) {
					exact_solution_found = true;
					PaymentSolution solution(starting_index, i-1, total_value, true);
					exact_payment_solution.push_back(prev_solution);
					prev_solution = solution;
					break;
				}
			}
		}
		
	}
	
	if (exact_solution_found) {
		sort(exact_payment_solution.begin(), exact_payment_solution.end(), ExactSolutionCmp);
		for (auto const solution : exact_payment_solution) {
			//printf("%d-%d\n", solution.starting_index_ + 1, solution.end_index_ + 1);
			cout << solution.starting_index_ + 1 << "-" << solution.end_index_ + 1 << endl;
		}
	}
	else {
		sort(exceeding_payment_solution.begin(), exceeding_payment_solution.end(), ExceedingSolutionCmp);
		int min_total_value = exceeding_payment_solution[0].total_value_;
		for (auto const solution : exceeding_payment_solution) {
			if (solution.total_value_ <= min_total_value) {
				//printf("%d-%d\n", solution.starting_index_ + 1, solution.end_index_ + 1);
				cout << solution.starting_index_ + 1 << "-" << solution.end_index_ + 1 << endl;
			}
		}
	}
	
	return 0;
}
 
