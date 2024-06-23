/*
một số bài toán không tuân theo tính toán cố định mà tuân theo quy tắc: "thử sai và quay lui".
(Try - error and Backtracking). (phương pháp này cũng còn có tên gọi là véc cạn). 
- tinh thần chủ đạo của quay lui là thử và sai.

quy trình:  

B1. tổ chức kh gian tìm kiếm nghiệm (lời giải) bài toán thành không gian phân cấp (cây tìm kiếm sẽ được nghiên cứu kĩ
ở chương 5).

B2. Dùng hàm đệ quy để dò tìm từ cấp thấp đến cấp cao thuộc cây tìm kiếm đó.

B3. tại mỗi cấp xét (thử và sai) đó tất cả các khả năng có thể lựa chọn nghiệm (thỏa mãn yêu cầu đặt ra): nếu có một lựa 
chọn chấp nhận được thì ghi nhớ các thông tin của nó và tiến hành thử ở cấp cao hơn thuộc cây tìm kiếm.

B4. nếu kh có lựa chọn nào chấp nhận được thì "quay lui" lại bước trước r tiến hành "thử, sai" với các trạng thái còn lai
và xóa bỏ thông tin vừa chọn ở bước vừa r.

thuật toán quay lui dùng để giải bài toán liệt kê các cấu hình. Mỗi cấu hình được xây dựng bằng cách xây dựng từng phân tử
mỗi phần tử được chọn bằng cách thử tất cả các khả năng.

*/
