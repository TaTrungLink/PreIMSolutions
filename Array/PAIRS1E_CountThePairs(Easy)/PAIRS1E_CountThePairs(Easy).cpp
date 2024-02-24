//Cách 1: với mỗi số nhập từ input, kiểm tra khoảng cách của nó với tất cả các số đã nhập
#include <stdio.h>
#define MAX_N 10001

int A[MAX_N];

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T, N, K;;
	int count;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &N, &K);
		count = 0;
		for (int i = 0; i < N; i++) {			
			scanf("%d", &A[i]);
			for (int j = 0; j < i; j++)
				if (A[i] - A[j] == K || A[j] - A[i] == K)
					count++;
		}
			
		printf("%d\n", count);
	}

	return 0;
}


//Cách 2: Quick sort để sắp xếp, cửa sổ trượt để tìm số cặp có khoảng cách K trên mảng đã sắp xếp
//#include <stdio.h>
//#define MAX_N 10001
//
//int A[MAX_N];
//
//void swap(int i, int j)
//{
//	int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
//}
//
//void quickSort(int left, int right)
//{
//	if (left >= right)
//		return;
//	int last = left;
//	swap(left, (left + right) / 2);
//	for (int i = left + 1; i <= right; i++)
//		if (A[i] < A[left])
//			swap(++last, i);
//	swap(left, last);
//	quickSort(left, last - 1);
//	quickSort(last + 1, right);
//}
//
//
//int main()
//{
//	//freopen("input.txt", "r", stdin);
//	int test_case, T, N, K;
//	int left, right, count;
//	scanf("%d", &T);
//	for (test_case = 1; test_case <= T; test_case++) {
//		scanf("%d%d", &N, &K);
//		for (int i = 0; i < N; i++)
//			scanf("%d", &A[i]);
//		if (N < 2)
//			printf("0\n");
//		else {
//			quickSort(0, N - 1);
//          count = 0;
//			left = 0; right = 1;
//			while (right < N) {
//				if (A[right] - A[left] == K) {
//					count++;
//					left++;
//					right++;
//				}
//				else if (A[right] - A[left] < K)
//					right++;
//				else
//					left++;
//			}
//			printf("%d\n", count);
//		}
//	}
//	return 0;
//}