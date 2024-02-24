#include <stdio.h>

//Các bước bạn Mo "mã hóa"
//- Ghi từng ký tự của string gốc vào mảng 2 chiều, ghi theo từng cột, bắt đầu từ (0, 0) rồi đến (1, 0), (2, 0)...
//- Ghi từ mảng 2 chiều sang mảng 1 chiều theo từng dòng, dòng chẵn thì ghi từ trái sang phải, dòng lẻ ghi từ phải sang trái

//Ta sẽ làm ngược lại quá trình này, với mảng 1 chiều nhập vào từ input, ghi từng ký tự vào mảng 2 chiều
//dòng chẵn thì ghi từ trái sang phải, dòng lẻ ghi từ phải sang trái
//Ghi từng ký tự của mảng 2 chiều ra output, ghi từ trên xuống dưới từ trái sang phải, ghi theo từng cột.

char twoDArr[100][21]; //tối đa 200 ký tự, tối thiểu 2 cột => tối đa 100 dòng
char inp[201];
int colNum, rowNum; //số dòng, số cột của ma trận 2 chiều

void build2DArray()
{
	//i: index trong mảng 1 chiều
	//r, c: index theo hàng và cột trong mảng 2 chiều
	int i = 0, r = 0, c;
	while (inp[i] != '\0') {
		if (r % 2 == 0) { //hàng chẵn, ghi từ trái sang phải
			for (c = 0; c < colNum; c++) {
				twoDArr[r][c] = inp[i];
				i++;
			}
		} else { ////hàng lẻ, ghi từ phải sang trái
			for (c = colNum - 1; c >= 0; c--) {
				twoDArr[r][c] = inp[i];
				i++;
			}
		}
		r++;
	}
	rowNum = r; //Khi r chạy đến cuối cùng, không ghi được nữa thì r là số hàng của ma trận 2 chiều
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (1) {
		scanf("%d", &colNum);
		if (colNum == 0)
			break;

		scanf("%s", inp);
		build2DArray();

        //Ghi từ mảng 2 chiều ra input, duyệt theo cột trước
		for (int c = 0; c < colNum; c++)
			for (int r = 0; r < rowNum; r++)
				printf("%c", twoDArr[r][c]);
		printf("\n");		
	}

	return 0;
}


//Cách 2: Vẫn theo luồng tư tưởng trên nhưng map trực tiếp vị trí ở output với vị trí trong mảng input để in ra
//Code ngắn gọn, dùng ít bộ nhớ hơn và ít thời gian hơn vì không cần thông qua mảng 2 chiều
//
//#include <stdio.h>
//
//char inp[201];
//int colNum, rowNum;
//
//int countRow()
//{
//	int len;

//  //Các hàng và cột luôn được điền đầy đủ, nên chỉ cần check vị trí đầu mỗi hàng
//  //Từ đầu hàng này sang đầu hàng kia bằng cách cộng với số cột, thay vì ++ để check từng ô
//	for (len = 0; inp[len] != '\0'; len += colNum) 
//		;
//	return len / colNum; //rowNum * colNum = tổng số phần tử (cũng là độ dài của mảng 1 chiều)
//}
//
//int main()
//{
//	//freopen("input.txt", "r", stdin);
//	while (1) {
//		scanf("%d", &colNum);
//		if (colNum == 0)
//			break;
//
//		scanf("%s", inp);
//		rowNum = countRow();
//      //Ghi từ mảng 2 chiều ra input, duyệt theo cột trước
//      //Cứ hàng này lấy cột c thì hàng sau lấy cột colNum - 1 - c (duyệt từ trái sang phải và từ phải sang trái)
//		for (int c = 0; c < colNum; c++){
//			int realCol = c;
//			for (int r = 0; r < rowNum; r++) {
//				printf("%c", inp[r * colNum + realCol]);
//				realCol = colNum - 1 - realCol;
//			}
//		}
//		printf("\n");
//	}
//
//	return 0;
//}