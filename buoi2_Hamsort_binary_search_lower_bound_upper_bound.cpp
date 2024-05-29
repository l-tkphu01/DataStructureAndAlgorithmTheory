#include <bits/stdc++.h>
#include <algorithm>


/*thuật toán sắp xếp chọn.(selection sort): đưa phần tử nhỏ nhất chưa được sắp xếp về với đầu dãy, để sắp xếp dãy có n
phần tử cần thực
hiện n - 1 bước.
độ phức tạp thuật toán là: o(n^2)
*/

// using ll = long long;
using namespace std;
// thuật toán sắp xếp chọn.(selectionsort).
void selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { // bởi vì nó chỉ được thực hiện từ n --> n-1 bước thoi
        // dung 1 biên để lưu trữ phần tử nhỏ nhất
        int min_pos = i;
        // duyệt tất cả các phần tử đứng sau phần tử hiện tại và cập nhật chỉ số của phần tử nhỏ nhất.
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}


/*
thuật toán sắp xếp nổi bot.(bubble sort)
cách sử dụng: so sánh 2 phần tử liền kề với nhau, nếu 2 phần tử với nhau là 1 cặp nghịch thế. nghĩa là phần tử đứng
phải lớn hơn phần tử đứng sau thì sẽ "swap" luôn 2 phần tử đó và đưa về cuối dãy luôn
độ phức tạp: 0(n^2).
*/
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {                                       // sau đó duyệt từ đầu dãy đến vị trí cuối cùng trừ đi 1.
        for(int j = 0; j < n - i - 1; j++) // n - i - 1: là chỉ số chưa được sắp xếp cuối cùng.
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

/*thuật toán sắp xếp chèn(insertionsort)(array) (thuật toán sắp xếp bài).
cách sử dụng: đưa phần tử ở vị trí hiện tại về đúng vị trí(trong đó các phần tử đứng trước phần tử ht đều đã được sắp r)
*/
void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // phần tử đầu tiên đã sắp xếp r thì chắc người ta kh chèn.
        //  lấy ra phần tử ở chỉ số i
        int x = a[i], pos = i - 1;     // pos là biến chỉ vị trí (tìm vị trí cho thằng "x" và chèn thằng x vào.)
        while (pos >= 0 && x < a[pos]) // có "=" dùm t cái..............................
        {                              // điều kiện 1: chặn trường hợp chỉ số pos ra bên ngoài mảng(luôn xét chỉ số bên trong)
            a[pos + 1] = a[pos];       // dịch phần tử pos sang bên phải.
            --pos;                     // sau khi thực hiện xong sẽ thk pos xuống 1 đơn vị để xét TH tiếp theo
        }                              // điều kiện để dừng vòng lặp là x > a[pos].
        a[pos + 1] = x;
    }
}

/*giả sử mảng của bạn được sắp xếp như thế này "1 2 5 8 10 4 9"
thuật toán sắp xếp đếm phân phối(counting sort).
cách dùng : đếm xem mỗi phần tử sắp xếp của bạn xuất hiện bao nhiêu lần, sau đó duyệt từ phần tử nhỏ nhất đến phần tử
lớn nhất
nhược điểm: it can't sắp xếp phần tử âm hoặc phần tử quá lớn, bởi vì nó sử dụng mảng để nó đếm phân phối.
đk: chỉ áp dụng cho những số không âm và có giới hạn 10^7 a[10^7 + 1]thoi. lớn quá thì tràn bộ nhớ.
chỉ áp dụng mảng từ 0 <= ai <= 10^7 còn các thuật toán khác áp dụng mảng nào cũng được.
*/

// cách chia:

void swap(int a[1000], int x, int y){
  int temp = a[x];
  a[x] = a[y];
  a[y] = temp;
}
int partition(int a[1000], int l, int r){
  int pivot = a[l]; //giá trị đầu tiên

  int count = 0;
  // dem so luong phan tu nam ben trai pivot
  for(int i = l + 1; i <= r; i++){
    if(a[i] <= pivot)
        count++;
  }
  // lay vi tri cho gia tri pivot
  int pivotIndex = l + count;

  // hoan vi
  swap(a, l, pivotIndex);
  int i = l;
  int j = r;
  
  while(i < pivotIndex && j > pivotIndex){
    while(a[i] <= pivot){
      i++;
    }
    while(a[j] > pivot){
      j--;
    }
    if(i < pivotIndex && j > pivotIndex){
      swap(a, i, j);
    }
  }
  return pivotIndex;
}
void quicksort(int a[1000], int l, int r){
  //nếu l > r kh còn phần tử nào để xử lí mà l < r thì ms xử lí đc.
  if(l >= r){
    return; //kh còn gì để sắp xếp.
  }
  //chia
  int pivot = partition(a, l, r); //chia phân vùng nhỏ.
  //trị:
  //sắp xếp dãy bên trái
  quicksort(a, l, pivot - 1);
  //sắp xếp dãy bên phải
  quicksort(a, pivot + 1, r);
}
int cnt[10000001];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[1000], n;
    cin >> n;
/*    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        m = max(m, a[i]); // để tìm phần tử lớn nhất trong mảng.
    }
    selectionsort(a, n);
    bubblesort(a, n);
    insertionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i <= m; i++)
    {
        if(cnt[i] != 0){
            for(int j = 0; j < cnt[i]; j++){
                cout << i <<" ";
            }
        }
    }
    return 0;
} // nếu muốn sắp xếp theo một cách giảm dần ta chỉ cần sửa ">" => thành "<" là xong.
*/

/*
thuật toán sắp xếp Quick sort.
ý tưởng:
chia: 
+ chọn 1 phần tử làm phần tử chốt(pivot)
+ chia dãy thành 2 dãy con.
  -dãy bên trái: những phần tử nhỏ hơn phần tử chốt.
  -dãy bên phải: những phần tử lớn hơn phần tử chốt
trị:
  -đối với từng dãy con ta gọi đệ quy để sắp xếp từng dãy con đó.

+ tổng hợp dãy:
[dãy bên trái, pivot, dãy bên phải].

cách chọn pivot: 
- first
- last
- middle
- random

vd: 15 12 16 13 11 17.
chọn 15.
- nhỏ: 12 13 11 lấy 12 pivot  có nhỏ: 11 và lớn: 13 và gọi quick sort để sắp xếp gọp lại là 11 - 12 - 13.
- lớn: 16 17 lấy 16: pivot có lớn: 17 sau đó sort
(vs 2 dãy con trên chúng ta sẽ sort)
- nếu giảm dần chỉ cần đổi dấu và làm ngược lại vấn đề đó lại.
*/

for(int i = 0; i < n; i++){
  cin >> a[i];
}
quicksort(a, 0, n - 1);
for(int i = 0; i < n; i++){
  cout << a[i] << endl;
}
return 0;
}




// #include <bits/stdc++.h>
// #include <algorithm>

// //using ll = long long;
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; cin >> n;
//     int a[n]; //nếu kh cho khai báo a[n] thì cho khai báo theo a cố định a[100];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a, a + n); //O(NlogN) = intro sort : kết hợp 2 thằng quick sort + heap sort.
//     for(int x : a){
//         cout << x <<" ";
//     }
// }


