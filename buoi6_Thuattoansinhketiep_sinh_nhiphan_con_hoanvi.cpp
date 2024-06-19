#include <bits/stdc++.h>

using namespace std;
/*
Gom có 4 bài toán chính: sinh xâu nhi phân, sinh con, sinh hoán vi, phân ho?ch.
sinh sâu nhi phân có do dai n:

vidu: n = 3.
       000
       001
       010
       100
       101
       110
       111

- cau hinh xay dung dau tien: lúc nào cung nbit = 0
- cau hinh cuoi cung: nbit = 1
- phuong pháp sinh: la cong 2 so nhi phan lai voi nhau: 0001110 + 1 = 

buoc 1:
<ktao cau hinh dau tien>
-buoc lap:
while(<khi chua phai cau hinh cuoi cung>){
	<in ra cau hinh hien tai> bit 0 : 000
	<sinh ra cau hinh tiep theo> (su dung thuat toan sinh) (pp sinh se bi trung trong toan).
}
*/
int n, a[100], ok, cnt; //ok: dung de check xem nó có phai la cau hinh cuoi cung hay chua. 

//viet mot cau hinh khoi tao de sinh ra cau hinh dau tien.
//nhiem vu cua no(xet tat ca cac bit tu 1 --> n cua cau hinh nhi phan hien tai thanh bit 0.
/*
1.
void ktao(){
	for(int i = 1; i <= n; i++){ //n chi luu tu bit 1 --> n;
		a[i] = 0;
	}	
}
*/

void ktao(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}


/*
1.
void sinh(){
	//bat dau tu bit cuoi cung và di tim bit  0 dau tien
	int i = n;
	while(i >= 1 && a[i] == 1){ // i >= 1: dam bao duyet tu bit 1 den bit n thoi
		a[i] = 0;
		--i;
	}
	if(i == 0){
		ok = 0;//ta se biet dc tai i == 0 thi ok = 0. thi no ket thuc. (cau hinh cuoi cung).
	}
	else{
		a[i] = 1;
	}
}
*/

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        --i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i]++;
        for(int j = i + 1; j <= k; ++j){
            a[j] = a[j - 1] + 1;
        }
    }
}

/*
check xem sau nhi phan hien tai ma ban co, co kbit 1 hay kh.
bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += a[i];
	}
	return cnt == k;
}
*/

/*
int main(){
	cin >> n;
	ok = 1;
	ktao();
	while(ok){// khi nào mà bien ok = 1 thi chua phai la cau hinh cuoi cung.
		for(int i = 1; i <= n; i++){
			cout << a[i];
		}
//		if(check()){
//			for(int i = 1; i <= n; i++){
//				cout << a[i];
//			}
	cout << endl;
//	}
		sinh();
	}
	return 0;
}
*/
// vi du: mot so bai toan: in ra k bit 1, k bit 1 lien ke, nhieu nhat k bit 1. thuc chat van la bai toan sinh nhi phan
/*
bai3: sinh ra cac to hop chap k cua n.
*/

int main(){
    cin >> n >> k;
    ok = 1;
    ktao();
    while(ok){
        for(int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        sinh();
    }
    return 0;
}

/*
baitap: Sinh hoán vi cua n phan tu:
ghi nho: a[i] < a[i + 1]
*/
/*
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
		--i; 	
	}
	if(i == 0){
		ok = 0; //cau hinh cuoi cung;
	}
	else{
		//di tim thang > a[i] trong doan [i + 1, n];
		int j = n;
		while(a[i] > a[j]) --j; //neu dieu kien a[i] < a[j] thì tien hanh hoan doi.
			swap(a[i], a[j]);
			//lat nguoc i + 1 den n tai bay h chung no dang nguoc
			int l = i + 1, r = n;
			while(l < r){
				swap(a[l], a[r]);
				++l; --r;
			}
			//ham lat nguoc trong c++
			reverse(a + i + 1, a + n + 1); //can n + 1 k lay cho nen a + n + 1 = a + n.	
		}
	}

next_permutation(a, a + n) : luu cau hinh ra mot cai mang, vector, string cung duoc sau do goi next.. in ra cau hinh tiep theo.
int main(){
	cin >> n; 
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= n; i++){
			cout << a[i];
		}
	cout <<endl;
	sinh();
}
return 0;
}

/*
cách 2: next_permutation(a, a + n)
int n; cin >> n;
int a[n];
for(int i = 0; i < n; i++){
	a[i] = i + 1;
}
	//goi ham next_permutation(a, a + n): sinh ra hoán vi ke tiep tu hoan vi hien tai duoc luu trong mang a cua ban.
	do{
		for(int i = 0; i < n; i++){
			cout << a[i];
		}
		cout << endl;
	} while(next_permutation(a, a + n)); //sinh ra cau hinh tiep theo neu sinh ra cau hinh cuoi cung thi lap tuc no se return false.
	//thi vong lap do while se ket thuc.
	return 0;
}
*/

//cach 3: ham prev_permutation(a, a + n)
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) a[i] = n - i; //54321
	do{
		for(int i = 0; i < n; i++){
			cout << a[i];
		}
		cout << endl;
	}while(prev_permutation(a, a + n));
	return 0;
}

//co the luu cho vector cung duoc.

//vi du: 
int main(){
	string s = "abcdef";
	next_permutation(s.begin(), s.end());
	cout << s << endl;
	return 0;
}

/*
Sinh phan hoach nguyên cua cac so tu nhien n (cach phan tich n duoi dang tung cac so tu nhien kh vuot qua n).
*/

void ktao(){
    cnt = 1;
    a[1] = n;
}

void sinh(){
    int i = cnt;
    while(i >= 1 && a[i] == 1){
        --i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        if(q){
            for(int j = 1; j <= q; j++){
                ++cnt;
                a[cnt] = a[i];
            }
        }
        if(r){
            ++cnt; 
            a[cnt] = r;
        }
    }
}

int main(){
    cin >> n;
    ktao();
    ok = 1;
    while(ok){
        for(int i = 1; i <= cnt; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        sinh();
    }
    return 0;
}
