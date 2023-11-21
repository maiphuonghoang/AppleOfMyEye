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

/** Cho thứ tự duyệt inorder của 1 cây nhị phân. Xác định xem 
 * thứ tự này có phải là thứ tự duyệt của 1 cây nhị phân tìm kiếm hay k 
6
2 3 4 5 6 7 
=> yes
*/
int checkBST(int a[],  int n){
    for(int i=1; i<n; i++)
        if(a[i] < a[i-1])
            return 0;
    return 1;
}
void run(){
    int n; cin >> n;
    int a[n];
    for(int &x: a) cin >> x;
    checkBST(a, n) ? yes: no;
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