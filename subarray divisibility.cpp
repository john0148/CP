#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("a.txt","w",stdout);
	int n; cin>>n;
	long long prefix = 0;
	long long res = 0;
	map<long long, int> subarr;
	subarr[0] = 1;
	for(int i = 1; i <=n; i++){
		int temp; cin>>temp;
		prefix = ((prefix + temp)%n + n) %n;
		res += subarr[prefix];
		subarr[prefix]++;
	}
	cout<<res<<"\n";
}
