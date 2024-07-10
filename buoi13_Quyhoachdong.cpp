/*
quy hoạch động cho mấy thk mới bắt đầu (phần 1).

- sử dụng vòng lặp for cơ bản.
sơ lược tổng quan về thuật toán: quy hoạch động được ưa chuộng bởi vì ban đầu, bài toán có muôn hình vạn trạng và phải 
suy nghĩ rất nhiều mới tìm ra được lời giải. Không có một công thức chuẩn mực nào áp dụng được cho mọi bài toán. Bởi 
vì sự phổ biến của nó, bạn bắt buộc phải cực kì thuần thục thuật toán này nếu muốn có kết quả tốt trong các kì thi.

có 2 hướng tiếp cận bài toán Quy hoạch động: 
- sử dụng vòng lặp for - với cách tiếp cận Bottom-up.
- sử dụng đệ quy có nhớ - với cách tiếp cận Top-down.

*quy hoạch động sẽ đi từ cơ bản đến nâng cao, quy hoạch động 1 chiều, 2 chiều. so sánh và đánh giá 2 cách tiếp cận, để 
có cái nhìn tổng quan, chi tiết hơn về quy hoạch động.

+ khi nào muốn dùng quy hoạch động: 
- tất nhiên kh có công thức nào cho bài toán như vậy.

tuy nhiên có một số bài toán có tích chất để các bạn có thể liên tưởng đến quy hoạch động. dưới đây là hai tính chất
nổi bật nhất trong số chúng:

- bài toán có các bài toán con gối nhau (bài toán có công thức quy nạp giống trong toán học): sử dungj kết quả của bài 
toán nhỏ để giải quyết bài toán lớn (bài toán chia để trị (chia bài toán lớn ra thành những bài toán nhỏ sau đó tìm điều kiện dừng 
của đệ quy và đệ quy nó để từng bước sử lí bài toán nhỏ)).

- bài toán có cấu trúc con tối ưu.

một số dấu hiệu khi code thuật toán Quy Hoạch Động.
1/ tính chất con tối ưu 
mô tả: bài toán lớn có thể được chia thành các bài toán con nhỏ hơn và lời giải của bài toán lớn có thể được tạo thành 
từ lời giải của các bài toán con.

ví dụ bài toán tìm đường đi ngắn nhất từ A --> c => a --> b or b --> c.

2/ trạng thái và quyết định.
mô tả: xác định rõ trạng thái của bài toán và các quyết định cần thực hiện tại mỗi trạng thái.

ví dụ: trong bài toán xếp ba lô.
3/ tính lặp lại.
mô tả: các bài toán con lặp lại nhiều lần và có thể được lưu trữ và sử dụng lại thay vì tính toán lại.

ví dụ: thuật toán Fibonacci, giá trị của F(n) phụ thuộc vào F(n - 1) + F(n - 2). Chúng có thể lưu trữ để không phải tính
lại nhiều lần.


- bài toán dãy con chung dài nhất.
- bài toán ba lô.
*/


// phương pháp này là bottom-up.
#include <bits/stdc++.h>

using namespace std;
/*
int F[100] = {0};
unsigned long long Fibonacci( unsigned long long n){
    if( n == 0) 
        return 0;
    if( n == 1) 
        return 1;
    else{
        F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        return F[n];
    } 
}

signed main(){
    unsigned long long n; cin >> n;
    unsigned long long result = Fibonacci(n);
    cout << result << endl;
    return 0;
}
*/
// cách code thứ 2.

int F[100] = {0};
int fibon(int n){
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i <= n; i++){ //có độ phức tạp là O(n).
        F[i] = F[i - 1] + F[i - 2]; 
    }
    return F[n];
}

signed main(){
    unsigned long long n; cin >> n;
    unsigned long long result = fibon(n);
    cout << result << endl;
    return 0;
}
