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

/*thuật toán sắp xếp vun đống (Heap sort).
cây nhị phân: lá cuối cùng lúc nào cũng nghiên về bên trái thì mới điền đủ.
+ cấu trúc dữ liệu heap:
- heap là một cây nhị phân hoàn chỉnh
- nốt ở gốc lúc nào cũng lớn hơn gốc ở nốt con bên trái và bên phải, trường hợp nốt cha lớn hơn các nốt con của nó ta có
Max_Heap, ngược lại nếu nốt cha nhỏ hơn 2 nốt con của nó ta có Min_Heap.

- Heapify: thao tác heapify với nốt có chỉ số i trong mảng.
- Để gọi hàm heapify có n phần tử ta sử dụng công thức: n/2 - 1 = ... sau đó heapify ngược lại từng phần tử và thực hiện
theo thuật toán.
- để sắp xếp các phần tử sau khi đã heapify lại với nhau ta hoán đổi vị trí (largest) với phần tử cuối cùng và đồng thời
loại bỏ phần tử cuối tiếp tục heapify phần tử đầu dãy với phần tử cúi lớn nhất --> dãy đã đc sắp xếp.
*/

void heapify(int a[], int n, int i){
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && a[l] > a[largest])
    largest = l;

  if(r < n && a[r] > a[largest])
    largest = r;

  if(largest != i){ //chỉ số lớn nhất i khác i (max: ban đầu) cập nhật swap để đổi chỗ phần tử lớn hơn và nhỏ hơn.
    swap(a[i], a[largest]);
    heapify(a, n, largest); //duy trì tính chất heap trong nhóm con để đệ quy duyệt tất cả các phần tử con bên dưới.
  }
}

  //thuật toán heapsort.
  void heap(int a[], int n){
    //xay dung max heap
    for(int i = n/2 - 1; i >= 0; i--){
      heapify(a, n, i);
    }
    //
    for( int i = n - 1; i >= 0; i--){
      swap(a[i], a[0]);
      heapify(a, i, 0); //*lưu ý: nếu cập nhật heapify(a, n, 0) thì nó sẽ trở về ban đầu kh sắp xếp đâu.
    }
  }


int main()
{
  //để random số lớn hơn.
  int n = 100;
  int a[1000];
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    a[i] = rand() % 500;
  }
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //int a[1000], n;
    //cin >> n;
/*    int m = INT_MIN; //kiểu dữ liệu INT_MIN sử dụng với kiểu khai báo int. tương tự sử dụng LLONG_MAX, LLONG_MIN trong 
kiểu khai báo long long.
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

//for(int i = 0; i < n; i++){
  //cin >> a[i];
//}
//quicksort(a, 0, n - 1);
heap(a, n);
for(int i = 0; i < n; i++){
  cout << a[i] <<" ";
}
return 0;
}



#include <bits/stdc++.h>
#include <algorithm>

//using ll = long long;
using namespace std;
/*sort(v.begin(), v.end())
++n: tăng n lên 1 và đồng thời gán m = n;
n++: gán m = n trước và tăng n lên 1.
sort kh áp dụng được vs set, map vì chúng đã có thứ tự ròi.
using namespace std;

nếu sort trên vector.
sort(a.begin() + x, a.end() + y + 1);
*/

//hàm so sánh: comparator.
int tong(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n/= 10;
    }
    return ans;
}
bool cmp(int a, int b){
    if(tong(a) != tong(b)) //kh quan tâm đến tiêu chí chúng khác nhau.
        return tong(a) < tong(b);// sẽ sắp xếp tổng tăng dần.
    //nếu 2 chúng nó bằng nhau.
    else
        return a > b;
    //trị tuyệt đối tăng dần return abs(a) < abs(b);
    return 0;
    //*lưu ý: nếu sắp xếp sinh viên theo thứ tự gpa, thì những sinh viên có gpa bằng nhau sẽ yêu cầu sắp theo tên.
    //lớp gì đó.
    //nếu các số có cùng tổng chữ số, thì sắp xếp cho số lớn hơn đứng trước
}

int main(){
    //độ phức tạp của thuật toán kh thay đổi. o(logn)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n]; //nếu kh cho khai báo a[n] thì cho khai báo theo a cố định a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp); // sắp xếp theo hàm yêu cầu.
    //sort(a + 2, a + n - 2, greater<int>()); //O(NlogN) = intro sort : kết hợp 2 thằng quick sort + heap sort.
    //nếu rơi vào trường hợp tệ nhất của quicksort thì tự chuyển qua heap sort
    for(int x : a){
        cout << x <<" ";
    }
    return 0;
}


