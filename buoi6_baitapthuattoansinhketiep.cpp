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


//int n, k, a[1005];
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

/*
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
*/

/*
bai tap: lập trình chuyển số thập phân sang số nhị phân.

dùng hàm đệ quy để giải bài tập:

giới thiệu sơ lượt:  vòng lặp khác với vòng lặp while thì câu lệnh này sẽ thực thi trong câu lệnh stament ít nhất 1 lần
sau đó mới thực hiện lên câu lệnh while.
do...(while).

do{
		stament
}while (expresion); nếu điều kiện này đúng thì nó sẽ check câu lệnh <stament>, nếu câu lệnh này sai thì nó sẽ kh thực 
thi câu lệnh stament nữa.

*lưu ý: vòng lặp while sẽ kiểm tra điều kiện trước tiên sau đó ms thực thi khối lệnh, còn do...while sẽ thực thi 'do' 
đầu tiên sau đó mới ktra 'while'.

Sự hoạt động của vòng lặp:
Bước 1: thực hiện khối lệnh sau do.
Bước 2: kiểm tra giá trị của biểu thức <biểu thức> sau while, nếu có giá trị 'đúng' (khác 0) thì lặp lại bước 1, nếu 
sai or (=0) thì kết thúc vòng lặp.

ví dụ:
Viết chương trình hiện menu sau đây lên màn hình:
	- nhập số 0 để thoát.
	- nhập bất kì kí tự khác để tiếp tục.
*/

// int main(){
// 	int c;
// 	do{
// 		cout <<"--------"<<endl;
// 		cout << "MENU" << endl;
// 		cout << "nhap vao ki tu 0 de thoat" <<endl;
// 		cout << "nhap vao so bat ki != 0 de tiep tuc"<<endl;
// 		cin >> c;
// 	// xét kí tự thì mình phải để nó vào ngoặc đơn.
// 	} while (c != 0);
// }

//ví dụ câu lệnh yêu câu nhập 0 < n < 100.

/*
int main() {
    int n;
    cout << "nhap gia tri cua n";
	cin >> n;
    while (n <= 0 || n >= 100) {
        cout << "gia tri cua n kh nam tu 1 --> 99. vui long nhap lai: ";
        cin >> n;
    }

    cout << "Gia tri cua n nam trong khoang tu 1 den 99" << endl;

    return 0;
}
*/
/*
bai tap: lập trình chuyển số thập phân sang số nhị phân.

dùng hàm đệ quy để giải bài tập:
*/

/*
void printnhiphan(unsigned long long x){
	//trong ham de quy ta phai xác định được khi nào dừng lại và khi nào chúng ta tiếp tục.
	if(x == 0) return;
	else{
		int r = (x%2); // de lay phan du.
		//sau do goi ham printnhiphan.
		printnhiphan(x/2); //thuc hiên phep chia nguyen de lay so nguyen, gọi lại hàm printnhiphan de lap lai cach tinh tren
		cout << r;
	}
}

int main(){
	unsigned long long n;
	do{
		cout <<" nhap vao so thap phan de chuyen sang nhi phan: ";
		cin >> n;
	} while( n < 0);
	// khi điều kiện while (n < 0) kh đúng thì nó sẽ thực hiện nhiphan(n);
	printnhiphan(n); 
}
*/
// một cách code khác.

/*
long long nhiphan(int n){
		long long binarynumber = 0;
		int p = 0;
		while(n > 0){
			binarynumber += (n % 16) * pow(10, p);
			++p;
			n /= 16;
		}
		return binarynumber;
	}

int main(){
	int n; cin >> n;
	cout << nhiphan(n);
}
*/

//tương tự chuyển từ thập phân sang thập lục phân.

//chuyen nhi phan sang thap phan.
/*
int thapphan(long long binarynumber){
	int p = 0;
	int decNumber = 0;
	while(binarynumber > 0){
		decNumber += (binarynumber % 10)*  pow(2, p);
		++p;
		binarynumber /= 10;
	}
	return decNumber;
}

int main(){
	long long binarynumber;
	cin >> binarynumber;
	cout << thapphan(binarynumber);
	return 0;
} 
// tưởng tự như cách chuyển từ thập phân sang thập lục phân.
*/

//bai tap chuyen tu thap luc phan --> nhi phan.(cơ số 16 --> cơ số 2).

/*
int main(){
	//int kh có các số ABCDEF đâu.
	string n; cin >> n;  
	string check[16];
	check[0] ="0000";
	check[1] ="0001";
	check[2] ="0010";
	check[3] ="0011";
	check[4] ="0100";
	check[5] ="0101";
	check[6] ="0110";
	check[7] ="0111";
	check[8] ="1000";
	check[9] ="1001";
	check[10] ="1010";
	check[11] ="1011";
	check[12] ="1100";
	check[13] ="1101";
	check[14] ="1110";
	check[15] ="1111";
	for(int i = 0; i < n.length(); i++)
	{
		if(n[i] >= '0' && n[i] <= '9') cout << check[n[i] - '0'];
		else cout << check[n[i] - 'a' + 10];
	}
	return 0;
}
*/

//bai tap: chuyển từ hệ nhị phân sang hệ thập lục phân.
int main(){
	//int kh có các số ABCDEF đâu.
	string n; cin >> n;  
	string check[16];
	check[0] ="0000";
	check[1] ="0001";
	check[2] ="0010";
	check[3] ="0011";
	check[4] ="0100";
	check[5] ="0101";
	check[6] ="0110";
	check[7] ="0111";
	check[8] ="1000";
	check[9] ="1001";
	check[10] ="1010";
	check[11] ="1011";
	check[12] ="1100";
	check[13] ="1101";
	check[14] ="1110";
	check[15] ="1111";
	// nếu chia hết cho 4 thì ta không cần phải thêm con số 0 nào, còn nêu kh chia hết cho 4 thì phải thêm 0 vào.
	// 4 số ở hệ nhị phân thành 1 số ở hệ thập lục phân. 
	while(n.length() % 4 != 0){
		//thêm sô 0 ở đầu cua n.
		n = "0" + n;
	}
	for(int i = 0; i < n.length(); i = i + 4){
		string tem ="";
		tem += n[i];
		tem += n[i + 1];
		tem += n[i + 2];
		tem += n[i + 3];
		for(int j = 0; j <= 15; j++){
			if(tem == check[j]){
			if(j < 10) cout <<j;
			else cout <<(char)('a' + j - 10);
			}
		}
	}
	return 0;
}