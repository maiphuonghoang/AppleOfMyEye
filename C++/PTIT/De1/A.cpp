#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
3
12345678
23
18
=>
Yes
No
Yes
*/
// Viết hàm chuyển số thành chuỗi (K xử lí số mà xử lí chuỗi)
// số âm chuyển thành số dương 
bool check(ll n){
    if(n < 0) n*= -1;
    string s = to_string(n);
    // duyệt qua từng kí tự xem chẵn / lẻ
    for (int i = 0; i < s.size(); i++) 
    //i là chỉ số, vị trí tương ứng là i + 1
    {
        // vị trí và số khác tính chẵn lẻ 
        if((i + 1) %2 != (s[i] - '0') % 2)
            return false;
    }
    return true;

}
void run(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(check(n)) cout << "YES" << endl;
        else cout << "N0" << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}