/*
NỘI DUNG.
/01. Tìm kiếm tuyến tính(Linear search).
/02. Tìm kiếm nhị phân(Binary search).
/03. Vị trí đầu tiên trong mảng tăng dần.
/04. Vị trí cuối cùng trong mảng tăng dần.
/05. Vị trí đầu tiên lớn hơn hoặc bằng X trong mảng tăng dần.
/06. Vị trí cuối cùng lớn hơn hoặc bằng X trong mảng tăng dần.

CÁCH DÙNG: LOWER_BOUND  /  UPPER_BOUND. 
1. Tìm kiếm tuyến tính (Linear Search): độ phức tạp: 0(N).
- Thuật toán tìm kiếm tuyến tính: 
+ Ý tưởng: Duyệt tuần tự các phần tử trong mảng và so sánh giá trị cần tìm với từng phần tử trong mảng.

+ Áp dụng cho một số bài toán sau: các bài toán như tìm kiếm vị trí đầu tiên, cuối cùng, đếm số lần xuất hiện của phần
tử trong mảng đều là biến đổi của thuật toán tìm kiếm tuyến tính 
+ có thể áp dụng với mảng bất kì không cần sắp xếp gì hết.
*/

//code:
#include <bits/stdc++.h>

using namespace std;

bool ls(int a[], int n, int x){
  for(int i = 0; i < n; i++){
    if(x == a[i]){
      return true;
    }
  }
  return false;
}

/*
1. tìm kiếm nhị phân (binary Search): độ phức tạp O(logN).
- Thuật toán tìm kiếm nhị phân:
+ ý tưởng: tìm kiếm trong đoạn từ [left, right] của mảng, ở mỗi bước thuật toán tìm vị trí middle ở giữa đoạn left, right
nếu phần tử cần tìm kiếm bằng phần tử ở vị trí middle thì kết luận là tìm thấy, nếu kh ta có thể giảm một nữa đoạn tìm 
kiếm xuống và tiếp tục tìm bên trái hay bên phải của middle.

+ đây là một thuật toán cực kì hiệu quả và quan trọng, khi học lập trình bạn cần nắm rõ thuật toán này.

*lưu ý: mảng phải được sắp xếp giảm dần hoặc tăng dần thì mới sử dụng được.

- giải thích thuật toán:
mid = (r - l)/2 =.... và + thêm một đơn vị. (đặt số ban đầu là 0).

*/


//code:

bool bs(int a[], int n, int x){
  int l = 0, r = n - 1;
  while(l <= r){
    int mid = (l + r)/2;
    if(a[mid] == x){
      return true;
    }
    else if(a[mid] < x){
      // tìm kiếm ở bên trái.
      l = mid + 1;
    }
    else{
      //tìm kiếm ở bên phải.
      r = mid - 1;
    }
  }
  return false;
}

// hàm tìm kiếm đệ quy.
bool binary_search(int a[], int l, int r, int x) {
    if (l > r)
        return false;
    int m = (l + r) / 2;
    if (a[m] == x)
        return true;
    else if (a[m] < x)
        return binary_search(a, m + 1, r, x);//nhớ phải có tham số trong hàm đệ quy.
    else
        return binary_search(a, l, m - 1, x);
}
//binary_search(a + x, a + y, key) => a[x] => a[y - 1]
//binary_search(a + 1, a + 4, key) => với a[x] là chỉ số bắt đầu và a[y - 1] là chỉ số kết thúc.
//binary_search(v.begin(), v.end(), key)
//binary_search(v.begin() + x, v.begin() + y, key) => v[x] => v[y - 1]
int main(){
  int n, x; cin >> n >> x;
  int a[n];
  //nếu sử dụng vector.
  //vector <int> v(n);
  //for(int i = 0; i < n; i++){
  // cin >> v[i];
  //}
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  //nếu mảng chưa được sắp xếp thì sử dụng linear_search.
  if(bs(a, n, x))
  //if(ls(a, n, x))
  //nếu bằng đệ quy.
  //if(binary_search(a, 0, n - 1, x))
  // nếu sử dụng vector.
  //if(binary_search(v.begin(), v.end(), x))
      cout << "FOUND!\n";
  else
      cout << "NOT FOUND\n";
  return 0;
}
/*
3. vị trí đầu tiên của phần tử X trong mảng đã được sắp xếp.
*/

//code:









