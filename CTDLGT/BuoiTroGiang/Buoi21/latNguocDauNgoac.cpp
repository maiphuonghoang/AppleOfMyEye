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

/** Cho xâu s chỉ bao gồm dấu đóng mở ngoặc, hãy tìm số lượng dấu ngoặc 
 * tối thiểu cần phải đổi chiều để tạo thành 1 xâu hợp lệ
- K hợp lệ ở 
    - thừa ) -> đổi chiều và push vào stack 
    - thừa ( -> đổi chiều 1 nửa st.size()
)))())()()((((
=> 4
*/
int xuly(string s){
    int cnt = 0;    
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            st.push(i);
        else{
            if(st.empty()){
                cnt++;
                st.push(i);
            }else
                st.pop();     
        }
    }
    cnt += st.size()/2;
    return cnt;
}
void run(){
    string s; cin >> s;
    cout << xuly(s);
}

int main() {
    run();
    return 0;
}