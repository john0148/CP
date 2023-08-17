#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

stack<long long> near;
vector<long long> a, res;
int n;



int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n;
	a.resize(n);
	near.push(-1);
	for(int r = 0; r <n; r++){
		cin>>a[r];
		while(a[r] <= near.top()){
			near.pop();
		}
		res.push_back(near.top());
		near.push(a[r]);
	}
	for(int i = 0; i< n; i++){
		cout<<a[i]<<" "<<res[i]<<endl;
	}
}