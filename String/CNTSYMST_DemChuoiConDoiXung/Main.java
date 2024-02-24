import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		String str;
		int ret;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; ++tc) {
			ret = 0;		
			str = sc.next();
			
			for (int i = 0; i < str.length(); i++) {
				ret += countPalindrome(str, i);
			}
			
			System.out.println("#" + tc + " " + ret);					
		}
		
		sc.close();
	}
	
	//Từ vị trí pos, lan sang 2 bên để đếm số palindrome mà có pos là vị trí ở giữa
	static int countPalindrome(String str, int pos)
	{
		int cnt = 1; //bản thân mỗi phần tử đã là một palindrome
		
		//Trường hợp độ dài chuỗi lẻ, so sánh các phần tử đối xứng qua pos, ví dụ pos - 1 vs pos + 1
		for (int i = 1; pos - i >= 0 && pos + i < str.length(); i++) {
			if (str.charAt(pos - i) == str.charAt(pos + i)) {
				cnt++;
			} else {
				break;
			}
		}
		
		//Trường hợp độ dài chẵn, so sánh các phần tử đối xứng qua cặp pos và pos + 1, ví dụ pos - 1 vs pos + 2
		for (int i = 0; pos - i >= 0 && pos + i + 1 < str.length(); i++) {
			if (str.charAt(pos - i) == str.charAt(pos + i + 1)) {
				cnt++;
			} else {
				break;
			}
		}
		
		return cnt;
	}
		
}