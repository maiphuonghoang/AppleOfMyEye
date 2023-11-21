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

/** Xóa k kí tự liền kề giống nhau khỏi xâu S
aaabbbcccedddeeu => xóa 3 kí tự giống nhau => u 
*/

string mp_xuly(string s, int k){
    stack<pair<char, int>> st;
    for(int i=0; i<s.length(); i++){
        if(!st.empty() && s[i] == st.top().first){
            if(st.top().second + 1 == k)
                st.pop();
            else
                st.top().second += 1;
        }
        else st.push({s[i], 1});
    }
    string res = "";
    while (!st.empty()){
        while (st.top().second)
        {
            res += st.top().first;
            st.top().second -= 1;
        }
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    
}
string xuly2(string s, int k){
    stack<pair<char, int>> st;
    for(int i=0; i<s.length(); i++){
        if(!st.empty() && s[i] == st.top().first && st.top().second == k-1)     
                st.pop();
        else{
            if(st.empty() || s[i] != st.top().first)
                st.push({s[i], 1});
            else
                st.top().second++;
        } 
    }
    string res = "";
    while (!st.empty()){
        auto it = st.top(); st.pop();
        for (int i=0; i<it.second; i++)
            res += it.first;
    }
    reverse(res.begin(), res.end());
    return res;
    
}
void run(){
    string s; cin >> s;
    int k; cin >> k;
    if(mp_xuly(s, k) == "") cout << "EMPTY" << endl;
    else cout<< mp_xuly(s, k);
    if(xuly2(s, k) == "") cout << "EMPTY" << endl;
    else cout<<" "<< xuly2(s, k);
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