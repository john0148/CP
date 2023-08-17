#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	char letter[] = "HPS";
	vector<char> s(n);
	vector<long long> prefix(n+1,0);
	vector<vector<long long>> max_char(3,vector<long long> (n+1));
	max_char[0][0] = max_char[1][0] = max_char[2][0] = 0;
	for(int i = 0; i< n; i++){
		cin>>s[i];
		for(int j = 0; j < 3; j++){
			max_char[j][i+1] = (letter[j] == s[i]) ? max_char[j][i] + 1: max_char[j][i];
			prefix[i+1] = max(prefix[i+1],max_char[j][i+1]);
		}
	}

	long long res = 0;
	for(int i = 1; i <= n; i++){
		long long temp = 0;
		for(int j = 0; j<3; j++){
			temp = max(temp, max_char[j][n] - max_char[j][i]);
		}
		res = max(res,prefix[i] + temp);
	}
	cout<<res<<"\n";
}
