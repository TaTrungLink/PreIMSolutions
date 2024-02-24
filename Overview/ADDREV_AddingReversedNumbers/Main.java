import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T, tc;
		int a, b, reverseA, reverseB;
		T = sc.nextInt();
		
		for (tc = 1; tc <= T; tc++) {
			a = sc.nextInt();
			b = sc.nextInt();
			//lấy 2 số đảo ngược
			reverseA = reverse(a);
			reverseB = reverse(b);
			//in ra số đảo ngược của tổng 2 số đó
			System.out.println(reverse(reverseA + reverseB));			
		}	
	}
	
	static int reverse(int x) {
		int ret = 0;
		int digit;
		while (x > 0) {
			digit = x % 10; //lấy từng chữ số
			ret = ret * 10 + digit; //thêm chữ số vào số đảo ngược 
			x /= 10;
		}
		return ret;
	}
}