import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 101;

	static int[][] map = new int[MAX_N][MAX_N];
	
	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int M, N, H, W;
		int maxSum, currSum;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			H = sc.nextInt();
			W = sc.nextInt();
			M = sc.nextInt();
			N = sc.nextInt();		
			maxSum = 0;
			
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			for (int i = 0; i <= M - H; i++) {
				for (int j = 0; j <= N - W; j++) {
					if ((currSum = cal(i, j, H, W)) > maxSum) {
						maxSum = currSum;
					}
				}
			}
			
			System.out.println("#" + tc + " " + maxSum);
			
		}
		sc.close();
	}
	
	//Đếm tổng giá trị các ô lẻ trên viền của hình chữ nhật kích thước H * W, điểm trên cùng bên trái là (r, c)
	static int cal(int r, int c, int H, int W)
	{
		int sum = 0;
		
		//Tính trên 2 cạnh dọc
		for (int i = 0; i < H; i++) {			
			if (map[r + i][c] % 2 == 0) {
				sum += map[r + i][c];
			}
			
			if (map[r + i][c + W - 1] % 2 == 0) {
				sum += map[r + i][c + W - 1];
			}		
		}
		
		//Tính trên 2 cạnh ngang
		for (int i = 1; i < W - 1; i++) {
			if (map[r][c + i] % 2 == 0) {
				sum += map[r][c + i];
			}
			
			if (map[r + H - 1][c + i] % 2 == 0) {
				sum += map[r + H - 1][c + i];
			}
		}
		
		return sum;
	}
	
}