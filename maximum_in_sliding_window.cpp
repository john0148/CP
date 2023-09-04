#include<iostream>
#include<vector>
#include<deque>


const int MAX = 1e5+5;
std::vector<int> Maximum_sliding(std::vector<int> a, int m){
	std::vector<int> res;
	std::deque<int> q;
	for(int i = 0;i < (int)a.size(); i++){
		while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.push_back(i);
		while(i - q.front() + 1 > m) q.pop_front();
		if(i >= m-1)res.push_back(a[q.front()]);
	}
	return res;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	int n, m; 
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) std::cin >> a[i];
	std::cin >> m;
	std::vector<int> ans = Maximum_sliding(a, m);
	for(int i = 0;i <(int)ans.size(); i++) std::cout<<ans[i]<<" ";
}