#include <stdio.h>

int main()
{
	int T, test_case, n, x, y;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d%d%d", &n, &x, &y);
		for (int i = 1; i < n; i++)
			if (i % x == 0 && i % y != 0)
				printf("%d ", i);

		printf("\n");
	}
	return 0;
}