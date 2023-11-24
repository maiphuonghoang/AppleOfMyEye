#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define nhap_mang for(int &x : a) cin >> x
#define input(a) for(int &x : a) cin >> x
#define xuat_mang for(int x : a) cout << x << " "
using ll = long long;
using namespace std;

/** Thuật toán đổi chỗ trực tiếp O(n^2)
4
5 7 3 2 
=>
Buoc 1: 2 7 5 3 
Buoc 2: 2 3 7 5
Buoc 3: 2 3 5 7

i j
5 7 3 2
3 7 5 2
  i j
2 7 5 3
2 5 7 3 
    i j
2 3 7 5
2 3 5 7
*/
void run1(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j <n; j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);          
        }
        cout << "Buoc " << i + 1 << ": "; 
        xuat_mang; el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp chọn O(n^2)
4
5 7 3 2
=> 
Buoc 1: 2 7 3 5 
Buoc 2: 2 3 7 5
Buoc 3: 2 3 5 7

2 5 7 3 min=2
2 | 7 3 5
2   3 7 5 min = 3
2 3 | 5 7 min = 5
*/
void run2(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n - 1; i++){
        int min_pos = i;
        for(int j = i+1; j <n; j++){
            if(a[j] < a[min_pos])
                min_pos = j;    
        }
        swap(a[i], a[min_pos]);
        cout << "Buoc " << i + 1 << ": "; 
        xuat_mang; el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp chèn O(n^2)
4
5 7 3 2
=> 
Buoc 0: 5 
Buoc 1: 5 7
Buoc 2: 3 5 7
Buoc 3: 2 3 5 7

5 | 7 3 2
5 7 | 3 2
3 5 7 | 2
2 3 5 7 |
*/
void run3(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n; i++){
        int x = a[i], pos = i-1;
        while(pos >= 0 && a[pos] > x){
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
        cout << "Buoc " << i << ": "; 
        for(int j=0; j<=i; j++)
            cout << a[j] << " ";
        el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp nổi bọt O(n^2)
4
5 3 2 7
=> 
Buoc 1: 3 2 5 7 
Buoc 2: 2 3 5 7
*/
void run4(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n - 1; i++){
        bool ok = false;
        for(int j = 0; j <n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);   
                ok = true;
            }
        }
        if(ok){
            cout << "Buoc " << i + 1 << ": "; 
            xuat_mang; el;
        }else break;   
    }
}
//----------------------------------------------------------------
/**Tìm kiếm nhị phân 
5 3
1 2 3 4 5
1
=> YES 
*/
bool binarySearch(int a[], int n, int x){
    int l = 0, r = n-1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) return true;
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
void run5(){
    int n, x; cin >> n >> x;
    int a[n];
    nhap_mang;
    binarySearch(a, n, x) ? yes : no;
}
//----------------------------------------------------------------
/** Vị trí đầu tiên, cuối cùng 
 * Cho mảng số nguyên đã được sắp xếp tăng dần và số nguyên x. 
 * Tìm vị trí xuất hiện đầu tiên của x trong mảng 
2
5 3
1 2 3 3 3
5 4
1 1 2 5 6 
=> 3 5
   -1 -1 

*/
int dautien(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            r = m - 1;//****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
int cuoicung(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            l = m + 1;//*****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;    
}
void run6(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int a[n];
        nhap_mang;
        cout << dautien(a, n, x) << " ";
        cout << cuoicung(a, n, x) << " ";
        el;
    }
}
//----------------------------------------------------------------
/**Đếm số lần xuất hiện của phần tử trong mảng sắp xếp 
 * Vị trí cuối cùng - vị trí đầu tiên + 1
2
5 3
1 2 3 3 3
5 4 
1 1 2 5 6
=> 3 0 
*/
void run7(){
    int t; cin >> t;
        while(t--){
            int n, x; cin >> n >> x;
            int a[n];
            nhap_mang;
            int i = dautien(a, n, x);
            int j =  cuoicung(a, n, x);
            if(i != -1)
                cout << j - i + 1 << endl;
            else
                cout << 0 << endl;
        }    
}
//----------------------------------------------------------------
/** Quick sort - Phân hoạch Lomuto 
8
8 7 2 1 5 3 6 4
=> 2 1 3 [4] 5 8 6 7
*/
void partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l-1;
    for (int j=l; j <r; j++){
        if(a[j] < pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[++i], a[r]);

    for(int j=l; j<=r; j++){
        if(i==j)
            cout << "[" << a[j] << "] ";
        else 
            cout << a[j] << " ";
    }
}
void run8(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    partition(a, 0, n-1);
}
//----------------------------------------------------------------
/** Merge sort - Trộn 2 dãy đã sắp xếp 
 * Cho mảng b gồm n phần tử, c gồm m phần tử 
 * In ra dãy thứ tự trộn sao cho nếu áp dụng dãy thứ tự trộn trên thì 
 * mảng kết quả được sắp xếp tăng dần 
4 4
1 2 4 6
3 5 8 9
=> b1 b2 c1 b3 c2 b4 c3 c4
*/
//Thao tác merge O(n+m)
void run9(){
    int n, m; cin >> n >> m;
    int b[n], c[m];
    input(b); input(c);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(b[i] <= c[j]){
            cout << "b" << i+1 << " ";
            ++i;
        }
        else {
            cout << "c" << j+1 << " ";
            ++j;
        }
    }
    while(i < n){
        cout << "b" << i+1 << " ";
            ++i;
    }
    while(j < m){
        cout << "c" << j+1 << " ";
            ++j;
    }   
}
//----------------------------------------------------------------
/** Khiêu vũ 
 * n nam và m nữ
 * Chiều cao nam: a1 a2 ... an
 * Chiều cao nữ: b1 b2 ... bn
 * Trong 1 cặp khiêu vũ, bạn nam phải cao hơn nữ.
 * Tính số cặp đôi nhiều nhất thỏa mãn 
Sắp xếp chiều cao của nam và nữ tăng dần 
để chọn ra nam thấp nhất xem có ghép được với nữ thấp nhất k 
3 2
3 2 1
2 3
=> 1
3 3 
4 3 4
2 2 1
=> 3
*/
void run10(){
    int n, m; cin >> n >> m;
    int b[n], c[m]; //b nam c nữ 
    input(b); input(c);
    sort(b, b+n); sort(c, c+m);
    int i = 0, j = 0;
    int cnt = 0;
    while(i < n && j < m){
        if(b[i] <= c[j]){
            ++i;
        }
        else {
            cnt++;
            ++j;
        }
    }
    cout << cnt;
}
//----------------------------------------------------------------
/**Nhà gần nhất 
 * Tìm khoảng cách giữa 2 nhà gần nhau nhất 
Sắp xếp tăng dần, nhà gần nhau sẽ cạnh nhau 
3
1 6 3
=> 2
*/
void run11(){//O(nlogn)
    int n; cin >> n;
    int a[n];
    int res = INT_MAX;
    nhap_mang;
    sort(a, a+n);
    for (int i = 1; i < n; ++i){
        res = min(res, a[i] - a[i-1]);
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/**Xếp gạch 
 * Các viên gạch có độ cứng a1 a1...an
 * 1 viên gạch có độ cứng x nghĩa là Nam có thể chồng lên trên viên gạch 
 * đó tối đa x viên gạch khác, nếu chồng nhiều hơn thì viên gạch đó bị vỡ.
 * Hỏi Nam có thể sắp được chồng gạch cao nhất là bao nhiêu?
Để có chồng gạch có độ cao max thì phải để viên gạch có độ cứng max ở bên dưới 
sort gạch theo độ cứng giảm dần 
4 
1 2 3 4 
=> 4
4 
0 0 0 0
=> 1 
*/
void run12(){
    int n; cin >> n;
    int a[n]; nhap_mang;
    sort(a, a+n, greater<int>());
    int ans = 1;//luôn có thể đặt viên gạch đầu tiên 
    int docung = a[0];
    for(int i=1; i<n; i++){
        if(docung >= 1){
            ++ans;//tăng tổng số lượng viên gạch lên
            docung = min(docung - 1, a[i]); //cập nhật độ cứng của viên gạch vừa xếp lên  
        }else break;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Vắt sữa bò
 * Con bò thứ i có khả năng sẽ vắt được a[i] lít sữa 
 * Tuy nhiên cứ mỗi lần vắt sữa 1 con, những con bò còn lại trông thấy sợ quá 
 * nên sẽ bị giảm sản lượng mỗi con 1 lít sữa. Nếu vắt sữa con bò 1, 
 * n-1 con bò còn lại bị giảm sản lượng. Sau đó vắt sữa con bò 2 thì 
 * n-2 con bò còn lại giảm sản lượng. Tính xem thứ tự vắt sữa bò như thế nào 
 * để số lượng sữa vắt được là nhiều nhất 
 * Ouput: số lít sữa nhiều nhất mà anh Bo có thể vắt được 
Vắt con bò có sản lượng sữa lớn nhất trước để những con bò ít sữa dù hết cũng k thẻ giảm được nữa 
4
4 4 4 4
=> 10
4 
2 1 4 3
=> 6
*/
void run13(){
    int n; cin >> n;
    int a[n]; nhap_mang;
    sort(a, a+n, greater<int>());//sắp xếp giảm dần 
    int ans = 0;
    for(int i=0; i<n; i++){
        //sữa nó có > sữa bị mất đi thì còn thu hoạch được 
        if(a[i] > i){
            //con bò thứ i giảm i lít sữa 
            ans += a[i] - i;
        }
        //bò hết sữa rồi thì tất cả những con đứng đằng sau nó cũng hết sữa 
        else break;
    }
    cout << ans;
}
//----------------------------------------------------------------
/**Đổi chỗ 
 * Cho dãy a có n ptu, đưa ra dãy các thao tác đổi chỗ để nhận được dãy giảm dần 
5 
5 4 3 2 1
=> 1 5
   2 4 
Mỗi lần hoán vị thì in ra chỉ số hvi  
*/
void qs(int a[], int l, int r){
    int pivot = a[r];
    int i = l, j = r;
    while(i <= j){
        while(a[i] <= pivot) ++i;
        while(a[i] <= pivot) --j;
        if(i<=j){
            swap(a[i], a[j]);
            if(i!=j)
                cout << i + 1 << " " << j + 1 << endl;
            ++i, --j;
        }
    }
    if(l < j) qs(a, l, j);
    if(i < r) qs(a, i, r);
}
void run14(){
    int n; cin >> n;
    int a[n]; nhap_mang;
    qs(a, 0, n-1);
}
//----------------------------------------------------------------
/**Sắp xếp chèn 
 * In ra phần tử được chèn và vị trí chèn 
6 
8 5 2 7 9 3 
=>
5 0 
2 0 
7 2 
9 4 
3 1 
*/
void run15(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i=1; i<n ; i++){
        int x = a[i], pos = i-1;
        while(pos>=0 && a[pos]>x){
            a[pos+1] = a[pos];
            --pos;
        }
        cout << x << " " << pos+1 << endl;
        a[pos+1] = x;
    }
}
//----------------------------------------------------------------
/** Phân tích nhóm
 * 2 phần tử được xếp chung nhóm với nhau nếu như chênh lệch giữa chúng 
 * không vượt quá K 
Sắp xếp tăng dần,xét 2 ptu kề nhau độ chênh lệch
7
2 6 1 7 3 4 9 
=> 3
{1 2 3 4} {6 7} {9}
*/
void run16(){
    int n, k; cin >> n >> k;
    int a[n]; nhap_mang;
    sort(a, a+n);
    int cnt = 1;//ptử đầu là 1 nhóm 
    for(int i=1; i<n; i++){
        if(a[i] - a[i-1] <= k)
            continue;
        else
            cnt++;
    }
    cout << cnt;
}
//----------------------------------------------------------------
/** Đoàn thứ i được mời lưu diễn từ ngày ai đến ngày b1
 * Chọn những đoàn nào để số lượng đoàn là nhiều nhất mà 
 * k bị trùng nhau về mặt thời gian 
Chọn đoàn có thời gian kết thúc càng sớm càng tốt 
6
3 8 
9 12
6 10
1 4
2 7
11 14
=> 3
*/
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void run(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    f0(i, n) cin >> v[i].first >> v[i].second;
    // sắp xếp theo thời gian kết thúc 
    sort(v.begin(), v.end(), cmp);
    int ans = 1;
    int tmp = v[0].second;
    for(int i=1; i<n; i++){
        // thời gian bắt đầu của chuyến lưu diễn mới có > tgian kết thúc của chuyến nãy k
        if(v[i].first > tmp){
            ans++;
            tmp = v[i].second;//cập nhật thời gian kết thúc mới 
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}