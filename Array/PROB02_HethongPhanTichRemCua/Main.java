import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 502;
	static int[] cnt = new int[5];
	static String[] map = new String[MAX_N];
	
	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int M, N;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			M = sc.nextInt();
			N = sc.nextInt();	

			//Số hàng số cột thực tế của mảng input = số hàng số cột trong đề bài * 5 + 1			
			M = 5 * M + 1;
			N = 5 * N + 1;
			
			//Reset mảng kết quả
			for (int i = 0; i < 5; i++) {
				cnt[i] = 0;
			}
			
			
			for (int i = 0; i < M; i++) {
				map[i] = sc.next();
			}
			
			//Ô trên cùng bên trái của cửa sổ đầu tiên có tọa độ (1, 1)
			//Vị trí các cửa sổ tiếp theo bằng vị trí hiện tại dịch 5 ô theo chiều ngang hoặc dọc
			for (int i = 1; i < M; i += 5) {
				for (int j = 1; j < N; j += 5) {
					check(map, i, j);
				}
			}

			System.out.print("#" + tc + " ");
			for (int i = 0; i < 5; i++) {
				System.out.print(cnt[i] + " ");
			}
			System.out.println("");
			
		}
		sc.close();
	}
	
	//r, c là tọa độ ô trên cùng bên trái của từng chiếc cửa sổ
	static void check(String[] map, int r, int c) {
		
		//Nếu dòng trên cùng là ..... => loại 0
		//Nếu dòng trên cùng là ***** và dòng 2 là ..... => loại 1
		//Nếu dòng 2 là ***** và dòng 3 là ..... => loại 2
		//Nếu dòng 3 là ***** và dòng dưới cùng là ...... => loại 3
		//Nếu không dòng nào có ..... => loại 4
	
		for (int i = 0; i < 4; i++) {
			if (map[r + i].charAt(c) == '.') { //Tất cả các ô trên cùng dòng là giống nhau => chỉ cần check ô đầu tiên của từng dòng
				cnt[i]++;
				return;
			}
		}
		cnt[4]++;		
	}
	
}
