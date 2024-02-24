import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T, tc;
		int a, b;
		T = sc.nextInt();
		
		for (tc = 1; tc <= T; tc++) {
			a = sc.nextInt();
			b = sc.nextInt();
			++b;
			for (int i = a; i < b; i++) {
				if (isPrime(i)) {
					System.out.println(i);
				}
			}
			
			System.out.println("");
		}
		sc.close();
	}
	
	//Hàm kiểm tra số nguyên tố
	static boolean isPrime(int x)
	{
		if (x == 1) { 
			return false;  //1 không phải là số nguyên tố
		}
		
		//Nếu x = y * z chắc chắn một trong hai y hoặc z phải nhỏ hơn căn bậc 2 của x
		// => Chỉ cần cho i chạy đến căn bậc 2 của x để giảm thời gian tìm kiếm	
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		//Nếu không có ước nào trong khoảng từ 2 đến căn x => là số nguyên tố
		return true;
	}
		
}
