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

/** Cho số nguyên dương n (2<n<10). 1 số nguyên dương x có n chữ số 
 * được gọi là số xa cách nếu thỏa mãn: 
 *  - x không chứa chữ số 0
 *  - Tất cả các chữ số từ 1 đến n đều xuất hiện trong x đúng 1 lần
 *  - Không có 2 chữ số liên tiếp nào trong x có hiệu = 1
Quay lui hoán vị 
4
=>
2413
3142
*/
int n, x[100];
bool used[10];
void ql(int i){ //O(n!)
    for(int j=1; j<=n; j++){
        if(!used[j] && abs(j - x[i-1]) != 1){
            x[i] = j;
            used[j] = true;
            if(i == n){
                f1(u,n) cout << x[u];
                el;
            }
            else ql(i+1);
            used[j] = false;
        }
    }
}
void run(){
    cin >> n;
    x[0] = -1;
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
