#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Đổi tiền 
 * Có các mệnh giá 1,2,5,10,20,50,100,200,500,1000.
 * Tổng số tiền cần đổi có giá trị bằng N
 * Cần ít nhất bao nhiêu tờ tiền để đổi 
*/
/*
10 138
1 2 5 10 20 50 100 200 500 1000
=> 6
100 20 10 5 2 1
*/
int n, s, a[100], x[100], res = INT_MAX;
void ql(int i, int bd, int sum){
    for(int j= bd; j<=n; j++){
        x[i] = j;
        if(sum + a[j] <= s){
            if(sum + a[j] == s){
                // for(int u = 1; u<=i; u++)
                //     cout << a[x[u]] << " "; 
                // el;
                res = min(res, i);
            }else{
                ql(i+1, j, sum + a[j]);//dùng 1 tờ nhiều lần 
                // ql(i+1, j+1, sum + a[j]);//chỉ dùng 1 tờ 1 lần 
            }
        }
    }
}
void run1(){
    cin >> n >> s;
    f1(i,n) cin >> a[i];
    sort(a+1, a+n+1, greater<int>());
    ql(1, 1, 0);
    cout <<"res = " << res;
}
//----------------------------------------------------------------
/**
2250k = 2*1000 + 250k
250k = 0*500 + 250k
250k = 1*200 + 50k
50k = 0*100 + 50k
50k = 1*50 + 0k 

138
=>6
*/
void run(){
    int sum; cin >> sum;
    int tien[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2,1};
    int cnt = 0, idx = 0;
    while(sum){
        cnt += sum/tien[idx];
        sum %= tien[idx];
        idx++;
    }
    cout << cnt;
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