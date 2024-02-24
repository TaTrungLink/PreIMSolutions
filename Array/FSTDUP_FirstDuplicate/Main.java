import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 100001;
	
	static boolean[] exist = new boolean[MAX_N]; //mảng đánh dấu trạng thái của 1 số đã xuất hiện hay chưa
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int N, num, ret;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			ret = -1;
			N = sc.nextInt();					
			
			//Reset
			for (int i = 1; i <= N; i++) {
				exist[i] = false;
			}
			
			for (int i = 1; i <= N; i++) {
				num = sc.nextInt();
				
				if (ret == -1) { 
					//nếu num đã từng xuất hiện trước đó => num chính là số đầu tiên xuất hiện 2 lần:
					if (exist[num]) {
						ret = num;
					} else {
						exist[num] = true; //nếu chưa, đánh dấu là đã xuất hiện
					}
				} //nếu đã có câu trả lời (ret != -1), chỉ cần scan cho hết input mà không cần check
			}
						
			System.out.println("#" + tc + " " + ret);
			
		}
		sc.close();
	}
	
}