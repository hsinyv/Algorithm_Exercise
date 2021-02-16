#include <iostream>
#include <algorithm>
using namespace std;
typedef long double ld;

int main(void){
	int n;
	cin >> n;
	ld a,b,c;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		ld sum = a + b;
		if(sum > c) cout << "Case #"<< i << ": true\n";
		else cout << "Case #"<< i << ": false\n";
	}
	return 0;
} 
