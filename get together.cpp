#include<bits/stdc++.h>
using namespace std;

int n;
vector<double> x,v;

bool good(double time){
	double l = -1e9, r = 1e9;
	for(int i = 0; i< n; i++){
		l = max(l, x[i] - time*v[i]);
		r = min(r, x[i] + time*v[i]);
	}
	return r > l;
}

int main(){
	cin>>n;
	x.resize(n); v.resize(n);
	for(int i = 0; i< n; i++){
		cin>>x[i]>>v[i];
	}
	double l = 0, r = 1e9;
	for(int i = 0; i< 100; i++){
		double m = (l+r)/2;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout<<setprecision(16)<<r<<"\n";
}