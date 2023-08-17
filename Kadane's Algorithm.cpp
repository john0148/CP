#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
/*
	Thuật toán của ông Kadane thực hiện như sau:
	Với mỗi chỉ số j (1 -> n) thì ông xem xét thử là đoạn con nào từ i -> j
	có tổng hậu tố lớn nhất chứa phần tử a[j], gọi sum lớn nhất đó là max_suffix_sum_j
	Rồi sau đó ông chỉ cần lấy max của các max_suffix_sum_j là được kết quả.

	Làm sao để tìm max_suffix_sum_j:
	Cái này thì dựa vào thuật toán tham lam:
		max_suffix_sum_j chứa phần từ a[j] như vậy để tính thì ta chỉ cần tính
		tổng hậu tố lớn nhất chứa phần tử a[j-1] rồi xem đó cộng thêm a[j].
		Nhưng có một điều cần trọng là nếu max_suffix_sum_(j-1) < 0
		thì max_suffix_sum_j = a[j]
		do đó công thức tính max_suffix_sum_j = max(max_suffix_sum_(j-1)+ a[j], a[j])

*/
int main() {
	int n;
	cin >> n;
	vector<long long> x(n);
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	ll max_suffix_sum = x[0];
	ll max_sum = x[0];
	for (int i = 1; i < n; i++) {
		max_suffix_sum = max(max_suffix_sum + x[i], x[i]);
		max_sum = max(max_sum, max_suffix_sum);
	}
	cout << max_sum << endl;
}