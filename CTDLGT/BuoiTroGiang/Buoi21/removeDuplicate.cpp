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

/** Xóa các kí tự liền kề giống nhau khỏi xâu S
aabbccc => c
abba => O
dddbbabcb => dabcb
*/
void mp_xuly(string s){
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(st.empty()) st.push(i);
        else{
            if(s[st.top()] == s[i])
                st.pop();
            else 
                st.push(i);
        }
    }
    while (!st.empty()) {
        cout << s[st.top()];
        st.pop();
    }   
}
string xuly2(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(!st.empty() && s[i] == st.top()){
            st.pop();
        }
        else st.push(s[i]);
    }
    string res = "";
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    
}
void run(){
    string s; cin >> s;
    mp_xuly(s), el;
    if(xuly2(s) == "") cout << "EMPTY";
    else cout<< xuly2(s);
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