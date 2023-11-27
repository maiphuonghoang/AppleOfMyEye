#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Mã số máy tính
 * Sử dụng 2*n kí tự, trong đó n kí tự đầu tiên là hoán vị 
 * của n chữ cái in hoa đầu tiên tính từ A, n ký tự tiếp theo 
 * là các kí tự số bất kì từ 1 đến n (có thể trùng nhau)
 *
2 
=>
AA11
AA12
AA21
AA22
AB11
AB12
AB21
AB22
*/
int n, k, a[100], x[100];
bool used[105];
vector<string> v1, v2;
void xuly(){
    string s = "";
    for(int i=1; i<=n; i++)
        s = s + char(x[i]+'A'-1);
        // 1 + 'A' - 1 => 'A'
        // 2 + 'A' - 1 => 'B
    v1.push_back(s);  
}

void ql_hoan_vi(int i){
    for(int j=1; j<=n; j++){
        if(!used[i]){
            x[i] = j;
            used[j] = true;
            if(i==n) xuly();
            else ql_hoan_vi(i+1);
            used[j] = false;
        }
    }
}
void xuly2(){
    string s = "";
    for(int i=1; i<=n; i++)
        s = s + to_string(x[i]);
    v2.push_back(s);  
}
void ql_chinh_hop(int i){
    for(int j=1; j<=n; j++){
        x[i] = j;
        if(i == n) xuly2();
        else ql_chinh_hop(i+1);
    }   
}
void run(){
    cin >> n;
    ql_hoan_vi(1);
    ql_chinh_hop(1);
    // for(string x : v1) cout << x << endl;//AA AB
    // for(string x : v2) cout << x << endl;//11 12 21 22
    //ghép vào với nhau 
    for(string x : v1){
        for(string y : v2) {
            cout << x + y << endl;
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