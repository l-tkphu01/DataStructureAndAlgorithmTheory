/*
Kĩ thuật 2 con trỏ:
bài 1: trộn 2 dãy tăng dần thành 1 dãy tăng dần.
*/

#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int i = 0, j = 0;
    while( i < n && j < m){
        if(a[i] <= b[j]){
            cout << a[i] <<' '; ++i;
        }
        else{
            cout << b[j] <<' '; j++;
        }
    }
    //check xem thk nào còn phần tử cuối cùng hay không.
    while(i < n){
        cout << a[i] <<' '; i++;
    }
    while(j < m){
        cout << b[j] <<' '; j++;
    }
    return 0;
}

/*
bài 2: Số lượng nhỏ hơn.

*/