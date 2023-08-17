#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int n; cin>>n;
	vector<pair<long long,long long>> a(n);
	for(int i =0; i<n; i++){
		cin>>a[i].second>>a[i].first;
	}
	sort(a.begin(),a.end());
	int l = 0, r = n-1;
	long long res = 0;
	while(r >= l){
		long long s = a[r].first + a[l].first;
		res = max(res,s);
		long long temp = min(a[r].second,a[l].second);
		if(a[r].second > a[l].second){
			a[r].second -= temp;
			l++;
		}
		else if(a[r].second < a[l].second){
			a[l].second -= temp;
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<res<<endl;
}