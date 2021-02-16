#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
typedef map<int,string> mis;

vector<string> ini_deck(){
	vector<string> deck;
	string ch[4] = {"S","H","C","D"};
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= 13; j++){
			deck.push_back(ch[i] + to_string(j));
		}
	}
	deck.push_back("J1");
	deck.push_back("J2");
	return deck;
}

void get_index_seq(vector<int> &index_seq){
	string s; 
	getline(cin, s);
	stringstream ss(s);
	int index;
	while(ss >> index){
		index_seq.push_back(index);
	}
	return;
}

void shuffling(vector<string> &deck, vector<int> index_seq){
	mis m;
	for(int i = 0; i < 54; i++){
		m[index_seq[i]] = deck[i];
	}
	int i = 0;
	for(auto it : m){
		deck[i++] = it.second;
	}
	return;
}

int main() {
	
	int shuffling_num;
	cin >> shuffling_num;
	getchar();
	vector<int> index_seq;
	get_index_seq(index_seq);
	
	vector<string> deck = ini_deck();
	
	for(int i = 0; i < shuffling_num; i++){
		shuffling(deck, index_seq);
	}
	
	for(int i = 0; i < 54; i++){
		cout << deck[i];
		if(i < 53) cout << " ";
		else cout << endl;
	}
	
	return 0;
}


