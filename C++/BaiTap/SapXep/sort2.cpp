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

/**
 * Đưa ra các phần tử của mảng theo khuôn dạng 
 * lớn nhất, nhỏ nhất, lớn thứ 2, nhỏ thứ 2
2
7
7 1 2 3 4 5 6
8
1 6 9 4 3 7 8 2 
=> 
7 1 6 2 5 3 4 
9 1 8 2 7 3 6 4
*/
void run1(){//O(nlogn)
    int n; cin >> n;
    int a[n]; nhap_mang;
    sort(a, a+n);
    int l = 0, r = n-1;
    while(l<=r){
        if(l==r){
            cout << a[l] << " ";
            break;
        } 
        else{
            cout << a[r] << " " << a[l] << " ";
            ++l; --r;
        }
    }
    el;
}
//----------------------------------------------------------------
/**Couting sort
 * Sắp xếp mảng chỉ bao gồm các số 0, 1, 2
2 
5
1 1 0 0 2
6
1 1 1 0 0 2
=> 
0 0 1 1 2 
0 0 1 1 1 2
*/
void run2(){//O(n)
    int n; cin >> n;
    int a[n]; 
    int cnt[3] = {0};
    for(int i=0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i=0; i<3; i++){
        for(int j=0; j<cnt[i]; j++)
            cout << i << " ";
    }
    el;
}
//----------------------------------------------------------------
/**Cặp số có tổng bằng K 
2
4 4 
2 2 2 2
3 3 
1 2 3 
=> 6 1
*/
int a[1000001];
void run3(){//O(n)
    int n, k; cin >> n >> k;
    map<int, int> mp;
    f0(i, n){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for (int i=0; i<n; i++){
        ans += mp[k-a[i]];
        // tính chính nó 1 lần 
        if(a[i]*2==k)
            ans--;
    }
    cout << ans/2 << endl;
}
void run4(){//O(n^2)
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] + a[j] == k)
                ++ans;
        }
    }
    cout << ans << endl;
}
int first_pos(int a[], int l, int r, int x){
    int res = -1;
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
int last_pos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            l = m + 1;//****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
void run5(){//Tìm kiếm nhị phân 
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        //với mỗi a[i] tìm số lần xh của k-a[i], chỉ xét từ sau nó 
        int l = first_pos(a, i+1, n-1, k-a[i]);
        int r = last_pos(a, i+1, n-1, k-a[i]);
        if(l != -1) ans += r-l+1;
    }
    cout << ans << endl;
}
void run6(){//lower_bound, upper_bound
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        //tìm sau vị trí i 
        auto l = lower_bound(a + i + 1, a+n, k - a[i]);//vị trí đầu tiên của ptu >= x
        auto r = upper_bound(a + i + 1, a+n, k - a[i]);//vị trí đầu tiên của ptu > x
        if(l != r)
            ans += r-l;         
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Cặp số có tổng nhỏ hơn k 
 * a[i] + a[j] < k
 * a[j] < k - a[i]
 * Duyệt tất cả a[i] trong mảng đã sắp xếp, tìm xem có ptu < k-a[i]
k = 6
1 2 3 4 7   6-1=5
  | | |

2
4 5
2 2 2 2 
3 4 
1 2 4
*/
//Tìm vị trí xuất hiện cuối cùng của 1 ptu < x trong đoạn l-r
int last_pos_smaller(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] < x) {
            res = m;
            l = m + 1;//tìm thêm ở bên phải 
        }
        else r = m - 1;
    }
    return res;
}
void run7(){
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        //a[i]=>a[j]<k-a[i]
        int l = last_pos_smaller(a, i+1, n-1, k-a[i]);
        if(l != -1)
            ans += l-i;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Cặp số có tổng lớn hơn k 
 * a[i] + a[j] > k
 * a[j] > k - a[i]
 * 
k = 4 |  1 4 6 8 9 
Tìm ptu đầu tiên lớn hơn, những ptu sau chắc chắn lớn hơn k-a[i]

2
4 5
2 3 4 5 
3 3 
1 2 3 
*/
int first_pos_greater(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] > x) {
            res = m;
            r = m - 1;//tìm thêm ở bên trái  
        }
        else l = m + 1;
    }
    return res;
}
void run8(){
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        //a[i]=>a[j]>k-a[i]
        int l = first_pos_greater(a, i+1, n-1, k-a[i]);
        if(l != -1)
            ans += n-1 - l + 1;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Tìm tích của số lớn nhất của mảng a và nhỏ nhất của mảng b 
 * K dùng cách sort để lấy max và min của mảng 
2 
3 4
1 2 3 
-2 3 4 
=> -6
1 1 
1000000000
1000000000
=> 10^18
*/
//int a[1000001];
int b[1000001];
void run9(){
    int n, m; cin >> n >> m;
    f0(i, n) cin >> a[i];
    f0(i, n) cin >> b[i];
    // HÀM TÌM PHẦN TỬ NHỎ NHẤT TRONG ĐOẠN/MẢNG O(n)
    // max_element trả về iterator nên dùng * để lấy giá trị 
    int m1 = *max_element(a, a+n);
    int m2 = *min_element(b, b+m);
    cout << 1ll*m1*m2 << endl;//tràn số 
}
//-----------------------------------------------------------
/**Hợp nhất 2 mảng 
1
3 4 
1 2 3 
1 5 6 2 
=> 1 1 2 2 3 5 6
*/
void run10(){
    int n, m; cin >> n >> m;
    int arr[n+m];
    for(int i=0; i<n+m; i++) cin >> arr[i];
    sort(arr, arr + n + m);
    for(int i=0; i<n+m; i++)
        cout << arr[i] << " ";
    el;
}
//---------------------------------------------------------
/**Điền số còn thiếu 
 * Cho mảng a, gọi L và R là min và max. Tìm số phần tử cần thêm vào mảng
 * để mảng có đầy đủ các số trong khoảng [L,R].
 * VD {5,7,9,3,6,2} thiếu 4,8
Mảng đánh dấu 
2
5
4 5 3 8 6 
3
2 1 3
*/
void run11(){
    int n; cin >> n;
    int l = INT_MAX;
    int r = INT_MIN;
    bool a[1000001] = {0};
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        l = min(l, x);
        r = max(r, x);
        a[x] = 1;
    }
    int cnt = 0;
    for (int i=l; i<=r; i++){
        if(a[i] == 0)
            ++cnt;
    }
    cout << cnt << endl;
}
//----------------------------------------------------------
/**Sắp xếp theo giá trị tuyệt đối của |X-a[i]|
 * cùng giá trị tuyệt đối thì ưu tiên thứ tự xh trong mảng 
2
5 7 
10 5 3 9 2 
5 6 
1 2 3 4 5 
=>
5 9 10 3 2 
5 4 3 2 1
*/
int n, x;
bool cmpAbs(int a, int b){
    return abs(x-a) < abs(x-b);
}
void run12(){
    cin >> n >> x;
    f0(i, n) cin >> a[i];
    stable_sort(a, a+n, cmpAbs);//giữ nguyên thứ tự xh
    f0(i, n) cout << a[i] << " ";
    el;
}

