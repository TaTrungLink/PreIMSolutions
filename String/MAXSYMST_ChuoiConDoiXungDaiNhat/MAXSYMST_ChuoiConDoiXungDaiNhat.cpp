#include <stdio.h>
#define MAX_LEN 1001

char str[MAX_LEN];

//Tìm độ dài chuỗi đối xứng dài nhất với pos là vị trí ở giữa
int longestPalindrome(int pos)
{
	int maxLen = 1;
	int i;
	for (i = 1; pos - i >= 0 && str[pos + i] != '\0'; i++) {
		if (str[pos - i] != str[pos + i])
			break;
	}
	//chuỗi có độ dài lẻ dài nhất tại vị trí pos: từ pos - (i - 1) đến pos + (i - 1)
	if (i * 2 - 1 > maxLen)
		maxLen = i * 2 - 1;

	for (i = 0; pos - i >= 0 && str[pos + i + 1] != '\0'; i++) {
		if (str[pos - i] != str[pos + i + 1])
			break;
	}
	//chuỗi có độ dài chẵn dài nhất tại vị trí pos: từ pos - (i - 1) đến pos + i
	if (i * 2> maxLen)
		maxLen = i * 2;

	return maxLen;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T;
	int ret, currLen;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		ret = 0;
		scanf("%s", str);
		for (int i = 0; str[i] != '\0'; i++) {
			currLen = longestPalindrome(i);
			if (currLen > ret)
				ret = currLen;
		}
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}