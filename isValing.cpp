#include<stdio.h>
#include<string.h>
const int N = 1e5;

bool isValing(char s[]){
	int L[N] = {};
	L[0] = -1, L[1] = 1;
	int n = strlen(s);
	int index = 1;
	for(int i = 2; i <= n;i++){
		if(int(s[i-1]) == int(s[index-1])+1 || int(s[i-1]) == int(s[index-1])+2){
			L[i] = index = L[index-1];
		}
		else{
			index = L[i] = i;
		}
	}
	return L[n] == -1 ? true:false;
}
