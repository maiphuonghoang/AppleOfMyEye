#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
3
4 1 2
=> 0 1 2 3 4 5 6 7
*/
void run(){// O(n * 2^n)
    int n; cin >> n;
    int a[n];
    set<int> se;
    for (int i=0; i<n; i++) cin >> a[i];
    //bắt đầu từ bit 0 
    for (int i = 0; i < (1<<n); i++) {
        int sum = 0;
        for (int j=0; j<n;j++){
            if(i &(1<<j)){
                sum += a[j];
        }
        cout << endl;
        se.insert(sum);
        }
    }
    for (auto it : se)
        cout << it << " ";
}
//----------------------------------------------------------------
/**
 * Trả lời cho câu hỏi có thể tạo được tổng bằng 1,2..x không 
 * Dãy con có tổng bằng s 
*/
void run2(){//O(n*sum)
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
    for (int i=1; i<=n; i++)
        //sum đi từ lớn -> nhỏ 
        for (int j=sum; j>=1; j--){
            if(j >= a[i])
                F[j] = F[j] || F[j-a[i]];
        }
    for (int i=0; i<=sum; i++)
        if(F[i]) cout << i << " ";
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