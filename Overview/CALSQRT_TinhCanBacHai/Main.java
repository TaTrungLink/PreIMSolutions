import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N, ret;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			
			for (ret = 1; ret * ret <= N; ret++) 
				;
			
			--ret;		
			System.out.println("#" + tc + " " + ret);
		}
		sc.close();
		
	}
	
}