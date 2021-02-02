#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;
bool isspace(char a){
	if(a == ' ') return true;
	if(a == '\t') return true;
	if(a == '\r') return true;
	if(a == '\n') return true;
	return false;
	
}
int main(void){
	char a,b;
	a = getchar(); if(isalpha(a)) a = toupper(a);
	printf("%c",a);
	
	while((b = getchar()) != EOF){
		if(isspace(a) && isalpha(b)) b = toupper(b);
		a = b;
		printf("%c",a);
	}
	return 0;
} 
