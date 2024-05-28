//lí thuyết:
/*cau truc du lieu va giai thuat
nội dung học: 
1. C++ STL.
-set, map, string, vector, pair, auto,...
-sort, comparator, binary search, linear search.
-mảng cộng dồn, mảng hiệu, sàng số nguyên tố, hai con trỏ, cửa sổ trượt...


#include <bits/stdc++.h>

using namespace std;
// foreach : Range base for loop (c++ 11) tro len.
//push_back: day vao sau.
int main(){
	// vector luu tru mot so dang thuong gap nhu sau: int, string, pair, class, struct, vector, set,....
//	vector<int> v;
//	vector<long long> v;
//	vector<char> v;
//	vector<pair<int, int>>v;
//vector<int> v(10);a
// neu khai bao theo kieu 
vector<int> v(3, 100); //(100, 100, 100)
v.push_back(3);
v.push_back(2);
v.push_back(1);
v.push_back(5);
//////cout << v.size() << endl;
//////for(int i = 0; i < v.size(); i++){
//////	cout << v[i] <<" "; //se in ra het luon.
//////	}
//////	cout << endl;
////	//neu muon duyet tu cuoi ve.
////	for(int i = v.size() - 1; i >=0; i--){
////		cout << v[i] <<" ";
////}
//int a[5] = {3, 1, 2, 4, 5};
//for(int &x : a){
//cout << x <<" ";	
//return 0;
//// mot kien thuc lien quan den iterator
//}

/* thuat toan: iterator duoc coi la mot con tro thong minh, cac ban co the hieu don gian iterator la mot con tro tro den phan tu trong vector, tuc la thong qua iterator ban co the truy cap, thay doi phan tu ma nó dang quan li
begin(): iter den phan tu dau tien.
end(): iter den phan tu sau phan tu cuoi.
rbegin(): iter den phan tu cuoi trong vector.
rend(): iter den phan tu trc phan tu dau tien.
*/
//vector<int>::iterator it = v.begin();//:: toán tu pham vi 
//it dang tro den phan tu dau tien trong mang.
// kh dc in ra cout << it << endl;
//cout << *it << endl; //* giai tham chiu.
//++it; //nhay sang 1 ô.
//it += 2;// tro den thk 3
//--it;
//cout << *it << endl;
//for(it = v.begin(); it != v.end(); it++){
//	cout <<*it <<" ";
//	}
//*neu phan tu có gia tri la x : v.begin + x;
// vector<int>::iterator it = v.begin() + 4; //có the su dung auto it : v.begin();
// cout << *it << endl;
/*các hàm pho bien trong vector
hàm size: tra ve so luong phan tu trong vector
hàm clear: xóa toan bo cac phan tu trong vector
ham empty: tra ve true neu vector rong, nguoc lai tra ve false
ham insert:
- chuc nang: them 1 phan tu vao vi tri bat ki trong vector thong qua itertor.
- cú pháp: insert(vi tri iterator, val) 0(n).
cách code:

vector<int> v;
for( int i = 1; i <= 5; i++){
   v.push_back(i);
   }
   for(int i = 0; i < v.size(); i++){
   cout << v[i] <<" ";
   }
   v.insert( v.begin() + 2, 100);// thêm vào v? trí thu 2.
   v.erase(v.bgein() + 4);
   or v.pop_back(); neu muon xoa chu so hang cuoi cung.
   hàm assign: gán các phan tu trong vector voi cung 1 gia tri
   . cú phap: assign(so phan tu, val).
   v.assign(5, 100); 
   ham resize.
   - chuc nang: thay doi kich thuoc cua vector.
   . cú phap: resize(n).
   cách code:
   vector<int> v;
   v.assign(5, 28);
   for( int x : v) cout << x <<' ';
   cout << endl;
   v.resize(3);
   for(int x : v) cout << x <<' ';
   } 
   for(int x : v){
   cout << x << endl;
   }
*/
//auto it = v.begin;
//auto x = 100; //int.
//auto y = '0'; //char.
//auto z; //loi.
// for(auto x : v){
//    cout << x <<' ';
//}