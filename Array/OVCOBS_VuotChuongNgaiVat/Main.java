import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 101;
	static final int INF = 1001;
	
	static int[][] map = new int[MAX_N][MAX_N];
	static int N;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int startR, startC;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			startR = sc.nextInt();
			startC = sc.nextInt();
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
					
			System.out.println("#" + tc + " " + countSteps(startR, startC));
			
		}
		sc.close();
	}
	
	//Hàm tính số bước tối đa mà Alex có thể nhảy
	static int countSteps(int r, int c) { //r, c: tọa độ vị trí hiện tại
		int nextR = 0, nextC = 0;
		int minHeight;
		int cnt = 0;
		
		while (true) {
			minHeight = INF;
			
			for (int i = r - 1; i < r + 2; i++) { //kiểm tra tất cả các ô xung quanh ô hiện tại
				if (i < 0 || i >= N) { //nếu tọa độ vượt ra ngoài mảng, bỏ qua
					continue;
				}
				
				for (int j = c - 1; j < c + 2; j++) {
					if (j < 0 || j >= N) {
						continue;
					}
					
					//nếu ô đang check cao hơn ô hiện tại và thấp hơn ô đã chọn trước đó, chọn ô này
					if (map[i][j] > map[r][c] && map[i][j] < minHeight) {
						nextR = i;
						nextC = j;
						minHeight = map[i][j];
					}
				}
			}
			
			if (minHeight != INF) { //nhảy sang ô được chọn và tăng số bước
				r = nextR;
				c = nextC;
				cnt++;
			} else { //nếu không chọn được ô nào để nhảy, dừng thuật toán
				break;
			}
		}
		
		return cnt;
	}
	
}