/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1059 Prime Factors
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: N = p​1​​ ^k​1​​ *p​2​​ ^k​2​​ *…*p​m​​ ^k​m. I do not know the math algorithm 
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
typedef long long ll;

bool IsPrime(ll n) {
	if (n < 2)return false;
	if (n == 2)return true;
	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}

int main(void) {
	for (ll i = 3; i < 9999; i++)
	{
		if (IsPrime(i)) {
			cout << i << endl;
		}
	}

	return 0;
}
 
