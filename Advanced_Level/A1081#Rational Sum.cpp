/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1081 Rational Sum
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: sign bit should be processed separately
* Point:  pay attention to space between integer portion and fraction portion
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
typedef pair<ll, ll> Fraction;
ll GCD(ll a, ll b) {
	return b == 0 ? abs(a) : GCD(b, a % b);
}

void FractionReduction(Fraction &a) {
	bool negtive = false;
	if (a.first < 0) {
		negtive = true;
		a.first = abs(a.first);
	}
	ll gcd = GCD(a.first, a.second);
	a.first = a.first / gcd;
	a.second = a.second / gcd;
	if (negtive) a.first = -a.first;
	return;
}

Fraction FractionAdd(Fraction a, Fraction b) {
	if (a.first == 0) return b;
	Fraction result;
	result.first = a.first * b.second + b.first * a.second;
	result.second = a.second * b.second;
	FractionReduction(result);
	return result;
}

int main(void) {
	int fractions_num; 
	ll numerator, denominator;
	Fraction sum = make_pair(0,1);
	scanf("%d", &fractions_num);
	for (int i = 0; i < fractions_num; i++)
	{
		scanf("%lld/%lld", &numerator, &denominator);
		if (denominator > 0 && numerator != 0) {
			sum = FractionAdd(sum, make_pair(numerator, denominator));
		}
	}
	ll integer_portion = sum.first / sum.second;
	sum.first = sum.first % sum.second;
	if (integer_portion != 0) {
		if (sum.first < 0) printf("-");
		printf("%lld", integer_portion);
		if (sum.first == 0) printf("\n");
		else printf(" ");
	}
	if (sum.first != 0) {
		printf("%lld/%lld\n", sum.first, sum.second);
	}
	if (integer_portion == 0 && sum.first == 0) printf("0\n");

	return 0;
}
 
