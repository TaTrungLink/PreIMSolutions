import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T, tc;
		int n, sum;
		T = sc.nextInt();
		
		for (tc = 1; tc <= T; tc++) {
			n = sc.nextInt();
			while (n > 9) { //chừng nào còn nén được (nhiều hơn 1 chữ số)
				sum = 0; //tính tổng các chữ số
				while (n > 0) {
					sum += n % 10; //lấy từng chữ số và cộng vào tổng
					n /= 10;
				}
				n = sum; //gán n bằng tổng các chữ số
			}
			System.out.println("#" + tc + " " + n);
		}
		sc.close();
	}
		
}