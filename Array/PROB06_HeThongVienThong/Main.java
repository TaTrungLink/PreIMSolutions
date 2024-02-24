import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	static final int MAX_N = 101;
	
	static int M, N;
	static String[] map;
	static boolean[][] isCovered = new boolean[MAX_N][MAX_N]; //mảng đánh dấu 1 vị trí đã được phủ sóng hay chưa
	
	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int count;
		
		for (int tc = 1; tc <= T; tc++) {
			M = sc.nextInt();
			N = sc.nextInt();
			
			//Reset mảng đánh dấu:
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					isCovered[i][j] = false;
				}
			}
			
			map = new String[M];
			char curr;
			
			for (int i = 0; i < M; i++) {
				map[i] = sc.next();
				
				for (int j = 0; j < N; j++) {
					curr = map[i].charAt(j);
					if (curr >= 'A' && curr <= 'C') { //trạm phát sóng
						spread(i, j, curr - 'A' +1);
					}
				}
			}
			
			count = 0;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if(map[i].charAt(j) == 'H' && !isCovered[i][j]) {
						++count;
					}
				}
			}
			System.out.println("#" + tc + " " + count);
		}
		sc.close();
		
	}

	static void spread(int r, int c, int type) { //từ 1 trạm phát sóng, đánh dấu tất cả các điểm nó có thể phủ sóng
		
		for (int step = 1; step <= type; step++) {
			if (r - step >= 0) isCovered[r - step][c] = true;
			if (r + step < M) isCovered[r + step][c] = true;
			if (c - step >= 0) isCovered[r][c - step] = true;
			if (c + step < N) isCovered[r][c + step] = true;
		}
		
	}
	
}