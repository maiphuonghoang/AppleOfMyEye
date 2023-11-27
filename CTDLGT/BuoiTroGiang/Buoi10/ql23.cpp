#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Liệt kê các hoán vị của các ptu khác nhau trong mảng theo thứ tự ngược 
2
1 2
=> 
*/
int n, a[100], x[100];
bool used[1005];
void ql(int i){
    for(int j= n; j>=1; j--){
        if(!used[i]){
            x[i] = j;
            used[j] = true;
            if(i == n) {
                for(int u=1; u<=n; u++)
                    cout << a[x[u]] << " ";
                el;
            }
            else ql(i+1);
            used[j] = false;
        }
    }
}
void run(){
    int m; cin >> m;
    set<int> se;
    f1(i,m){
        int x; cin >> x;
        se.insert(x);
    }
    n = 0;
    //gán ptu trong se vào mảng 
    for(int x : se){
        n++;
        a[n] = x;
    }
    ql(1);
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