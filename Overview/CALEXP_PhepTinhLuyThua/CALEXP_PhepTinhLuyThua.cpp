//Cách 1: nhân b lần số a
#include <stdio.h>

int main()
{
	int test_case, T, a, b, ret;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &a, &b);
		ret = 1;
		for (int i = 1; i <= b; i++)
			ret *= a;
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}

//Cách 2: nếu b lẻ: a ^ b = (a ^ (b / 2)) * (a ^ (b / 2)) * a
//nếu b chẵn: a ^ b = (a ^ (b / 2)) * (a ^ (b / 2))
// b liên tiếp bị chia đôi nên số phép tính toán sẽ giảm rất nhiều so với cách 1

//#include <stdio.h>
//
//int pow(int base, int ex)
//{
//	if (ex == 0)
//		return 1;
//	int tmp = pow(base, ex / 2);
//	if (ex % 2 == 1) //nếu số mũ lẻ
//		return tmp * tmp * base;
//	else //nếu số mũ chẵn
//		return tmp * tmp;
//}
//
//int main()
//{
//	//freopen("input.txt", "r", stdin);
//	int test_case, T, a, b;
//	scanf("%d", &T);
//	for (test_case = 1; test_case <= T; test_case++) {
//		scanf("%d%d", &a, &b);
//		printf("#%d %d\n", test_case, pow(a, b));
//	}
//
//	return 0;
//}