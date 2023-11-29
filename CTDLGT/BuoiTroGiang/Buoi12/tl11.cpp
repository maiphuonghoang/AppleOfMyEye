#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;

/** Giá trị xâu kí tự 
 * Cho xâu S gồm [A..Z]. Giá trị xâu S là tổng bình phương 
 * số lần xuất hiện mỗi kí tự trong xâu 
 * S[]="AAABBCD"   F(S)=3^2+2^2+1^2+1^2 
 * Tìm giá trị nhỏ nhất của xâu S sau khi loại bỏ K kí tự trong xâu  
Bước nào cũng tìm thằng lớn nhất để giảm 1 đơn vị 
                -> priority_queue
2
0
ABCC
1
ABCC
=> 6 3
*/
void solve(){
    int k;
    string s;
    cin >> k >> s;
    int d[256] = {0};
    for(char c : s) d[c]++;
    priority_queue<int> pq;
    for(int i=0; i<256; i++){
        if(d[i] > 0)
            pq.push(d[i]);
    }
    while(k-- && pq.size()){
        int u = pq.top(); pq.pop();
        //push ngược lại u-1
        if(u-1 >= 1) pq.push(u-1);
    }
    ll res = 0;
    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        res += 1ll*u*u;
    }
    cout << res << endl;
}
void run(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}