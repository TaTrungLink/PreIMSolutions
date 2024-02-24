import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	//Khai báo
	static int A[] = new int[1000]; //Khai báo mảng cùng với size
	static int B[] = { 2, 4, 51, 7, 21, 98, 1, 52, 76, 42 }; //Khai báo mảng cùng các phần tử
	static int C[] = { 10, 3, 6, 1, 12, 25, 18, 9, 43, 36 };
	static int N; // kích cỡ mảng (không nhất thiết phải là kích cỡ tối đa)
	
	//Kiểm tra phần tử x có tồn tại trong mảng arr
	static boolean isExist(int arr[], int val) {
		for (int i = 0; i < N; i++) {
			if (val == arr[i]) {
				return true;
			}
		}
		
		return false;
	}

	//Tìm số lớn nhất trong mảng arr
	static int findMax(int arr[])
	{
		int max = arr[0];
		
		for (int i = 1; i < N; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		
		return max;
	}

	//Đảo ngược mảng
	static void reverse(int arr[]) {
		int tmp;
		int half = N / 2;
		
		for (int i = 0; i < half; i++) {
			tmp = arr[i];
			arr[i] = arr[N - 1 - i];
			arr[N - 1 - i] = tmp;
		}
	}

	//Sắp xếp mảng
	static void selectionSort(int arr[])
	{
		int minIdx, tmp;
		
		for (int i = 0; i < N; i++) {
			//Tìm phần tử nhỏ nhất trong khoảng từ i đến N - 1
			minIdx = i;
			for (int j = i + 1; j < N; j++) {
				if (arr[j] < arr[minIdx]) {
					minIdx = j;
				}
			}

			//Đổi chỗ phần tử nhỏ nhất tìm được với phần tử thứ i
			if (minIdx != i) {
				tmp = arr[minIdx];
				arr[minIdx] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	static void bubbleSort(int arr[]) 
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
	static void insert(int[] arr, int val, int pos) 
	{
		if (pos < 0 || pos > N) {
			return;
		}

		//Dịch toàn bộ các phần tử phía sau vị trí cần chèn
		for (int i = N; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		
		N++; //tăng kích thước mảng
		arr[pos] = val;
	}

	//Xóa một số phần tử từ 1 vị trí
	//cnt: số phần tử cần xóa
	//pos: vị trí bắt đầu xóa
	static void remove(int arr[], int pos, int cnt)
	{
		if (N - pos <= cnt) { //xóa tất cả các phần tử bắt đầu từ vị trí pos
			N = pos;
			return; 
		}

		N -= cnt; //giảm kích thước mảng
		
		for (int i = pos; i < N; i++) {//Xóa cnt số, dồn các số ở bên phải vào các vị trí trống.
			arr[i] = arr[i + cnt];
		}
	}
	
	
	//Mảng 2 chiều
	//Khai báo
	static int D[][] = new int[1000][1000];
	static int E[][] = { { 1, 2, 3 , 4, 5}, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
	static int M; //số cột
	
	//Duyệt mảng 2 chiều:
	//Duyệt lần lượt theo hàng ngang
	static void horizontalPrint()
	{
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				System.out.print(E[r][c] + " ");
			}
		}

		System.out.println("");
	}

	//Duyệt lần lượt theo hàng dọc
	static void verticalPrint()
	{
		for (int c = 0; c < M; c++)
			for (int r = 0; r < N; r++)
				System.out.print(E[r][c] + " ");

		System.out.println("");
	}

	//Duyệt xen kẽ
	static void ziczacPrint()
	{
		for (int r = 0; r < N; r++) {
			if (r % 2 == 0)
				for (int c = 0; c < M; c++)
					System.out.print(E[r][c] + " ");
			else
				for (int c = M - 1; c >= 0; c--)
					System.out.print(E[r][c] + " ");
		}
		System.out.println("");		
	}
	
	//tính tổng 4 cạnh bao
	static int edgeSum()
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
	
	
	
	
	public static void main(String[] args) throws Exception {
		//Test mảng 1 chiều
		N = 10;
		boolean b = isExist(B, 1);
		System.out.println(b);

		int maxInC = findMax(C);
		System.out.println(maxInC);

		reverse(B);
		for (int i = 0; i < N; i++) {
			System.out.print(B[i] + " ");
		}
		System.out.println("");

		selectionSort(B);
		for (int i = 0; i < N; i++) {
			System.out.print(B[i] + " ");
		}
		System.out.println("");

		bubbleSort(C);
		for (int i = 0; i < N; i++) {
			System.out.print(C[i] + " ");
		}
		System.out.println("");
		
		//Test mảng 2 chiều
		N = M = 5;
		horizontalPrint();
		verticalPrint();
		ziczacPrint();
		System.out.println(edgeSum());
	}
	
}