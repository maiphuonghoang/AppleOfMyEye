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
 * https://cses.fi/problemset/task/1621
*/
//SET: O(nlogn)
void run(){
    int n; cin >> n;
    set<int> se;
    f0(i, n){
        int x;  cin >> x; 
        se.insert(x);
    } 
    cout << se.size() << endl;
}
//SORTING: O(nlogn)
void run2(){
    int n; cin >> n;
    vector<int> v(n);
    f0(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    int cnt = 0;
    f0(i, n){
        //phần tử đầu tiên hoặc khác ptu trước 
        if(i == 0 || v[i] != v[i-1])
            cnt++;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}