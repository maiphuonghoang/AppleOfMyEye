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

/** Dãy con tăng dần
 * Cho dãy a có n phần tử nguyên dương khác nhau đôi 1.
 * Liệt kê các dãy con có từ 2 ptu trở lên của dãy thỏa mãn tính chất tăng dần.
 * Dãy con phải giữ nguyên thứ tự ban đầu. Liệt kê theo thứ tự từ điển 
 * => K được sắp xếp
7
4 8 6 7 3 5 3 
=> 
3 5 
4 5
4 6
4 6 7
4 7
4 8
6 7
*/
int n, x[100], a[100];
vector<string> v;
void ql(int i, int bd){
    //vừa phải lớn hơn về vị trí
    for(int j=bd; j<=n; j++){
        //vừa phải lớn hơn về giá trị 
        if(a[j] > x[i - 1]){
            x[i] = a[j];
            //có ít nhất 2 ptu trở lên thì in ra
            if(i >= 2){
                string s = "";
                for(int u=1; u<=i; u++){
                    s += to_string(x[u]) +  " ";
                }
                v.push_back(s);
            }
            //đúng rồi thì vẫn quay lui tiếp 
            ql(i+1, j+1);
            }
    }
}
void run(){
    cin >> n;
    f1(i,n) cin >> a[i];
    x[0] = 0;
    ql(1, 1);
    sort(v.begin(), v.end());
    for(string s : v) cout << s << endl;
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
