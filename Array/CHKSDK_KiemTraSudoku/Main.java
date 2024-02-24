import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static char[][] map = new char[9][10];
	static boolean[] exist = new boolean[9]; //đánh dấu sự tồn tại của một giá trị trong 1 hàng, 1 cột hoặc 1 ô 3x3
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		int ret;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			for (int i = 0; i < 9; i++) {
				map[i] = sc.next().toCharArray();
			}
			
			//nếu cả 3 hàm check đều true thì kết quả = 1, chỉ cần một hàm false thì kết quả = 0
			ret = checkHorizontal() && checkVertical() && checkSquare() ? 1 : 0;
					
			System.out.println("#" + tc + " " + ret);
			
		}
		sc.close();
	}
	
	static boolean checkHorizontal()
	{
		//kiểm tra từng hàng
		for (int i = 0; i < 9; i++) {	

			//reset mảng đánh dấu
			for (int j = 0; j < 9; j++) {
				exist[j] = false;
			}
			
			for (int j = 0; j < 9; j++) {
				if (map[i][j] != '.') {
					if (exist[map[i][j] - '1']) {
						return false;
					}
					
					exist[map[i][j] - '1'] = true;
				}
			}
		}
		
		return true;
	}
	
	static boolean checkVertical()
	{
		//kiểm tra từng cột
		for (int i = 0; i < 9; i++) {
			
			//reset mảng đánh dấu
			for (int j = 0; j < 9; j++) {
				exist[j] = false;
			}
			
			for (int j = 0; j < 9; j++) {
				if (map[j][i] != '.') {
					if (exist[map[j][i] - '1']) {
						return false;
					}
					
					exist[map[j][i] - '1'] = true;
				}
			}
		}
		
		return true;
	}
	
	static boolean checkSquare() {
		//kiểm tra từng ô vuông 3x3
		//nếu ô trên cùng bên trái của 1 ô vuông có tọa độ (r, c), duyệt các ô trong khoảng từ r đến r + 2, và c đến c + 2
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) { //i, j là ô trên cùng bên trái của hình vuông nhỏ
				
				//reset mảng đánh dấu
				for (int k = 0; k < 9; k++) {
					exist[k] = false;
				}
				
				for (int k = i; k < i + 3; k++) { //duyệt trong hình vuông nhỏ
					for (int t = j; t < j + 3; t++) {
						if (map[k][t] != '.') {
							if (exist[map[k][t] - '1']) {
								return false;
							}
							
							exist[map[k][t] - '1'] = true;
						}
					}
				}
			}
		}
		
		return true;
	}
	
}