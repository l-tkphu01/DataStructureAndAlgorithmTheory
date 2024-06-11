#include <bits/stdc++.h>

using namespace std;


/*
bài tập: truy vấn tổng trên đoạn
cho dãy số A[] gồm n phần tử, nhiệm vụ của bạn là tính tổng các số trong dãy từ vị trí l đến chỉ số r.

- input fomat: Dòng đầu tiên là số nguyên N. Dòng tiếp theo gồm N số nguyên A[i] và số Q là số cuối cùng ở dòng thứ 2. Q 
dòng tiếp theo mỗi dòng là 2 vị trí l, r.
- output fomat: in ra tổng các phần tử trong đoạn [l, r] của từng truy vấn trên 1 dòng.

vd: 3 1 2 5 7 8 4 3.
- mỗi truy vấn là 1 vòng for.
*/

/*int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for( int i = 0; i < n; i++) cin >> a[i];
    // nhập số lượng truy vấn q.(bạn cần truy vấn bao nhiêu số lượng l và r thì nhập bấy nhiêu q).
    int q; cin >> q;
    while(q--){//lặp qua từng truy vấn.
        //mỗi truy vấn nhập 2 chỉ số l, r;
        int l, r; cin >> l >> r;
        //bởi vì chỉ số l và r bắt đầu là 1 nên giảm l, r vì chỉ số mảng bắt đầu = 0;
        --l; --r;
        //sau khi có chỉ số bắt đầu và kết thúc ròi thì dùng for.
        for(int i = l; i <= r; i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
}
*/

/*
1. MẢNG CỘNG DỒN TRÊN MẢNG 1 CHIỀU: pre (prefix sum)
- gọi mảng pre[] là mảng cộng dồn của mảng A[].
- khi đó pre[i] = A[1] + A[2] + A[3] +...+ A[i] sẽ lưu tổng các phần tử từ chỉ số 0 --> i của mảng A[]
- ta có thể pre[k] thông qua pre[k - 1]: pre[k] = pre[k - 1] + A[k].
vd:                                   2 3  8  6  4  1
tổng các tiền tố thông qua công thức: 2 5 13 19 23 24 --> ct: [l, r] : pre[r] - pre[l - 1]; mà pre[r] = pre[r - 1] + pre[r].
- lưu ý: nên lưu vị trí duyệt từ 1 --> n.
*/

/*
code.

int main(){
    int n; cin >> n;
    int a[n + 1]; // khai báo a[n + 1] để tổng tiền đề chạy tử 1 --> n; thay vì a[n]: 0 -->
    for( int i = 1; i <= n; i++) cin >> a[i];
    int prefix[n + 1] = {0};
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + a[i];// tổng các phần tử từ i --> i - 1 + phần tử hiện tại a[i].
    }
    int q; cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] <<' ';// o(1).
    }
    return 0;
}
*/

/*
2. MẢNG CỘNG DỒN TRÊN MẢNG 2 CHIỀU.
bài toán: cho hình chữ nhật tính tổng miền trên và dưới giới hạn bởi 1 hình chữ nhật nào đó.
*/


//prefix[i][j] : tổng tất cả các phần tử của hcn bắt đầu từ hàng 1,kết thúc ở hàng i, bắt đầu từ cột 1, kết thúc ở cột j.
// hàng i cột j.

/*int main(){
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1]; //mục đích để tính tổng tiền tố từ 1 --> n;
    //trong th hàng 1 và cột 1 là full 0 thì mới cho i và j chạy từ 1 --> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    int q; cin >> q;
    while(q--){
        int h1, h2, c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        int sum = 0;
        for(int i = h1; i <= h2; i++){
            for(int j = c1; j <= c2; j++){
            sum += a[i][j]; //cộng các giá trị của hàng 1 và hàng 2, cột 1 và côt 2 lại.
        }
    }
    cout << sum << endl;
    }
return 0;
}
*/


