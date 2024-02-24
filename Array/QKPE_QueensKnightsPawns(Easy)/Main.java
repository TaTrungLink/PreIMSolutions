import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	//8 hướng quân hậu có thể đi
	static final int[] queenDx = { 1, 1, 0, -1, -1, -1, 0, 1 };
	static final int[] queenDy = { 0, 1, 1, 1, 0, -1, -1, -1 };
	
	//8 vị trí quân mã có thể nhảy tới
	static final int[] knightDx = { 1, 2, 2, 1, -1, -2, -2, -1 };
	static final int[] knightDy = { -2, -1, 1, 2, 2, 1, -1, -2 };
	
	static final int MAX_N = 1001;
	static final int MAX_AMOUNT = 101;
	static final int SAFE = 0;
	static final int OCCUPIED = 1;
	static final int UNSAFE = 2;

	static int[][] map = new int[MAX_N][MAX_N];
	static int N, M, safeCount;
	
	static int[] queenRow = new int[MAX_AMOUNT];
	static int[] queenCol = new int[MAX_AMOUNT];
	static int[] knightRow = new int[MAX_AMOUNT];
	static int[] knightCol = new int[MAX_AMOUNT];
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int r, c;
		int qNum, kNum, pNum; //số lượng queen, knight, pawn
		
		for (int tc = 1; ; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			
			if (N == 0 && M == 0) {
				break;
			}
			
			//Ban đầu đánh dấu tất cả các ô là an toàn
			safeCount = N * M;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					map[i][j] = SAFE;
				}
			}
			
			qNum = sc.nextInt();
			for (int i = 0; i < qNum; i++) {
				queenRow[i] = sc.nextInt();
				queenCol[i] = sc.nextInt();
				map[queenRow[i]][queenCol[i]] = OCCUPIED;
			}

			kNum = sc.nextInt();
			for (int i = 0; i < kNum; i++) {
				knightRow[i] = sc.nextInt();
				knightCol[i] = sc.nextInt();
				map[knightRow[i]][knightCol[i]] = OCCUPIED;
			}

			pNum = sc.nextInt();
			for (int i = 0; i < pNum; i++) {
				r = sc.nextInt();
				c = sc.nextInt();
				map[r][c] = OCCUPIED;
			}
			
			safeCount -= pNum + kNum + qNum;
			
			for (int i = 0; i < qNum; i++) {
				checkQueen(queenRow[i], queenCol[i]);
			}
			
			for (int i = 0; i < kNum; i++) {
				checkKnight(knightRow[i], knightCol[i]);
			}
			
			System.out.println("Board " + tc + " has " + safeCount +" safe squares.");
			
		}
		sc.close();
	}
	
	static void checkQueen(int r, int c)
	{
		int nextR, nextC;
		for (int d = 0; d < 8; d++) {
			nextR = r + queenDy[d];
			nextC = c + queenDx[d];
			while (true) {	
			
				//nếu đi ra ngoài hoặc bị chặn
				if (nextR < 1 || nextR > N || nextC < 1 || nextC > M || map[nextR][nextC] == OCCUPIED) {
					break;
				}
				
				//đánh dấu ô bị ăn
				if (map[nextR][nextC] == SAFE) {
					map[nextR][nextC] = UNSAFE;
					safeCount--;
				}
				
				nextR += queenDy[d]; 
				nextC += queenDx[d];
			}
		}
	}

	static void checkKnight(int r, int c)
	{
		int nextR, nextC;
		for (int d = 0; d < 8; d++) {
			nextR = r + knightDy[d];
			nextC = c + knightDx[d];
			
			//ô ở ngoài map hoặc bị chiếm chỗ
			if (nextR < 1 || nextR > N || nextC < 1 || nextC > M || map[nextR][nextC] == OCCUPIED) {
				continue;
			}
			
			//đánh dấu ô bị ăn
			if (map[nextR][nextC] == SAFE) {
				map[nextR][nextC] = UNSAFE;
				safeCount--;
			}
		}
	}
	
}