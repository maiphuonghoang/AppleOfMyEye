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

/** Đổi chỗ chữ số  
 * Cho số tự nhiên K cà xâu kí tự các chữ số S. Đưa ra số lớn nhất 
 * bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S.
 * k = 3, s = 1234567 được 7654321
 *
3
1234567
=> 7654321
2
4355
=> 5543 
*/
int n, k;
string s, res;
/* 72345616
76345216 76345612
*/
void ql(int i, string cur_str, int cnt){
    if(cnt > k || i > n) 
        return;
    res = max(res, cur_str);
    //lấy max để swap 
    char max_val = cur_str[i];
    for(int j=i+1; j<=n; j++){
        max_val = max(max_val, cur_str[j]);
    }
    if(max_val == cur_str[i]){
        ql(i+1, cur_str, cnt);
    }
    else{
        //xh ở nhiều vị trí 
        for(int j=i+1; j<=n; j++){
            if(cur_str[j] == max_val){
                string tmp = cur_str;
                swap(tmp[i], tmp[j]);
                ql(i+1, tmp, cnt + 1);
            }
        }
    }
}
void run(){
    cin >> k >> s;
    n = s.length();
    s = "0" + s;
    res = s;
    ql(1, s, 0);
    cout << res.substr(1) << endl;
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