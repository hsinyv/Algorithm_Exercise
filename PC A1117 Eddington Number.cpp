#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(void){
	int n; cin >> n;
	vector<int> num; num.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> num[i];
	}
	sort(num.begin(), num.end(), [](int a, int b) {return a > b; });
	
	for(int i = 0; i < n; ++i){
		if(num[i] < i+1){
			cout << i << endl;
			break;
		}
	}
	return 0;
} 
