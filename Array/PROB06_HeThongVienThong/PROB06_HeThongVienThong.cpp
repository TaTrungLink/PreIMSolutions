#include <iostream>
#define MAX_N 102

using namespace std;

char map[MAX_N][MAX_N];
bool isCovered[MAX_N][MAX_N];//mảng đánh dấu 1 vị trí đã được phủ sóng hay chưa
int N, M;

void spread(int r, int c, int type) //từ 1 trạm phát sóng, đánh dấu tất cả các điểm nó có thể phủ sóng
{
	for (int step = 1; step <= type; step++) {
		if (r - step >= 0) isCovered[r - step][c] = true;
		if (r + step < N) isCovered[r + step][c] = true;
		if (c - step >= 0) isCovered[r][c - step] = true;
		if (c + step < M) isCovered[r][c + step] = true;
	}
}

int main()
{
	int test_case, T;
	//freopen("input.txt", "r", stdin);
	int ret;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		//Reset mảng đánh dấu:
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				isCovered[i][j] = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 'A' && map[i][j] <= 'C') //trạm phát sóng
					spread(i, j, map[i][j] - 'A' + 1);
			}
		}

		ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'H' && !isCovered[i][j]) //hộ dân chưa được phủ sóng
					ret++;
			}
		}
		cout << "#" << test_case << " " << ret << endl;
	}

	return 0;
}