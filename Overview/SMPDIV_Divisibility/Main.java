import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T, tc;
		int n, x, y;
		T = sc.nextInt();
		
		for (tc = 1; tc <= T; tc++) {
			n = sc.nextInt();
			x = sc.nextInt();
			y = sc.nextInt();
			for (int i = 1; i < n; i++) {
				if (i % x == 0 && i % y != 0) {
					System.out.print(i + " ");
				}
			}
			System.out.println("");
		}
		sc.close();
	}
		
}