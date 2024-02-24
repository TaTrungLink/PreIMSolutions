import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	//Khai báo:
	static char[] A = new char[1000];
	static char[] B = "abc".toCharArray();
	
	static String C = "12345";
	static String D = new String();
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		//Nhập string từ input
		C = sc.next();
		System.out.println(C);
		
		//Nhập từ input vào mảng char
		B = sc.next().toCharArray();
		System.out.println(B); 
		
		//Nhập 1 dòng từ input
		//Nếu trước khi nhập có dấu xuống dòng thì phải bỏ qua nó trước bằng lệnh
		sc.nextLine();
		//Sau đó nhập cả dòng
		C = sc.nextLine();

		
		//Độ dài:
		int stringLen = C.length();
		System.out.println("C length: " + stringLen); 
		int charArrLen = B.length; //(không có dấu ngoặc)
		System.out.println("B length: " + charArrLen); 
		
		//Sao chép string
		String D = C;
		System.out.println("D: " + D);
		
		//Sao chép mảng char
		int len = B.length;
		char[] E = new char[len];
		for (int i = 0; i < len; i++) {
			E[i] = B[i];
		}
		System.out.println(E);
		
		//So sánh String
		boolean b = C.equals(D); //So sánh có bằng hay không
		System.out.println(b);
		D += 'b';
		
		//so sánh theo thứ tự từ điển, trả về 0 nếu bằng nhau, số âm nếu C đứng trước D và số dương nếu ngược lại
		int dif = C.compareTo(D); 
		System.out.println(dif);
		
		//so sánh theo thứ tự từ điển không quan tâm chữ hoa, 'A' và 'a' được coi là bằng nhau
		C += 'B';
		dif = C.compareToIgnoreCase(D);
		System.out.println(dif);

		//Chuyển từ string sang số
		C = "1234";
		int num = Integer.parseInt(C);
		System.out.println(num);
		
		//Chuyển từ số sang string
		C = Integer.toString(124);
		System.out.println(C);
		
		sc.close();
	}
	
}