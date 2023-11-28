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

/** Tổ hợp có tổng bằng x 
 * Tìm phép tổ hợp các số trong mảng a có tổng bằng x.
 * Các số trong mảng a được in ra theo thứ tự tăng dần 
 * A = {2,4,6,8} X=8
 * {2,2,2,2}, {2,2,4}, {2,6}, {4,4}
đằng sau >= đằng trước
3 10
4 2 3 
=> 5
{2 2 2 2 2}
{2 2 2 4}
{2 2 3 3}
{2 4 4}
{3 3 4}
*/
int n, s, a[100], x[100];
vector<vector<int>> v;
void ql(int i, int bd, int sum){
    for(int j=bd; j<=n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s){
                vector<int> tmp(x+1, x+i+1);
                v.push_back(tmp);
            }
            else ql(i+1, j, sum+a[j]);
        }
    }
}
void run(){
    cin >> n >> s;
    f1(i,n) cin >> a[i];
    sort(a+1, a+n+1);
    ql(1,1,0);
    if(v.size() == 0)
        cout << -1;
    else {
        cout << v.size() << endl;
        for(auto it : v){
            cout << "{";
            for(int i=0; i<it.size(); i++){
                cout << it[i];
                if(i < it.size() - 1)
                    cout << " ";
            } 
            cout << "}\n";
        }
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
