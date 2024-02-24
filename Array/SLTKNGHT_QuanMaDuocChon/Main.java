import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 1001;
	
	//8 vị trí quân mã có thể ăn
	static final int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	static final int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	
	static boolean[][] board = new boolean[MAX_N][MAX_N]; //board[i][j] = true nghĩa là ở vị trí (i, j) có quân cờ có thể ăn, false tức là không có quân nào hoặc quân cờ không thể ăn
	
	//Danh sách tọa độ các quân mã
	static int[] knightRow = new int[MAX_N * MAX_N];
	static int[] knightCol = new int[MAX_N * MAX_N];
	static int N;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int K, M, D;
		int r, c, maxCnt, currCnt;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			K = sc.nextInt();
			M = sc.nextInt();
			D = sc.nextInt();
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					board[i][j] = false;
				}
			}
			
			for (int i = 0; i < K; i++) {
				knightRow[i] = sc.nextInt();
				knightCol[i] = sc.nextInt();
				board[knightRow[i]][knightCol[i]] = true; //Quân mã cũng có thể bị ăn, đánh dấu là true
			}
			
			for (int i = 0; i < M; i++) {
				r = sc.nextInt();
				c = sc.nextInt();
				board[r][c] = true;
	 		}
			
			for (int i = 0; i < D; i++) {
				r = sc.nextInt();
				c = sc.nextInt();
				board[r][c] = false; //Đánh dấu lại ô (r, c) là không thể bị ăn
			}
			
			maxCnt = -1;
			r = c = 0;
			
			for (int i = 0; i < K; i++) {
				currCnt = count(knightRow[i], knightCol[i]);
				
				if (currCnt > maxCnt) {
					maxCnt = currCnt;
					r = knightRow[i];
					c = knightCol[i];
				}
			}
								
			System.out.println("#" + tc + " " + r + " " + c + " " + maxCnt);
			
		}
		sc.close();
	}
	
	//Hàm đếm số quân cờ mà quân mã ở vị trí (r, c) có thể ăn
	static int count(int r, int c) {
		int nextR, nextC;
		int ret = 0;
		
		for (int d = 0; d < 8; d++) {
			nextR = r + dy[d];
			nextC = c + dx[d];
			
			if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && board[nextR][nextC]) { //vị trí (nextR, nextC) có quân cờ có thể bị ăn
				ret++;
			}
		}
		
		return ret;
	}
	
}