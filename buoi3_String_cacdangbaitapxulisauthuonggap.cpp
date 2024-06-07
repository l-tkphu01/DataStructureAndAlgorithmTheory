/*
buổi 3
bài 1: cho mảng A[] gồm N phần tử, hãy sắp xếp các phần tử trong mảng theo yêu cầu sau.
- sắp xếp số lượng chữ số chẵn xuất hiện trong số tăng dần, nếu 2 số còn cùng số lượng chữ số chẵn thì số nhỏ hơn in
trước.

- sắp xếp theo số lượng chữ số lẽ xuất hiện trong số ban đầu tăng dần, nếu 2 số có cùng số lượng chữ số lẻ thì số nào 
xuất hiện trước sẽ in ra trước. (làm theo mảng và vector để luyện tập).
*/

#include <bits/stdc++.h>

using namespace std;

/*int sc(int n){
    int dem = 0;
    if(n == 0) return 1;
    while(n){ // n>0 or n != 0;
        if(n % 2 == 0)
            dem++;
        n/=10;
    }
    return dem;
}

int sl(int n){
    int dem = 0;
    while(n){
        if(n % 2 == 1)
            dem++;
            n/=10;
    }
    return dem;

}
bool cmp1(int a, int b){
    if(sc(a) != sc(b)){
        return sc(a) < sc(b);
    }
    else{
        return a < b;
    }
}

bool cmp2(int a, int b){
    if(sl(a) != sl(b)){
        return sl(a) < sl(b);
    }
    else{
        return a < b;
    }
}

int main(){
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stable_sort(a, a + n, cmp1);
    for(auto it : a){
        cout << it <<' ';
    }
    cout <<endl;
    stable_sort(a, a + n, cmp2);
    for(auto it : a){
        cout << it <<' ';
    }
    return 0;
}
*/


/*
bài 2: sắp xếp theo trị tuyệt đối.
cho mảng A[] và số nguyên dương X, bạn hãy sắp xếp các phần tử trong mảng theo yêu cầu sau:
- sắp xếp các phần tử trong mảng theo abs của hiệu của các phần tử này với X tăng dần (tính trị của A[i] với X ròi sắp 
tăng dần). nếu có 2 phần tử có cùng giá trị sắp xếp thì nào nhỏ hơn thì đứng trước 

- sắp xếp sao cho các phần tử là số chẵn đứng trước, các phần tử là số lẻ đứng sau, trong đó chẵn tăng dần, lẻ giảm dần
với 1 comparator duy nhất, không tách mảng.
*/

//truy cập vào biến toàn cục vd: int x thì cmp sẽ truy cập vào biến x đó để nó tính.

int x;

bool cmp1(int a, int b){
    if(abs(a - x) != abs(b - x)){
        return abs(a - x) < abs(b - x);
    }
    else{
        return a < b; // sắp xếp các phần tử cùng giá trị: nhỏ đứng trc sau đó mới tới lớn.
    }
}

/*int sc(int n){
    while(n){
        if(n % 2 == 0)
    n/=10;
    }
    return 0;
}

int sl(int n){
    while(n){
        if(n % 2 == 1)
        n/=10;
    }
    return 0;
}
*/

bool cmp2(int a, int b){
    int r = a%2; int R = b%2;
    if( r == 0 && R == 0){
        return r < R;
    }
    if( r == 1 && R == 1){
        return r > R;
    }
    if( r == 0 && R == 1){
        return true;
    return false;
    }
}

/*bool cmp2(int a, int b){
    if(sc(a) && sc(b)){
        return sc(a) < sc(b);
    }
    if(sl(a) && sl(b)){
        return sl(a) > sl(b);
    }
    if(sc(a) && sl(b)){
        return sc(a) > sl(b);
    }
    if(sl(a) && sc(b)){
        return sl(a) < sc(b);
    }
}
*/

int main(){
    int n;
    cin >> n >> x;
    int a[n];
    for( int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp1);
    for(int x : a){
        cout << x <<' ';
    }
    cout << endl;
    sort(a, a + n, cmp2);
    for(int x : a){
        cout << x <<' ';
    }
    return 0;
}
