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

/** Số nhỏ/lớn nhất 
 * S là tổng các chữ số và D là số các chữ số của 1 số
 * Tìm số nhỏ nhất và lớn nhất thỏa mãn S và D 
 * 1 <= S, D <= 1000
12 8
=> min: 10000029
   max: 93000000
Đặt hết số 9 vào cuối, vị trí chốt k phải vị trí đầu thì phải để cho đầu 1 đơn vị  
Các trường hợp 
20 4 
1199

20 3
299

28 3
ktm vì max 999=27

0 3
ktm 

0 1 
0 tm
*/
string beNhat(int sum, int n){
    // tạo ra xâu toàn số 0
    string res = string(n, '0');
    //điền từ cuối về
    for(int i=n-1; i>=0; i--){
        if(sum > 9){
            res[i] = '9';
            sum -= 9;
        }else{
            if(i!=0){
                res[0] = '1';
                res[i] += (sum - 1);
                return res;
            }else{//vị trí chốt là vị trí đầu tiên
                res[i] += sum;
                return res;
            }
        }
    }
}
string lonNhat(int sum, int n){
    // tạo ra xâu toàn số 0
    string res = string(n, '0');
    //điền từ đầu về
    for(int i=0; i<n; i++){
        if(sum > 9){
            res[i] = '9';
            sum -= 9;
        }else{
            res[i] += sum;
            return res;
        }
    }
}
void run(){
    int sum, n; cin >> sum >> n;
    if(sum > n*9 || sum == 0 && n>1)
        cout << -1;
    else{
        cout << beNhat(sum, n) << endl;
        cout << lonNhat(sum, n) << endl;
    }
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