#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
const int MAXN = 1e5;

using namespace std;

struct location{
	int x,y;
};

struct perimeter{
	int right = INT_MIN;
	int left = INT_MAX;
	int top = INT_MIN;
	int bottom = INT_MAX;
};

vector<int> adj[MAXN];
vector<struct location> positions;
bool visited[MAXN];
int n, m;

void initialPerimeter(struct location pos, struct perimeter &peri){
	if(pos.x < peri.left)peri.left = pos.x;
	if(pos.x > peri.right)peri.right = pos.x;
	if(pos.y < peri.bottom)peri.bottom = pos.y;
	if(pos.y > peri.top)peri.top = pos.y;
}

void dfs(int node, struct perimeter &peri){
	visited[node] = true;
	initialPerimeter(positions[node],peri);
	for(auto v : adj[node]){
		if(!visited[v]){
			dfs(v,peri);
		}
	}
}

int perimeterOfconnection(struct perimeter peri){
	return (peri.right - peri.left + peri.top - peri.bottom)*2;
}

int minPerimeter(){
	int res = INT_MAX;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			struct perimeter peri;
			dfs(i,peri);
			res = min(res,perimeterOfconnection(peri));
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n>>m;
	positions.resize(n);
	for(int i = 0; i < n; i++){
		cin>>positions[i].x>>positions[i].y;
	}
	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<minPerimeter()<<endl;
}
