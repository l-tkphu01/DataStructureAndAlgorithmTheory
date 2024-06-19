#include <bits/stdc++.h>

using namespace std;

/*
bai 1: Xau nhi phan ke tiep.
cho xau nhi phan X[], nhiem vu cua ban la hay dua ra sau nhi phan tiep theo cua X[]. Vi du
X[] = "010101" thi sau nhi phan tiep theo cua X[] la "010110".
*/
/*
void next(string s){
	int i = s.length() - 1; //boi vi i chay tu 0 --> n - 1.(s.length() - 1)
		while(i >= 0 && s[i] == '1'){ //'1' ki tu 1 k phai la so 1. 
		s[i] = '0'; //chuyen cac ki tu có s[i] = 1 thành = 0;
		--i; //sau do giam i
	}
	// doi voi buoi 5 hom truoc thi sau if(i == 0) thi ra sau cuoi cung.
	// i = -1 thi moi la sau cuoi cung.
	if(i != -1){
		s[i] = '1';
	}
	cout << s << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s; cin >> s;
		next(s);
	}
	return 0;
}
*/
/*
bai 2: tap con ke tiep. (dang bai sinh to hop chap k cua n).
Cho hai so N, K va mot tap con K phan tu X[] = {X1, X2,..., XK} cua 1, 2, .., N.
Nhiem vu cua ban la hay dua ra tap con K phan tu tiep theo cua X[]. Vi du N=5,
K=3, X[] = {2, 3, 4} thi tap con tiep theo cua X[] la {2, 3, 5}.
*/


int n, k, a[1005];
/*
//doi voi to hop chap k cua n thi ta bat dau tu bit cuoi cung truoc.
void next(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){ // n - k + 1: la gia tri max cuoi cung.	
		--i;
	}
	if( i == 0){
		for(int i = 1; i <= k; i++){
			cout << i << " ";
			//thuat toan tren la cho cau hinh cuoi cung va in ra cau hinh dau tien.
		}
	}
		else{
			a[i]++;
			for(int j  = i + 1; j <= k; j++){
				a[j] = a[j - 1] + 1;
			}
			for(int i = 1; i <= k; ++i){
				cout << a[i] <<" ";
			}
		}
	}
	
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= k; ++i) cin >> a[i];
		next();
	}
	return 0;
}

*/
/*
bai 3:
Cho so tu nhien N va mot hoan vi X[] cua 1, 2, .., N. Nhiem vu cua ban la dua ra 
hoan vi tiep theo cua X[]. Vi du N=5, X[] = {1, 2, 3, 4, 5} thi hoan vi tiep theo cua 
X[] la {1, 2, 3, 5, 4}.
*/

void next(){
	int i = n - 1;
	while( i >= 1&& a[i] > a[i + 1]){
		--i;
	}
	if(i == 0){// in ra cau hinh tu 1 --> n;
		for(int i = 1; i <= n; i++){
			cout << i <<' ';  
		}	
	}
	//trong truong hop i != 0 
	else{
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		// lat nguoc doan
		reverse(a + i + 1, a + n + 1); // a + n + 1 <=> a + n;
		for( int i = 1; i <= n; i++){
			cout << a[i] <<' ';
		}
	}	
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		next();
	}
	return 0;
}