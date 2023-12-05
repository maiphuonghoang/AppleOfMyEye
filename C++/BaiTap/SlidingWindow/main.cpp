#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "; el
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "; el
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Cửa sổ lớn nhất 
 * Tìm dãy con liên tiếp của mảng có độ dài k sao cho tổng các phần tử 
 * trong dãy con là lớn nhất và liệt kê dãy con đó. Nếu có nhiều dãy con 
 * có cùng tổng lớn nhất thì in ra dãy con đầu tiên 
10 3 
1 2 3 1 5 2 7 8 9 1
=> 24
7 8 9 
*/

void run1(){
    int n, k; cin >> n >> k;
    int a[1001];
    input0(a);
    ll sum = 0;
    for(int i=0; i<k;i++) sum += a[i];
    ll res = sum, idx = 0;//chỉ số đầu tiên của cửa số 
    for(int i=k; i<n; i++){
        sum = sum + a[i] - a[i-k];
        if(sum > res){
            res = sum;
            idx = i-k+1;
        }
    }
    cout << res << endl;
    for(int i=0; i<k; i++)
        cout << a[idx + i] << " ";
}
//----------------------------------------------------------------
/** Số nhỏ hơn k
 * Sắp đặt lại các phần tử của mảng sao cho các số <= k đứng cạnh nhau 
 * Vd a[]={2, 1, 5, 6, 3} k=3 cần thực hiện 1 phép đổi chỗ để có 
 *    a[]={2, 1, 3, 6, 5}
 * 
4
5 3
2 1 5 6 3
7 5
2 7 9 5 8 7 4 
7 2 
8 1 2 5 1 2 4
7 2 
8 1 2 1 2 4 5
=> 1 2 1 0
*/
void run2(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        int d=0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] <= k) ++d;
        }
        //Xét tất cả cửa sổ cỡ là d 
        int cnt = 0;
        //cửa sổ đầu tiên có bn ptu <= k 
        for(int i=0; i<d; i++){
            if(a[i] <= k) ++cnt;
        }
        int ans = cnt;
        for(int i=d; i<n; i++){
            if(a[i-d] <= k) --cnt;//ptu bị loại khi trượt
            if(a[i] <= k) ++cnt;//ptu thêm vào khi trượt
            ans = max(ans, cnt);
        }//tìm được cửa sổ cỡ là d có nhiều ptu <= k nhất 

        //phép hoán vị = (số lượng ptu <= k trong mảng) - (số lượng ptu <= k trong cửa sổ lớn nhất)
        cout << d-ans << endl;
    }
}
//----------------------------------------------------------------
/** Sửa đèn 
 * Tuyến đường ven biển của thành phố có n chiếc đèn. Không may cơn bão
 * đã làm hỏng b chiếc đèn
 * Hãy sửa 1 số đèn đường bị hỏng sao cho có ít nhất 1 khu vực có k chiếc đèn liên tiếp hoạt động.
 * Xác định xem số đèn đường cần phải sửa chữa ít nhất là bn  
 * 
10 6 5
2 10 1 5 9 
=> 1  
x x      x        x x 
1 2 [3 4 5 6 7 8] 9 10

10 6 4
2 10 1 9
=> 0
*/
void run3(){
    int n, k, b; cin >> n >> k >> b;
    int a[n+1] = {0};
    for(int i=1; i<=b; i++){
        int x; cin >> x;
        a[x] = 1; //đèn bị hỏng 
    }
    //Tìm cửa số cỡ k có số lượng đèn bị hỏng ít nhất 
    int cnt = 0, idx = 1;
    for(int i=1; i<=k; i++){
        if(a[i]) cnt++;
    }
    int ans = cnt;
    for(int i=k+1; i<=n; i++){
        // if(a[i-k]) cnt--;
        // if(a[i]) cnt ++;
        cnt = cnt - a[i-k] + a[i];
        if(ans > cnt){
            ans = cnt;
            idx = i - k + 1;
        }
    }
    cout << ans << endl;
    for(int j=0; j<k; j++)
        cout << idx + j << " ";
}
//----------------------------------------------------------------
/** Cửa sổ trùng nhau 
 * Kiểm tra xem có tồn tại cửa sổ cỡ k nào của mảng ban đầu chứa 
 * 2 phần tử giống nhau hay không  
 * 
5 3 
1 2 3 1 3 
=> YES
5 3 
1 2 5 4 3
=> NO
*/

void run4(){
    int n, k; cin >> n >> k;
    int a[n];
    input0(a);
    bool ok = false;
    set<int> s;
    for(int i=0; i<k; i++){
        if(s.count(a[i])){
            ok = true; break;
        }
        s.insert(a[i]);
    }
    for(int i=k; i<n; i++){
        s.erase(a[i-k]);
        if(s.count(a[i])){
            ok = true; break;
        }
        s.insert(a[i]);
    }
    ok? yes:no;
}
//----------------------------------------------------------------
/** Cửa sổ trùng nhau 
 * Kiểm tra xem có tồn tại cửa sổ cỡ k nào của mảng ban đầu chứa 
 * 2 phần tử lệch nhau k vượt quá t  
 * 
|ai-aj| <= t
-t <= ai-aj <= t
aj-t <= ai <= t+aj

6 3 3 
1 5 8 1 5 9 
=> YES
6 3 0 
1 2 3 4 5 6
=> NO
*/
bool check(){
    int n, k, t; cin >> n >> k >> t;
    int a[n];
    input0(a);
    bool ok = false;
    multiset<int> s;
    for(int j=0; j<k; j++){
        //kiểm tra xem trong set có ptu a[i] >= a[j]-t
        auto it = s.lower_bound(a[j]-t);
        if(it != s.end() && (*it <= a[j] + t))
            return true;
        s.insert(a[j]);
    }
    for(int j=k; j<n; j++){
        s.erase(s.find(a[j-k]));
        auto it = s.lower_bound(a[j]-t);
        if(it != s.end() && (*it <= a[j] + t))
            return true;
        s.insert(a[j]);
    }
    return false;
}

void run(){
    check() ? yes : no;
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