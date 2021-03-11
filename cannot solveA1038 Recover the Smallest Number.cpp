/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1038 Recover the Smallest Number
*  Date: 2021/03/06
***********************************************/
/***********************************************
* Core Mission:
* Point:
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

void SortNumbers(vector<string>& all_numbers) {
	for (int i = 0; i < all_numbers.size() - 1;)
	{
		if ((all_numbers[i])[0] == (all_numbers[i + 1])[0]) {
			for (int j = i; j < all_numbers.size(); j++)
			{
				if ((all_numbers[j])[0] == (all_numbers[j + 1])[0]) {
					if (stoi(all_numbers[j] + all_numbers[j + 1]) > \
						stoi(all_numbers[j + 1] + all_numbers[j])) {
						swap(all_numbers[j], all_numbers[j + 1]);
					}
				}
				else break;	
			}
		}
		else {
			i++;
		}
	}
}

int main(void) {
	int number_num;	cin >> number_num;
	vector<string> all_numbers;
	for (int i = 0; i < number_num; i++)
	{
		string number_input;
		cin >> number_input;
		all_numbers.push_back(number_input);
	}
	sort(all_numbers.begin(), all_numbers.end());
	SortNumbers(all_numbers);
	for (auto number : all_numbers) {
		cout << stoi(number);
	}
	cout << endl;
	return 0;
}
 
