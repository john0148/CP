#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e2;

vector<pair<int, int>> a;

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int n; cin>>n;
	a.resize(n);
	for(int i = 0; i<n;i++){
		char dir; cin>>dir;
		int temp; cin>>temp;
		a[i].first = temp;
		if(dir == 'G')
			a[i].second = -1;
		else
			a[i].second	= 1;
	}
	sort(a.begin(),a.end());

	int res = n;
	for(int i = 0; i < n; i++){
		int numliars = 0;
		for(int j = 0; j < i; j++){
			if(a[j].second == 1)	
				++numliars;
		}
		for(int j = i+1; j < n; j++){
			if(a[j].second == -1)
				++numliars;
		}
		res = min(res,numliars);
	}

	cout<< res;
	
}
