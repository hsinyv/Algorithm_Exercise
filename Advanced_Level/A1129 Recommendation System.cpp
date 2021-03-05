/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1129 Recommendation System 
*  Date: 2021/02/25
***********************************************/
/***********************************************
* Core Mission: sort the browsing record before and gives reconmmendation
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

class Item {
public:
	int item_id_;
	int sum_;
	int serial_num_;
	Item(int item_id, int sum, int serial_num) {
		item_id_ = item_id;
		sum_ = 1;
		serial_num_ = serial_num;
	}
};

int FindItem(vector<Item> recom_items, int item_id) {
	for (int i = 0; i < recom_items.size(); ++i) {
		if (item_id == recom_items[i].item_id_) return i;
	}
	return -1;
}

bool MyComp(Item a, Item b) {
	if (a.sum_ == b.sum_) {
		return a.serial_num_ > b.serial_num_;
	}
	return a.sum_ > b.sum_;
}

void Recom(vector<Item> &recom_items, int recom_num) {
	int loop_limit = 0;
	if (recom_items.size() < recom_num) {
		loop_limit = recom_items.size();
	}
	else {
		sort(recom_items.begin(), recom_items.end(), MyComp);
		loop_limit = recom_num;
	}

	for (size_t i = 0; i < loop_limit; i++)
	{
		cout << recom_items[i].item_id_;
		if (i < loop_limit - 1) cout << " ";
		else break;
	}
	cout << endl;
	return;
}

void Recommendation(vector<int> query_record, int query_num, int recom_num) {
	vector<Item> recom_items; int query_cnt = 0;
	Item item(query_record[0], 1, query_cnt++);
	recom_items.push_back(item);
	for (size_t i = 1; i < query_num; i++)
	{
		cout << query_record[i] << ": ";
		Recom(recom_items, recom_num);
		if (recom_items.size() < recom_num) {
			Item item(query_record[i], 1, query_cnt++);
			recom_items.push_back(item);
		}
		else {
			int index = FindItem(recom_items, query_record[i]);
			if (index == -1) {
				/*recom_items[recom_num - 1].item_id_ = query_record[i];
				recom_items[recom_num - 1].sum_ = 1;*/
				Item item(query_record[i], 1, query_cnt++);
				recom_items.push_back(item);
			}
			else {
				recom_items[index].sum_ += 1;
			}
		}
	}
	return;
}

int main(void) {
	int query_num, recom_num;
	cin >> query_num >> recom_num;
	vector<int> query_record;
	query_record.resize(query_num);
	for (size_t i = 0; i < query_num; i++)
	{
		cin >> query_record[i];
	}
	Recommendation(query_record, query_num, recom_num);
	return 0;
}
 
