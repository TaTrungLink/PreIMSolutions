#include <iostream>

using namespace std;

#define MAX_N 2500 //Dãy ban đầu có tối đa 200 số, insert thêm tối đa 20 lần với tối đa 100 phần tử mỗi lần.

int arr[MAX_N];
int N;

void insert(int pos, int cnt)
{
	for (int i = N - 1; i >= pos; i--) //Các số từ vị trí pos trở về sau sẽ bị đẩy sang phải để dành ra cnt vị trí
		arr[i + cnt] = arr[i];
	for (int i = 0; i < cnt; i++) //Lần lượt nhập từ input
		cin >> arr[pos + i];
	N += cnt; //Cập nhật size
}

void remove(int pos, int cnt)
{
	N -= cnt; //Cập nhật size
	for (int i = pos; i < N; i++) //Xóa cnt số, dồn các số ở bên phải vào các vị trí trống.
		arr[i] = arr[i + cnt];
}

int main()
{
	//freopen("cryptogram_input.txt", "r", stdin);
	int tc;
	int cmdCnt, pos, numberCnt;
	char cmdType;
	for (tc = 1; tc <= 10; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		cin >> cmdCnt;
		for (int i = 0; i < cmdCnt; i++) {
			cin >> cmdType; 
			cin >> pos >> numberCnt;
			if (cmdType == 'I')
				insert(pos, numberCnt);
			else
				remove(pos, numberCnt);
		}

		cout << "#" << tc << " ";
		for (int i = 0; i < 10; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}