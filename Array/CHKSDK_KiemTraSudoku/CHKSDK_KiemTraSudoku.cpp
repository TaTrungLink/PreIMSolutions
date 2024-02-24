#include <stdio.h>
char map[9][10];
bool exist[9];//đánh dấu sự tồn tại của một giá trị trong 1 hàng, 1 cột hoặc 1 ô 3x3

bool checkHorizontal()
{
	//kiểm tra từng hàng
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) //reset mảng đánh dấu
			exist[j] = false;
		for (int j = 0; j < 9; j++) {
			if (map[i][j] != '.') {
				if (exist[map[i][j] - '1'])
					return false;
				exist[map[i][j] - '1'] = true;
			}
		}
	}
	return true;
}

bool checkVertical()
{
	//kiểm tra từng cột
	for (int i = 0; i < 9; i++) {
		//reset mảng đánh dấu
		for (int j = 0; j < 9; j++)
			exist[j] = false;
		for (int j = 0; j < 9; j++) {
			if (map[j][i] != '.') {
				if (exist[map[j][i] - '1'])
					return false;
				exist[map[j][i] - '1'] = true;
			}
		}
	}
	return true;
}

bool checkSquare() {
	//kiểm tra từng ô vuông 3x3
	//nếu ô trên cùng bên trái của 1 ô vuông có tọa độ (r, c), duyệt các ô trong khoảng từ r đến r + 2, và c đến c + 2
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) { //i, j là ô trên cùng bên trái của hình vuông nhỏ
			for (int k = 0; k < 9; k++)
				exist[k] = false;
			for (int k = i; k < i + 3; k++) { //duyệt trong hình vuông nhỏ
				for (int t = j; t < j + 3; t++) {
					if (map[k][t] != '.') {
						if (exist[map[k][t] - '1'])
							return false;
						exist[map[k][t] - '1'] = true;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	int tc, T;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 9; i++)
			scanf("%s", map[i]);
		//nếu cả 3 hàm check đều true thì in ra 1, chỉ cần một hàm false sẽ in ra 0
		printf("#%d %d\n", tc, checkHorizontal() && checkVertical() && checkSquare());
	}
	return 0;
}