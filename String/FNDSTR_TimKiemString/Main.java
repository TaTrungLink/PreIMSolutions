import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		String s2;
		String s1;
		int tc;
		int cnt, wordLen, senLen;
		boolean isExist;

		do {
			tc = sc.nextInt();
			
			s1 = sc.next();
			
			//Để đọc cả dòng từ input bao gồm cả dấu cách: dùng nextLine()
			//Hàm nextLine() không tự động bỏ qua ký tự '\n' khi nhập s1 trước đó, nên cần xử lý ký tự này trước.
			sc.nextLine();
			s2 = sc.nextLine();
			
			wordLen = s1.length();			
			senLen = s2.length();		
			cnt = 0;
			
			for (int i = 0; i <= senLen - wordLen; i++) { //với từng vị trí i, kiểm tra xem đoạn từ s2[i] đến s2[i + M] có trùng với s1 không
				isExist = true;
				
				for (int j = 0; j < wordLen; j++) {
					if (s2.charAt(i + j) != s1.charAt(j)) {
						isExist = false;
						break;
					}
				}
				
				if (isExist)
					cnt++;
			}		
			
			System.out.println("#" + tc + " " + cnt);		
			
		} while (tc < 10);
		
		sc.close();
	}
		
}

//Độ phức tạp: O(N * M) với N là độ dài của chuỗi lớn và M là độ dài chuỗi con
//Nâng cao: tham khảo giải thuật KMP (Knuth–Morris–Pratt), có thể giải quyết bài toán này với độ phức tạp O(N)