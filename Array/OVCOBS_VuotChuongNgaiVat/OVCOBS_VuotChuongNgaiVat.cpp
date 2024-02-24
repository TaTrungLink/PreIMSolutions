#include <stdio.h>
#define MAX_N 101
#define MAX_H 1001

int N;
int m[MAX_N][MAX_N];

//Hàm tính số bước tối đa mà Alex có thể nhảy
int countSteps(int r, int c) { //r, c: tọa độ vị trí hiện tại
	int nextR, nextC, i, j;
	int minHeight;
	int cnt = 0;
	while (true) {
		minHeight = MAX_H;
		for (i = r - 1; i < r + 2; i++) { //kiểm tra tất cả các ô xung quanh ô hiện tại
			if (i < 0 || i >= N) continue; //nếu tọa độ vượt ra ngoài mảng, bỏ qua
			for (j = c - 1; j < c + 2; j++) {
				if (j < 0 || j >= N) continue;
				//nếu ô đang check cao hơn ô hiện tại và thấp hơn ô đã chọn trước đó, chọn ô này
				if (m[i][j] > m[r][c] && m[i][j] < minHeight) { 
					nextR = i;
					nextC = j;
					minHeight = m[i][j];
				}
			}
		}
		if (minHeight != MAX_H) { //nhảy sang ô được chọn và tăng số bước
			r = nextR;
			c = nextC;
			cnt++;
		} else //nếu không chọn được ô nào để nhảy, dừng thuật toán
			break;
	}
	
	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int T, test_case;
	int startR, startC;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d%d", &N, &startR, &startC);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &m[i][j]);

		printf("#%d %d\n", test_case, countSteps(startR, startC));
	}
	return 0;
}