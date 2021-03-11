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
void InitializeHashTable(HashTable& hash_table) {
	for (MyPair &it : hash_table) {
		it.first = -1;
		it.second = 0;
	}
	return;
}
bool IsPrime(int n) {
	if (n <= 1)return false;
	bool is_prime = true;
	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0) {
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

MyPair Hash(HashTable const hash_table, int const key_to_add) {
	//return value: first is the index, second is probing times
	//-1 indicates invalid
	int probing_num = 1;
	int index = key_to_add % hash_table.size();
	//Quadratic Probing
	if (hash_table[index].first != -1) {
		while (probing_num <= hash_table.size()) {
			index = (index + (probing_num * probing_num)) % hash_table.size();
			++probing_num;
			if (hash_table[index].first == -1) {
				break;
			}
		}
	}
	if (probing_num > hash_table.size()) {
		index = -1;
	}
	MyPair p(index, probing_num);
	return p;
}

int FindHashTable(HashTable const hash_table, int const key_to_find) {
	//return value: probing times
	int probing_num = 1;
	int index = key_to_find % hash_table.size();
	//Quadratic Probing
	if (hash_table[index].first != key_to_find) {
		while (probing_num <= hash_table.size()) {
			index = (index + (probing_num * probing_num)) % hash_table.size();
			++probing_num;
			if (hash_table[index].first == key_to_find) {
				break;
			}
		}
	}
	return probing_num - 1;
}

double CalculateAverageSearchTime(HashTable const hash_table, vector<int> const all_keys_to_find) {
	double searching_times_sum = 0;
	for (int key : all_keys_to_find) {
		searching_times_sum += FindHashTable(hash_table, key);
	}
	return searching_times_sum / double(all_keys_to_find.size());
}
int main(void) {
	int table_size, key_to_get_num, key_to_find_num;
	cin >> table_size >> key_to_get_num >> key_to_find_num;
	OptimizeTableSize(table_size);
	HashTable hash_table;
	hash_table.resize(table_size);
	InitializeHashTable(hash_table);
	for (int i = 0; i < key_to_get_num; i++)
	{
		int key_input;	cin >> key_input;
		MyPair hash_result = Hash(hash_table, key_input);
		if (hash_result.first > -1) {
			hash_table[hash_result.first].first = key_input;
			hash_table[hash_result.first].second = hash_result.second;
		}
		else{
			cout << key_input << " cannot be inserted.\n";
		}
	}
	vector<int> all_keys_to_find(key_to_find_num,-1);
	for (int i = 0; i < key_to_find_num; i++)
	{
		int key_input;	cin >> key_input;
		all_keys_to_find[i] = key_input;
	}
	cout << fixed << setprecision(1) \
		<< CalculateAverageSearchTime(hash_table, all_keys_to_find) << endl;

	return 0;
}
 