/*
- CÁCH TÍNH PREFIX SUM TRONG MẢNG 2 CHIỀU NHANH NHƯ SAU:
sử dụng công thức: prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];(1)

- khi biết hàng 1 và hàng 2 cần truy vấn ròi thì ta có thể sử dụng công thức để tính luôn.
arr[i][j] = prefix[A][B] - prefix[a - 1][B] - prefix[A][b - 1] + prefix[a - 1][b - 1].o(1) (2)
lưu ý: phải tính prefix[i][j] <=> prefix[A][B].
*/

/*int main(){
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];//đảm bảo chạy từ 1 và loại bỏ hàng 0.
    for( int i = 1; i <= n; i++){
        for( int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int pre[n + 1][m + 1] = {0};
    //memset(pre, 0, sizeof(pre));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j]; 
        }
    }
    //nhập phần tử truy vấn.
    int q; cin >> q;
    while(q--){
        int h1, h2, c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        cout << (pre[h2][c2] - pre[h1 - 1][c2] - pre[h2][c1 - 1] + pre[h1 - 1][c1 - 1]) << endl;
    }
    return 0;
}
*/

/*
bài tập: 
- Tèo hiện tại đã bỏ làm lập trình viên và về trồng rau nuôi cá, anh ta có một mảng vườn hình chữ nhật có kích
thước NxM. ngta chia vườn của mình thành NxM ô vuông và trồng vào đó 1 cây cà rốt, tới vụ thu hoạch có những cây cà rốt 
bị chết và có những cây cà rốt có củ, anh ta muốn biết với mỗi hình chữ nhật bắt đầu từ hàng x1 tới x2 và từ cột y1 tới y2
thì số cà rốt thu hoạch được là bao nhiêu.

- Biết rằng mảnh vườn đc mô tả là một ma trận nhị phân, 0 tương ứng với cây cà rốt chất và 1 tương ứng với cây cà rốt
có củ. 
*/

/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int pre[n + 1][m + 1] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    int q; cin >> q;
    while(q--){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}*/

//cách 2: có thể khai báo biến toàn cục.

/*int a[1005][1005];
int pre[1005][1005];
int n, m;

void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    //nhap truy vấn;
    int q; cin >> q;
    while(q--){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
*/

/*
MẢNG HIỆU (DIFFERENCE ARRAY).
- Cho mảng A[] có N phần tử, có Q thao tác, mỗi thao tác sẽ tăng các phần tử trong đoạn L --> R của mảng A[] lên k đơn vị
. Hãy xác định mảng A[] sau Q thao tác.
- Cách tiếp cận đơn giản cho vấn đề này là đối với (mỗi truy vấn bạn sẽ duyệt từ L tới R và thêm K vào các phần tử trong 
mảng A[], như vậy với mỗi truy vấn bạn sẽ mất o(N). 
vd: 3 8 1 4 7 2
*điều kiện: tăng k từ l --> r vd: 1 3 3 (tăng từ 1 -> 3 lên 3 đv)
*/

/*
cách 1: truy vấn 
int main(){
    int n, q; cin >> n >> q; //q là số truy vấn.
    vector<long long> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        for(int i = l; i <= r; i++){
            a[i] += k;
        }
    }
    for(long x : a){
        cout << x <<' ';
    }
    return 0;
}
*/

