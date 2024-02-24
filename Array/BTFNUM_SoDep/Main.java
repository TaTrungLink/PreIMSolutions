import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 10;
	
	static boolean[] isGoodDigit = new boolean[MAX_N]; //mảng đánh dấu chữ số có phải là chữ số đẹp hay không
	static int N, M;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int cnt, x, y, tmp;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			cnt = 0;

			for (int i = 0; i < 10; i++) {
				isGoodDigit[i] = false;
			}
			
			for (int i = 0; i < N; i++) {
				tmp = sc.nextInt();
				isGoodDigit[tmp] = true;
			}
			
			x = sc.nextInt();
			y = sc.nextInt();		
			
			for (int i = x; i <= y; i++) {
				if (isGood(i)) {
					cnt++;
				}
			}
								
			System.out.println("#" + tc + " " + cnt);
			
		}
		sc.close();
	}
	
	//Hàm kiểm tra 1 số có chứa đủ M số đẹp không
	static boolean isGood(int x) {
		int cnt = 0;//tổng số lần các chữ số đẹp xuất hiện

		while (x > 0) {
			if (isGoodDigit[x % 10]) {
				++cnt;
				if (cnt >= M) {
					return true; //khi đủ số lượng chữ số đẹp => x là số đẹp
				}
			}
			x /= 10;
		}

		return false; //số lượng chữ số đẹp < M nên x không phải là số đẹp
	}
	
}