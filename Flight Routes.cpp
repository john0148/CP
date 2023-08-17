#include<iostream>
#include<vector>
const int MAXN = 1e5 + 10;
using namespace std;

int n,m;
vector<int> inNode[MAXN], outNode[MAXN];
bool visited[MAXN];

void dfs(int node, vector<int> adj[]){
	visited[node] = true;
	for(auto v : adj[node]){
		if(!visited[v]){
			dfs(v,adj);
		}
	}
}

bool checkConnection(int &x, int &y){
	dfs(0,outNode);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			x = 1;
			y = i+1;
			return false;
		}
	}
	fill(visited,visited+n,false);
	dfs(0,inNode);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			x = i+1;
			y = 1;
			return false;
		}
	}
	return true;
}

int main(){
	// freopen("input.txt","r",stdin);
	// freopen("a.txt","w",stdout);
	cin>>n>>m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		a--; b--;
		inNode[b].push_back(a);
		outNode[a].push_back(b);
	}
	int x = 0, y = 0;
	if(checkConnection(x,y)) cout<<"YES\n";
	else cout<<"NO\n"<<x<<" "<<y<<endl;
}