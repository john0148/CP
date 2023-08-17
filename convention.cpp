#include<bits/stdc++.h>
using namespace std;
int N,M,C;
vector<int> t;

bool good(int m){
	int i = 0, bus = 0;
	while(i < N){
		int j  = lower_bound(t.begin(), t.end(), t[i] + m + 1) - t.begin();
		int k = min(j - i,C);
		i+=k;
		bus++;
	}
	return bus <= M;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>N>>M>>C;
	t.resize(N);
	for(int i = 0; i< N; i++){
		cin>>t[i];
	}
	sort(t.begin(),t.end());
	int l = 0, r = 1e9;
	while(r > l+1){
		int m = (l+r)/2;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout<<r<<"\n";
}