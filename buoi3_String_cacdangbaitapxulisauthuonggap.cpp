#include <bits/stdc++.h>

using namespace std;

/* int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      int a; cin >> a;
      v.push_back(a);
    } else if (v.empty() == false) {
      v.pop_back();
    }
  }
    if(v.empty())
        cout << "EMPTY" <<" ";
        else{
        for(int x : v) cout << x <<" ";
        }
   return 0;
}
*/

/*
Một cách khác:
pair <int, int> p = make_pair(10, 20);//khai báo 2 phần tử phần thứ nhất là first, thứ 2: second.
pair <int, int> p = {10, 20}; //c++ 11
// pair<char, char> p;
// pair<int, long> p;
// pair<int, int > p1 = p;
// cout << p1.first <<" "<< p1.second << endl;
cout << p.first <<' '<<p.second << endl;
int n; cin >> n;
pair<int, int > a[n]; //cho n cố định cũng được.
for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
}
vector<pair<int, int >> v;
pair<int, pair<int, int >> v; //trong trường hợp first là một int còn second là 2 kiểu dữ liệu khác
p.first = 10;
p.second.first = 20;
p.second.second = 30; //tương tự như cặp lồng nhau {10, {20, 30}}
pair<int, vector<int>> p;
*/


/*
Lý thuyết: se
set: tính chất là một cấu trúc dữ liệu kiểu cây (set: nó cũng có iterator).
set = {0, 2, 3, 5, 8} gồm có se.begin() là 0 và se.end( là sau số 8)
vẫn có cấu trúc là vector (sài mọi thứ của vector được).
hàm insert
- k thể lưu 2 phần tử giống nhau.
- được sắp xếp theo thứ tự tăng dần na ná như dùng vector.
set<int> se;
se.insert(2);// check xem có 2 chưa nó mới cho vào.
se.insert(3);
se.insert(1);
se.insert(2);
se.insert(0);
se.insert(3);
se.insert(4);
cout << se.size() << endl;
for(int x : se){
    cout << x <<" ";
}
cout << endl;
for(auto it = se.begin(); it != se.end(); i++){
    cout << *it <<" ";
}
cout << endl;
auto it = se.begin();
++it; //dùng đc.
it += 1; // k dùng đc.
// ta có thể duyệt set theo thứ tự ngược cũng được.
for(auto it  = se.rbegin(); it != se.rend(); it++){ //iterator ngược nên là nó it++.
    cout << *it << endl; // duyệt từ cuối tới trước.
}
for( int i = se.size() - 1; i >= 0; --i){
    cout << i <<" ";
} // duyệt từ cuối --> đầu 
return 0;
}
*/

/*
Bài tập: đếm số lượng phần tử khác nhau trong mảng.
int n; cin >> n; 
multiset<int> se;
while(n--){ //vòng lặp while.
    int x; cin >> x;
    se.insert(x);
}
for(int x : se) cout << x <<" ";
*/


/*
Hàm find tìm kiếm phần tử trong mảng.
 int a; cin >> a;
 auto it = se.find(a);
 if(se.find(a) != se.end()){
     cout << "FOUND\n";
 }
 else{
     cout << "NOT FOUND\n";
 }
*/

/*
Hàm erase: //xóa 1 phần tử trong mảng set but k có phần tử xóa thì sẽ lỗi.
 se.erase(it);
 for( int x : se) cout << x <<" ";
 return 0;
auto it = se.find(2); //trả về số 2 vị trí đầu tiên.
 cout << *it << endl;
Tìm khoảng cách thứ mấy(dùng hàm distance).
 cout << distance(se.begin(), it) << endl;
}
*/

/*
Hàm count;
se.erase(it);
for (int x : se)
cout << x << endl;// để xóa 1 số trong hàng đống số dống.
}
*/


/*
Hàm multiset: tương tự như set nhưng có thể lưu nhiều phần tử có giá trị giống nhau, các phần tử này cũng đc sắp xếp 
theo thứ tự tăng dần. các hàm của multiset dống i hệt các hàm của set chỉ khác một chút ở hàm find, count, erase.
- hàm này kh bỏ các phần tử trùng lặp nhau nhưng vẫn sắp xếp một các tăng dần.
*/

