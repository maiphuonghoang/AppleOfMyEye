#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * https://cses.fi/problemset/task/1745
*/
void run(){
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool F[sum+1];//có tạo được tổng bằng s k 
    memset(F, false, sizeof(F));
    F[0] = true;
    int dem = 0;
    for (int i=1; i<=n; i++){
        //sum đi từ lớn -> nhỏ 
        for (int j=sum; j>=1; j--){
            if(j >= a[i])
                F[j] = F[j] || F[j-a[i]];
        }
        
    }
    for (int i=1; i<=sum; i++)
        if(F[i]) dem++;
    cout << dem <<endl;  
    for (int i=1; i<=sum; i++)
        if(F[i]) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
