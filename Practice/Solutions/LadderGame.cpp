#include <stdio.h>

#define MAX_N 102

int m[MAX_N][MAX_N];
int N;

//Đi từ m[N][c] lên trên, trả về số cột ở hàng trên cùng của đường đi
int goUp(int c)
{
	for (int r = N; r > 0; r--)
		if (m[r][c])
			c = m[r][c];
	return c;
}

int main()
{
	//freopen("ladder_game_input.txt", "r", stdin);
	int tc, M, B;
	int r, c1, c2;
	for (tc = 1; tc <= 10; tc++) {
		scanf("%d%d%d", &N, &B, &M);
		//Reset toàn bộ map và 4 viền xung quanh
		for (int i = 0; i < N + 2; i++)
			for (int j = 0; j < N + 2; j++)
				m[i][j] = 0;
		//Nhập thông tin từng đường ngang, tại mỗi đầu mút là thông tin số cột của đầu mút còn lại
        //Khi gặp 1 đầu mút, dựa vào số cột trên đó để nhảy thẳng sau đầu mút bên kia thay vì từng ô trên đường ngang
        //Các ô bằng 0 là ô trống hoặc điểm giữa của đường ngang		
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d%d", &r, &c1, &r, &c2);
			m[r][c1] = c2;
			m[r][c2] = c1;
		}
		
		printf("#%d %d\n", tc, goUp(B)); //Đi ngược từ vị trí quả bom để tìm điểm bắt đầu.
	}
	return 0;
}