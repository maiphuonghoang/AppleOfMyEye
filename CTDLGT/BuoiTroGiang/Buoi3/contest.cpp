#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


/**
2352
2*1000 + 3*100+ 50 + 2
Số lượng = số tiền / mệnh giá 
2*1000 => 2352/1000=2 => thừa = 2352%1000 = 352  
*/

void doiTienThamLam(){
    int tien[] = {1000,500,200,100,50,20,10,5,2,1};
    long long n; cin >> n;
    long long cnt = 0;
    int i = 0;
    while (n!=0){
        cnt += n / tien[i];
        n = n % tien[i];
        i++;
    }
    cout << cnt << endl;
} 
//----------------------------------------------------------------
/**
888 289 123
321 54 888
=> 
888 2
123 1
289 1
*/
int checkKhongGiam(int n){
    while (n>=10){//chừng nào còn 2 chữ số thì mới check 
        int r = n%10;
        int l = n/10%10;
        if(r < l) return 0;
        n = n/10;
    }
    return 1;
}
bool cmplietKeVaDem(pair<int, int> a, pair<int, int> b){
    //In ra theo số lần xuất hiện giảm dần, trong trường hợp 
    //cùng số lần xuất hiện thì số nhỏ hơn sẽ xếp trước 
    if(a.second != b.second) 
        return a.second > b.second;
    return a.first < b.first;
}
//Nếu đề bài yêu cầu tiêu chí phụ: số nào xuất hiện trước in ra trước 
//thì trong cmp chỉ có tiêu chí chính, tiêu chí phụ thì dùng stable_sort 
bool cmplietKeVaDemXh(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) 
        return a.second > b.second;
}

