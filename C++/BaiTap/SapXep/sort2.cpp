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
5 5 4 6 4
5
9 9 9 2 5
=> 
*/
map<int, int> mp;
bool cmpTx(int a, int b){
    if(mp[a] != mp[b]) 
        return mp[a] > mp[b];
    return a < b;
}
void run(){
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