#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//BINARY SEARCH ON ANSWER - Chặt nhị phân kết quả 

/**Factory machine :  
 * 1 nhà máy có n máy để tạo ra sản phẩm. Mỗi máy cần k giây để tạo ra 1 sản phẩm. 
 * Các máy có thể hoạt động đồng thời và bạn có thể tự do quyết định lịch trình của chúng. 
 * Thời gian ngắn nhất cần thiết để làm ra t sản phẩm là bao nhiêu
3 7
3 2 5 
=> 8
*/
bool checkSanPham(int a[], int n, int k, ll time){
    ll dem = 0;
    for (int i = 0; i < n;i++){
        dem += time/a[i];
        if(dem >= k)
            return true;
    }
    return false;
}
void factoryMachine(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    ll l = 0, r = 1ll * (*max_element(a, a+n)) * k;
    ll ans = -1;
    while(l<=r){
        ll m = (l+r)/2;
        if(checkSanPham(a, n, k, m)){
            ans = m;
            r = m - 1;
        }
        else 
            l = m + 1;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Chặt cây xây nhà 
 * Biệt thự được xây bởi các khúc gỗ khác nhau và tổng độ dài của các thanh gỗ là L. 
 * Khu rừng có N cây với độ cao khác nhau. Máy cưa có thể cắt 1 lượt qua tất cả các cây. 
 * Đầu tiên sẽ chọn 1 độ cao cố định là H, sau đó dùng cưa để cắt 1 đường theo độ cao H này 
 * trên các cây có độ cao > H.
 * VD các cây có dộ cao 10,16,17,15; chọn H=15 do đó cây thứ 2,3 sẽ được cắt và có 
 * tổng dộ dài các khúc gỗ thu được là 1 + 2 = 3.
 * Tìm giá trị lớn nhất của H thỏa mãn chỉ cần dùng cưa cắt 1 lượt sẽ thu được số các khúc gỗ cần thiết.

4 10
10 15 12 13
=> 10
*/
bool checkKhucGo(int a[], int n, int l, ll h){
    int tong = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > h){
            tong += a[i] - h;
        }
    }
    return tong >= l;
}
void chatCayXayNha(){
    int n, h; cin >> n >> h;
    int a[n];
    for (int &x: a) cin >> x;

    ll ans = -1;
    ll l = 0, r = *max_element(a, a+n);
    while(l<=r){
        ll m = (l+r)/2;
        if(checkKhucGo(a, n, h, m)){
            ans = m;
            l = m + 1;
        }
        else 
            r = m - 1;           
    }
    cout << ans << endl;   
}
//----------------------------------------------------------------
/** Máy photo
 * Theo ước tính thì có n bạn sẽ mua phao thi của Tèo. Tèo k có ý đinh bán 
 * bản phao gốc của mình nên sẽ đi photo n bản nữa để bán. Tới quán photo
 * chỉ còn 2 máy hoạt động. Máy 1 cần x giây để photo xong phao thi cho Tèo,
 * máy 2 cần y giây. Cần ít nhất bn giây để có thể photo ra n bản khác từ 1 bản gốc.
 * Chú ý các máy photo có thể photo từ bản gốc hoặc có thể photo từ bản sao .
 * 2 máy này có thể hoạt động 1 cách đồng thời.  
5 1 2
=> 4 
*/
bool checkBanSao(ll n, ll x, ll y, ll time){
    //lấy máy nhanh hơn photo ra 1 bản để 
    //có 2 bản cho 2 máy hoạt động đồng thời  
    time -= min(x, y);
    //chỉ cần photo thêm n-1 bản
    return time/x + time/y >= n-1; 
}
void phoTo(){
    ll n, x, y; cin >> n >> x >> y;
    ll l = 0;//thời gian tối thiểu tạo ra n phao thi 
    ll r = 1ll*min(x, y)*n;
    ll ans = -1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(checkBanSao(n, x, y, mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Chia mảng thành k mảng con liên tiếp có tổng lớn nhỏ nhất 
 * Chia mảng thành k mảng con liên tiếp sao cho tổng lớn nhất trong 1 mảng con 
 * càng nhỏ càng tốt
 * 1 <= n <= 2.10^5; 1<= xi <= 10^9
 * Gợi ý: Binary search trên tổng lớn nhất của 1 mảng con 
Chặt nhị phân trên tổng của 1 dãy con, với mỗi tổng của 1 dãy con phải xác định 
chia mảng ban đầu thành bao nhiêu dãy con kiên tiếp & số lượng dãy phải <= k thì tm  
5 3 
2 4 7 3 5 
=> 8
*/
//Chia mảng a thành k dãy con, tổng không vượt quá sum
bool checkMangCon(int a[], int n, int k, ll sum){
    int dem = 0;
    ll tong = 0;
    for(int i = 0; i < n; i++){
        tong += a[i];
        if(tong > sum){
            ++dem;
            tong = a[i];
        }
    }
    ++dem;
    return dem <= k;
}
void mangTongMin(){
    int n, k; cin >> n >> k;
    int a[n];
    ll right = 0;//tổng lớn nhất cho phép là tổng của tất cả ptu 
    for(int &x : a){
        cin >> x;
        right += x;
    } 
    ll left = *max_element(a, a+n);//tổng dãy con nhỏ nhất cho phép là ptu max
    ll ans = -1;
    while(left<=right){
        ll mid = (left + right)/2;
        if(checkMangCon(a,n,k,mid)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Xếp hình domino
 * Các thanh domino hcn có chiều rộng a và chiều cao b. Tìm 1 bảng hình vuông
 * có cạnh nhỏ nhất sao cho có thể xếp n thanh domino vào hình vuông này.
 * K nhất thiết phải xếp kín cái bảng hv nhưng k được phép xoay ngang thanh domino
 * In ra chiều dài cạnh hv nhỏ nhất tìm được 
2 3 10
=> 9 
*/
void domino(){
    ll a, b, n; cin >> a >> b >> n;
    ll l = 0, r = max(a,b)*n;
    ll res = 0;
    while(l<=r){
        ll mid = (l+r)/2;
        ll x = mid/a;
        ll y = mid/b;
        if(x*y>=n){
            res = mid;
            r = mid - 1; 
        }else{
            l = mid + 1;
        }
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/** Trò chơi cắt dây
 * Có n sợi dây, bạn cần cắt k đoạn dây có cùng chiều dài từ chúng.
 * Tìm chiều dài tối đa của các mảnh dây bạn có thể nhận được 
 * 
4 11
802 743 457 539
=> 200.500000
số thực nên k thể cập nhật mid+1
chạy từ 0->10^18 mất 63,64 vòng lặp 
*/
//cắt các sợi dây trong mảng a thành các sợi dây độ dài len 
bool checkDay(int a[], int n, int k, double len){
    ll dem = 0;
    for(int i=0; i<n; i++){
        dem += (int) a[i]/len;//cắt được bn sợi 
    }
    return dem >= k;
}
void catDay(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    double left = 0, right = 9e18;
    double res = -1;
    for(int i=1; i<=100; i++){
        double mid = (left + right)/2;
        if(checkDay(a,n,k,mid)){
            res = mid;
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << fixed << setprecision(6) << res << endl;
}
//----------------------------------------------------------------
/** Mảng con tổng bằng x
 * Đếm số mảng con (dãy con các phần tử liên tiếp) có tổng = x
 * 
5 7 
2 4 1 2 7 
=> 3
số dãy con kết thúc tại chỉ số i có tổng = x
*/
void dayConDuongTongX(){
    int n, x; cin >> n >> x;
    int a[n];
    for(int &x : a) cin >> x; 
    ll tong = 0, ans = 0;
    map<ll, int> mp;
    for(int i=0; i<n; i++){
        tong += a[i];
        if(tong == x) ++ans;
        if(mp.count(tong - x)) ++ans;
        mp[tong] = 1;
    }
    cout << ans << endl;
}
/**
10 5
2 3 0 -1 1 4 1 -2 2 7
=> 10
*/
void dayConAmTongX(){
    int n, x; cin >> n >> x;
    int a[n];
    for(int &x : a) cin >> x; 
    ll tong = 0, ans = 0;
    map<ll, int> mp;
    for(int i=0; i<n; i++){
        tong += a[i];
        if(tong == x) ++ans;
        if(mp.count(tong - x)) 
            ans += mp[tong - x];
        mp[tong]++;
    }
    cout << ans << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    dayConAmTongX();
    return 0;
}