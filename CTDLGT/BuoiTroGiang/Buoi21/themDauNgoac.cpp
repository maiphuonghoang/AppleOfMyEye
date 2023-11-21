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

/** Cho 1 xâu kí tự gồm dấu đóng mở ngoặc tròn. Tìm số lượng 
 * dấu đóng mở ngoặc cần thêm tối thiểu để tạo thành 1 xâu cân bằng. 
))))()
=> 4
(((())))
=> 0
*/
int xuly(string s){
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')')
            if(!s.empty()) st.pop();
            else cnt++;
        else
            st.push(i);
    }
    cnt += st.size();
    return cnt;
}
void run(){
    string s; cin >> s;
    cout << xuly(s);
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