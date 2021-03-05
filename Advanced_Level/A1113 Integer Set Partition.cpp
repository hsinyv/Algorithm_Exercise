/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1113 Integer Set Partition
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: to answer how to minimize |n_1 - n_2| and then maximize |s_1 - s_2|
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

int main(void) {
	int n; cin >> n;
	vector<int> num; num.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num.begin(), num.end(), [](int a, int b) {return a < b; });
	if (n % 2 == 0) {
		int sum_front_part = 0, sum_latter_part = 0, sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			sum += num[i];
			if (i == ((n / 2) - 1)) {
				sum_front_part = sum;
			}
		}
		sum_latter_part = sum - sum_front_part;
		cout << 0 << " " << sum_latter_part - sum_front_part << endl;
	}
	else {
		int sum_left_front = 0, sum_right_front = 0;
		int sum_left_latter = 0, sum_right_latter = 0;
		int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			sum += num[i];
			if (i == (((n - 1) / 2) - 1)) {
				sum_left_front = sum;
			}
			if (i == (((n + 1) / 2) - 1)) {
				sum_right_front = sum;
			}
		}
		sum_left_latter = sum - sum_left_front;
		sum_right_latter = sum - sum_right_front;
		int left_difference = abs(sum_left_latter - sum_left_front);
		int right_difference = abs(sum_right_latter - sum_right_front);
		cout << 1 << " " << ((left_difference > right_difference) ? left_difference : right_difference) << endl;
	}

	return 0;
}
 
