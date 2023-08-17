#include<iostream>
#include<vector>
using namespace std;

bool cow_ends_infected[101];
int N, T, cowx[251], cowy[251];

bool check_f0(int patient_f0, int K){
	bool infection[101] = {false};
	infection[patient_f0] = true;
	int numInfection[251] = {0};
	for(int t  = 0; t <= 250; t++ ){
		int x = cowx[t], y = cowy[t];
		if(x > 0){
			if(infection[x])numInfection[x]++;
			if(infection[y])numInfection[y]++;
			if(numInfection[x] <=  K && infection[x])infection[y]=true;
			if(numInfection[y] <=  K && infection[y])infection[x]=true;
		}
	}
	for(int i =1; i <= N; i++){
		if(infection[i] != cow_ends_infected[i])return false;
	}
	return true;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	string s;
	cin>>N>>T>>s;
	for(int i = 1; i<= N; i++){
		cow_ends_infected[i] = s[i-1] == '1';
	}
	for(int i = 0; i < T; i++){
		int t,x,y;
		cin>>t>>x>>y;
		cowx[t] = x; cowy[t] = y;
	}

	bool possible_i[101] = {false};
	bool possible_K[252] = {false};
	for(int i = 1; i <= N; i++){
		for(int K = 0; K <= 251; K++){
			if(check_f0(i,K))
				{possible_i[i] = true; possible_K[K] = true;}
		}
	}
	int patients_f0 = 0, upper_K = 0, lower_K = 0;
	for(int i = 1; i < N; i++)
		if(possible_i[i])patients_f0++;
	for(int K = 0; K <= 251; K++){
		if(possible_K[K])upper_K = K;
	}
	for(int K = 251; K>=0; K--){
		if(possible_K[K])lower_K = K;
	}
	cout<<patients_f0<<" "<<lower_K<<" "<<upper_K<<"\n";

}