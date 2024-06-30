/*


Dấu hiệu: nhánh cận (brand and bound). (sử lí bài toán tìm con đường ngắn nhất - ).
1. bài toán tối ưu hóa.
- bài toán yêu cầu tìm giá trị tốt nhất(tối đa hoặc tối thiểu) của một mục tiêu.
2. kh gian tìm kiếm lớn:
- không gian tìm kiếm rất lớn, và cần có pp để loại (cắt tỉa) các nhánh không cần thiết 
3. có thể ước lượng giá trị biên
- Bạn có thể tính giá trị biên để quyết định có tiếp tục tìm kiếm trong một nhánh hay không.
- dấu hiệu: contest mảng 2 chiều đối xứng là dùng nhánh cận.
áp dụng: 

- ÁP DỤNG:
- bài toán ba lô.
- bai toán du lịch.
- bài toán phân chia công việc.
- bài toán chia tập hợp con.
- bài toán cây phủ tối thiểu.
- bài toán tối ưu hóa lộ trình xe tải.
THUẬT TOÁN QUAY LUI NHÁNH CẬN: ứng dụng trong cấu trúc dữ liệu và giải thuật, trong toán rời rạc.

- cho n thành phố đánh số từ 1 --> n và các đoạn đường 2 chiều giữa chúng, chi phí đi lại giữa các thành phố này được
cho bởi mảng 2 chiều c[][], trong đó C[i][j] = C[j][i] là chi phí đi từ thành phô i đến thành phố j. Chi phí giữa thành 
phố thứ i với chính nó là 0.

một người đi du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối 
cùng quay lại thành phố 1. hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
*/

