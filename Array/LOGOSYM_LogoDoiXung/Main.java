import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 33;
	
	static int[][] map = new int[MAX_N][MAX_N];
	
	public static void main(String[] args) throws Exception {
		
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N;
		boolean ret;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			ret = true;
			for (int i = 0; i < (N + 1) / 2; i++) {
				for (int j = 0; j < (N + 1) / 2; j++) {
					
					//mỗi điểm có 3 điểm đối xứng: qua tâm, qua trục tung và qua trục hoành
					//nếu các điểm đối xứng không bằng nhau thì kết luận logo không đối xứng
					if (map[i][j] != map[N - 1 - i][N - 1 - j] || map[i][j] != map[i][N - 1 - j] || map[i][j] != map[N - 1 - i][j]) {
						ret = false;
						break;
					}
				}
				
				if (!ret)
					break;
			}
			
			System.out.println("#" + tc + " " + (ret ? "YES" : "NO"));
		}
		
		sc.close();	
	}
	
}