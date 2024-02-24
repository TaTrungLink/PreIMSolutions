#include <stdio.h>

int main()
{
	int num;
	while (true) {
		scanf("%d", &num);
		if (num == 42)
			break;
		printf("%d\n", num);
	}
	return 0;
}