import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		String str;
		int op1, op2, sum;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			//Test case luôn có dạng "number + number = number" => đọc 5 string
			
			//Đọc số hạng thứ nhất
			str = sc.next();
			op1 = toInt(str);
			
			//Đọc dấu "+"
			str = sc.next();
			
			//Đọc số hạng thứ hai
			str = sc.next();
			op2 = toInt(str);
			
			//Đọc dấu "="
			str = sc.next();
			
			//Đọc tổng
			str = sc.next();
			sum = toInt(str);
			
			//Dùng 2 số không bị dính mực để tính số còn lại rồi in kết quả
			if (op1 == -1) {
				op1 = sum - op2;
			} else if (op2 == -1) {
				op2 = sum - op1;
			} else {
				sum = op1 + op2;
			}
			
			System.out.println(op1 + " + " + op2 + " = " + sum);		
		}
		sc.close();
	}
	
	static int toInt(String str)
	{
		int ret = 0;
		char digit;
		
		for (int i = 0; i < str.length(); i++) {
			digit = str.charAt(i);
			
			if (digit == 'm') { // số bị dính mực
				return -1;
			}
			
			ret = ret * 10 + digit - '0';
		}
		
		return ret;
	}
	
}