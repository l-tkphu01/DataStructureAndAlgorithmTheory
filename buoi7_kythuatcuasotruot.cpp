/*
KI THUAT CUA SO TRUOT (phu thuoc vao kich thuoc cua con tro trai va phai)

- li thuyet: là ky thuat duoc su dung trong bai toan mang va chuoi, thuc hien bang cach ap dung 2 con tro.
- muc tieu: tim ra "cua so" tot nhat thoa man dieu kien de bai.

Mang con - (cua so).
- khai niem: cho mot mang, mang con la mot phan cua mang, sao cho cac phan tu van lien ke nhau va theo thu tu.

vd: mang 1 3 5 2 co cac cua so la:
ta se co cac nhom nhu sau:
1  1 3   1 3 5   1 3 5 2
3  3 5   3 5 2 
5  5 2 
2
- ket luan: trong bai hoc, su dung thuat ngu "cua so" thay cho "mang con".
PHUONG PHAP CAI DAT CUA SO TRUOT.
                                                    con tro 1(trai)
BUOC1: xác dinh con tro trai va con tro phai.    ví du:  |
                                                         1
                                                         |
                                                    con tro 2 (phai)
BUOC2: lap lai mang voi con tro phai de them cac phan tu vao cua so.
buoc3: trong vong lap, neu dieu kien bi pha vo, ta tang con tro trai.
rang buoc cua de bai: la tong cac phan tu cua cua so phai nho hon mot so k cho truoc nao do.
*/
//thuật toán cuaso_truot in ra phân đoạn liên tục của mảng arr.
/
#include <bits/stdc++.h>

using namespace std;
// vi du bai toan tren.
int cuaso_truot(vector<int>& arr){
	int n = arr.size(); //ví dụ: 4 6 8 4 2 
	//loop de chon diem bat dau.
	for(int i = 0; i < n; i++){
		//loop(vong lap) de chon diem ket thuc.
		for(int j = i; j < n; j++){
			/*
			Kiểm tra j < n (tức là 2 < 5, đúng)
			Thực hiện các câu lệnh trong vòng lặp
			Tăng j lên 3 (j++), tức là tăng j lên 1 đơn vị.
			i vẫn là 2
			j < n: tương tự với việc j chạy từ i tới n: 
			*/
		for(int k = i; k <= j; k++){
			cout << arr[k] <<" ";
		}
		cout << endl;
		}
	}
}
//giải thích chi tiết đoạn code trên:

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cuaso_truot(arr);
	return 0;
}
*/

/*
cho mang mot so nguyen duong nums va mot so nguyen k.

- tim do dai cua mang con dai nhat co tong <= k;
vd: k = 10
 nums = [1, 1, 4, 9, 3, 6, 6, 8]
 dau tien tao tro 2 con tro vao 1 thay thoa man ràng buot de bai
 dich con tro trai sang phai va cong tat ca lai. 
 
- do phuc tap cua ki thuat nay dung o muc tuyen tinh.
*/

int cuaso_truot(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0;
    int ans = 0;
    int sum = 0;
	int res = 0;
    for (int r = 0; r < arr.size(); r++) {
        sum += arr[r];
        while (sum > k){
        	sum -= arr[l];//loai bo phan tu l va dong thoi tang l len 1 don vi.
        	l++;
		}
		ans = max(ans, r - l + 1);
	}
	return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = cuaso_truot(arr, k);
    cout << result <<' ';
    return 0;
}

/*
cho mot chuoi nhi phan s.
chi co duy nhat 1 lan chuyen 0 thanh 1.
sau khi thuc hien viec chuyen, do dai cua chuoi con dai nhat chi chua 1 la bao nhiu.
*/
/*
int cuaso_truot(string s) {
    int n = s.size();
    int l = 0;
    int ans = 0;
    int cnt = 0;
    
    for(int r = 0; r < n; r++) {
        if (s[r] != '1') { 
            s[r] = '1';
            cnt = r - l;
            
            // Di chuyen l lên r voi muc dich de bat dau lai phan tu khac sau khi da duyet xong.
            l = r;
        } else {
            cnt++; // Tang cnt vì s[r] dã là '1'
        }
        //cap nhat gia tri lon nhat cua cnt.
        ans = max(ans, cnt);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int result = cuaso_truot(s);
    cout << result << endl;
    return 0;
}
*/
/*
Bai toan dem so luong mang con: 
cho mot mang so nguyen duong nums va mot so nguyen k. Hãy tra ve so luong mang con chua cac phan tu dc xep dung theo thu tu cua mang goc
trong do tich cua tat ca cac phan tu trong mang con nho hon k.
vd: k = 45
nums = [1, 6, 4, 5, 2]
*/

