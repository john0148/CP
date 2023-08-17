#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;


int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int n; cin>>n;
	vector<int> prefix(n,0), mark(7,0);
	for(int i = 1; i <= n; i++){
		int temp; cin>>temp;
		prefix[i] = (prefix[i-1] + temp % 7) % 7;
		mark[prefix[i]] = i;
	}
	int res = 0;

	for(int i = 0; i < 7; i++){
		for(int j = 0; j <= n; j++){
			if(prefix[j] == i){
				res = max(res,mark[i] - j);
				break;
			}
		}
	}
	cout<<res<<"\n";
}