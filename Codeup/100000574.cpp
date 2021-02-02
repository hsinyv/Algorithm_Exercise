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
	while(scanf("%d", &n) != EOF) {
		int sum = 0; int b;
		for(int i = 0; i < n; i++){
			scanf("%d", &b);
			sum += b;
		}
		printf("%d\n", sum);
	}	
	return 0;
}
