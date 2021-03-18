/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.1058 A+B in Hogwarts
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: calculate addition in specific rule
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

class Number_Hogwarts {
public:
	string standard_format_;
	int gallon_;
	int sickle_;
	int kunt_;
	Number_Hogwarts(string ini) {
		standard_format_ = ini;
		int split_cnt = 0;
		for (int i = 0; i < ini.size(); ++i)
		{
			string get_segment;
			while (ini[i] != '.' && i < ini.size()) {
				get_segment += ini[i];
				i++;
			}
			switch (split_cnt) {
			case 0: {
				gallon_ = stoi(get_segment);
				break;
			}
			case 1: {
				sickle_ = stoi(get_segment);
				break;
			}
			case 2: {
				kunt_ = stoi(get_segment);
				break;
			}
			}
			++split_cnt;
			
		}
	}
};

void AddHogwarts(Number_Hogwarts a, Number_Hogwarts b) {
	int sum = a.kunt_ + b.kunt_;
	//calculate this_level
	a.kunt_ = sum % 29;
	//calculate carry
	a.sickle_ += sum / 29;
	
	sum = a.sickle_ + b.sickle_;
	a.sickle_ = sum % 17;
	a.gallon_ += sum / 17;

	a.gallon_ = a.gallon_ + b.gallon_;
	cout << a.gallon_ << "." << a.sickle_ << "." << a.kunt_ << endl;
}

int main(void) {
	string a_addend, b_addend;
	cin >> a_addend >> b_addend;
	Number_Hogwarts a(a_addend);
	Number_Hogwarts b(b_addend);
	AddHogwarts(a, b);
	return 0;
}
 
