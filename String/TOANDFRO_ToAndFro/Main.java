import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	
	//Các bước bạn Mo "mã hóa"
	//- Ghi từng ký tự của string gốc vào mảng 2 chiều, ghi theo từng cột, bắt đầu từ (0, 0) rồi đến (1, 0), (2, 0)...
	//- Ghi từ mảng 2 chiều sang mảng 1 chiều theo từng dòng, dòng chẵn thì ghi từ trái sang phải, dòng lẻ ghi từ phải sang trái

	//Ta sẽ làm ngược lại quá trình này, với mảng 1 chiều nhập vào từ input, ghi từng ký tự vào mảng 2 chiều
	//dòng chẵn thì ghi từ trái sang phải, dòng lẻ ghi từ phải sang trái
	//Ghi từng ký tự của mảng 2 chiều ra output, ghi từ trên xuống dưới từ trái sang phải, ghi theo từng cột.
	
	static char[][] twoDArr = new char[100][21]; //tối đa 200 ký tự, tối thiểu 2 cột => tối đa 100 dòng
	static String inp;
	static int colNum, rowNum; //số dòng, số cột của ma trận 2 chiều
	
	public static void main(String[] args) throws Exception {
		
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);

		while (true) {
			colNum = sc.nextInt();
			
			if (colNum == 0) {
				break;
			}
			
			inp = sc.next();
			rowNum = build2DArray();
			
			String ret = "";
			
			for (int c = 0; c < colNum; c++) {
				for (int r = 0; r < rowNum; r++) {
					ret += twoDArr[r][c];
				}
			}
			System.out.println(ret);
		}
		sc.close();
	}
	
	static int build2DArray(){
		
		//i: index trong mảng 1 chiều
		//r, c: index theo hàng và cột trong mảng 2 chiều
		int i = 0, r = 0, c;
		
		while (i < inp.length()) {
			if (r % 2 == 0) { //hàng chẵn, ghi từ trái sang phải
				for (c = 0; c < colNum; c++, i++) {
					twoDArr[r][c] = inp.charAt(i);
				}
			} else { //hàng lẻ, ghi từ phải sang trái
				for (c = colNum - 1; c >= 0; c--, i++) {
					twoDArr[r][c] = inp.charAt(i);
				}
			}
			r++;
		}

		return r;
	}
	
}