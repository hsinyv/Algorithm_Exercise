/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1089 Insert or Merge
*  Date: 2021/02/24
***********************************************/
/***********************************************
* Core Mission: Decide how to tell insertion sort and merg sort.
*	Because the result of test case is unique, may it works that generate all the seq in the process
*	of insertion sort, and find "partially sorted seq" in the generated seq. So sorting method 
*	is Insertion Sort if it is found, and Merge Sort otherwise.
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
typedef vector<int> VI;

bool VectorEq(VI a, VI b) {
	if (a.size() != b.size()) return false;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

VI FillVector(VI const ini_seq, VI const sorting_seq) {
	VI patial_sorted_vector; patial_sorted_vector.resize(ini_seq.size());
	for (size_t i = 0; i < ini_seq.size(); i++)
	{
		if (i < sorting_seq.size()) {
			patial_sorted_vector[i] = sorting_seq[i];
		}
		else {
			patial_sorted_vector[i] = ini_seq[i];
		}
	}
	return patial_sorted_vector;
}

ostream& operator<<(ostream& out, VI v) {
	out << "__ ";
	for (auto i : v) out << i << " ";
	out << endl;
	return out;
}

vector<VI> InsertionSort(VI ini_seq) {
	vector<VI> all_insertion_seq;
	VI sorting_seq;
	for (size_t i = 0; i < ini_seq.size(); i++)
	{
		sorting_seq.push_back(ini_seq[i]);
		sort(sorting_seq.begin(), sorting_seq.end());
		cout << sorting_seq;
		VI v;
		v = FillVector(ini_seq, sorting_seq);
		all_insertion_seq.push_back(v);
	}
	return all_insertion_seq;
}

int FindSeq(vector<VI> all_insertion_seq, VI patially_sorted_seq) {
	for (size_t i = 0; i < all_insertion_seq.size(); i++)
	{
		if (VectorEq(all_insertion_seq[i], patially_sorted_seq)) return i;
	}
	return -1;
}

void MergeSort(VI& ini_seq, VI const patially_sorted_seq) {
	int step = 1;
	int loop_cnt = 0;
	int target_loop_num = -1;
	while (!is_sorted(ini_seq.begin(), ini_seq.end())) {
		step *= 2;
		for (size_t i = 0;;)
		{
			if ((i + step) < ini_seq.size()) {
				sort(ini_seq.begin() + i, ini_seq.begin() + i + step);
				i += step;
			}
			else {
				sort(ini_seq.begin() + i, ini_seq.end());
				cout << ini_seq;
				break;
			}
		}
		if (loop_cnt == target_loop_num) break;
		if (VectorEq(ini_seq, patially_sorted_seq)) {
			target_loop_num = loop_cnt + 1;
		}
		++loop_cnt;
	}
}

int main(void) {
	int num; cin >> num;
	VI ini_seq, patially_sorted_seq;
	ini_seq.resize(num);	patially_sorted_seq.resize(num);
	for (size_t i = 0; i < num; i++)
	{
		cin >> ini_seq[i];
	}
	for (size_t i = 0; i < num; i++)
	{
		cin >> patially_sorted_seq[i];
	}
	vector<VI> all_insertion_seq = InsertionSort(ini_seq);
	int index = FindSeq(all_insertion_seq, patially_sorted_seq);
	if (index >= 0) {
		cout << "Insertion Sort\n";
		for (size_t i = 0; i < num; i++)
		{
			cout << (all_insertion_seq[index + 1])[i];
			if (i < num - 1)cout << " ";
		}
		cout << endl;
	}
	else {
		cout << "Merge Sort\n";
		MergeSort(ini_seq, patially_sorted_seq);
		for (size_t i = 0; i < num; i++)
		{
			cout << ini_seq[i];
			if (i < num - 1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}
 
