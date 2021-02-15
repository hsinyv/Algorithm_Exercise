#include <iostream>
#include <cstdio>
#include <map>
#include <iomanip>	//control output format
using namespace std;
int main() {
	int n = 0;
	map<int, double, greater<int>> poly; //greater<int> assign poly in increasing order of key
	for (int cnt = 0; cnt < 2; cnt++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int key;	cin >> key;
			double value; 	cin >> value;
			bool FlagNotFound = true;
			for (auto it = poly.begin(); it != poly.end(); it++) {	//find the key in poly
				if (it->first == key) {
					it->second += value;
					FlagNotFound = false;
					break;
				}
			}
			if (FlagNotFound) {
				poly[key] = value;
			}
		}
	}
	for (auto it = poly.begin(); it != poly.end(); it++){	//delete items whose coef is 0
		if(it->second == 0){
			poly.erase(it);
		}
	}
	if(poly.size() == 0) cout << 0;
	else{
		cout << poly.size() << " ";
		int i = 1;
		for (auto it = poly.begin(); it != poly.end(); it++) {
			cout << it->first << " ";
			cout << fixed << setprecision(1) << it->second;	//reserve 1 decimal place
			if(i++ < poly.size()) cout << " ";	//avoid redundant rear space
		}
	}
	
	return 0;
}
