#include <stdio.h>

int main(void) {
	//freopen("input.txt", "r", stdin);
	int T, test_case, n;
	int sum;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &n);
		while (n > 9) { //chừng nào còn nén được (nhiều hơn 1 chữ số)
			sum = 0; //tính tổng các chữ số
			while (n > 0) {
				sum += n % 10; //lấy từng chữ số và cộng vào tổng
				n /= 10;
			}
			n = sum; //gán n bằng tổng các chữ số
		}
		printf("#%d %d\n", test_case, n);
	}

	return 0;
}