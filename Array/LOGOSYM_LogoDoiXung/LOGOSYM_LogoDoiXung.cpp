#include <stdio.h>

#define MAX_N 33
int map[MAX_N][MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T, N;
	bool ret;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
		ret = true;
		for (int i = 0; i < (N + 1) / 2; i++) {
			for (int j = 0; j < (N + 1) / 2; j++) {
				//mỗi điểm có 3 điểm đối xứng: qua tâm, qua trục tung và qua trục hoành
				//nếu các điểm đối xứng không bằng nhau thì kết luận logo không đối xứng
				if (map[i][j] != map[N - 1 - i][N - 1 - j] || map[i][j] != map[i][N - 1 - j] || map[i][j] != map[N - 1 - i][j]) {
					ret = false;
					break;
				}
			}
			if (!ret)
				break;
		}

		printf("#%d %s\n", test_case, ret ? "YES" : "NO");
	}

	return 0;
}