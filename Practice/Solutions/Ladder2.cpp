#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 102
#define INF 1000000000

int map[MAX_N][MAX_N];
int N;

////Hàm đi xuống bắt đầu từ map[0][c]:
int goDown(int c)
{
	int cnt = 0;
	for (int r = 0; r < N; r++) { //Đi dọc từ trên xuống dưới
		if (c > 0 && map[r][c - 1] == 1) { //Có đường ngang bên trái
			while (c > 0 && map[r][c - 1] == 1) {
				c--;
				cnt++;
			}
		}
		else if (c < N - 1 && map[r][c + 1] == 1) { //Có đường ngang bên phải
			while (c < N - 1 && map[r][c + 1] == 1) {
				c++;
				cnt++;
			}
		}
		cnt++;
	}
	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc, currCnt, minCnt, ret;
	do {
		scanf("%d%d", &tc, &N);
		minCnt = INF;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		//Đếm số bước đi của tất cả các con đường rồi chọn đường ngắn nhất		
		for (int i = N - 1; i >= 0; i--) {
			if (map[0][i] == 1) { //Nếu cột i là 1 đường dọc
				currCnt = goDown(i);
				if (currCnt < minCnt) {
					minCnt = currCnt;
					ret = i; //Người thứ i có thể là người có đường đi ngắn nhất
				}
			}
		}
		printf("#%d %d\n", tc, ret);
	} while (tc != 10);

	return 0;
}