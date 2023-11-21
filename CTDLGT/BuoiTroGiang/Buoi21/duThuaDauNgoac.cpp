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

/** Cho 1 biểu thức số học đúng nhưng có thể dư thừa dấu ngoặc.
 * Kiểm tra xem biểu thức này có dư thừa dấu đóng mở ngoặc hay k 
((x+y)) => Yes
(x) => Yes
    - stack lưu vị trí 
    - Vị trí đóng ngoặc - vị trí mở ngoặc = 2
    - bên trong () là 1 () khác 
*/

int check(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')'){
            if(i-st.top()==2 ) return 1;
            else if(s[st.top()+1] == '(' && s[i-1] == ')')
                return 1;
            else st.pop();//để lấy đỉnh mới 
        }
    }
    return 0;
}
void run(){
    string s; cin >> s;
    check(s) ? yes:no;
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