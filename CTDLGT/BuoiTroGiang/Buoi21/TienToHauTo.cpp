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

/** Cho biểu thức S ở dạng tiền tố, hãy biến đổi S về dạng hậu tố 
 * và in ra màn hình 
pre: *+AB-UV
=> post: AB+UV-*
*/
string TienTo2HauTo(string s){
    stack<string> st;
    for(int i = s.length()-1; i>=0; i--){
        if(isalpha(s[i]))
            st.push(string(1, s[i]));
        else{
            string o1 = st.top(); st.pop();
            string o2 = st.top(); st.pop();
            string res = o1 + o2 + s[i];
            st.push(res);
        }
    }
    return st.top();
}
void run(){
    string s; cin >> s;
    cout << TienTo2HauTo(s);
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