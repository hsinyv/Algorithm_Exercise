#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void decode_day_hour(string s1, string s2, int& day, int& hour) {
	//find the first common capital English letter£¬ 'day' is its index in alphabet
	//find the second common character ranging in 0~9 and A~N, 'hour' is its index in "vector<char> hour_"
	int len = (s1.size() < s2.size()) ? s1.size() : s2.size();
	int cnt = 0;
	vector<char> hour_ = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A','B','C','D','E','F','G','H','I','J','K','L','M','N' };
	for (int i = 0; i < len; i++) {
		if (s1[i] == s2[i]) {
			if (cnt == 0) {
				if (isupper(s1[i])) {
					day = s1[i] - 'A';
					cnt++;
				}
			}
			else {
				auto it = find(hour_.begin(), hour_.end(), s1[i]);
				if (it != hour_.end()) {
					hour = it - hour_.begin();
					return;
				}
			}
		}

	}
}

void decode_minute(string s1, string s2, int& minute) {
	//find the first same english letter in same position
	int len = (s1.size() < s2.size()) ? s1.size() : s2.size();
	for (int i = 0; i < len; i++) {
		if (isalpha(s1[i]) && (s1[i] == s2[i])) {
			minute = i;
			return;
		}
	}
}

int main(void) { 
	string s1, s2, s3, s4;
	int day, hour, minute;
	cin >> s1 >> s2 >> s3 >> s4;
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	decode_day_hour(s1, s2, day, hour);
	decode_minute(s3, s4, minute);
	cout << week[day] << " ";
	if (hour < 10) cout << 0;
	cout << hour << ":";
	if (minute < 10) cout << 0;
	cout << minute << endl;
	return 0;
}


