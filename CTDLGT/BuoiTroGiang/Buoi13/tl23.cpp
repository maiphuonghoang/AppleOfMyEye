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

/** Xóa xâu kí tự 
 * Xâu nhị phân S chỉ bao gồm các kí tự 0 và 1
 * Ở mỗi bước đi, có thể chọn 1 xâu con liên tiếp các kí tự giống nhau 
 * và xóa nó khỏi xâu S. Sau khi xóa 1 xâu thì 2 xâu bên trái và phải 
 * của xâu vừa xóa sẽ liền kề. Ban đầu Tí đi trước, sau đó 2 bạn lần lượt 
 * thực hiện bước đi của mình cho tới khi xâu S trở thành xâu rỗng. 
 * Xác định xem Tí có thể xóa tối đa bn kí tự biết rằng cả 2 bạn đều chơi tối ưu.
Người xóa càng nhiều 1 thì là người thắng
Lấy lớn nhất ở thời điểm hiện tại  => sort danh sách số 1 liên tiếp
1000101110011111
Ti:     5   10001011100
Teo:    3   10001000
Ti:     1   10000000
Teo:    1   0000000
*/

void run(){
    string s; cin >> s;
    s += '0';//để k quên số 1 ở cuối
    int cnt = 0;
    vector<int> v;
    //đếm số lượng số 1 liên tiếp 
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1') cnt++;
        else{
            if(cnt!=0)
                v.push_back(cnt);
            cnt = 0;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int res = 0;
    for(int i=0; i<v.size(); i+=2)
        res += v[i];
    cout << res << endl;

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