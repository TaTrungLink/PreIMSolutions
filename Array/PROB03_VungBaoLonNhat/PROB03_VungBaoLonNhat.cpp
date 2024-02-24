#include <stdio.h>
#define MAX_N 101
int map[MAX_N][MAX_N];

//Đếm tổng giá trị các ô lẻ trên viền của hình chữ nhật kích thước H * W, điểm trên cùng bên trái là (r, c)
int cal(int r, int c, int H, int W)
{
	int sum = 0;
	//Tính trên 2 cạnh dọc
	for (int i = 0; i < H; i++) {
		if (!(map[r + i][c] & 1))
			sum += map[r + i][c];
		if (!(map[r + i][c + W - 1] & 1))
			sum += map[r + i][c + W - 1];
	}
	//Tính trên 2 cạnh ngang
	for (int i = 1; i < W - 1; i++) {
		if (!(map[r][c + i] & 1))
			sum += map[r][c + i];
		if (!(map[r + H - 1][c + i] & 1))
			sum += map[r + H - 1][c + i];
	}
	return sum;
}

int main()
{
	int testcase, T, N, M, H, W;
	//freopen("input.txt", "r", stdin);
	int maxSum, sum;
	scanf("%d", &T);
	for (testcase = 1; testcase <= T; testcase++) {
		scanf("%d%d%d%d", &H, &W, &N, &M);
		maxSum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &map[i][j]);
		for (int i = 0; i <= N - H; i++) {
			for (int j = 0; j <= M - W; j++) {
				if ((sum = cal(i, j, H, W)) > maxSum)
					maxSum = sum;
			}
		}

		printf("#%d %d\n", testcase, maxSum);
	}

	return 0;
}