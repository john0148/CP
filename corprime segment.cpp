#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long MAX = 10000000;
int n;
vector<long long> a;

long long gcd(long long a, long long b){
	return (b == 0) ? a : gcd(b,a%b);
}

struct stack{
	vector<long long> s, sgcd = {0};
	void push(long long x){
		s.push_back(x);
		sgcd.push_back(gcd(sgcd.back(),x));
	}

	long long pop(){
		long long res = s.back();
		s.pop_back();
		sgcd.pop_back();
		return res;
	}

	bool empty(){
		return s.empty();
	}

	long long gcds(){
		return sgcd.back();
	}
};

struct stack s1,s2;

void add(long long x){
	s2.push(x);
}

void remove(){
	if(s1.empty()){
		while(!s2.empty()){
			s1.push(s2.pop());
		}
	}
	s1.pop();
}

bool good(){
	int GCD = gcd(s1.gcds(),s2.gcds());
	return GCD == 1;
}

int main(){
	// freopen("input.txt","r",stdin);
	// freopen("a.txt","w",stdout);
	cin>>n; a.resize(n);
	for(int i = 0; i<n; i++)cin>>a[i];

	long long l = 0;
	long long res = MAX;
	for(long long r = 0; r < n; r++){
		add(a[r]);
		while(good()){
			res = min(res,r - l +1);
			remove();
			l++;
		}

	}
	if(res == MAX){
		cout<<-1<<"\n";
	}
	else{
		cout<<res<<"\n";
	}
}