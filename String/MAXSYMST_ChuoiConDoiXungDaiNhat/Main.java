import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		String str;
		int ret, currLen;
		int T = sc.nextInt();
		
		for (int tc = 1; tc <= T; ++tc) {
			ret = 0;		
			str = sc.next();
			
			for (int i = 0; i < str.length(); i++) {
				currLen = longestPalindrome(str, i);
				
				if (currLen > ret) {
					ret = currLen;
				}
			}
			
			System.out.println("#" + tc + " " + ret);					
		}
		
		sc.close();
	}
	
	//Tìm độ dài chuỗi đối xứng dài nhất với pos là vị trí ở giữa
	static int longestPalindrome(String str, int pos)
	{
		int maxLen = 1;
		int i;
		
		for (i = 1; pos - i >= 0 && pos + i < str.length(); i++) {
			if (str.charAt(pos - i) != str.charAt(pos + i)) {
				break;
			}
		}
		
		//chuỗi có độ dài lẻ dài nhất tại vị trí pos: từ pos - (i - 1) đến pos + (i - 1)
		if (i * 2 - 1 > maxLen) {
			maxLen = i * 2 - 1;
		}

		for (i = 0; pos - i >= 0 && pos + i + 1 < str.length(); i++) {
			if (str.charAt(pos - i) != str.charAt(pos + i + 1)) {
				break;
			}
		}
		
		//chuỗi có độ dài chẵn dài nhất tại vị trí pos: từ pos - (i - 1) đến pos + i
		if (i * 2> maxLen) {
			maxLen = i * 2;
		}

		return maxLen;
	}
		
}