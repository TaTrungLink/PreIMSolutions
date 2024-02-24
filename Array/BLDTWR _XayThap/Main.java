import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 51;
	
	static int[] weight = new int[MAX_N];
	static int N;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int ret, floor, brick;
		int M1, M2;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M1 = sc.nextInt();
			M2 = sc.nextInt();
			
			for (brick = 0; brick < N; brick++) {
				weight[brick] = sc.nextInt();
			}
			
			//Sắp xếp, các viên gạch nặng nhất sẽ dùng để xây những tầng dưới cùng
			sort();
			
			ret = 0;
			if (M2 < M1) { //đổi chỗ để M1 luôn thấp hơn
				int tmp = M2;
				M2 = M1;
				M1 = tmp;
			}
			
			//Chừng nào cả 2 tòa tháp chưa xây xong, lấy 2 viên nặng nhất chia đều vào 2 tòa tháp
			for (floor = 1, brick = 0; floor <= M1; floor++, brick += 2) {
				ret += floor * (weight[brick] + weight[brick + 1]);
			}
			
			//Còn lại 1 tòa tháp, đưa tất cả số gạch còn lại vào tòa tháp đó
			for ( ; brick < N; floor++, brick++) {
				ret += floor * weight[brick];
			}
						
			System.out.println("#" + tc + " " + ret);
			
		}
		sc.close();
	}
	
	//Sắp xếp các viên gạch theo thứ tự giảm dần về cân nặng
	static void sort() {
		int temp;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (weight[j] > weight[i]) {
					temp = weight[i];
					weight[i] = weight[j];
					weight[j] = temp;
				}
			}
		}
	}
	
}