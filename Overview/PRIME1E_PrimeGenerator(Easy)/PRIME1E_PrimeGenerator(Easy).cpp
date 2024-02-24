#include <stdio.h>

//Hàm kiểm tra số nguyên tố
bool isPrime(int x)
{
	if (x == 1) //1 không phải là số nguyên tố
		return false;
	//Nếu x = y * z chắc chắn một trong hai y hoặc z phải nhỏ hơn căn bậc 2 của x
	// => Chỉ cần cho i chạy đến căn bậc 2 của x để giảm thời gian tìm kiếm
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	//Nếu không có ước nào trong khoảng từ 2 đến căn x => là số nguyên tố
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int T, test_case, a, b;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &a, &b);
		b++;
		for (int i = a; i < b; i++) {
			if (isPrime(i))
				printf("%d\n", i);
		}
		printf("\n");
	}

	return 0;
}