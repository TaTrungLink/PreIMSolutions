#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int T, test_case, a, b;
	int i, square, cnt;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &a, &b);
		cnt = 0;

		printf("#%d ", test_case);
		for (i = 1; (square = i * i) <= b; i++) {
			if (square >= a) {
				printf("%d ", square);
				cnt++;
			}				
		}
		if (cnt == 0)
			printf("NO NUMBER");
		printf("\n");
	}

	return 0;
}