#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool find_winner(vector<string> win, string s){
	for(auto it : win){
		if(it == s) return true;
	}
	return false;
} 

int main(void){
	int n, first, skip; string s;
	cin >> n >> skip >> first; 
	if(first > n){
		cout << "Keep going...\n";
		return 0;
	}
	first--;
	vector<string> v, win;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		v.push_back(s);
	}
	
	for(int i = first; i < n; i += skip){
		while(find_winner(win,v[i])) i++;
		win.push_back(v[i]);
	}
	//cout << "---\n";
	for(auto it : win){
		cout << it << endl;
	}
	return 0;
}


