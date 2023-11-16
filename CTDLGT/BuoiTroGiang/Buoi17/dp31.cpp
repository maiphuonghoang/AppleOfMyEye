#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc 
 * và số tiền nhận được khi hoàn thành nó. Chỉ có thể tham dự 1 dự án trong 1 ngày.
 * Số tiền tối đa bạn có thể kiếm được ?
4
2 4 4 
3 6 6 
6 8 2 
5 7 3
=> 7 
*/
struct Job{
    int st, ed;
    ll profit;
};
bool cmp(Job a, Job b) {
    return a.ed < b.ed;
}
int first_pos(Job a[], int i, int x){//end lớn nhất mà vẫn <= x
    int l = 1, r = i-1, res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid].ed <= x){
            res = mid;
            l = mid + 1;
        }
        else r = mid -1;
    }
    return res;
}
void run(){
    int n; cin >> n;
    Job a[n+1];
    ll F[n+1] = {0};
    f1(i, n) cin >> a[i].st >> a[i].ed >> a[i].profit;

    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++){//đi từ dưới lên trên 
        int t = first_pos(a, i, a[i].st-1);
        // có thể lấy hoặc k lấy 
        if(t==-1){
            F[i] = max(a[i].profit + 0, F[i-1]);
        }else
            F[i] = max(a[i].profit + F[t], F[i-1]);
    }
    cout << F[n];
}
//----------------------------------------------------------------
ll F[200001] = {0};
Job a[200001];
ll tinh(int n){//đi từ trên xuống dưới 
    if(n==0) return 0;
    if(F[n] != 0) return F[n];
    F[n] = 0;
    int t = first_pos(a, n, a[n].st-1);
    if(t != -1)
        F[n] = max(a[n].profit + tinh(t), tinh(n-1));
    else    
        F[n] = max(a[n].profit + 0, tinh(n-1));
    return F[n];
}
void run2(){
    int n; cin >> n;
    f1(i, n) cin >> a[i].st >> a[i].ed >> a[i].profit;

    sort(a+1, a+n+1, cmp);
    cout << tinh(n);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}