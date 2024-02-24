#include <stdio.h>
#define MOD 1000007

//Cách 1: Xét từng số i từ 1 đến N, nhân số đó với N / i rồi cộng vào tổng
/*int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T, N, sum, i;
	int product;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		sum = 0;
		for (i = 1; i <= N; i++) {
			product = i * (N / i);
			sum = (sum + product) % MOD;
		}
		printf("%d\n", sum);
	}

	return 0;
}*/


//Cách 2: Giảm số lượng phép tính để tối ưu thời gian

//Hàm tính tổng các số nguyên liên tiếp trong 1 đoạn
long long consecutiveSum(int from, int to) {
	long long ret = (long long)(to - from + 1) * (from + to) / 2; //dùng long long vì nhân 2 số có thể tràn integer
	return ret % MOD;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T, N, sum, i;
	int left, right;
	long long tmpSum;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		sum = 0;
		right = N;
		
		// Với mỗi số i nhỏ hơn căn bậc 2 của N, cộng i * N / i vào tổng
		// Đồng thời sẽ có một hoặc nhiều số j lớn hơn căn bậc 2 của N sao cho N / j = i
		// Tìm tất cả các số j như vậy và nhân với i
		
		// Ví dụ với N = 11 và i = 1, ta có 1 * (11 / 1) = 11 => cộng vào tổng
		// Các số j từ 6 đến 11 đều có N / j = 1 => tính tổng từ 6 đến 11, rồi nhân với 1 và cộng vào tổng
		// Với i = 2, ta có 2 * (11 / 2) = 10 => cộng vào tổng
		// Các số j từ 4 đến 5 có N / j = 2 => tính tổng từ 4 đến 5, rồi nhân với 2 và cộng vào tổng
		
		for (i = 1; i * i <= N; i++) {
			tmpSum = i * (N / i); //tmpSum là tổng tất cả các tích có chứa i
			sum = (sum + tmpSum) % MOD;
			
			//Các số từ left đến right là các số j thỏa mãn N / j = i
			left = N / (i + 1) + 1;
			right = N / i;
			if (left == right && i == left) //nếu không có số nào
				continue;
				
			//Nếu có, tính tổng các số từ left đến right, rồi nhân với i và cộng vào tổng
			tmpSum = (consecutiveSum(left, right) * i) % MOD;
			sum = (sum + tmpSum) % MOD;
		}
		printf("%d\n", sum);
	}

	return 0;
}
