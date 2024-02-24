#include <stdio.h>
#define MAX_N 502

char map[MAX_N][MAX_N]; //input
int ret[5];

void check(int r, int c) //r, c là tọa độ ô trên cùng bên trái của từng chiếc cửa sổ
{
	//Nếu dòng trên cùng là ..... => loại 0
	//Nếu dòng trên cùng là ***** và dòng 2 là ..... => loại 1
	//Nếu dòng 2 là ***** và dòng 3 là ..... => loại 2
	//Nếu dòng 3 là ***** và dòng dưới cùng là ...... => loại 3
	//Nếu không dòng nào có ..... => loại 4

	for (int i = 0; i < 4; i++) {
		if (map[r + i][c] == '.') { //Tất cả các ô trên cùng dòng là giống nhau => chỉ cần check ô đầu tiên của từng dòng
			ret[i]++;
			return;
		}
	}
	ret[4]++;
}

int main()
{
	int test_case, T, N, M;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &N, &M);
		//Số hàng số cột thực tế của mảng input = số hàng số cột trong đề bài * 5 + 1
		N = 5 * N + 1;
		M = 5 * M + 1;
		//Reset mảng kết quả
		for (int i = 0; i < 5; i++)
			ret[i] = 0;

		for (int i = 0; i < N; i++)
			scanf("%s", map[i]);

		//Ô trên cùng bên trái của cửa sổ đầu tiên có tọa độ (1, 1)
		//Vị trí các cửa sổ tiếp theo bằng vị trí hiện tại dịch 5 ô theo chiều ngang hoặc dọc
		for (int i = 1; i < N; i += 5)
			for (int j = 1; j < M; j += 5)
				check(i, j);

		//In kết quả
		printf("#%d ", test_case);
		for (int i = 0; i < 5; i++)
			printf("%d ", ret[i]);
		printf("\n");
	}

	return 0;
}