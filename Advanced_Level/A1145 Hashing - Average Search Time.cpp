/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1145 Hashing - Average Search Time
*  Date: 2021/03/05
***********************************************/
/***********************************************
* Core Mission: build hash table and record probing times
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
typedef pair<int, int> MyPair;
typedef vector<MyPair> HashTable;
//first is the key, second is probing times

bool IsPrime(int n) {
	if (n <= 1)return false;
	bool is_prime = true;
	for (int i = 2; i < n/2; i++)
	{
		if (n / i == 0) {
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

void OptimizeTableSize(int& table_size) {
	while (!IsPrime(table_size)) {
		++table_size;
	}
	return;
}

int main(void) {
	int table_size, key_to_get_num, key_to_find_num;
	HashTable hash_table;
	cin >> table_size >> key_to_get_num >> key_to_find_num;


	return 0;
}
 
