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
int mod = 1e9+7;

/** Nối dây max
 * Cho n sợi dây, biết chi phí nối 2 sợi dây là tổng độ dài của 2 sợi dây đó.
 * Nối n sợi dây này thành 1 sao cho chi phí nối dây là lớn nhất 
 * Đáp án chia dư cho 10^9+7
9
10 1 5 7 4 8 7 7 1
=> 305
*/

void run(){
    int n; cin >> n;
    int a[n];
    priority_queue<ll> pq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        pq.push(a[i]);
    }
    ll res = 0;
    while(pq.size()>=2){ //còn 1 sợi dây duy nhất
        ll t1 = pq.top(); pq.pop();
        ll t2 = pq.top(); pq.pop();
        res += (t1 + t2);
        res %= mod;
        //k được push %mod trong queue
        pq.push(t1 + t2);
        /*
        60 50 40 30
        pq = [110, 40, 30] lấy 110 + 40
        pq = [10, 40, 30] lấy 40 + 30 chứ k phải 10+
        */
    }
    cout << res << endl;
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