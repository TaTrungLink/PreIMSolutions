import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T, tc;
		int a, b, ret;
		T = sc.nextInt();
		
		for (tc = 1; tc <= T; tc++) {
			a = sc.nextInt();
			b = sc.nextInt();
			ret = 1;
			
			for (int i = 1; i <= b; i++) {
				ret *= a;
			}
			
			System.out.println("#" + tc + " " + ret);
		}				
	}
		
}


//Cách 2: nếu b lẻ: a ^ b = (a ^ (b / 2)) * (a ^ (b / 2)) * a
//nếu b chẵn: a ^ b = (a ^ (b / 2)) * (a ^ (b / 2))
// b liên tiếp bị chia đôi nên số phép tính toán sẽ giảm rất nhiều so với cách 1

//import java.io.FileInputStream;
//import java.util.Scanner;
//
//public class Main {
//
//	public static void main(String[] args) throws Exception {
//		
//		System.setIn(new FileInputStream("input.txt"));
//		Scanner sc = new Scanner(System.in);
//		
//		int T, tc;
//		int a, b;
//		T = sc.nextInt();
//		
//		for (tc = 1; tc <= T; tc++) {
//			a = sc.nextInt();
//			b = sc.nextInt();
//			System.out.println("#" + tc + " " + pow(a, b));
//		}				
//	}
//	
//	static int pow(int base, int ex)
//	{
//		if (ex == 0)
//			return 1;
//		int tmp = pow(base, ex / 2);
//		if (ex % 2 == 1)  //nếu số mũ lẻ
//			return tmp * tmp * base;
//		else //nếu số mũ chẵn
//			return tmp * tmp;
//	}
//		
//}