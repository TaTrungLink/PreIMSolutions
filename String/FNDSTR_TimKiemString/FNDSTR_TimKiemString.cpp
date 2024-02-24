#include <stdio.h>
#define MAX_WORD_LEN 11
#define MAX_STR_LEN 1001

int len(char s[]) {
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char s1[MAX_WORD_LEN];
char s2[MAX_STR_LEN];

int main()
{
	//freopen("input.txt", "r", stdin);
	int test_case, cnt;
	bool isExist;
	do {
		scanf("%d", &test_case);		
		scanf("%s", &s1);
		int len1 = len(s1);
		
        //Để đọc cả dòng từ input bao gồm cả dấu cách: dùng cin.getline() của thư viện iostream hoặc fgets() của stdio.h:
        //Cả fgets() và cin.getline() đều không tự động bỏ qua ký tự '\n' khi nhập s1 trước đó, nên cần xử lý ký tự này trước.
		// 
        //Một điểm khác biệt: tuy cùng chạy đến khi gặp '\n' hoặc EOF là dừng, nhưng cin.getline() sẽ chỉ ghi đến ký tự đằng trước '\n',
        //còn fgets() sẽ ghi cả '\n'
        //Ví dụ với chuỗi "ab ab\n", cin.getline() ra kết quả là "ab ab" với độ dài 5, còn fgets() ra kết quả là "ab ab\n" với độ dài 6
		
		scanf("%c", &s2[0]); //đọc ký tự '\n' (với C++ dùng cin.ignore(); để bỏ qua 1 ký tự)
		
		// Đọc cả dòng bao gồm cả dấu cách, với C++: cin.getline(s2, MAX_STR_LEN);
		fgets(s2, MAX_STR_LEN, stdin); 
		int len2 = len(s2);
		if (s2[len2 - 1] == '\n') //nếu thừa ký tự '\n' ở cuối (trong trường hợp dùng fgets) thì cắt nó đi 
			len2--;
		
		cnt = 0;
		
		for (int i = 0; i <= len2 - len1; i++) {//với từng vị trí i, kiểm tra xem đoạn từ s2[i] đến s2[i + M] có trùng với s1 không
			isExist = true;
			for (int j = 0; j < len1; j++) {
				if (s2[i + j] != s1[j]) {
					isExist = false;
					break;
				}
			}
			if (isExist)
				cnt++;
		}
		printf("#%d %d\n", test_case, cnt);
	} while (test_case < 10);

	return 0;
}

//Độ phức tạp: O(N * M) với N là độ dài của chuỗi lớn và M là độ dài chuỗi con
//Nâng cao: tham khảo giải thuật KMP (Knuth–Morris–Pratt), có thể giải quyết bài toán này với độ phức tạp O(N)