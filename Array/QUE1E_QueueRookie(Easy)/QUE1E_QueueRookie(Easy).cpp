#include <stdio.h>
#define MAX_N 1001

int N;
int height[MAX_N], tallerCnt[MAX_N];
int ret[MAX_N];

//Sắp xếp theo thứ tự chiều cao tăng dần
//Nếu 2 người chiều cao bằng nhau, ai có số tallerCnt ít hơn sẽ đứng trước
void sort() {
	int i, j, temp;
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N; j++)
			if (height[j] < height[i] || (height[j] == height[i] && tallerCnt[j] < tallerCnt[i])) {
				//Đổi chỗ ở cả 2 mảng
				temp = height[i]; height[i] = height[j]; height[j] = temp;
				temp = tallerCnt[i]; tallerCnt[i] = tallerCnt[j]; tallerCnt[j] = temp;
			}
}

int main() {
	int T, cnt, i, j;
	//freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	while (T > 0) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d", &height[i]);
			ret[i] = 0; //ban đầu tất cả các ô trong mảng kết quả đều là ô trống
		}
		for (i = 0; i < N; i++)
			scanf("%d", &tallerCnt[i]);

		sort();

		//Lần lượt xếp từng người từ thấp nhất đến cao nhất vào mảng kết quả
		//Nếu trước một người có x người cao hơn anh ta thì dành ra x ô trống cho những người cao hơn đó
		//Người này sẽ ở ô trống thứ x + 1
		for (i = 0; i < N; i++) {
			cnt = 0;
			for (j = 0; j < N; j++) {
				if (ret[j] == 0) { //ô trống
					cnt++;
					if (cnt > tallerCnt[i]) { //đã dành đủ số ô trống, i sẽ là vị trí của người hiện tại
						ret[j] = height[i];
						break;
					}
				}
			}
		}

		for (i = 0; i < N; i++) printf("%d ", ret[i]);
		printf("\n");
		T--;
	}
	return 0;
}