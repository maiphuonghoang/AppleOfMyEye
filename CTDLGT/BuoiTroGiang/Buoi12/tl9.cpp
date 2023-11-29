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

/** Nối dây min
 * Cho n sợi dây, biết chi phí nối 2 sợi dây là tổng độ dài của 2 sợi dây đó.
 * Nối n sợi dây này thành 1 sao cho chi phí nối dây là nhỏ nhất 
Chọn 2 sợi dây bất kì có chiều dài nhỏ nhất chập lại với nhau 
tạo ra 1 sợi dây mới bớt đi 2 sợi dây cũ và thêm sợi dây tổng vào 
4
4 3 2 6
=> 29 (5,9,15)
4 3 2 6
4 5 6
6 9
15
*/

void run(){
    int n; cin >> n;
    int a[n];
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        pq.push(a[i]);
    }
    ll res = 0;
    while(pq.size()>=2){ //còn 1 sợi dây duy nhất
        int t1 = pq.top(); pq.pop();
        int t2 = pq.top(); pq.pop();
        res += (t1 + t2);
        pq.push(t1 + t2);
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