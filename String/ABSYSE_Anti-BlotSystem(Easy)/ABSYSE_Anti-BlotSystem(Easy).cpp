#include <stdio.h>
#define MAX_LEN 17 //số nguyên chỉ có tối đa 10 chữ số nhưng thêm chuỗi "machula" có thể lên nhiều hơn

int toInt(char arr[])
{
	int ret = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == 'm') // số bị dính mực
			return -1;
		ret = ret * 10 + arr[i] - '0';
	}
	return ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, T;
	int op1, op2, sum;
	char str[MAX_LEN];
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		//Test case luôn có dạng "number + number = number" => đọc 5 string
		
		//Đọc số hạng thứ nhất
		scanf("%s", str);
		op1 = toInt(str);
		//Đọc dấu "+"
		scanf("%s", str);
		//Đọc số hạng thứ hai
		scanf("%s", str);
		op2 = toInt(str);
		//Đọc dấu "="
		scanf("%s", str);
		//Đọc tổng
		scanf("%s", str);
		sum = toInt(str);
		
		//Dùng 2 số không bị dính mực để tính số còn lại rồi in kết quả
		if (op1 == -1)
			op1 = sum - op2;
		else if (op2 == -1)
			op2 = sum - op1;
		else
			sum = op1 + op2;
		printf("%d + %d = %d\n", op1, op2, sum);
	}

	return 0;
}