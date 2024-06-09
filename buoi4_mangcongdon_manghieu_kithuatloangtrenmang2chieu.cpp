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
int main(){
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