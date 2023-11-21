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

/** Cho biểu thức S ở dạng tiền tố, các số trong biểu thức chỉ là số có 1 chữ số.
 * Yêu cầu tính toán giá trị của biểu thức
+-7/451
=> 8
Cho biểu thức S ở dạng hậu tố 
316*+9*
=> 81
*/
int tinhTienTo(string s){
    stack<int> st;
    for(int i = s.length()-1; i>=0; i--){
        if(isdigit(s[i])) st.push(s[i] - '0');
        else{
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            int res;
            if(s[i] == '+')
                res = o1 + o2;
            if(s[i] == '-')
                res = o1 - o2;
            if(s[i] == '*')
                res = o1 * o2;
            if(s[i] == '/')
                res = o1 / o2;
            st.push(res);
        }
    }
    return st.top();
}
int tinhHauTo(string s){
    stack<int> st;
    for(int i = 0; i <= s.length()-1; i++){
        if(isdigit(s[i])) st.push(s[i] - '0');
        else{
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            int res;
            if(s[i] == '+')
                res = o1 + o2;
            if(s[i] == '-')
                res = o2 - o1;
            if(s[i] == '*')
                res = o1 * o2;
            if(s[i] == '/')
                res = o2 / o1;
            st.push(res);
        }
    }
    return st.top();
}
void run(){
    string s; cin >> s;
    // cout << tinhTienTo(s);
    cout << tinhHauTo(s);
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