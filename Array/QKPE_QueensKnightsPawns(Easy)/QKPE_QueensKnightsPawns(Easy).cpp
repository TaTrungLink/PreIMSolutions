#include <stdio.h>
#define MAX_N 1001
#define MAX_AMOUNT 101
#define SAFE 0
#define OCCUPIED 1
#define UNSAFE 2

int map[MAX_N][MAX_N];
int N, M;
int safeCount;

//8 hướng quân hậu có thể đi
int queenDx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int queenDy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//8 vị trí quân mã có thể nhảy tới
int knightDx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int knightDy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int queenRow[MAX_AMOUNT];
int queenCol[MAX_AMOUNT];
int knightRow[MAX_AMOUNT];
int knightCol[MAX_AMOUNT];

void checkQueen(int r, int c)
{
	int nextR, nextC;
	for (int d = 0; d < 8; d++) {
		nextR = r + queenDy[d];
		nextC = c + queenDx[d];
		while (true) {
			//nếu đi ra ngoài hoặc bị chặn
			if (nextR < 1 || nextR > N || nextC < 1 || nextC > M || map[nextR][nextC] == OCCUPIED)
				break;
			//đánh dấu ô bị ăn
			if (map[nextR][nextC] == SAFE) {
				map[nextR][nextC] = UNSAFE;
				safeCount--;
			}
			nextR += queenDy[d]; 
			nextC += queenDx[d];
		}
	}
}

void checkKnight(int r, int c)
{
	int nextR, nextC;
	for (int d = 0; d < 8; d++) {
		nextR = r + knightDy[d];
		nextC = c + knightDx[d];
		//ô ở ngoài map hoặc bị chiếm chỗ
		if (nextR < 1 || nextR > N || nextC < 1 || nextC > M || map[nextR][nextC] == OCCUPIED)
			continue;
		//đánh dấu ô bị ăn
		if (map[nextR][nextC] == SAFE) {
			map[nextR][nextC] = UNSAFE;
			safeCount--;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, r, c;
	int qNum, kNum, pNum; //số lượng queen, knight, pawn

	for (test_case = 1; ; test_case++) {
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0)
			break;

		//Ban đầu đánh dấu tất cả các ô là an toàn
		safeCount = N * M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				map[i][j] = SAFE;

		scanf("%d", &qNum);
		for (int i = 0; i < qNum; i++) {
			scanf("%d%d", &queenRow[i], &queenCol[i]);
			map[queenRow[i]][queenCol[i]] = OCCUPIED;
		}

		scanf("%d", &kNum);
		for (int i = 0; i < kNum; i++) {
			scanf("%d%d", &knightRow[i], &knightCol[i]);
			map[knightRow[i]][knightCol[i]] = OCCUPIED;
		}

		scanf("%d", &pNum);
		for (int i = 0; i < pNum; i++) {
			scanf("%d%d", &r, &c);
			map[r][c] = OCCUPIED;
		}
		safeCount -= pNum + kNum + qNum;

		for (int i = 0; i < qNum; i++)
			checkQueen(queenRow[i], queenCol[i]);
		for (int i = 0; i < kNum; i++)
			checkKnight(knightRow[i], knightCol[i]);

		printf("Board %d has %d safe squares.\n", test_case, safeCount);
	}

	return 0;
}