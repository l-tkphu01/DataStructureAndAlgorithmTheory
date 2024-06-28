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

using namespace std;

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

/*
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
*/

/*
cách chạy của code quay lui: 
*/
/*
//ôn lại bài cũ:
void inkq(){
    for(int i = 1; i <= N; i++){
        cout << X[i] <<" "; 
    }
    cout << endl;
}

void Try(int i){
    int N, X[N];
    //vòng for duyệt qua tất cả các khả năng có thể đề cập đến.
    for(int j = 0; j <= 1; j++){
        //gán X[i] cho j. (đối với xâu nhị phân không cần thiết phải dùng điều kiện).
        X[i] = j;
        if( i == N){// nếu i là chỉ số cuối cùng cua n.
            inkq();
        }
        else{
            Try(i + 1);
        }
    }
}
int main(){
    cin >> N;
    //khởi tạo giá trị Try đầu tiên bằng cách.
    Try(1);
    return 0;
}
*/

//liệt kê tổ hợp chập k của N: Xây dựng cấu hình (X1, X2,..., Xk)

int N, X[100], used[100];
/*
void inkq(){
    for(int i = 1; i <= K; i++){
        cout << X[i];
    }
    cout << endl;
}

// i : N - K + i: đối với bài toán tổ hợp chập k của n: có max là = N - K + i;
// khả năng nhỏ nhất mà nó có thể nhận được là: giá trị của phân tử đứng trước của nó + 1. là x[i - 1] + 1;
/*
max: N - K + i;
min: X[i - 1] + 1;
i = 1 : X[0] + 1 = 0 + 1 = 1;
*/

/*
void Try(int i){
    //duyet tat ca cac kha nang ma X[i] có thể nhận được.
    for(int j = X[i - 1] + 1; j <= N - K + i; j++){
        X[i] = j;
        //đôi khi ta gán X[i] = j. khi đệ quy chạy xong phải trả lại trạng thái ban đầu của X[i] + j. 
        if(i == K){
            inkq();
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    //để cẩn thận thì ta dùng: 
    X[0] = 0;
    Try(1);
    return 0;
}
*/

//Quay lui sinh hoán vị của N phần tử. 
// một phần tử không thể suất hiện 2 lần trong cấu hình.
/*
void Try(int i){
    for(int i = 1; j <= N; j++){ //giá trị nào cx thể gán đc cho thk X[i]. ví dụ X[1] == 1;
    // lưu ý: khi xây dựng cấu hình X[2], X[3], X[4], X[5]: kh xây dựng cấu hình theo X[1] nữa.
    //để kiểm tra mảng đã sử dụng chưa dùng (!used[j]).
        if(used[j] == 0){ // khi used của j chưa được sử dụng.
            used[j] = 1; //đánh dấu đã sử dụng used = 1; thì khả năng vòng lặp sau sẽ không được sử dụng nữa.
            X[i] = j;
            if(i == N)
                inkq();
            else:
                Try(i + 1);
            //backtrack; nếu kh có bước này thì khi used = 1: thực hiện xong thì nó sẽ kh sử dụng used = 1 nữa. 
            used[j] = 0;
        }
    }
}
*/

//code: 

void inkq(){
    for(int i = 1; i <= N; i++){
        cout << X[i];
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= N; j++){
        //xét xem liệu rèn có thể gán X[i] = j hay không.
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1; //danh dau j đã được sử dụng ròi.
            if( i == N){
                    inkq();
            }
            else{
                Try(i + 1);
            }
            //backtrack;
            used[j] = 0;
        }
    }
}

int main(){
    cin >> N;
    memset(used, 0, sizeof(used)); //ban đầu khởi tạo tất cả các giá trị ban đầu là 0 hết.
    Try(1);
}

/*thuật toán N quân hậu (cổ điển nhất).
-lí thuyết: tìm cách sắp xếp N quân hậu vào N hàng trên bàn cờ vua N*N sao cho không có 2 quân hậu nào ăn nhau. Gọi
x = (x1, x2,...xn) là một nghiệm của bài toán, khi đó nếu xi(phần tử thứ i của cấu hình X)= j thì có nghĩa ta xếp quân hậu hàng thứ i nằm ở cột j.

vd: x1 = 5
    x2 = 4
- quân hậu ăn theo dọc, ngang, chéo.
- để giải quyết xếp n quân hậu thì phải đánh dấu (tương tự như thuật toán quay lui sinh hoán vị).

*Lưu ý: vì ta đã xây dựng mỗi quân hậu nằm trên 1 hàng ròi, nên kh cần phải check xem có quân hậu nào trùng nhau hay không
mà chỉ cần check xem cột có quân hậu nào trùng nhau hay không hoặc các đường chéo.

2 loại đường chéo: đường chéo xui và đường chéo ngược.
- sẽ có [2*n - 1] đường chéo vì có 1 đường ở giữa trùng nhau.

có 15 đường chéo ngược và 15 đường chéo xuôi.

- khi đặt quân hậu X[i] = j tức là đặt quân hậu ở (i(hàng), j(cột)).

- (i, j) => quản lí cột j, đường chéo xuôi (i-j+N) và đường chéo ngược (i + j - 1).
*/

//mã giả của thuật toán là: 

/*
quay lui bài toán N queen: sử dụng giống như thuật toán "sinh hoán vị n".
sử dụng mảng cot[], d1[], d2[] (tương tự như kĩ thuật loang trên 2 mảng để giải quyết). để đánh dấu cột, đường chéo xuôi
và đường chéo ngược.

//code mã giả của thuật toán sau.

*Lưu ý: khi chuẩn bị gán X[i] = j.
void inkq(){
    for(int i = 1; i <= N; i++){
        cout << X[i];    
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= N; j++){
        if(cot[j] == 1 && d1[j] == 1 && d2[j] == 1){
                cot[j] = d1[j] = d2[j] = 0;
                X[i] = j;
                if(i == N){
                    inkq();
                }
                else{
                        Try(i + 1)
                }
                //backtrach: quay lại.
                cot[j] = d1[j] = d2[j] = 0;
        }
    }
}
*/

