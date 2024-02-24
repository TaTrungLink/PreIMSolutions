#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N 102

int N;
int map[MAX_N][MAX_N];

//Hàm đi lên bắt đầu từ map[N - 1][c]:
int goUp(int c)
{
	for (int r = N - 1; r >= 0; r--) { //Đi dọc từ dưới lên trên
		if (c > 0 && map[r][c - 1] == 1) //Có đường ngang bên trái
			while (c > 0 && map[r][c - 1] == 1)
				c--;
		else if (c < N - 1 && map[r][c + 1] == 1) //Có đường ngang bên phải
			while (c < N - 1 && map[r][c + 1] == 1)
				c++;
	}
	return c;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc, target;
	do {
		scanf("%d%d", &tc, &N);
		//Nhập input, lưu lại số cột chứa quả bom
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2)
					target = j;
			}
		}
		printf("#%d %d\n", tc, goUp(target));
	} while (tc != 10);
	return 0;
}