//C2: lưu ptu trong mảng kèm theo chỉ số xh 
bool cmpAbsXh(pair<int, int> a, pair<int, int> b){
    int abs1 = abs(a.first - x);
    int abs2 = abs(b.first - x);
    if(abs1 != abs2)
        return abs1 < abs2;
    return a.second < b.second;
}
void run13(){
    cin >> n >> x;
    pair<int, int> v[n];
    f0(i,n){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v, v+n, cmpAbsXh);
    f0(i,n) cout << v[i].first << " ";el;
}
//----------------------------------------------------------------
/** Hợp và giao của 2 mảng 
 * Giống merge sort, xh ở 2 mảng thì cho vào giao, 
 * <, giống xh thì cho vào hợp 
3 5 
1 2 3 
1 2 3 5 9 
=>
1 2 3 5 9 
1 2 3
*/
void run14(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    f0(i,n) cin >> a[i]; 
    f0(i,m) cin >> b[i];
    int i = 0, j = 0;
    vector<int> giao, hop;
    while(i < n && j < m){
        if(a[i] < b[j]){
            hop.push_back(a[i]);
            ++i;
        }else if(a[i] > b[j]){
            hop.push_back(b[j]);
            ++j;
        }else{
            hop.push_back(a[i]);
            giao.push_back(a[i]);
            ++i; ++j;
        }
    }
    while(i < n)
        hop.push_back(a[i++]);
    
    while(j < m)
        hop.push_back(b[j++]);
    
    for(int x : hop) cout << x << " ";el;
    for(int x : giao) cout << x << " ";el;
}
//-------------------------------------------------------------
/** Sắp xếp lại dãy con
 * Tìm dãy con liên tục của mảng a[r]...a[l] sao cho khi sắp xếp 
 * lại dãy con nhận được 1 mảng được sắp xếp.
Tìm 2 vị trí a[i] > a[i]+1, tìm max trong đoạn l-r
duyệt từ 0 tới l xem liệu còn ptu > min => vị trí left thực sự 
         n tới r xem liệu còn ptu < max => vị trí right thực sự 
10 12 20 30 25 40 5 32 31 35 50 60 
          l     x x    r  

3
11
10 12 20 30 25 40 32 31 35 50 60 
12
10 12 20 30 25 40 5 32 31 35 50 60 
9
0 1 15 2 6 7 30 40 50
=> 
4 9
1 10
3 6
*/
void run15(){
    int n; cin >> n;
    int a[n]; nhap_mang;
    int l, r;
    for(int i=0;i<n-1; i++){
        if(a[i] > a[i+1]){
            l=i;
            break;
        }
    }
    for(int i=n-1; i>0; i--){
        if(a[i] < a[i-1]){
            r=i;
            break;
        }
    }
    int min = *min_element(a+l, a+r+1);
    int max = *max_element(a+l, a+r+1);
    for(int i=0; i<=l; i++){
        if(a[i] > min){
            l = i;
            break;
        }
    }
    for(int i=n-1; i>=r; i--){
        if(a[i] < max){
            r = i;
            break;
        }
    }
    cout << l + 1 << " " << r + 1 << endl;
}
//----------------------------------------------------------------
/** Sắp xếp chữ số 
 * Đưa ra mảng đã được sắp xếp bao gồm các chữ số của mỗi ptu trong a 
 * VD a[] = {110, 111, 112, 113, 114} => {0,1,2,3,4}

2
3
131 11 48
4
111 222 333 446
=> 
1 3 4 8 
1 2 3 4 6
*/
void run16(){
    int n; cin >> n; cin.ignore();
    string s; getline(cin, s);
    int a[10] = {0};
    for(char x : s) {
        if(isdigit(x))
            a[x-'0'] = 1;
    }
    for(int i=0; i<10;i++){
        if(a[i]) 
            cout << i << " ";
    }el;
}
//-------------------------------------------------
/** Sắp xếp theo tần xuất 
2
5
5 5 4 6 4
5
9 9 9 2 5
=> 
4 4 5 5 6 
9 9 9 2 5
*/
map<int, int> mp;
bool cmpTx(int a, int b){
    if(mp[a] != mp[b]) 
        return mp[a] > mp[b];
    return a < b;
}
void run17(){
    int n; cin >> n; 
    int a[n];
    f0(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a, a+n, cmpTx);
    f0(i,n) cout << a[i] << " ";
    el;
    mp.clear();//các test sau 
}
bool cmpTx2(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
void run18(){//k dùng map toàn cục 
    int n; cin >> n; 
    int a[n];
    map<int, int> mp;
    f0(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int, int>> v;
    for(auto it : mp)
        v.push_back(it);
    sort(begin(v), end(v), cmpTx2);
    for(auto it : v){
        for(int j=0; j<it.second; j++)
            cout << it.first << " ";
    }
    el;
}
//-----------------------------------------------------
/** Đếm cặp x^y > y^x
 * Kiến thức x < y => x^y > y^x
 * Ngoại lệ (2,3) (2,4)
 * duyệt qua ptu trong x, sort y 
 * tìm vị trí đầu tiên của ptu trong mảng 2 > a[i]x  
 * X = {2, 1, 6}, Y = {1, 5}
 * 3 cặp (2,1) (2,5) (6,1)
3 2
2 1 6
1 5 
=> 3
*/
int cnt[5];//đếm tần xuất của 0,1,2,3,4 trong mảng 2
// Tìm vị trí đầu tiên của ptu > x trong đoạn l-r
//int first_pos_greater(int a[], int l, int r, int x){}

//đếm xem có bn ptu thuộc mảng y mà > a[i] của x
int count(int y[], int m, int x){
    if(x == 0)
        return 0;
    if(x == 1) //1^0 > 0^1
        // tất cả số 0 trong mảng 2 là đáp án 
        return cnt[0];
    //x != 0, 1
    ll res = cnt[0] + cnt[1];
    /*
    auto it = upper_bound(y, y+m, x);
    res += (y+m) - it;  
    */
    //hoặc 
    int l = first_pos_greater(y, 0, m-1, x);
    if(l != -1) 
        res += m-l;
    if(x == 2){
        //2
        //3 3 3 4 4 4 5 5 
        res -= (cnt[3] + cnt[4]);
    }
    if(x == 3){
        // x = 3 vô tình bỏ lỡ 2 đếm thiếu
        //1 2 2 3 4 6 8 
        res += cnt[2];
    }
    return res;
}
void run19(){//O(nlogm)
    int n, m; cin >> n >> m;
    int a[n], b[m];
    f0(i,n) cin >> a[i]; 
    f0(i,m){
        cin >> b[i];
        if(b[i] <= 4)
            cnt[b[i]]++;
    } 
    sort(b, b+m);
    ll ans = 0;
    for (int x : a)
        ans += count(b, m, x);
    cout << ans << endl;
    memset(cnt, 0, sizeof(cnt));
}
//---------------------------------------------------------------
/**Giao của 3 dãy số 
 * Đưa ra phần tử có mặt trong cả 3 dãy đã được sắp xếp theo thứ tự tăng dần 
Dùng 3 biến i,j,k để chạy 
1 
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
=> 20 80
*/
void run20(){
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m], c[k];
    input(a); input(b); input(c);
    vector<int> res;
    int i=0, j=0, l=0;
    while(i<n && j<m && l<k){
        if(a[i] == b[j] && b[j] == c[l]){
            res.push_back(a[i]);
            ++i; ++j; ++k;
        }else if(a[i] <= b[j] && a[i] <= c[l]){
            ++i;
        }else if(b[j] <= a[i] && b[j] <= c[l]){
            ++j;
        }else l++;
    }
    if(res.size() == 0) cout << "-1" << endl;
    else{
        for(int x : res)
            cout << x << " ";
        el;
    }
}
//----------------------------------------------------------------
/** Sắp xếp chẵn lẻ 
 * Sắp xếp các số chẵn trong dãy theo thứ tự tăng dần và các số lẻ 
 * theo thứ tự giảm dần  
10
1 2 3 4 5 6 7 7 9 6
=> 
9 2 7 4 7 6 5 3 1 6 
*/
void run21(){
    int n; cin >> n;
    int a[n];
    vector<int> chan, le;
    f0(i,n){
        cin >> a[i];
        if(a[i]%2 == 0) chan.push_back(a[i]);
        else le.push_back(a[i]);
    }
    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end(), greater<int>());
    int i = 0, j = 0;
    for(int k=0; k<n; k++){
        if(a[k]%2 == 0){
            cout << chan[i] << " "; 
            ++i;
        }else{
            cout << le[j] << " "; 
            ++j;
        }
    }
}
//----------------------------------------------------------------
/**Biểu thức lớn nhất 
 * Dãy a được viết thành 1 hàng ngang, giữa 2 số liên tiếp có 1 khoảng trắng, 
 * vậy có tất cả (n-1) khoảng trắng.
 * Người ta muốn đặt k dấu cộng và (n-1-k) dấu trừ vào những khoảng trắng đó
 * để nhận được 1 biểu thức có giá trị lớn nhất 
 * Vd a[]={28,9,5,1,69} và k=2 thì 28+9-5-1+69 là biểu thức có giá trị lớn nhất 
Muốn giá trị lớn thì đặt - vào nhỏ, + vào lớn 
Sắp xếp các ptu từ chỉ số 1 tới chỉ số cuối cùng của mảng, k ptu max thì điền +
2
5 2 
28 9 5 1 69
5 1
10 20 15 5 1
=> 
*/
void run22(){
    int n, k; cin >> n >> k;
    int a[n]; nhap_mang;
    sort(a+1, a+n, greater<int>());
    ll ans = a[0];
    for(int i=1; i<n; i++){
        if(k>0)
            ans += a[i];
        else 
            ans -= a[i];
        k--;
    }
    cout << ans << endl;
}
//-------------------------------------------------------------------
/** Xếp hàng 
 * Có tất cả n vị khách. Vị khách thứ i tới làm thủ tục tại thời điểm t[i]
 * và cần d[i] thời gian để checkin xong.
 * Xác định thời điểm tất cả vị khách làm xong thủ tục lên máy bay 
Thời gian vị khách mới đến với thời gian kết thúc của thủ tục trước 
Sắp xếp theo thời gian đến 
3
2 1
8 3
5 7
=> 15
*/
void run23(){
    int n; cin >> n;
    pair<int, int> a[n];
    f0(i,n) cin >> a[i].first >> a[i].second;
    sort(a,a+n);
    int end_time = a[0].first + a[0].second; //tgian làm xong thủ tục của người 1
    for(int i=1; i<n; i++){
        end_time = max(end_time, a[i].first) + a[i].second;
    }
    cout << end_time << endl;
}
//----------------------------------------------------------------
/**Cặp phần tử có tổng gần 0 nhất
 * Tìm cặp phần tử có tổng gần nhất so với 0. Nếu có nhiều cặp cùng tổng
 * thì lấy cặp đầu tiên xuất hiện  
Sắp xếp theo trị tuyệt đối để x -x gần nhau luôn 
2
3
-8 -66 -60
6
-21 -67 -37 -18 4 -65
=> -68 -14
*/
bool cmpAbsValue(pair<int,int> a, pair<int,int> b){
    if(abs(a.first) != abs(b.first))
        return abs(a.first) < abs(b.first);
    return a.second < b.second;
}
void run24(){
    int n; cin >> n;
    vector<pair<int, int>> v(n); //lưu giá trị và chỉ số 
    f0(i,n){
        int x; cin >> x; 
        v[i].first = x;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmpAbsValue);
    int index;
    ll res;//lưu giá trị thực sự 
    ll sum = INT_MAX;//trị tuyệt đối của tổng 
    for(int i=1; i<n; i++){
        int tmp = abs(v[i].first + v[i-1].first);
        if(tmp < sum){
            sum = tmp;
            res = v[i].first + v[i-1].first;//cập nhật kết quả thực sự 
            index = min(v[i].second, v[i-1].second);//chỉ số nhỏ hơn trong 2 số hiện tại 
        }else if(tmp == sum){//nhiều cặp cùng tổng 
            if(index > min(v[i].second, v[i-1].second)){//chỉ số > cặp mới 
                res = v[i].first + v[i-1].first;
                index = min(v[i].second, v[i-1].second);
            }
        }
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/**Số lặp đầu tiên trong mảng 
2
5 
1 2 3 4 5 
6 
10 20 30 30 20 5 7 
=> -1 30
*/
void run(){
    int n; cin >> n;
    int a[n]; nhap_mang;
    bool used[1000001];
    for(int i=0; i<n; i++){
        if(used[a[i]]){
            cout << a[i] << endl;
            return;
        }
        used[a[i]] = 1;
    }
    cout << "-1" << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    // run();
    int t; cin >> t;
    while(t--){
        run();
    }
    return 0;
}