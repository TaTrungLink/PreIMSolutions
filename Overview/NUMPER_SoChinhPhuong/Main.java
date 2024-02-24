import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int a, b, square, cnt;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			a = sc.nextInt();
			b = sc.nextInt();
			cnt = 0;
			System.out.print("#" + tc + " ");
			
			for (int i = 1; (square = i * i) <= b; i++) {
				if (square >= a) {
					System.out.print(square + " ");
					cnt++;
				}
			}
			
			if (cnt == 0) {
				System.out.println("NO NUMBER");
			} else {
				System.out.println("");
			}
		}
		sc.close();
	}
	
}