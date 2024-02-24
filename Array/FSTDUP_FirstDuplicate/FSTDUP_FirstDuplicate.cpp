#include <stdio.h>
#define MAX_N 100001
bool exist[MAX_N]; //mảng đánh dấu trạng thái của 1 số đã xuất hiện hay chưa

int main()
{
	int test_case, T, N, num;
	int ret; //Answer
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		//Reset
		ret = -1;
		for (int i = 1; i <= N; i++)
			exist[i] = false;
		
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num);
			if (ret == -1) { 
			    //nếu num đã từng xuất hiện trước đó => num chính là số đầu tiên xuất hiện 2 lần:
				if (exist[num])
					ret = num;
				else
					exist[num] = true; //nếu chưa, đánh dấu là đã xuất hiện
			} //nếu đã có câu trả lời (ret != -1), chỉ cần scan cho hết input mà không cần check
		}
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}