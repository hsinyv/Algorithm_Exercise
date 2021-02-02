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
typedef pair<char, int> pci;

int transfer(char a){
	switch(a){
		case 'C': return 2;
		case 'J': return 1;
		case 'B': return 0;
	}
	return -1;
}
bool cmp(pci a, pci b) {
	return a.second < b.second;
}

bool compare(char a_ges, char b_ges){
	int a = transfer(a_ges);
	int b = transfer(b_ges);
	if((a-b == 1) || (a-b == -2)) {
		return true;	
	}
	return false;
}
map<char, int> init_map(){
	map<char, int> m;
	m['C'] = 0;
	m['J'] = 0;
	m['B'] = 0;
	return m;
}
void map_sort(map<char, int> m){
	map<char, int>::iterator mit;
	vector<pci> vc;
	vector<pci>::iterator vit;
	for(mit=m.begin(); mit!=m.end(); mit++) {
		vc.push_back(pci(mit->first, mit->second));//put in vector
		//cout<<mit->first<<"  "<<mit->second<<endl;
	}
	//puts("-------------------------------------");
	sort(vc.begin(), vc.end(), cmp);
	if(vc.begin().second > (vc.begin()+1).second){
		cout << vc.begin().first;
	}
	else{
		if(vc.begin().first > (vc.begin()+1).first){
			cout << vc.begin().first << " ";
			cout << (vc.begin()+1).first << " ";
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		char a_ges, b_ges;	
		map<char, int> awin_ges, bwin_ges; //C-2 J-1 B-0
		awin_ges = init_map();
		bwin_ges = init_map();
		int awin_num = 0, bwin_num = 0, eq_num = 0;
		cin >> a_ges >> b_ges;
		if(a_ges == b_ges) eq_num++;
		else{
			if(compare(a_ges, b_ges)){
				awin_num++;
				awin_ges[a_ges]++;
			}
			else{
				bwin_num++;
				bwin_ges[b_ges]++;
			}
			
		}
		cout << awin_num << eq_num << bwin_num << endl;
		cout << bwin_num << eq_num << awin_num << endl;
		map_sort(awin_ges);
		map_sort(bwin_ges);		
	}
	return 0;
}

