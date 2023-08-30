#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void pointer(){
    int n; cin >> n;
    int a[n];
    for (int &x:a) cin >> x;
    cout << a << endl;
    for (int i = 0; i < n; i++)
        cout << &a[i] << " ";  cout << endl;
    cout << (a + 3) << endl; 
    cout << *(a + 3) << endl;

    sort(a, a  + n);
    auto it = a + 3;
    cout << it - a << endl;

}
/**
 * Đếm số lượng cặp số có tổng = k
*/
void twoSumEqual(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        //a[j] = k - a[i]
        auto it1 = lower_bound(a + i + 1, a+n, k-a[i]);
        auto it2 = upper_bound(a + i + 1, a+n, k-a[i]);
        ans += it2 - it1;
    }
    cout << ans << endl;
}
/**
 * Đếm số lượng cặp số có tổng < k
lower[aj] rồi dịch sang trái 1 cái là ra vị trí cuối cùng của ptu < a[j]
*/
void twoSumLesser(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a + i + 1, a+n, k-a[i]);
        --it;
        ans += it - (a + i);
    }
    cout << ans << endl;
}
/**
 * Đếm số lượng cặp số có tổng > k
*/
void twoSumGreater(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a + i + 1, a+n, k-a[i]);
        ans += a + n - it;
        //cuối dãy - upper 
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Số nhỏ nhất (thuộc mảng a) > a[i]
9
6 3 9 8 10 2 1 15 7 
=>
7 6 10 9 15 3 2 _ 8 
*/
void findMin(){
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    for (int i = 0; i<n; i++){
        auto r = upper_bound(a, a+n, b[i]);
        if(r != a + n)
            cout << *r << " ";
        else 
            cout << "_ ";
    }    
}
//----------------------------------------------------------------
/**Con đường độ dài l được thắp sáng bởi n chiếc đèn lồng
 * Đèn lồng thứ i ở điểm a[i]. Đèn lồng chiếu sáng tất cả các điểm 
 * trên đường phố cách nó nhiều nhất là d, trong đó d là 1 số đường chung 
 * cho tất cả các đèn lồng. Tìm bán kính ánh sáng tối thiểu mà những đèn lồng 
 * phải có để thắp sáng cả con phố 
Sắp xếp các đèn lồng kề nhau đứng cạnh nhau 
tìm min của đèn ở đầu vào cuối đường 
Cập nhật min khi duyệt các đèn lồng kề nhau sau 
3 8
2 4 5
=> 3.0
*/
void banKinhDenLong(){
    int n, l; cin >> n >> l;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    double max_distance = max(a[0], l - a[n-1]); 
    for (int i = 1; i < n; i++)
        max_distance = max(max_distance, (a[i] - a[i-1])/2.0);
    cout << fixed << setprecision(10) << max_distance << endl;
}
//------------------------------------------------------------------
/**
 * Ban đầu sức mạnh của Kiriro là s. Nếu Kiriro bắt đầu đấu tay đôi với rồng thứ i (1<i<n)
 * và sức mạnh Kiriro không lớn hơn sức mạnh xi của con rồng thì Kiriro thua trận đấu và chết.
 * Nhưng nếu sức mạnh của Kirito > sức mạnh của con rồng thì anh ta sẽ đánh bại nó và 
 * được tăng thêm sức mạnh theo là yi.
 * Kiriro có thể chiến đấu với những con rồng theo bất kì thứ tự nào. Xác định liệu anh ta có thể
 * chuyển sang cấp độ tiếp theo (đánh bại tất cả các con rồng mà k bị thua 1 lần nào)  
2 2
100 0
1 99
=> Yes 
Để đánh thắng nhiều trận nhất thì phải đánh từ rồng có sm nhỏ đến lớn 
*/
void battleDragon(){
    int n, s; cin >> n >> s;// số con rồng và sức mạnh ban đầu 
    vector <pair<int, int>> v;//sm từng con rồng và điẻm thưởng khi đánh bại nó 
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    bool winAll = true;
    sort(v.begin(), v.end());//sắp xếp sm con rồng 
    for (int i = 0; i < n; i++){
        if (s > v[i].first)
            s+= v[i].second;
        else 
            winAll = false;
    }  
    if(winAll) cout << "Yes";
    else cout << "No";  
}
//----------------------------------------------------------------
/**
 * n chàng trai và m cô gái. Kỹ năng khiêu vũ trong mỗi cặp chênh nhau nhiều nhất là 1 đơn vị.
 * Tìm số cặp lớn nhất có thể được hình thành từ n trai và m gái  
6 5
1 2 3 8 9 14
3 4 4 5 7 
Sắp xếp kỹ năng của các bạn nam và nữ theo thứ tự tăng dần 
*/
void BerSUBall(){
    int m, n; cin >> m >>n;
    int a[m], b[n];
    for (int &x : a) cin >>x;
    for (int &x : b) cin >>x;
    sort(a, a+m);
    sort(b, b+n);
    int i = 0, j = 0, ans = 0;
    while (i<m && j < n){
        int hieu = abs(a[i]-b[j]);
        if(hieu <= 1){
            ans++;
            i++; j++;
        }
        else{
            if(a[i] > b[j]) j++;
            else i++;
        }
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Có m người nộp đơn và n căn hộ miễn phí. Mỗi người nộp đơn có 1 kích thước
 * căn hộ mong muốn là x và họ sẽ chấp nhận bất kì căn hộ nào có diện tích từ 
 * x-k tới x+k. Phân phối các căn hộ sao cho càng nhiều người đăng kí 
 * sẽ nhận được căn hộ càng tốt  
4 3 5 
60 45 80 60
30 60 75 
*/
void xepCanHo(){
    int m, n, k; cin >> m >>n >>k;
    int a[m], b[n];
    for (int &x : a) cin >>x;
    for (int &x : b) cin >>x;
    sort(a, a+m);
    sort(b, b+n);
    int i = 0, j = 0, ans = 0;
    while (i<m && j < n){
        if(abs(a[i]-b[j]) <= k){
            cout << a[i] << " - " <<b[j] << endl;
            ans++;
            i++; j++;
        }
        else if(a[i] > b[j])j++;
        else i++;
        
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Có n đứa trẻ muốn chơi đu quay. Mỗi chiếc gondola có thể có 1 hoặc 2 người trong đó.
 * Tổng trọng lượng của 1 chiếc gondola k được vượt quá x.
 * Tìm số lượng thuyền tối thiểu 
Đưa các bạn nhẹ cân nhất và nặng cân nhất vào cùng 1 thuyền 
8 10
1 3 3 3 6 7 8 9 
l             r
=> 5
*/
void xepThuyen(){
    int n, s; cin >> n >>s;
    int a[n];
    for (int &x : a) cin >>x;
    sort(a, a+n);
    int l = 0, r = n - 1, ans = 0;
    while (l<=r){
        if(a[l] + a[r] <= s){
            ++l; --r;
        }
        else --r;//người lớn riêng đó vào 1 thuyền 
        ++ans;       
    }      
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Có n vé xem hòa nhạc, m khách hàng. Mỗi khách hàng thông báo mức gái tối đa 
 * mà họ sẵn sàng trả cho 1 vé. Sau đó họ sẽ nhận được 1 vé với mức giá gần nhất
 * có thể sao cho k vượt quá mức giá tối đa. 
5 3
5 3 7 8 5
4 8 3
=>  
3
8
-1
kh đưa 4, tìm vé lớn nhất <=4 chính là 3 rồi xóa vé đó đi 
đưa 8 thì xóa vé 8
đưa 3 thì hết vé 
*/
void duaVe(){
    //vé lớn nhất <= x chính là upper_bound xong dịch 1 vị trí 
    //dùng multiset để tìm kiếm logn, các ptu có thể trùng nhau
    multiset<int> ms;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        //vé lớn nhất <= x;
        auto it = ms.upper_bound(x);
        //trong trường hợp k có 
        if(it != ms.begin()){
            --it;
            cout << *it << endl;
            ms.erase(it);
        }else
            cout << -1;
    }
}
//----------------------------------------------------------------
/**
 * Bạn được cho biết thời gian đến và đi của 1 khách hàng trong 1 nhà hàng.
 * Số lượng khách hàng có mặt tại cửa hàng ở 1 thời điểm nhiều nhất là bn 
*/
void busyShop(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i< n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    int ans = 0, res = 0;
    sort(v.begin(), v.end());
    for (auto x : v) {
        res += x.second;
        ans = max(ans, res);
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Liên hoan phim 
 * n bộ phim. Số kượng bộ phim tối đa bạn có thể xem toàn bộ là bn.
 * Biết rằng nếu thời gian kết thúc của bộ phim trước <= thời gian 
 * bắt đầu của bộ phim sau thì bạn có thể xem cả 2 phim này 
Sắp xếp theo mốc thời gian kết thúc tăng dần 
so sánh bắt đầu bộ trước với kết thúc hiện tại 
*/
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void phimToiDa(){
    int n; cin >> n;
    //lưu tg bắt đầu và kết thúc vào mảng pair 
    pair<int, int> a[n];
    for (int i = 0; i <n ; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n, cmp);
    int ans = 1, end_time = a[0].second;
    for (int i = 1; i < n; i++){
        if(a[i].first >= end_time){
            ++ans;
            end_time = a[i].second;
        }
    }
    cout << ans << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    duaVe(); 
    return 0;
}