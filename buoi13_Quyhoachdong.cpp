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


/*
code tham khảo cho thuật toán quy hoạch động.

int F[100];
int fibon(int n){
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i <= n; i++){
        F[i] = F[i - 1] + F[i - 2]; //lưu ý: khi truy hồi thì luôn có 2 vế này.
    }
    return F[n];
}
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

/*
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

*/
/*
4. Bài toán Frog 1 VNOJ.
có N hòn đá, được đánh số từ 1 --> N. Với mỗi chỉ số i (1 <= i <= N), độ cao của hoàn đá thứ i là hi

ban đầu, có một chú ếch đang ngồi ở hòn đá thứ nhất và chú sẽ thực hiện liên tục một loạt cách hành động:

.) Nếu chú đang ngồi ở hòn đá i, chú có thể nhảy đến hòn đá thứ i + 1 hoặc i + 2. Chú sẽ mất chi phí khi nhảy là |hi - hj|
với j là hòn đá mà chú ếch nhảy đến.

bạn hãy giúp chú ếch tìm chi phí tối thiểu để nhảy từ hòn đá thứ nhất đến hòn đá thứ N nhé.

nhận thấy: xác định cách để chú ếch nhảy từ hòn đá 1 đến hòn đá n sao cho chi phí là nhỏ nhất.

==> đây là bài toán tối ưu, ta dùng cách quy hoạch động.
*/

/*
#include <iostream>
#include <cmath>  // Thêm thư viện cho hàm abs và min
#include <algorithm> // Thêm thư viện cho hàm min
using namespace std;

int F[100] = {0};
int h[100] = {0};

int f(int n) {
    F[1] = 0; // Chi phí để ở hòn đá đầu tiên là 0
    F[2] = abs(h[2] - h[1]); // Chi phí để nhảy từ hòn đá 0 đến hòn đá 1
    for (int i = 3; i <= n; i++) {
        F[i] = min(F[i - 1] + abs(h[i] - h[i - 1]), F[i - 2] + abs(h[i] - h[i - 2]));
    }
    return F[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int result = f(n); // Gọi hàm f với n - 1 vì chỉ số mảng bắt đầu từ 0
    cout << result << endl;

    return 0;
}
*/
// Bài toán xếp hàng mua vé.

/*
Có N người sắp hàng mua vé dự buổi hoà nhạc. Ta đánh số họ từ đến 
theo thứ tự đứng trong hàng. Mỗi người cần mua một vé, song người bán vé được phép bán cho mỗi người tối đa hai vé. Vì thế, một số người có thể rời hàng và nhờ người đứng trước mình mua hộ vé. Biết 
là thời gian cần thiết để người 
mua xong vé cho mình. Nếu người 
rời khỏi hàng và nhờ người 
mua hộ vé thì thời gian để người thứ 
mua được vé cho cả hai người là 

Yêu cầu: Xác định xem những người nào cần rời khỏi hàng và nhờ người đứng trước mua hộ vé để tổng thời gian phục vụ bán vé là nhỏ nhất.

theo quan sát thì nó có dạng là quy hoạch động:
để vé mua là rẻ nhất có nghĩa là tối ưu nhất ==> quy hoạch động, nhánh cận, quay lui.
*/

/*
Xác định các bước giải bài toán (làm ra nháp)
Bước 1: Xác định ý nghĩa mảng F

Gọi F[i] là thời gian nhỏ nhất để người thứ 1 đến người thứ i có thể mua vé
Kích thước mảng F là n, mảng F có 1 chiều.
Bước 2: Xác định bài toán con

Nếu chỉ có 1 người mua vé thì thời gian để người đó mua là T[1], F[1]=T[1]
Nếu chỉ có 2 người mua vé thì mình sẽ có 2 cách mua:
Cách 1: 2 người tự mua vé mất số thời gian là T[1]+T[2]
Cách 2: người 1 mua vé cho cả hai người 1 và 2, mất thời gian là R[1]
Vì ta đang cần tìm thời gian nhỏ nhất nên sẽ chọn cách nào cho ra kết quả nhỏ nhất: F[2]=min(T[1]+T[2],R[1])
Bước 3: Xác định công thức truy hồi
Xác định được bài toán con thì đến đây có thể dễ dàng tìm được công thức. Các cách để người thứ i mua vé:

Nếu người i tự mua vé của mình ta sẽ mất thời gian là: F[i−1]+T[i]
Nếu người i nhờ người i−1 mua vé hộ, ta sẽ mất thời gian là: F[i−2]+R[i−1]
Vậy ta có công thức: F[i]=min(F[i−1]+T[i],F[i−2]+R[i−1])

Bước 4: Xác định kết quả nằm ở đâu?
Kết quả nằm ở: F[n] – Thời gian mua vé cho người từ 1 tới n
*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>

int F[100] = {0};
int T[100] = {0};
int R[100] = {0};
int f(int n){
    F[1] = T[1];
    F[2] = min(T[1] + T[2], R[1]);//trường hợp 2 người mua 2 vé riêng lẻ.
    //b3: xác định công thức truy hồi.
    for(int i = 3; i <= n; i++){
        F[i] = min(F[i - 1] + T[i], F[i - 2] + R[i - 1]); 
    }
    return F[n];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie();
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> T[i];
    }
    for(int i = 1; i < n; i++){
        cin >> R[i];
    }
    int result = f(n);
    cout << result <<endl;
    return 0;
}
*/

// SỬ DỤNG VÒNG LẶP FOR NÂNG CAO.

/*
2. Bài toán đường đi có tổng lớn nhất:

link đề bài: Đường đi có tổng lớn nhất.

Cho một bảng A kích thước m*n (1≤m,n≤100), trên đó ghi các số nguyên aij (∣aij∣≤100). Một người xuất phát tại ô nào đó của
cột 1, cần sang cột n (tại ô nào cũng được).
Quy tắc di chuyển: Từ ô (i,j) chỉ được quyền sang một trong 3 ô (i,j+1); (i−1,j+1); (i+1,j+1).

input: Ghi 2 số m, n là số hàng và số cột của bảng.

M dòng tiếp theo, dòng thứ i ghi đủ n số trên hàng i của bảng theo đúng thứ tự từ trái sang phải.

- các bước giải bài toán:
B1: Xác định ý nghĩa của mảng F.
'.) Gọi F[i][j] là tổng đường đi lớn nhất khi đi từ ô nào đó thuộc cột 1 đến ô (i,j)
Kích thước mảng F là m∗n, mảng F có 2 chiều, tương ứng hàng và cột.
 .) Kích thước mảng F là m∗n, mảng F có 2 chiều, tương ứng hàng và cột.

B2: xác định bài toán con.
 .)Ta thấy một ô (i,j) bất kỳ sẽ được đi tới bởi các ô: (i−1,j−1),(i,j−1),(i+1,j−1)
 .)
*/


