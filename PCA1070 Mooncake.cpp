/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1070 Mooncake
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
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef pair<int, double> Mooncake;
//first is storage, second is unit price

bool Cmp(Mooncake a, Mooncake b) {
	return a.second > b.second;
}

double CalculateMaxProfit(vector<Mooncake> all_mooncakes, int demand) {
	double profit = 0;
	for (auto &mooncake : all_mooncakes) {
		if (demand > mooncake.first) {
			profit += mooncake.first * mooncake.second;
			demand = demand - mooncake.first;
			mooncake.first = 0;
		}
		else {
			profit += demand * mooncake.second;
			break;
		}
	}
	return profit;
}

int main(void) {
	int kinds_num, demand;
	cin >> kinds_num >> demand;
	vector<Mooncake> all_mooncakes;
	for (int i = 0; i < kinds_num; i++)
	{
		int storage_input;	cin >> storage_input;
		all_mooncakes.push_back(make_pair(storage_input, 0));
	}
	for (int i = 0; i < kinds_num; i++)
	{
		double total_price; cin >> total_price;
		all_mooncakes[i].second = total_price / all_mooncakes[i].first;
	}
	sort(all_mooncakes.begin(), all_mooncakes.end(), Cmp);
	cout << fixed << setprecision(2) << \
		CalculateMaxProfit(all_mooncakes, demand) << endl;
	return 0;
}
 
