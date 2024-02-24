//Cách 1: với mỗi số nhập từ input, kiểm tra khoảng cách của nó với tất cả các số đã nhập
import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 10001;
	
	static int[] A = new int[MAX_N];
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N, K, count;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			K = sc.nextInt();
			count = 0;
			
			for (int i = 0; i < N; i++) {			
				A[i] = sc.nextInt();
				
				for (int j = 0; j < i; j++) {
					if (A[i] - A[j] == K || A[j] - A[i] == K) {
						count++;
					}
				}
			}
			
			System.out.println(count);
			
		}
		sc.close();
	}
	
}


////Cách 2: Quick sort để sắp xếp, cửa sổ trượt để tìm số cặp có khoảng cách K trên mảng đã sắp xếp
//import java.io.FileInputStream;
//import java.util.Scanner;
//
//public class Main {
//	
//	static final int MAX_N = 10001;
//	
//	static int[] A = new int[MAX_N];
//	
//	public static void main(String[] args) throws Exception {
//		
//	//	System.setIn(new FileInputStream("input.txt"));
//		Scanner sc = new Scanner(System.in);
//		
//		int N, K, count;
//		int left, right;
//		int T = sc.nextInt();
//
//		for (int tc = 1; tc <= T; tc++) {
//			N = sc.nextInt();
//			K = sc.nextInt();
//			
//			for (int i = 0; i < N; i++) {			
//				A[i] = sc.nextInt();
//			}
//			
//			count = 0;
//			quickSort(0, N - 1);
//			left = 0; right = 1;
//			
//			while (right < N) {
//				if (A[right] - A[left] == K) {
//					count++;
//					left++;
//					right++;
//				} else if (A[right] - A[left] < K) {
//					right++;
//				} else {
//					left++;
//				}
//			}
//						
//			System.out.println(count);
//			
//		}
//		sc.close();
//	}
//	
//	static void swap(int i, int j)
//	{
//		int tmp = A[i]; A[i] = A[j]; A[j] = tmp;
//	}
//
//	static void quickSort(int left, int right)
//	{
//		if (left >= right) {
//			return;
//		}
//		
//		int last = left; 
//		
//		for (int i = left + 1; i <= right; i++) {
//			if (A[i] < A[left]) {
//				swap(++last, i);
//			}
//		}
//		
//		swap(left, last);
//		quickSort(left, last - 1);
//		quickSort(last + 1, right);
//	}
//	
//}