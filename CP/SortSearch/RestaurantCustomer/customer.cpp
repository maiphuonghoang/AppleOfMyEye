#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * https://cses.fi/problemset/task/1619
*/

void run(){
    int n; cin >> n;
    vector<pair<int, int>> events;
    for(int i=0; i<n; i++){
        int start, end; cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }
    sort(events.begin(), events.end());
    int max_customers = INT_MIN;
    int actual_customers = 0;
    for(auto it : events){
        actual_customers += it.second;
        max_customers = max(max_customers, actual_customers);
    }
    cout << max_customers << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}