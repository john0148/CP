#include<iostream>
#include<cstring>
#include<vector>
#define MAXN 100

using namespace std;

int n;
vector<string> all_characterics;
vector<string> characterics[MAXN];

bool crossing(int a, int b){
	int A = 0, B = 0, AB = 0;
	for(int i = 0; i <n; i++){
		vector<string> &v = characterics[i];
		bool has_a = false, has_b = false;
		int size_v = v.size();
		for(int j = 0; j < size_v; j++){
			if(v[j] == all_characterics[a])has_a = true;
			if(v[j] == all_characterics[b])has_b = true;
		}
		if(has_a && has_b)AB++;
		else if(has_a)A++;
		else if(has_b)B++;
	}
	return AB > 0 && A > 0 && B > 0;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n;
	string s;
	for(int i  = 0; i < n; i++){
		int k; cin>>k;
		for(int j = 0; j < k; j++){
			cin>>s;
			characterics[i].push_back(s);
			bool check = false;
			int size_all_c = all_characterics.size();
			for(int k = 0; k < size_all_c; k++){
				if(all_characterics[k] == s)check = true;
			}
			if(!check)all_characterics.push_back(s);
		}
	}

	bool ok = true;
	int m = all_characterics.size();
	for(int a = 0; a < m; a++){
		for(int b = a + 1; b < m; b++){
			if(crossing(a,b))ok = false;
		}
	}

	if(ok)cout<<"yes\n";
	else cout<<"no\n";
}