/*
lí thuyết: thuật toán quay lui dùng để giải bài toán (liệt kê các cấu hình). Mỗi cấu hình được xây dựng bằng cách xây dựng 
từng phần tử, mỗi phần tử được chọn bằng cách thử tất cả các khả năng.

- giả thiết cấu hình cần liệt kê có dạng(x1, x2,...xn). Khi đó thuật toán quay lui thực hiện qua các bước sau.
1) Xét tất cả các giá trị x1 có thể nhận, thử cho x1 nhận lần lượt các giá trị đó. với mỗi giá trị thử cho x1 ta sẽ: 
2) xét tất cả giá trị x2 có thể nhận, lại thử cho x2 nhận lần lượt các giá trị đó. với mỗi giá trị thử gán cho x2 lại 
xét tiếp các khả năng chọn x3....cứ tiếp tục như vậy đến bước:
...
n) xét tất cả các giá trị xn có thể nhận, thử cho xn nhận lần lượt các giá trị đó, thông báo cấu hình tìm được(x1, x2,..xn).

trên phương diện quy nạp, có thể nói rằng thuật toán quay lui liệt kê các cấu hình n phần tử dạng (x1, x2,..., xn) bằng cách 
thử cho x1 nhận lần lượt các giá trị có thể. với mỗi giá trị thử gán cho x1 lại liệt kê tiếp cấu hình n - 1 phần tử (x2, x3,..., xn).

sinh ra nhiều cấu hình: ở mỗi bước vd x1 xét 3 th, x2 xét 3 trường hợp, x3 xét 3 trường hợp.
ở mỗi bước sẽ có 3 x 3 x 3 = 27th tất cả.

*/
//thuật toán mã giả.
//- cấu hình xây dựng mã giả thuật toán quay lui:
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int N, X[100];
/*
(thủ tục đệ quy là như thế này).
Try(int i){ //xây dựng giá trị cho phần tử x[i].
    for(j = <khả năng 1>; j <= <khả năng M>; j++){
    //xét tất cả các khả năng gán cho thằng x[i] này.
        if(<chấp nhận khả năng j>){ //nếu có 1 điều kiện gì đó chấp nhận khả năng j thì gán cho x[i].
            X[i] =<khả năng j>;
            if(i == n) // nếu i == n(phần tử cuối cùng).
                <Thông báo cấu hình tìm được>
            else{
            //nếu chưa phải là phần tử cuối cùng thì gọi đệ quy Try(i + 1). để xây dựng tiếp cấu hình đó.
                Try(i + 1);
            }
        }
    }
}
*/

//bài toán: quay lui xâu nhị phân có độ dài N.
//đầu tiên xây dựng cấu hình: (x1, x2,..., xn).
//xem thử bit1 nhận giá trị gì, bit2 nhận giá trị gì.
/*
void Try(int i){
    for(int j = 0; j <= 1; j++){
        //lẽ ra sẽ có 1 câu điều kiện ở đây nữa.(liệu rằng bạn có gán đc hay kh nhưng sâu nhị phân kh cần phải gáng).
        X[i] = j;
        if(i == N)
            Inkq();
        else:
            Try(i + 1); // để tiếp tục xây dựng bit(i + 1).
    }

    //khi chạy thủ tục Try thì cây quay lui nó sẽ chạy như thế.
}
*/
void inkq(){
    for(int i = 1; i <= N; i++){
        cout << X[i];
    }
    cout << endl;
}

//Thuật toán quay lui.
void Try(int i){
    //duyet qua tung kha nang cua X[i].
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == N){// tức là xây dưng tới bit N ròi. 
            inkq();
        }
        else{
           Try(i + 1);
        }
    }
}

int main(){
    cin >> N;
    Try(1); // để xây dựng bit 1.
    return 0;
}

/*
cách chạy của code quay lui: 
*/


