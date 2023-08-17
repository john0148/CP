#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("a.txt","w",stdout);

	int n, b, k; cin>>n>>k>>b;
	vector<int> a(n), prefix(n+1,0);
	for(int i = 0; i < b; i++){
		cin>>a[i];
		prefix[a[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		prefix[i] = prefix[i] + prefix[i-1];
	}

	int res = prefix[n];
	for(int i = 1; i <= n - k + 1; i++){
		res = min(res,prefix[i+k-1] - prefix[i]);
	}
	cout<<res<<"\n";
}