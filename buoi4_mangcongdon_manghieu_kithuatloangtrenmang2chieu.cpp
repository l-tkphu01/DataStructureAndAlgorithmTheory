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
sử dụng công thức: prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];

- khi biết hàng 1 và hàng 2 cần truy vấn ròi thì ta có thể sử dụng công thức để tính luôn.
arr[i][j] = prefix[A][B] - prefix[a - 1][B] - prefix[A][b - 1] + prefix[a - 1][b - 1].o(1).
*/

int main(){
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






