#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//Khai báo:
char A[1000];
char B[] = "abc";
char C[1000] = "12345";

//Nhập string từ input
void input(char str[])
{
	scanf("%s", str);
	//C++: cin >> str;
}

//Nhập 1 dòng từ input
void inputLine(char str[])
{
	fgets(str, 1000, stdin);	
	//C++: cin.getline(str, 1000);

	//Nếu trước khi nhập có dấu xuống dòng thì phải bỏ qua nó trước
	//C: scanf("%c", &str[0]);
	//C++: cin.ignore();
}

//Tính độ dài
int strLen(char str[])
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

//Sao chép string và đồng thời trả về độ dài string
int strCopy(char dest[], char source[])
{
	int len = 0;
	while (source[len] != '\0') {
		dest[len] = source[len];
		len++;
	}
	dest[len] = '\0';
}

//So sánh string
bool isEqual(char s1[], char s2[])
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] != s2[i]) 
			return false;
		i++;
	}

	if (s1[i] != '\0' || s2[i] != '\0') 
		return false;
	return true;
}

//Đảo ngược string
void reverse(char str[])
{
	int len = strLen(str);
	int half = len / 2;
	char tmp;
	for (int i = 0; i < len / 2; i++) {
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

//Chuyển từ string sang số
int atoi(char str[])
{
	int num = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		num = num * 10 + str[i] - '0';
	}
	return num;
}

//Chuyển từ số sang string
void itoa(int num, char str[]) {
	int i = 0;
	while (num > 0) {
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	reverse(str);
}