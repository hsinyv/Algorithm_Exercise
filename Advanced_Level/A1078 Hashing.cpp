/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1078 Hashing
*  Date: 2021/03/04 Partly Correct
*        2021/03/05 AC(1 is not prime)
***********************************************/
/***********************************************
* Core Mission: determine the length of hash table and quadratically probe correctly
* Point:  1 is not prime
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

bool IsPrime(int n) {
    if (n <= 1) return false;
    bool is_prime = true;
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

void OptimizeTableSize(int& n) {
    while (!IsPrime(n)) {
        ++n;
    }
    return;
}

int QuadraticProbing(vector<int> hash_table, int index) {
    bool left_probing_failure = false;
    bool right_probing_failure = false;
    //for (int i = 1; i < hash_table.size(); i++)
    //{
    //    int offset = i * i;
    //    //leftside
    //    if (!left_probing_failure) {
    //        int left_probing = index - offset;
    //        if (left_probing >= 0) {
    //            if (hash_table[left_probing] == -1) return left_probing;
    //        }
    //        else {
    //            left_probing_failure = true;
    //        }
    //    }
    //    
    //    //rightside
    //    if (!right_probing_failure) {
    //        int right_probing = index + offset;
    //        if (right_probing < hash_table.size()) {
    //            if (hash_table[right_probing] == -1) return right_probing;
    //        }
    //        else {
    //            right_probing_failure = true;
    //        }
    //    }
    //    
    //    if (left_probing_failure && right_probing_failure) return -1;
    //}
    int probing_num = 1;
    while (probing_num <= hash_table.size()) {
        int probing_index = (index + (probing_num * probing_num)) % hash_table.size();
        if (hash_table[probing_index] == -1) return probing_index;
        ++probing_num;
    }
    return -1;
}

int main(void) {
	int table_size, number_num;
    cin >> table_size >> number_num;
    OptimizeTableSize(table_size);
    vector<int> hash_table(table_size, -1);
    vector<int> index_for_printing;
    for (int i = 0; i < number_num; i++)
    {
        int number; cin >> number;
        int index = number % table_size;
        if (hash_table[index] == -1) {
            index_for_printing.push_back(index);
            hash_table[index] = number;
        }
        else {
            index = QuadraticProbing(hash_table, index);
            index_for_printing.push_back(index);
            if (index >= 0)hash_table[index] = number;;
        }
    }
    for (int i = 0; i < index_for_printing.size(); i++)
    {
        if (index_for_printing[i] == -1) {
            cout << "-";
        }
        else cout << index_for_printing[i];
        if (i < index_for_printing.size() - 1) {
            cout << " ";
        }
        else cout << endl;
    }
	return 0;
}
 
