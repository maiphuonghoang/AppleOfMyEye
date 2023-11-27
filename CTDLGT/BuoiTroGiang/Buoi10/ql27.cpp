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

/** Tèo có n thẻ bài, mỗi thẻ ghi 1 con số từ 1 tới n. K có 2 thẻ nào ghi 
 * 2 số trùng nhau. Tèo muốn xếp thứ tự các thẻ bài sao cho kcos 2 con số nào 
 * liền kề nhau ở cạnh nhau  
 * 
4
=> 2413 3142
*/

int n, a[100], x[100];
bool used[100];

void xuly(){
    for(int i=2; i<=n; i++)
        if(abs(x[i] - x[i-1]) == 1)
            return;
    f1(i, n) cout << x[i]; el;
}
void ql(int i){
    for(int j=1; j<=n; j++){
        if(!used[j]){
            x[i] = j;
            used[j] = true;
            if(i==n) xuly();
            else ql(i+1);
            used[j] = false;
        }
    }
}
void run(){
    cin >> n;
    ql(1);
}
//----------------------------------------------------------------
//Gửi kèm điều kiện luôn khi quay lui 
void xuly2(){
    f1(i, n) cout << x[i]; el;
}
void ql2(int i){
    for(int j=1; j<=n; j++){
        if(!used[j] && abs(j-x[i-1]) != 1){
            //TTD của j chuẩn bị gán - ptu đằng trước 
            x[i] = j;
            used[j] = true;
            if(i==n) xuly2();
            else ql2(i+1);
            used[j] = false;
        }
    }
}
void run2(){
    cin >> n;
    x[0] = -1;
    ql(1);
}
//----------------------------------------------------------------
//Gửi kèm tham số là giá trị hiện tại 
void ql3(int i, int prev){
    for(int j=1; j<=n; j++){
        if(!used[j] && abs(j-prev) != 1){
            x[i] = j;
            used[j] = true;
            if(i==n) xuly2();
            else ql3(i+1, x[i]);
            used[j] = false;
        }
    }
}
void run3(){
    cin >> n;
    ql3(1,-1);
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
