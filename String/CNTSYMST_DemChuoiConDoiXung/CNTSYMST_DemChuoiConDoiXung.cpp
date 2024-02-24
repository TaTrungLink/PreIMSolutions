#include <stdio.h>
#define MAX_LEN 1001

char str[MAX_LEN];

//Từ vị trí pos, lan sang 2 bên để đếm số palindrome mà có pos là vị trí ở giữa
int countPalindrome(int pos)
{
	int cnt = 1; //bản thân mỗi phần tử đã là một palindrome
    //Trường hợp độ dài chuỗi lẻ, so sánh các phần tử đối xứng qua pos, ví dụ pos - 1 vs pos + 1
	for (int i = 1; pos - i >= 0 && str[pos + i] != '\0'; i++) {
		if (str[pos - i] == str[pos + i])
			cnt++;
		else
			break;
	}
    //Trường hợp độ dài chẵn, so sánh các phần tử đối xứng qua cặp pos và pos + 1, ví dụ pos - 1 vs pos + 2
	for (int i = 0; pos - i >= 0 && str[pos + i + 1] != '\0'; i++) {
		if (str[pos - i] == str[pos + i + 1])
			cnt++;
		else
			break;
	}
	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T;
	int ret;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		ret = 0;
		scanf("%s", str);
		for (int i = 0; str[i] != '\0'; i++)
			ret += countPalindrome(i);
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}