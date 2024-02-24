#include <stdio.h>

//Hàm tìm số đảo ngược của số x
int reverse(int x) {
	int ret = 0;
	int digit;
	while (x > 0) {
		digit = x % 10; //lấy từng chữ số
		ret = ret * 10 + digit; //thêm chữ số vào số đảo ngược 
		x /= 10;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T, test_case, a, b, reverse_a, reverse_b;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d%d", &a, &b);
		//lấy 2 số đảo ngược
		reverse_a = reverse(a);
		reverse_b = reverse(b);
		//in ra số đảo ngược của tổng 2 số đó
		printf("%d\n", reverse(reverse_a + reverse_b));
	}
	return 0;
}