void lietKeVaDem(){
    map<int, int> mp;
    int n; 
    //Dùng khi cho đầu vào không có số lượng phần tử  
    while (cin >> n){//cứ lặp đi đến chừng nào còn cin được 
        if(checkKhongGiam(n))
            mp[n]++;
    }
    //in ra biến map
    for (auto it : mp) cout << it.first << '-' << it.second <<' ';
    //đổ dữ liệu từ trong map vào vector 
    vector <pair<int, int>> v;
    for (auto it : mp) 
        v.push_back(it);
    sort(v.begin(), v.end(), cmplietKeVaDem);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
    stable_sort(v.begin(), v.end(), cmplietKeVaDemXh);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
}
//----------------------------------------------------------------
//chinh: sx theo trị tuyệt đối tăng dần
//phụ: sx trước in ra trước  
//2 -3 3 3 -5 5 -5
bool cmpthuTuSort(int a, int b) {
    // if(abs(a) != abs(b))
        return abs(a) < abs(b);
}
void thuTuSort(){
    int a[7] = {-5,5,2,-3,3,3,-5};
    stable_sort(a, a+7, cmpthuTuSort);
    for (int x: a) cout << x << ' ';
}
//----------------------------------------------------------------
/**
4
6 -3 0 4
=> 2 1
*/
void brt(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;  

    sort (a, a + n);
    int min_val = 1e9, cnt = 0;
    for (int i = 1; i < n; i++) {
        int kc = a[i] - a[i - 1];
        if(kc < min_val){
            min_val = kc;
            cnt = 1;
        }
        else if(kc == min_val)
            cnt++;       
    }
    cout << min_val << ' '<< cnt << endl;
}
//----------------------------------------------------------------
/** Tính tổng từ l đến r
5
1 2 3 4 5 
1
1 3 
1 nghìn truy vấn từ left đến right => mảng cộng dồn
F[i] = F[i-1] + a[i]
F[L-R] = F[R] - F[L-1] 
*/
void tongLR(){
    int n; cin >> n;
    int a[n+1];
    long long F[n+1] = {0};//F[0] = 0
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        F[i] = F[i-1] + a[i];
    }
    int q; cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl;
    }
}
//----------------------------------------------------------------
/** Số cặp bằng nhau 
6 
2 2 1 3 2 3 
=> 4 
8
2 2 4 4 3 4 3 4
2 - 2
4 - 4
3 - 2
2C2 + 2C4 + 2C2 
2Cn = n(n-1)/2 
*/
int d[1000005] = {0};
void capBangNhau(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        d[x]++;
    }    
    long long cnt = 0;
    for (int val = 0; val <= 1e6; val++)
        cnt += 1ll* d[val]*(d[val]-1)/2;
    cout << cnt << endl;
}
//----------------------------------------------------------------
/**
2 2 3 5 8 10 20 88
=> Yes
*/
void dayUuThe(){
    int cnt_chan = 0, cnt_le = 0;
    int n;
    while (cin >> n){
        if(n%2 == 0) cnt_chan++;
        else cnt_le++;
    }
    int cnt = cnt_chan + cnt_le;
    if(cnt % 2 == 0 && cnt_chan > cnt_le) cout << "YES";
    else if(cnt %2 == 1 && cnt_le > cnt_chan) cout << "YES";
    else cout << "NO"; 
}
//----------------------------------------------------------------
/** Tìm phần tử lặp đầu tiên trong mảng 
5
1 4 4 2 2 3 1
=> 2
*/
int dl[100];
void firstLap(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        dl[x]++;
        if(dl[x] == 2){
            cout << x ;
            break;
        }
    }    
}
//----------------------------------------------------------------
/**
 * Hãy trộn 2 dãy với nhau sao cho dãy a được đưa vào vị trí có chỉ số chẵn,
 * dãy B được đưa vào các vị trí có chỉ số lẻ. Đồng thời dãy a được sắp xếp 
 * tăng dần, dãy b giảm dần
4
4 2 7 1
5 6 2 8  
=> 1 8 2 6 4 5 7 2
*/
void tronChanLeSapXep(){
    int n; cin >> n;
    int a[n], b[n];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    //cách chậm 
    int t = 0;
    int i = 0, j = 0;
    while (t<2*n) {
        if(t%2 == 0){
             cout << a[i] << " ";
             i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
        t++;
    } 
    //cách nhanh 
    for (int i = 0; i < n; i++){
        cout << a[i] << " " << b[i] << " ";
    }
}
//----------------------------------------------------------------
/**
 * Cho dãy a gồm n phần tử, các ptu chỉ là 0,1,2. 
 * Hãy sắp xếp các ptu thoe thứ tự tăng dần 
5
1 1 0 2 1 
=> 0 1 1 1 2
couting sort O(n)
*/
void sort012(){
    int n; cin >> n;
    int a[n];
    int dC[3] = {0};
    for (int &x : a) {
        cin >> x;
        dC[x]++;
    }
    for (int i = 0; i <= 2; i++) {
        while (dC[i]){
            cout << i << " ";
            dC[i]--;
        }
    }
}
//----------------------------------------------------------------
/** Số đơn vị tối thiểu giúp mảng tăng chặt 
5
3 2 7 8 1
=> 10
3 4 7 8 9 (2+8)
*/
void donViTangDan(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    long long cnt = 0;
    for (int i = 1; i < n; i++){
        if(a[i] <= a[i-1]){
            //tương lai a[i] = a[i-1]+1
            //kc = a[i] mới - a[i] cũ 
            int kc = a[i-1]+1 - a[i];
            //cập nhật a[i] mới 
            a[i] = a[i-1] + 1;
            cnt += kc;
        }
    }
    cout << cnt << endl;
}
/** Số thao tác tối thiểu giúp mảng tăng chặt 
3 3
15 17 9
=> 3
3 3
15 17 8
=> 4
*/
void thaoTacTangDan(){
    int n, d; cin >> n >> d;
    int a[n], cnt = 0;
    for (int &x : a) cin >> x;
    //C1: 
    /*
    for (int i = 1; i < n; i++){
        if(a[i] <= a[i-1]){
            while (a[i] <= a[i - 1]){
                a[i] += d;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    */
    //C2: ít nhất phải là 18 => 18-8=10; 10/3=3.3
    long long res = 0;
    for (int i = 1; i < n; i++){
        if(a[i] <= a[i-1]){
            int hieu = a[i-1] + 1 - a[i];
            int buoc = (hieu+d-1)/d;
            res += buoc;
            //cập nhật a[i] mới 
            a[i] = buoc*d + a[i];
            cout << a[i] << endl;
        }
    }
    cout << res << endl;

}
//----------------------------------------------------------------
/**
a0*0 + a1*1 + a2*2 + a3*3 + a4*4
5
5 3 2 4 1
=> 40
5 3 2 4 1
0 1 2 3 4
để tổng max thì thứ tự 
1 2 3 4 5
0 1 2 3 4
(nhỏ đi với nhỏ, to đi với to)
*/
void productSum (){
    int n; cin >> n ;
    int a[n], cnt = 0;
    for (int &x : a) cin >> x;

    int sum = 0;
    int mod = 1e9+7;
    sort(a, a+n);
    for (int i=0; i<n; i++) {
        sum = (sum + (1ll*a[i]*i)%mod)%mod;
    }
    cout << sum << endl;

}
//----------------------------------------------------------------
/**
6
6 8 4 5 2 3
246 + 358
=> 604
2 3 4 5 6 8
x   x   x 
*/

void minSum(){
    int n; cin >> n ;
    int a[n], cnt = 0;
    for (int &x : a) cin >> x;

    sort(a, a+n);
    long long n1 = 0, n2 = 0;
    for (int i = 0; i < n; i++){
        if(i%2 == 0) n1 = n1*10+a[i];
        else n2 = n2*10+a[i];
    }
    cout << n1 + n2;
}
//----------------------------------------------------------------
/**
 * Chia mảng a thành 2 mảng con có kích cỡ k và n-k sao cho hiệu giữa
 * tổng 2 mảng con là lớn nhất 
5 2
8 4 5 2 10
=> 17 
2 4 5 8 10
{8+5+10} - {4,2} = 23-6 = 17
hay bị lừa 
5 3
8 4 5 2 10
=> 17 
k = min(k, n-k) = min (2, 5-2) = 2;
*/
void chiaMang(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    k = min(k, n-k);
    sort (a, a + n);
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i <n; i++) 
        if(i<k) sum1 += a[i];
        else sum2 += a[i];
    cout << sum2 - sum1;
}
//----------------------------------------------------------------
/**
 * Cho mảng a gồm n ptu. Tìm 2 chỉ số i, j khác nhau sao cho 0<i<j<n
 * và trị tuyệt đối của tổng 2 ptu a[i] và a[j] đạt giá trị lớn nhất 
5
-1 -2 -3 9 -5
=> chỉ quan tâm 2 thằng đầu và 2 thằng cuối
-5 -3 -1 3 4
|-8| và |7|
*/
void maxPair(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    int res1 = abs(a[0]+ a[1]);
    int res2 = abs(a[n-1]+ a[n-2]);
    cout << max(res1, res2) << endl;
}
//----------------------------------------------------------------
/**Cặp a[i], a[j] có tổng = k*/
int twoSum(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);

    int l, r;
    while (l < r){
        int sum = a[l] + a[r];
        if(sum == k) return 1;
        else if(sum < k) l++;
        else r--;
    }
    return 0;
}
int threeSum(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        int l = i+1, r = n-1;
        while (l < r){
            int sum = a[l] + a[r] + a[i];
            if(sum == k) return 1;
            else if(sum < k) l++;
            else r--;
        }
    }
    
    return 0;
}
int fourSum(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        if(a[i] > k/4) return 0;
        for (int j = i+1; j < n; j++) {
            int l = j+1, r = n-1, s2 = k - a[i]+a[j];
            while (l < r){
                int cur_sum2 = a[l] + a[r];
                if(cur_sum2 == s2) return 1;
                else if(cur_sum2 < s2) l++;
                else r--;
            }
        }
    }
    
    return 0;
}

/**
4
4 1 2 10
=> 12 5
7
1 2 3 4 5 6 7
=> 16 12 
*/
void SerejaAndDima(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int l = 0, r = n-1, sum1 = 0, sum2 = 0;
    bool serejaTurn = true;
    while (l<=r) 
    {   int maxi = max(a[l], a[r]);
        if(maxi == a[l]) l++;
        else r--;
        if(serejaTurn) {
            sum1 += maxi;
        }else sum2 += maxi;
        serejaTurn = !serejaTurn;
    }
    cout << sum1 << " " << sum2 << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    SerejaAndDima();
    return 0;
}