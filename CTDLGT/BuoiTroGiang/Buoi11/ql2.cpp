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
/** Dãy con có tổng k
 * Đưa ra tất cả các dãy con của dãy a theo thứ tự từ điển
 *  sao cho tổng các phần tử của dãy con đó đúng bằng k. 
 * Các ptu của dãy số a nguyên dương và k có các ptu giống nhau 
 * 
 * Hoán vị k lặp: vị trí trước < vị trí sau 
5 50
5 10 15 20 25
=> {5,10,15,20} {5,20,25} {10,15,25}

10 26
12 11 9 10 6 8 14 7 5 13
=>
5 6 7 8 
5 7 14
5 8 13
5 9 12
5 10 11
6 7 13
6 8 12
6 9 11
7 8 11
7 9 10
12 14
*/
// Quay lui nhánh cận 
int n, s, a[500], x[500];
void ql(int i, int bd, int sum){
    //j là vị trí 
    for(int j= bd; j <= n; j++){
        x[i] = j;
        if(sum + a[j] == s){
            for(int u = 1; u<=i; u++)
                cout << a[x[u]] << " "; 
            el;
        }
        else if(sum + a[j] < s)//nhỏ hơn thì mới được quay lui tiếp 
             ql(i+1, j+1, sum + a[j]);
        //ngắt cành sum + a[j] > s
    }
}
void run(){
    cin >> n >> s;
    f1(i,n) cin >> a[i];
    sort(a+1, a+n+1);
    ql(1, 1, 0);
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