#include <stdio.h>
#define MAX_N 1000

bool board[MAX_N][MAX_N]; //board[i][j] = true nghĩa là ở vị trí (i, j) có quân cờ có thể ăn, false tức là không có quân nào hoặc quân cờ không thể ăn
int N;
//Danh sách tọa độ các quân mã
int knightRow[MAX_N * MAX_N];
int knightCol[MAX_N * MAX_N];

//8 vị trí quân mã có thể ăn
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

//Hàm đếm số quân cờ mà quân mã ở vị trí (r, c) có thể ăn
int count(int r, int c) {
	int nextR, nextC;
	int ret = 0;
	for (int d = 0; d < 8; d++) {
		nextR = r + dy[d];
		nextC = c + dx[d];
		if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && board[nextR][nextC]) //vị trí (nextR, nextC) có quân cờ có thể bị ăn
			ret++;
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc, T, i, r, c;
    int K, M, D;
	int maxCnt, currCnt;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d%d%d%d", &N, &K, &M, &D);
		for (i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = false;
			      
		for (i = 0; i < K; i++) {
			scanf("%d%d", &knightRow[i], &knightCol[i]);
			board[knightRow[i]][knightCol[i]] = true; //Quân mã cũng có thể bị ăn, đánh dấu là true
		}
			
		for (i = 0; i < M; i++) {
			scanf("%d%d", &r, &c);
			board[r][c] = true;
 		}
		for (i = 0; i < D; i++) {
			scanf("%d%d", &r, &c);
			board[r][c] = false; //Đánh dấu lại ô (r, c) là không thể bị ăn
		}
		maxCnt = -1;
		for (int i = 0; i < K; i++) {
			currCnt = count(knightRow[i], knightCol[i]);
			if (currCnt > maxCnt) {
				maxCnt = currCnt;
				r = knightRow[i];
				c = knightCol[i];
			}
		}

		printf("#%d %d %d %d\n", tc, r, c, maxCnt);
	}
	return 0;
}