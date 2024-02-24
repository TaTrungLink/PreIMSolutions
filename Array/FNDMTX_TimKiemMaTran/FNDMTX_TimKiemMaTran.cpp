//Cách 1: tại từng điểm, tính tổng ma trận con M x M bắt đầu tại điểm đó
#include <stdio.h>
#define MAX_N 100

int map[MAX_N][MAX_N];
int N, M;

int sum(int startR, int startC)
{
	int ret = 0;
	for (int i = startR; i < startR + M; i++)
		for (int j = startC; j < startC + M; j++)
			ret += map[i][j];
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc, T, K;
	int curSum, curDiff; //tổng ma trận con hiện tại và chênh lệch của tổng đó với số K
	int retSum, minDiff; //tổng của ma trận con và mức chênh lệch tốt nhất đến thời điểm hiện tại
	int r = 0, c = 0; //hàng và cột kết quả
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d%d%d", &N, &M, &K);
		minDiff = 100000000;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
			
		for (int i = 0; i <= N - M; i++) {
			for (int j = 0; j <= N - M ; j++) {
				curSum = sum(i, j);
				curDiff = curSum > K ? curSum - K : K - curSum;
				//So sánh diff hiện tại với diff thấp nhất, nếu bằng nhau thì so tổng hiện tại với tổng đã chọn lúc trước
				//Nếu cả diff và sum đều bằng của 1 ô đã chọn lúc trước thì chọn ô trước, vì số hàng và cột của ô trước nhỏ hơn
				if (curDiff < minDiff || (curDiff == minDiff && curSum < retSum)) {
					r = i;
					c = j;
					minDiff = curDiff;
					retSum = curSum;
				}
			}
		}

		printf("#%d %d %d\n", tc, r, c);
	}

	return 0;
}


//Cách 2: Vẫn so sánh tổng các ô của từng ma trận con M x M giống cách 1
//Nhưng giảm số lần tính toán khi tính tổng bằng cách tận dụng các ô đã được tính toán trước đó
//Ví dụ muốn tính tổng của 1 ma trận con M x M khi đã biết tổng của ma trận con bên trái nó:
//lấy tổng đã biết trừ đi tổng cạnh bên trái của ma trận con bên trái trước rồi cộng cạnh bên phải của ma trận con hiện tại
//Tương tự khi đã biết tổng của ma trận con bên phải hoặc ở trên thì cũng trừ đi cạnh bị cắt và cộng thêm cạnh mới

//#include <stdio.h>
//#define MAX_N 100
//
//int map[MAX_N][MAX_N];
//int N, M, K;
//int curSum, curDiff;
//int retSum, minDiff, r, c;
//
//void updateResult(int i, int j) //tương tự cách 1
//{
//	curDiff = curSum > K ? curSum - K : K - curSum;
//	if (curDiff < minDiff || (curDiff == minDiff && curSum < retSum) || (curDiff == minDiff && curSum == retSum && i == r)) {
//		r = i;
//		c = j;
//		minDiff = curDiff;
//		retSum = curSum;
//	}
//}
//
//int main()
//{
//	//freopen("input.txt", "r", stdin);
//	int tc, T;	
//	int i, j;
//	scanf("%d", &T);
//	for (tc = 1; tc <= T; tc++) {
//		scanf("%d%d%d", &N, &M, &K);
//		minDiff = 100000000;
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < N; j++)
//				scanf("%d", &map[i][j]);
//		retSum = 0;
//      
//      Tính tổng ma trận con đầu tiên
//		for (int i = 0; i < M; i++) {
//			for (int j = 0; j < M; j++) {
//				retSum += map[i][j];
//			}
//		}
//		minDiff = retSum > K ? retSum - K : K - retSum;
//		r = 0; c = 0;
//		curSum = retSum;
//		for (i = 0; ; i++) {
//			if (i % 2 == 1) { //chạy từ phải sang trái
//				for (j = N - M - 1; j >= 0; j--) {
//					for (int k = 0; k < M; k++)
//						curSum  = curSum - map[i + k][j + M] + map[i + k][j];
//					updateResult(i, j);
//				}
//				j = 0;
//			} else { //chạy từ trái sang phải
//				for (j = 1; j <= N - M; j++) {
//					for (int k = 0; k < M; k++)
//						curSum = curSum - map[i + k][j - 1] + map[i + k][j + M - 1];
//					updateResult(i, j);
//				}
//				j = N - M;
//			}
//
//			if (i >= N - M)
//				break;
//          //chạy xuống dưới
//			for (int k = 0; k < M; k++)
//				curSum = curSum - map[i][j + k] + map[i + M][j + k];
//			updateResult(i + 1, j);
//		}
//
//		printf("#%d %d %d\n", tc, r, c);
//	}
//
//	return 0;
//}