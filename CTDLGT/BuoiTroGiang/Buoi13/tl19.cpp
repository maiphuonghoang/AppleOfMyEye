#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;

/** Di chuyển dấu ngoặc 
 * Cho 1 xâu kí S chỉ bao gồm '(', ')'. S có độ dài chẵn có giá trị N.
 * Xâu S gồm N/2 kí tự mở ngoặc và N/2 kí tự đóng ngoặc. Ở mỗi thao tác 
 * được lựa chọn 1 kí tự bất kì của S để đưa về vị trí đầu tiên hoặc 
 * vị trí cuối cùng của dãy. Xác định số thao tác tối thiểu cần thực hiện
 * để tạo được 1 xâu dấu ngoặc hợp lệ.   
 *
Lỗi khi ) trước ( => chỉ cần đưa ) về cuối 
Số lượng lỗi là đáp án 
)))((((())
=> 3
*/
int xuly(string s){
    stack<int> st;
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push(i);
        else{
            if(st.empty()) res++;
            else{
                st.pop();
            }
        }
    }
    return res;//số lượng ( trước )
}
void run(){
    string s; cin >> s;
    cout << xuly(s);
}

int main() {
    run();
    return 0;
}