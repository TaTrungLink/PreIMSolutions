#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//Khai báo:
int A[1000]; //Khai báo mảng cùng với size
int B[100] = { 2, 4, 51, 7, 21, 98, 1, 52, 76, 42 }; //Khai báo mảng cùng size và khởi tạo các phần tử đầu tiên, các phần tử còn lại nhận giá trị 0
int C[] = { 10, 3, 6, 1, 12, 25, 18, 9, 43, 36 }; //Khai báo mảng cùng các phần tử, size sẽ tự động được gán bằng số phần tử truyền vào

int N; // kích cỡ mảng (không nhất thiết phải là kích cỡ tối đa)

//Kiểm tra phần tử x có tồn tại trong mảng arr
bool isExist(int arr[], int val)
{
	for (int i = 0; i < N; i++)
		if (val == arr[i])
			return true;
	return false;
}

//Tìm số lớn nhất trong mảng arr
int findMax(int arr[])
{
	int max = arr[0];
	for (int i = 1; i < N; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//Đảo ngược mảng
void reverse(int arr[])
{
	int tmp;
	int half = N / 2;
	for (int i = 0; i < half; i++) {
		tmp = arr[i];
		arr[i] = arr[N - 1 - i];
		arr[N - 1 - i] = tmp;
	}
}

//Sao chép mảng s sang mảng t
void arrCopy(int s[], int t[])
{
	for (int i = 0; i < N; i++)
		t[i] = s[i];
}

//Sắp xếp mảng
void selectionSort(int arr[])
{
	int minIdx, tmp;
	for (int i = 0; i < N; i++) {
		//Tìm phần tử nhỏ nhất trong khoảng từ i đến N - 1
		minIdx = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}

		//Đổi chỗ phần tử nhỏ nhất tìm được với phần tử thứ i
		if (minIdx != i) {
			tmp = arr[minIdx];
			arr[minIdx] = arr[i];
			arr[i] = tmp;
		}
	}
}

void bubbleSort(int arr[])
{
	int tmp;
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			//từ vị trí 0 đến i + 1, so sánh nếu 1 phần tử lớn hơn phần tử liền sau nó thì đổi chỗ
			//phần tử lớn nhất sẽ được đẩy dần lên (giống hình ảnh bong bóng nổi lên mặt nước)
			//sau khi chạy xong thì arr[i] là phần tử lớn nhất trong khoảng từ 0 đến i
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//Thêm phần tử vào 1 vị trí
void insert(int arr[], int val, int pos) 
{
	if (pos < 0 || pos > N)
		return;

	//Dịch toàn bộ các phần tử phía sau vị trí cần chèn
	for (int i = N; i > pos; i--)
		arr[i] = arr[i - 1];
	N++; //tăng kích thước mảng

	arr[pos] = val;
}

//Xóa một số phần tử từ 1 vị trí
//cnt: số phần tử cần xóa
//pos: vị trí bắt đầu xóa
void remove(int arr[], int pos, int cnt)
{
	if (N - pos <= cnt) { //xóa tất cả các phần tử bắt đầu từ vị trí pos
		N = pos;
		return; 
	}

	N -= cnt; //giảm kích thước mảng
	for (int i = pos; i < N; i++) //Xóa cnt số, dồn các số ở bên phải vào các vị trí trống.
		arr[i] = arr[i + cnt];
}


//Mảng 2 chiều
int D[1000][1000];
int E[5][5] = { { 1, 2, 3 , 4, 5}, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
int M; //số cột

//Duyệt mảng 2 chiều:
//Duyệt lần lượt theo hàng ngang
void horizontalPrint()
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cout << E[r][c] << " ";

	cout << endl;
}

//Duyệt lần lượt theo hàng dọc
void verticalPrint()
{
	for (int c = 0; c < M; c++)
		for (int r = 0; r < N; r++)
			cout << E[r][c] << " ";

	cout << endl;
}

//Duyệt xen kẽ
void ziczacPrint()
{
	for (int r = 0; r < N; r++) {
		if (r % 2 == 0)
			for (int c = 0; c < M; c++)
				cout << E[r][c] << " ";
		else
			for (int c = M - 1; c >= 0; c--)
				cout << E[r][c] << " ";
	}
	cout << endl;
}

//tính tổng 4 cạnh bao
int edgeSum()
{
	int sum = 0;
	//tính tổng 2 cạnh dọc
	for (int i = 0; i < N; i++) {
		sum += E[i][0];
		sum += E[i][M - 1];
	}

	//Tính tổng 2 cạnh ngang (trừ các ô ở góc đã được cộng ở trên rồi)
	for (int i = 1; i < M - 1; i++) {
		sum += E[0][i];
		sum += E[N - 1][i];
	}

	return sum;
}




//Test
int main() {
	//Test mảng 1 chiều
	N = 10;
	bool b = isExist(B, 1);
	cout << b << endl;

	int maxInC = findMax(C);
	cout << maxInC << endl;

	reverse(B);
	for (int i = 0; i < N; i++)
		cout << B[i] << " ";
	cout << endl;

	selectionSort(B);
	for (int i = 0; i < N; i++)
		cout << B[i] << " ";
	cout << endl;

	bubbleSort(C);
	for (int i = 0; i < N; i++)
		cout << C[i] << " ";
	cout << endl;

	//Test mảng 2 chiều
	N = M = 5;
	horizontalPrint();
	verticalPrint();
	ziczacPrint();
	cout << edgeSum();

	return 0;
}