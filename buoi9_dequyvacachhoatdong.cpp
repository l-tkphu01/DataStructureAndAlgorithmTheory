/* 
kien thuc ve ham de quy.
- cách hoạt động của hàm đệ quy là gọi lại hàm chính nó.
thao tac: 
push: day phan tu vao trong stack
thao tac: 
pop: lay ra khoi phan tu ra khoi stack. 
LIFO: last in first out.: vào cuoi nhung ra dau tien

- moi lan xay dung ham de quy: dieu kien dung va cong thuc truy hoi. 
- dieu kien dung: ban da co cau tra loi roi do.
- s(n) = 1 + 2 + 3 + 4 + 5 + 6 +....+ n.
 vi du: cho n = 1 => s = 1;
 s(n) = n + s(n - 1); s(5) = n + s(n - 1);
 
 
 
 * lúc nào cung giai quyet tu dau xuong cuoi het.
 moi dau vo giai phai xac dinh bai toan con nho nhat la gi.
*/
#include <bits/stdc++.h>

using namespace std;

//luu y: 
//void hello(){
//	cout <<"xin chao" <<" ";
//	hello();//tran du liu bo nho kh co diem dung.
//}.
//int tong(int n){
////	if(n == 1)
////	return 1;
////	else 
//	return n + tong(n - 1); //công thuc truy hoi. // neu kh co dong tren thi bo nho no se day va xay ra hien tuong tran bo nho. 
//}
//s(n) = 1 + 2 + 3 + 4 + 5 +...+ 6.
//n! = n*(n-1)*(n-2)*.....*1.


// bài toán tìm số fibonacci bằng phương pháp đệ quy: 
// int fibo(long long n){
// 	if(n <= 1) return n;
// 	else return fibo(n - 1) + fibo(n - 2);
// }

// int main(){
// 	long long n;
// 	cin >> n;
//     cout << fibo(n) << endl;
// 	return 0;
// }

// bài tập: tổ hợp chập k của n phần tử:

// int nCK(int n, int k){
//     if(k == 0 || n == k) return 1;
//     else return nCK(n-1, k) + nCK(n - 1, k - 1);
// }

// int main(){
//     int n, k;
//     cin >> n >> k;
//     cout << nCK(n, k) <<" ";
//     return 0;
// }

/*
bài tập: tìm ước chung lớn nhất của giải thuật
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    cout << gcd(10, 45) << endl;
}


    bai tap: luy thua nhi phan.

    int binpow(int a, int b){
        if(b == 0) return 1;
        int x = binpow(a, b/2);
        if(b % 2 == 1)
        return a*x*x;
        else
        return x * x;
    }

    int main(){
        cout << binpow(10, 2) << endl;
    }
*/

/*
bài tập: đếm số lượng chữ số của số tự nhiên sử dụng hàm đệ quy.

int count(int n){
    if(n < 10) return 1;
    else 
    return 1 + count(n / 10);
}

int palin(int a[], int l, int r){
    if( l >= r) return 1;//khong phai mang doi xung.
if(a[l] != a[r]) return 0;
else 
    return palin(a, l+1, r-1);//nó sẽ tiến hành kiểm tra các số còn lại.

}
int main(){
    int n;
    cin >> n;
    int a[n];
    for( int &x : a) cin >> x;
    if(palin(a, 0, n - 1))//bắt đầu chỉ số 0 và kết thúc chỉ số n - 1;
        cout << "YES\n";
    else cout << "no\n";
    return 0;
}
*/




/*
dễ xảy ra hiện tượng tràn bộ nhớ.


#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long dp[n+1];

    // Khởi tạo điều kiện ban đầu
    dp[0] = 0;
    for (long long i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + (i * i * (i + 1) / 2);
    }

    // Kết quả của S(n) được lưu tại dp[n]
    cout << dp[n] << endl;
    return 0;
}
*/

/*
ta có đề bài đệ quy sau đây.
f(n) = 1 + 2 + 3 +...+ n = n*(n+1)/2 (n >= 1)
b1
base case: n = 1 => f(1) = 1.(để xác định đến thời điểm nào nó dừng lại).
general case: giả sử ta dùng: n - 1.
f(n - 1) = 1+....+ (n - 1) = (n - 1)*n/2.
chứng minh f(n) = f(n-1) + n. mới có đc công thức cuối cùng. 
để tính đc f(n) = f(n - 1) + n = f(n - 2) + (n - 1) + n=....= f(1).
*/