#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Trong 8 chữ cái tiếng anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là A,E,
 * còn lại là phụ âm. Người ta muốn ghép các chữ cái bắt đầu từ 'A' cho đến chữ cái c ('D'<= c <='H)
 * sao cho mỗi chữ cái được sử dụng đúng 1 lần và xâu kết quả k có nguyên âm nào bị kẹp giữa bởi 2 phụ âm 
 * Liệt kê các xâu thỏa mãn theo thứ tự từ điển 
D
=>
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA 
*/
int n, a[100]; char x[100];
bool used[256];
char c;
int nguyen_am(char c){
    return c == 'A' || c == 'E';
}
void xuly(){
    for(int i=2; i<=n-1; i++){
        if(nguyen_am(x[i]) && !nguyen_am(x[i+1]) && !nguyen_am(x[i-1]))
            return;
    }
    for(int i=1; i<=n; i++)
        cout << x[i];
    el;
}
void ql(int i){
    for(char j='A'; j<=c; j++){
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
    cin >> c;
    n = c - 'A' + 1;
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