#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <iomanip>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		string *s = new string[n * 2 - 1];
		int i, j, len = n;
		int *offset = new int[n];
		for (i = 0; i < n; i++) {
			offset[i] = 2 * (n - i) - 1;
		}
		for (i = 0; i < n; i++) {
			string t;
			for (j = 0; j < i; j++) {
				t = t + " ";
			}//pre_space
			bool flag = true;
			for (j = 0; j < offset[i]; j++) {
				if (flag) {
					t = t + "*";
					flag = false;
				}
				else {
					t = t + " ";
					flag = true;
				}
			}
			s[i] = t;
		}
		for (i = n; i < 2 * n - 1; i++) {
			s[i] = s[2 * n - 2 - i];
		}
		for (i = 0; i < 2 * n - 1; i++) {
			cout << s[i] << endl;
		}
	}
	return 0;
}
