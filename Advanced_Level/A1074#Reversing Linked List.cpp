/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1074 Reversing Linked List
*  Date: 2021/03/18
***********************************************/
/***********************************************
* Core Mission: reverse the links of every K elements on L
* Point:  try to use a large traditional array and improve speed
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
	int head_addr;
	int num_nodes, reverse_para;
	cin >> head_addr >> num_nodes >> reverse_para;
	int addr2data[100005], addr2next[100005];
	
	for (int i = 0; i < num_nodes; i++)
	{
		int addr; cin >> addr;
		cin >> addr2data[addr] >> addr2next[addr];
	}
	vector<int> list;
	int next = head_addr;
	//record addr by order is eqt reproduce whole list
	while (next != -1) {
		list.push_back(next);
		next = addr2next[next];
	}
	int num_reverse = list.size() / reverse_para;
	int index = 0;
	for (int i = 0; i < num_reverse; i++)
	{
		reverse(list.begin() + index, list.begin() + index + reverse_para);
		index += reverse_para;
	}
	int i = 0;
	for (i = 0; i < list.size() - 1; i++)
	{
		printf("%05d %d %05d\n", list[i], addr2data[list[i]], list[i + 1]);
	}
	printf("%05d %d -1\n", list[i], addr2data[list[i]]);
	return 0;
}
 