/*
int cuaso_truot(vector<int>& arr, int k){
	if(k <= 1){
		return 0;
	}
	int l = 0;
	int mult = 1;
	int cnt = 0; //dem cac phan tu trong cua so truot.
	for(int r = 0; r < arr.size(); r++){
		mult *= arr[r];
		while(mult >= k){
			mult /= arr[l];
			l++;
		}
		cnt += r - l + 1;
	}
	return cnt;
}

int main(){
	int n, k; cin >> n >> k; 
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int result = cuaso_truot(arr, k);
	cout << result <<" ";
	return 0;
}
*/


/*
*luu y: khi dung quy tac cua so truot khi su dung dung pp - or / bot di phan tu dau dua vao phep toan.
neu la +: thi ta su dung: sum -= arr[l]. l++;
neu la tich: thi ta su dung: mult += arr[l]. l++;
*/

/*
KÍCH THUOC CUA SO CO DINH.
(kh phu thuoc tro trai va phai - trai va phai cach nhau khoang co dinh or minh kh dung den 2 con tro do nua).
vd: 
cho mang so nguyen nums va so nguyen k. tính tong cua mang con có tong lon nhat co do dai la k.
   k = 4.
nums = [3, 6, 4, -5, 9, -1, 2] 
*/

/*
int cuaso_codinh(vector<int>& arr, int k){
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += arr[i];
	}
	int ans = sum;
	for(int i = k; i < arr.size(); i++){
		sum += arr[i] - arr[i - k];
		ans = max(ans, sum);
	}
	return ans;
}
	
int main(){
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int result = cuaso_codinh(arr, k);
	cout << result <<' ';
	return 0;
}
*/
/*
int cuaso_truot(vector<int>& arr){
	int n = arr.size();
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = i; k < j; k++){
				cout << arr[k] <<" ";
			}
			cout << endl;
		}
	}
}

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}	
	int result = cuaso_truot(arr);
	cout << result <<' ';
	return 0;
}
*/
/*
Sliding Windown.
cho mang cac so nguyen. hãy tìm dãy con k phan tu lien tiep co tong cac phan tu lon nhat.

vd: n = 7; k = 3
      | la vi tri (n - k)
4 3 1 2 8 6 de tinh cua so tu 3 1 2 dung cong thuc: 8 - 4 + 2.
*/
/*
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[1001];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long sum = 0; //khai bao kieu long long de tranh tran so.
		for(int i = 0; i < k; i++){
			sum += a[i];
		}
		long long res = sum, idx = 0; //idx: la chi so bat dau day con co tong lon nhat hien tai.
		for(int i = k; i < n; i++){ // i la cua so ket thuc cua cua so
			sum = sum - a[i - k] + a[i];
			if(sum > res){
				res = sum;
				idx = i - k + 1; // chi so bat dau cua cua so.
			}
		}
		cout << res << endl;
		for(int j = 0; j < k; j++){
			cout << a[idx + j] <<" ";
		}
		cout << endl;
	}
}
*/

//viết ra một mảng số nguyên n, tính tổng 2 số từ 1 tới n để tổng 2 số đó chia hết cho 3.

//sử dụng cửa sổ trượt để giải.

/*
int cuaso_codinh(vector<int>& arr){
	int n = arr.size();
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			sum = arr[i] + arr[j];
		}
	}
	cout << sum;
}

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int result = cuaso_codinh(arr);
	cout << result <<' ';
	return 0;
}
*/

/*
int cuaso_codinh(vector<int>& arr){
	int n = arr.size();
	int cnt = 0;
	int sum = 0;
    for(int i = 0; i < n; i++){ //khi i = 0 thì j chạy từ 1 đến 3, khi i = 1 j chạy từ 2 đến 3.
        for(int j < n; j++){
			sum = arr[i] + j = i + 1; arr[j];
			if(sum % 3 == 0){
				cnt++;
			}
        }
    }
	return cnt;
}
int main() {
    int n;
	cin >> n;
	vector<int>arr(n);
	for(int &x : arr) cin >> x;
	int result = cuaso_codinh(arr);
	cout << result <<" ";
    return 0;
}

*/

/*
int cuaso_truot(vector<int>& arr, int k){
	int n = arr.size();
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += arr[i];
	}
	int ans = sum;
	for(int i = k; i < arr.size(); i++){
		sum += arr[i] - arr[i - k];
		ans = max(ans, sum);
	}
	return ans;
}

int main(){
	int n 
}
*/
