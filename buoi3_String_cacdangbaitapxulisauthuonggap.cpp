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

int sc(int n){
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