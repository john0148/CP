#include<iostream>
#include<vector>

using namespace std;


vector<int> adj[1001], child;
bool visited[1001];

int childNode(int node){
	if(adj[node].size()  == 0){
		visited[node] = true;
		child[node] = node;
		return child[node];
	}
	else{
		if(!visited[node]){
			visited[node] = true;
			for(auto v : adj[node]){
				child[node] =  childNode(v);
				return child[node];
			}
		}
		else{
			return child[node];
		}
	}
	return child[node];
}

int main(){
	// freopen("input.txt","r",stdin);
	// freopen("a.txt","w",stdout);
	int n; cin>>n;
	child.resize(n);
	int a,b;
	for(int i = 0; i < n-1; i++){
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
	}
	int res = childNode(0);
	bool check = true;
	for(int i = 1; i <n; i++){
		if(res != childNode(i)){
			check = false;
			break;
		}
	}
	if(check){
		cout<<res+1<<"\n";
	}
	else{
		cout<<-1<<"\n";
	}
}

