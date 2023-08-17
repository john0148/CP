#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;
const int MAXN = 1e5 + 10;
struct location{
	int x, y;
};

int n;
vector<struct location> node;
bool visited[MAXN];

int distance(struct location A, struct location B){
	int dx = A.x - B.x;
	int dy = A.y - B.y;
	return dx*dx + dy*dy;
}

void bfs(int x, int &cnt, int dist){
	visited[x] = true;
	deque<int> q; q.push_back(x);
	while(!q.empty()){
		int v = q.front();
		q.pop_front();
		for(int i = 0; i < n; i++){
			if(!visited[i] && distance(node[v],node[i]) <= dist){
				visited[i] = true;
				q.push_back(i);
				cnt++;
			}
		}
	}
}


bool good(int m){
	fill(visited,visited+n,false);
	int cnt = 1;
	bfs(0,cnt,m);
	return cnt >= n;
}



int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n; node.resize(n);
	for(int i = 0; i < n; i++){
		cin>>node[i].x>>node[i].y;
	}
	int l = 0, r = 1;
	while(!good(r))r*=2;
	while(l + 1 < r){
		int m = (l+r)/2;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout<<r<<"\n";
}