import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	static final int MAX_N = 1001;
	
	static int[] height = new int[MAX_N];
	static int[] tallerCnt = new int[MAX_N];
	static int[] ret = new int[MAX_N];
	static int N;
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int count;
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			
			for (int i = 0; i < N; i++) {			
				height[i] = sc.nextInt();
				ret[i] = 0;  //ban đầu tất cả các ô trong mảng kết quả đều là ô trống
			}
			
			for (int i = 0; i < N; i++) {			
				tallerCnt[i] = sc.nextInt();
			}
			
			sort();
			
			//Lần lượt xếp từng người từ thấp nhất đến cao nhất vào mảng kết quả
			//Nếu trước một người có x người cao hơn anh ta thì dành ra x ô trống cho những người cao hơn đó
			//Người này sẽ ở ô trống thứ x + 1
			for (int i = 0; i < N; i++) {
				count = 0;
				
				for (int j = 0; j < N; j++) {
					if (ret[j] == 0) { //ô trống
						count++;
						
						if (count > tallerCnt[i]) { //đã dành đủ số ô trống, i sẽ là vị trí của người hiện tại
							ret[j] = height[i];
							break;
						}
					}
				}
			}
			
			for (int i = 0; i < N; i++) {
				System.out.print(ret[i] + " ");
			}
						
			System.out.println("");
			
		}
		sc.close();
	}
	
	static void swap(int i, int j)
	{
		//Đổi chỗ ở cả 2 mảng
		int temp = height[i]; 
		height[i] = height[j];
		height[j] = temp;
		
		temp = tallerCnt[i];
		tallerCnt[i] = tallerCnt[j];
		tallerCnt[j] = temp;
	}
	
	//Sắp xếp theo thứ tự chiều cao tăng dần
	//Nếu 2 người chiều cao bằng nhau, ai có số tallerCnt ít hơn sẽ đứng trước
	static void sort()
	{
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (height[j] < height[i] || (height[j] == height[i] && tallerCnt[j] < tallerCnt[i])) {
					swap(i, j);		
				}
			}
		}
	}
	
}