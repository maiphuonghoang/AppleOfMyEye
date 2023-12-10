#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a,n) f0(i,n) cin >> a[i]
#define output0(a,n) f0(i,n) cout << a[i] << " "; el
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Number of smaller  
 * Cho 2 dãy tăng dần. Đối với mỗi ptu của mảng 2,
 * tìm số lượng phần tử của mảng 1 nhỏ hơn nó  
6 7 
1 6 9 12 18 18
2 3 8 13 15 21 25 
=> 1 1 2 4 4 6 6 
1 3
3
1 1 2
=> 0 0 0 
*/

void run1(){
    int n, m; cin >> n >> m;
    int a[n]; int b[m]; 
    input0(a,n); input0(b,m);
    int i=0, j=0;
    while(i<n && j<m){
        if(a[i] < b[j]) ++i;
        else{
            cout << "run";
            cout << i << " ";
            ++j;
        }
    }
    while(j<m){
        cout << n << " ";//lớn hơn mọi ptu trong mảng a 
        ++j;
    }
} 
//----------------------------------------------------------------
/** Number of equal
 * Cho 2 mảng tăng dần. Tìm số cặp ai=bj 
8 7 
1 1 3 3 3 5 8 8
1 3 3 4 5 5 5 
=> 11
*/
void run2(){
    int n, m; cin >> n >> m;
    int a[n]; int b[m]; 
    input0(a,n); input0(b,m);
    int i=0, j=0;
    ll ans = 0;
    while(i<n && j<m){
        if(a[i] < b[j]){
            ++i;
            continue;
        }else if(a[i] > b[j]){
            j++;
            continue;
        }
        int dem1 = 0, dem2 = 0;
        while(i<n && a[i] == b[j]){
            ++dem1; ++i;
        }
        int tmp = a[i-1];
        while(j<m && tmp == b[j]){
            dem2++; ++j;
        }
        ans += 1ll*dem1*dem2;
    }
    cout << ans << endl;

}
//----------------------------------------------------------------
/** Segment with small sum 
 * Dãy con liên tiếp dài nhất có tổng các phần tử <= s
7 20
2 6 4 3 6 8 9 
=> 4
*/
void run3(){
    int n; ll s;
    cin >> n >> s;
    int a[n]; input0(a, n);
    int l = 0, r, sum = 0, ans = 0;
    for(r = 0; r < n; ++r){
        sum += a[r];
        while(sum > s){
            sum -= a[l];
            l++;
        }
        //cập nhật chiều dài 
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Segment with big sum 
 * Dãy con liên tiếp ngắn nhất có tổng các phần tử >= s
7 20
2 6 4 3 6 8 9 
=> 3
*/
void run4(){
    int n; ll s;
    cin >> n >> s;
    int a[n]; input0(a, n);
    int l = 0, r, sum = 0, ans = 1e9;
    for(r = 0; r < n; ++r){
        sum += a[r];
        while(sum >= s){
            //cập nhật chiều dài 
            ans = min(ans, r-l+1);
            sum -= a[l];
            l++;
        }
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}
//----------------------------------------------------------------
/** Number of Segments with small sum 
 * Số lượng dãy con liên tiếp có tổng các phần tử <= s
7 20
2 6 4 3 6 8 9 
=> 19
2 
[2,6] 6
[2,6,4] [6,4] 4  
[2,6,4,3] [6,4,3] [4,3] 3
*/
void run5(){
    int n; ll s;
    cin >> n >> s;
    int a[n]; input0(a, n);
    int l = 0, r, sum = 0, cnt = 0;
    for(r = 0; r < n; ++r){
        sum += a[r];
        while(sum > s){
            sum -= a[l];
            l++;
        }
        // Khi [l,r]<=s thì số xâu con r-l+1
        cnt += r-l+1;
    }
    cout << cnt << endl;
}
//----------------------------------------------------------------
/** Number of Segments with big sum 
 * Dãy con liên tiếp có tổng các phần tử >= s
7 20
2 6 4 3 6 8 9 
l       r     => n-r
=> 9
*/
void run6(){
    int n; ll s;
    cin >> n >> s;
    int a[n]; input0(a, n);
    int l = 0, r, sum = 0, cnt = 0;
    for(r = 0; r < n; ++r){
        sum += a[r];
        while(sum >= s){
            cnt += n-r; //(n-1 -r + 1)
            sum -= a[l];
            l++;
        }
    }
    cout << cnt << endl;
}
//----------------------------------------------------------------
/** Number of Segments not more than k unique elements 
 * Số lượng dãy con liên tiếp chứa không quá k phần tử khác nhau  
7 3
2 6 4 3 6 8 3 
=> 20
*/
void run7(){
    int n, k; cin >> n >> k;
    int a[n]; input0(a, n);
    int l = 0, r;
    int cnt = 0;//đếm số lượng phần tử khác nhau trong segment
    int dem[100001] = {0};
    int ans = 0;
    for(r = 0; r < n; ++r){
        dem[a[r]]++; 
        if(dem[a[r]] == 1) cnt++;

        while(cnt > k){
            if(dem[a[l]] == 1) cnt--;
            dem[a[l]]--;
            l++;
        }
        ans += r-l+1;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Segment with small spread
 * Số lượng dãy con liên tiếp độ chênh lệch giữa max và min <= k  
7 3
2 6 4 3 6 8 9 
=> 16
*/
void run8(){
    int n, k; cin >> n >> k;
    multiset<int> ms;
    int a[n]; input0(a, n);
    int l = 0, r, ans = 0;
    for(r = 0; r < n; ++r){
        ms.insert(a[r]);
        while (*ms.rbegin() - *ms.begin() > k){
            auto it = ms.find(a[l]);
            ms.erase(it);
            l++;
        }
        ans += r-l+1;
    } 
    cout << ans << endl;
}
//----------------------------------------------------------------
/** Two sum 
 * Tìm vị trí 2 phần tử tổng = s 
4 8
2 7 5 1
*/
void run(){
    int n, s; cin >> n >> s;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n-1;
    while(l<r){
        int sum = v[l].first + v[r].first;
        if(sum == s){
            cout << v[l].second + 1 << " " << v[r].second + 1 << endl;
            return;
        }else if(sum < s){
            ++l;
        }else{
            --r;
        }
    }
    cout << "Impossible" << endl;
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