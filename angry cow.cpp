#include<bits/stdc++.h>
using namespace std;
long long N, K;
vector<long long> x;

bool good(int m){
	long long pos = 0, temp = 0;
	while(pos < N){
		pos = lower_bound(x.begin(), x.end(), x[pos] + 2*m + 1) - x.begin();
		temp ++;
		if(temp > K)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>N>>K;
	x.resize(N);
	for(long long i = 0; i< N; i++){
		cin>> x[i];
	}

	sort(x.begin(), x.end());

	long long l = 0, r = x[N-1];
	while(r > l+1){
		long long m = (l+r)/2;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout<<r<<"\n";

}