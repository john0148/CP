#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int n; cin>> n;
	vector<int> cnt(n,0);
	int a,b;
	for(int i = 0; i < n-1; i++){
		cin>>a>>b;
		a--; b--;
		cnt[a]++;
		cnt[b]++;
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		res = max(res,cnt[i]);
	}
	cout<<res+1<<endl;
	return 0;
}