/*
cách 2: dùng mảng hiệu(DA) cho phép sử dụng để giải nhiều bài tập khó hơn

Đặt vấn đề: Cho mảng A[] có N phần tử, có Q thao tác mỗi thao tác sẽ tăng
các phần tử trong đoạn từ chỉ số L tới R của mảng A[] lên K đơn vị. Hãy 
xác định mảng A[] sau Q thao tác.

cách tiếp cận: đó là đối với mỗi truy vấn bạn sẽ duyệt từ L tới R và thêm 
K vào các phần tử trong mảng A[], như vậy với mỗi truy vấn bạn sẽ mất O(N).

Cách tối ưu hơn:
vd:                                                    A = 3 8 1 4 7 2 9 
sử dụng công thức sau:D[0] = A[0];
                      D[i] = A[i] - A[i - 1]:          D = 3 5-7 3 3 -5 7 (mảng hiệu). 
Khi tính mảng cộng dồn của mảng D thì sẽ ra A ban đầu: F = 3 8 1 4 7  2 9 (mảng cộng dồn).
ví dụ tính mảng cộng dồn F[4] = D0 + D1 + D2 + D3 + D4.
                              = A0 + A1 - A0 + A2 - A1 + A4 - A3. (c/m A = F)


A = 3 8 1 4 7 2 9 
D = 3 5-7 3 3 -5 7
    3 5-4 3 3 -8 7 (khi cộng thêm k) dùng câu lệnh D[l] += k: mỗi thằng từ vị trí l đến cuối đều + k đơn vị.
mcd:3 8 4 7 10 2 9                                                   D[r + 1] -= k; giới hạn vị trí [l, r].
*luôn cập nhật thông qua mảng hiệu.
- muốn giới hạn khoảng [l, r] thì dùng D[r + 1] -= k; sẽ bù trừ cho D[l] += k: không muốn cuối dãy bị ảnh hưởng.
*/

/*
int main(){
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for( int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long D[n + 5]; // để đảm bảo D[r + 1]; hợp lệ
    for(int i = 0; i < n; i++){
        if(i == 0) D[0] = a[0];
        else
        D[i] = a[i] - a[i - 1];
    }
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        D[l] += k;
        D[r + 1] -= k;
        }
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += D[i];
            cout << sum <<' ';
        }
    return 0;
}
*/

/*MẢNG 2 CHIỀU: 
KĨ THUẬT DUYỆT CÁC Ô LIỀN KỀ.
*/

/*
bài tập: cho ma trận A các số nguyên có N hàng và M cột. điểm được coi là cực đại trong ma trận nếu nó 
lớn hơn tất các số ở các số ô xung quanh mà chung đỉnh với nó. Hãy đếm xem trong ma trận có bao nhiêu điểm cực đại.

cách làm: phải duyệt qua từng ô 1 nếu muốn nhanh thì dùng kĩ thuật sau.
5/ kĩ thuật duyệt các ô liền kề: 
ta có mảng sau:  i - 1, j - 1| i - 1, j| i - 1, j + 1|
                 i ,  j - 1  | i,  j   | i, j + 1    |
                 i + 1, j - 1| i + 1, j| i + 1, j + 1|

- để duyệt qua 8 ô còn lại sau ô i, j: xét sự thay đổi của i, j
(-1, -1)
(-1, 0)
(-1, 1)
(0, -1)
(0, 1)
(1, -1)
(1, 0)
(1, 1) - có 8 lượng di chuyển với 8 ô xung quang, dùng vong for kh nên dùng if (else) vì dễ trùng và thiếu.
*/

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; //mỗi cặp sẽ tương ứng với 1 lượng di chuyển.

int main(){
int n, m; cin >> n >> m;
int a[n][m];
for( int i = 0; i < n; i++){
    for( int j = 0; j < m; j++){
        cin >> a[i][j];
    }
}
int dem = 0;
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
    //check (i, j) xem có phải là nó lớn hơn hơn các số có chung đỉnh với nó hay không.
        bool check = true;
        //để duyệt qua 8 ô xung quanh.
        for(int k = 0; k < 8; k++){ // dùng chỉ số k để duyệt qua 2 mảng dx, dy này.
            int i1 = i + dx[k], j1 = j + dy[k]; // là 1 trong 8 ô xung quanh chung đỉnh với ô i, j.
            //check xem có nhỏ hơn ô i, j không.
            if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m){
                if(a[i1][j1] >= a[i][j]){
                    check = false;
                    break;
                }
            }
        }
        if(check) ++dem;
    }
}
cout << dem << endl;
}