/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1048 Find Coins
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: divide the bill
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
	int coins_num, bill;
	scanf("%d %d", &coins_num, &bill);
	vector<int> face_value;
	vector<pair<int, int>> solution;
	for (int i = 0; i < coins_num; i++)
	{
		int t; scanf("%d", &t);
		face_value.push_back(t);
	}
	sort(face_value.begin(), face_value.end(), [](int a, int b) {return a > b; });
	bool not_found = true;
	for (int i = 0; i < coins_num; i++)
	{
		int coin_to_find = bill - face_value[i];
		if (coin_to_find > face_value[i]) break;
		for (int j = i + 1; j < coins_num; j++)
		{
			if (face_value[j] == coin_to_find) {
				printf("%d %d\n", coin_to_find, face_value[i]);
				not_found = false;
				break;
			}
			if (face_value[j] < coin_to_find) {
				break;
			}
		}
		if (!not_found) break;
	}
	if (not_found) {
		printf("No Solution\n");
	}
	return 0;
}

