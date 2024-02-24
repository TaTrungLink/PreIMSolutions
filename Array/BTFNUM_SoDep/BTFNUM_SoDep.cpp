#include <stdio.h>

int N, M;
bool isGoodDigit[10]; //mảng đánh dấu chữ số có phải là chữ số đẹp hay không

//Hàm kiểm tra 1 số có chứa đủ M số đẹp không
bool isGood(int x)
{
	int cnt = 0; //tổng số lần các chữ số đẹp xuất hiện

	while (x > 0) {
		if (isGoodDigit[x % 10]) {
			++cnt;
			if (cnt >= M) //khi đủ số lượng chữ số đẹp => x là số đẹp
				return true;
		}
		x /= 10;
	}
	return false; //số lượng chữ số đẹp < M nên x không phải là số đẹp
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int tc, T, cnt, x, y, tmp;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d%d", &N, &M);
		cnt = 0;
		for (int i = 0; i < 10; i++)
			isGoodDigit[i] = false;

		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			isGoodDigit[tmp] = true;
		}
		scanf("%d%d", &x, &y);
		for (int i = x; i <= y; i++)
			if (isGood(i))
				cnt++;

		printf("#%d %d\n", tc, cnt);
	}

	return 0;
}