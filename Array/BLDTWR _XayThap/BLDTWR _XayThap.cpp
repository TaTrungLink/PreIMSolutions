#include <stdio.h>
#define MAX_N 51

int weight[MAX_N];
int N;

//Sắp xếp các viên gạch theo thứ tự giảm dần về cân nặng
void sort() {
	int i, j, temp;
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N; j++)
			if (weight[j] > weight[i]) {
				temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
			}
}


int main()
{
	int test_case, T;
	//freopen("input.txt", "r", stdin);
	int ret, floor, brick;
	int M1, M2;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d%d", &N, &M1, &M2);
		for (brick = 0; brick < N; brick++)
			scanf("%d", &weight[brick]);
		
		//Sắp xếp, các viên gạch nặng nhất sẽ dùng để xây những tầng dưới cùng
		sort();
		
		ret = 0;
		if (M2 < M1) { //đổi chỗ để M1 luôn thấp hơn
			int tmp = M2; M2 = M1; M1 = tmp;
		}

		//Chừng nào cả 2 tòa tháp chưa xây xong, lấy 2 viên nặng nhất chia đều vào 2 tòa tháp
		for (floor = 1, brick = 0; floor <= M1; floor++, brick += 2)
			ret += floor * (weight[brick] + weight[brick + 1]);
		
		//Còn lại 1 tòa tháp, đưa tất cả số gạch còn lại vào tòa tháp đó
		for ( ; brick < N; floor++, brick++)
			ret += floor * weight[brick];
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}