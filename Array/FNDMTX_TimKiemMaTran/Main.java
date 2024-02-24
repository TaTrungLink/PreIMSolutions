import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 102;
	static final int INF = 100000000;
	
	static int[][] map = new int[MAX_N][MAX_N];
	static int N, M;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int K, r = 0, c = 0;
		int curSum, curDiff; //tổng ma trận con hiện tại và chênh lệch của tổng đó với số K
		int retSum = 0, minDiff; //tổng của ma trận con và mức chênh lệch tốt nhất đến thời điểm hiện tại
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			K = sc.nextInt();
			
			minDiff = INF;
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			for (int i = 0; i <= N - M; i++) {
				for (int j = 0; j <= N - M ; j++) {
					curSum = sum(i, j);				
					curDiff = diff(curSum, K);
					
					//So sánh diff hiện tại với diff thấp nhất, nếu bằng nhau thì so tổng hiện tại với tổng đã chọn lúc trước
					//Nếu cả diff và sum đều bằng của 1 ô đã chọn lúc trước thì chọn ô trước, vì số hàng và cột của ô trước nhỏ hơn
					if (curDiff < minDiff || (curDiff == minDiff && curSum < retSum)) {
						r = i;
						c = j;
						minDiff = curDiff;
						retSum = curSum;
					}
				}
			}
					
			System.out.println("#" + tc + " " + r + " " + c);
			
		}
		sc.close();
	}
	
	static int diff (int a, int b) {
		return a > b ? a - b : b - a;
	}
	
	static int sum(int startR, int startC)
	{
		int ret = 0;
		for (int i = startR; i < startR + M; i++)
			for (int j = startC; j < startC + M; j++)
				ret += map[i][j];
		return ret;
	}
	
}