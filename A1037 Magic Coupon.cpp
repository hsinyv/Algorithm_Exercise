/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1037 Magic Coupon
*  Date: 2021/03/06
***********************************************/
/***********************************************
* Core Mission: Get as much money back as possible
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

bool DecrementCmp(int a, int b) {
	return a > b;
}

int main(void) {
	int coupons_num, products_num;
	cin >> coupons_num;
	vector<int> positive_coupons, negtive_coupons, positive_products, negtive_products;
	for (int i = 0; i < coupons_num; i++)
	{
		int coupon_input; cin >> coupon_input;
		if (coupon_input > 0) {
			positive_coupons.push_back(coupon_input);
		}
		else {
			negtive_coupons.push_back(coupon_input);
		}
		
	}
	cin >> products_num;
	for (int i = 0; i < products_num; i++)
	{
		int product_input; cin >> product_input;
		if (product_input > 0) {
			positive_products.push_back(product_input);
		}
		else {
			negtive_products.push_back(product_input);
		}
	}
	sort(positive_coupons.begin(), positive_coupons.end(), DecrementCmp);
	sort(positive_products.begin(), positive_products.end(), DecrementCmp);
	sort(negtive_coupons.begin(), negtive_coupons.end());
	sort(negtive_products.begin(), negtive_products.end());
	int positive_loop_limit = (positive_coupons.size() > positive_products.size()) ? \
		positive_products.size() : positive_coupons.size();
	int negtive_loop_limit = (negtive_coupons.size() > negtive_products.size()) ? \
		negtive_products.size() :negtive_coupons.size();
	int earnings = 0;
	for (int i = 0; i < positive_loop_limit; i++)
	{
		int product = positive_coupons[i] * positive_products[i];
		if (product > 0) {
			earnings += product;
		}
	}
	for (int i = 0; i < negtive_loop_limit; i++)
	{
		int product = negtive_coupons[i] * negtive_products[i];
		if (product > 0) {
			earnings += product;
		}
	}
	cout << earnings << endl;
	return 0;
}
 
