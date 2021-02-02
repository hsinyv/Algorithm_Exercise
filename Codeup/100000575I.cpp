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
int transfer(char a){
	switch(a){
		case 'C': return 2;
		case 'J': return 1;
		case 'B': return 0;
	}
	return -1;
}
char retrans(int a){
	switch(a){
		case 2: return 'C';
		case 1: return 'J';
		case 0: return 'B';
	}
	return '#';
}
void print_ges(int ges[]){
	int fst_index = 0, snd_index = 0, tth_index = 0;
	int fst_value = 0, snd_value = 0, tth_value = 0;
	for(int i = 0; i < 3; ++i){
		if(ges[i] > fst_value){
			fst_index = i;
			fst_value = ges[i];
		}else if(ges[i] > snd_value){
			snd_index = i;
			snd_value = ges[i];
		}
		else{
			tth_index = i;
			tth_value = ges[i];
		}	
	}
	if(fst_value > snd_value){
		cout << retrans(fst_index);
		return;
	}
	else{
		char fst_ges = retrans(fst_index);
		char snd_ges = retrans(snd_index);
		char tth_ges = retrans(tth_index);
		char lst_ges = '#';
		if(fst_value == snd_value){
			lst_ges = (fst_ges < snd_ges)? fst_ges : snd_ges;
		}
		if(snd_value == tth_value){
			lst_ges = (tth_ges < lst_ges)? tth_ges : lst_ges;
		}
		cout << lst_ges;
	}
	return;
}
int main() {
	int n;
	cin >> n;
	char a_ges, b_ges;	
	int awin_ges[3] = {0}, bwin_ges[3] = {0}; //C-2 J-1 B-0
	int awin_num = 0, bwin_num = 0, eq_num = 0;
	
	for(int i = 0; i < n; ++i){
		cin >> a_ges >> b_ges;
		if(a_ges == b_ges) eq_num++;
		else{
			int a = transfer(a_ges);
			int b = transfer(b_ges);
			if((a-b == 1) || (a-b == -2)) {
				awin_num++;
				awin_ges[a]++;
			}
			else{
				bwin_num++;
				bwin_ges[b]++;
			}
		}		
	}
	cout << awin_num << " " << eq_num << " " << bwin_num << endl;
	cout << bwin_num << " " << eq_num << " " << awin_num << endl;
	print_ges(awin_ges); cout << " ";
	print_ges(bwin_ges); cout << endl;
	return 0;
}

