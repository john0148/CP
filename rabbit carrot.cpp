#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string.h>
const int MAX = 2e5+5;
using namespace std;

int n, m;
int a[MAX];
vector<int> v;

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(m*i - a[i] >= 0) v.push_back(m*i - a[i]);
	}

	int k = v.size();
	int dp[k+1];
	fill(dp,dp+k+1,INT_MAX);
	dp[0] = INT_MIN;
	for(int i = 0; i < k; i++){
		int x = upper_bound(dp,dp+k+1,v[i]) - dp;
		if(x != k+1 && dp[x] > v[i]) dp[x] = v[i];
	}
	int res = lower_bound(dp, dp+k+1, INT_MAX) - dp - 1;
	cout << n - res << endl;
}