/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1149 Dangerous Goods Packaging
*  Date: 2021/03/04
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
#include <set>
using namespace std;
typedef pair<string, bool> goods;
typedef map<goods, vector<goods>> GoodsMap;
void InitializeIncompatibleGoods(GoodsMap &incompatible_goods) {
	for (auto &i : incompatible_goods) {
		for (auto &j : i.second) {
			j.second = false;
		}
	}
	return;
}

void InsertIncompatibleGoods(GoodsMap &incompatible_goods, goods a_incompatible, goods b_incompatible) {
	GoodsMap::iterator it = incompatible_goods.find(a_incompatible);
	if (it != incompatible_goods.end()) {
		(*it).second.push_back(b_incompatible);
	}
	else {
		vector<goods> incompatible_goods_vector;
		incompatible_goods_vector.push_back(b_incompatible);
		incompatible_goods[a_incompatible] = incompatible_goods_vector;
	}
	return;
}

int main(void) {
	int incompatible_rules_num, goods_lists_num;
	cin >> incompatible_rules_num >> goods_lists_num;
	GoodsMap incompatible_goods;
	for (int i = 0; i < incompatible_rules_num; i++)
	{
		string a, b;
		cin >> a >> b;
		goods a_incompatible(a, false);
		goods b_incompatible(b, false);
		InsertIncompatibleGoods(incompatible_goods, a_incompatible, b_incompatible);
		InsertIncompatibleGoods(incompatible_goods, b_incompatible, a_incompatible);
	}

	

	for (int i = 0; i < goods_lists_num; i++)
	{
		int goods_num; cin >> goods_num;
		set<string> goods_list;
		for (int i = 0; i < goods_num; i++)
		{
			string get_goods; cin >> get_goods;
			goods_list.insert(get_goods);
		}
		bool incompatible_found = false;
		for (string get_goods : goods_list)
		{
			goods goods_for_find(get_goods, false);
			GoodsMap::iterator it = incompatible_goods.find(goods_for_find);
			if (it != incompatible_goods.end()) {
				//the goods got now has its incompatible goods
				for (goods now_incompatible_goods : (*it).second) {
					//check presented status of every goods whether 
					//		it is incompatible with the goods got now
					if (now_incompatible_goods.second == true) {
						cout << "No\n";
						incompatible_found = true;
						break;
					}
					else {
						vector<goods>::iterator goods_to_modify = \
							find(incompatible_goods[now_incompatible_goods].begin(), \
								incompatible_goods[now_incompatible_goods].end(), goods_for_find);
						(*goods_to_modify).second = true;

					}
				}
			}
			if (incompatible_found) break;
		}
		if (!incompatible_found)cout << "Yes\n";
		InitializeIncompatibleGoods(incompatible_goods);
	}

	return 0;
}


 
