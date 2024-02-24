#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int T, test_case, num, ret;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &num);
		for (ret = 1; ret * ret <= num; ret++)
			;
		
		ret--;
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}