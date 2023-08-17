#include<iostream>
#include<vector>
#define MAXN 100000
using namespace std;

/*
	Ý tưởng:
		Gọi p là một phép biến đổi qua m cặp l,r
		hay nói cách khác là vị trí thứ i qua phép biến đổi p
		sẽ thành vị trí thứ p[i] (i -> p[i])
	Ta nhận thấy rằng là sau mỗi phép biến đổi p thì i -> p[i] và p[i] in [1,n]
	Do đó nếu ta tiếp tục biến đổi phép p nhiều lần thì nó sẽ quay lại vị trí i ban đầu
	Nên ý tưởng của bài này là sẽ tìm x nhỏ nhất sao cho (p^x)[i] = i
	ở đây (p^x)[i] = p[...p[...p[i]]] có x chữ p

	Trong lúc ta đi tìm x ta cũng đồng đi tìm (p^k)[i] với 1 <= k <= x-1
	i -> p[i] -> p[p[i]] -> ...> (p^(x-1))[i] -> (p^x)[i] = i

	Xét hai chỉ số 1 <= i1 < i2 <= n:
		i1 -> p[i1] -> p[p[i1]] -> ...> (p^(x-1))[i1] -> (p^x)[i1] = i1
		i2 -> p[i2] -> p[p[i2]] -> ...> (p^(x-1))[i2] -> (p^x)[i2] = i2

	ta thấy là trong tiến trình biến đổi vị trí i1 nó có thể chứa cả
	tiến trình biến đổi vị trí của i2

	Do đó để tránh thực hiện cùng một tiến trình lại nhiều lần thì ta chỉ
	cần tìm một tiến trình bao quát để giảm độ phức tạp bài toán.
	
	Giả sử ta đã tạo ra được một tiến trình bao quát:
	A[i1] = {i1,i2,...,ix} (i1, i2, ...., ik là các vị trí từ 1 -> n)
	Tức là i1 -> p[i1] = i2 -> p[[i1]] = p[i2] = i3 ->...-> (p^x)[ix] = i1
	
	Như vậy để tìm vị trí của iy (iy thuộc {i1,i2,...,ix}) 
	sau K phép biến đổi p thì ta chỉ cần tìm vị trí của i1
	sau K phép biến đổi p cộng thêm khoảng cách từ iy đến i1 trong A[i1]
	là sẽ tìm được vị trí iy sau K phép biến đổi
	Khoảng cách này để sẽ làm ta sẽ đặt là dist. Khi đó dist[iy] = y-1

	Và để biết iy có trong tiến trình của i1 không ta cũng sẽ tạo một
	biến để lưu. Gọi đó là cc. Khi đó cc[iy] = i1
*/

int cc[MAXN], dist[MAXN], ans[MAXN], p[MAXN], l[100], r[100];
vector<int> A[MAXN+1];
int n,m;
long long k;

int main(){
	freopen("input.txt","r",stdin);
	freopen("a.txt","w",stdout);
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++){
		cin>>l[i]>>r[i];
		l[i]--; r[i]--;
	}

	for(int i = 0; i < n; i++){
		p[i] = i;
		for(int j = 0; j < m; j++){
			if(p[i] >= l[j] && p[i] <= r[j]){
				p[i] = l[j] + r[j] - p[i];
			}
		}
	}

	int C = 1;
	for(int i = 0; i < n; i++)if(!cc[i]){
		cc[i] = C;
		A[C].push_back(i);
		int j = p[i];
		if(j != i)dist[j] = 1;
		while(j != i){
			cc[j] = C;
			A[C].push_back(j);
			if(p[j] != i)dist[p[j]] = dist[j] + 1;
			j = p[j];
		}
		C++;
	}

	for(int i = 0; i < n; i++){
		ans[A[cc[i]][(dist[i]+k) % A[cc[i]].size()]] = i;
	}
	
	for(int i = 0; i < n; i++){
		cout<<ans[i]+1<<"\n";
	}
}