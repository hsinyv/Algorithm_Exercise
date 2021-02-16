#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Cards{
	public:
	string card;
	int index;
	Cards(string c, int i = 0){
		card = c;
		index = i;
	}
};
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
vector<Cards> ini_deck(){
	vector<Cards> deck;
	string ch[4] = {"S","H","C","D"};
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= 13; j++){
			Cards c(ch[i] + to_string(j));
			deck.push_back(c);
		}
	}
	Cards a("J1");deck.push_back(a);
	Cards b("J2");deck.push_back(b);
	return deck;
}
bool my_com(Cards A, Cards B){
	return A.index < B.index;
}

void shuffling(vector<Cards> &deck, vector<int> index_seq){
	for(int i = 0 ; i < 54; i++){
		deck[i].index = index_seq[i];
	}
	sort(deck.begin(), deck.end(), my_com);
}

int main() {
	int shuffling_num;
	cin >> shuffling_num;
	getchar();
	vector<int> index_seq;
	get_index_seq(index_seq);
	
	vector<Cards> deck = ini_deck();
	
	for(int i = 0; i < shuffling_num; i++){
		shuffling(deck, index_seq);
	}
	
	for(int i = 0; i < 54; i++){
		cout << deck[i].card;
		if(i < 53) cout << " ";
		else cout << endl;
	}
	
	return 0;
}


