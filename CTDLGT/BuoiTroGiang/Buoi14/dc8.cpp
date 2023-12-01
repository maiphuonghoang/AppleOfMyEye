#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Trộn 2 mảng 
 * Cho 2 mảng đã được sắp xếp a và b gồm n, m phần tử 
 * Tìm phần tử ở vị trí số K sau khi trộn 2 mảng để nhận được 
 * 1 mảng đã sắp xếp 
Trộn lên rồi truy cập vào vị trí 
7 9 14
4 6 7 9 10 10 10
1 1 2 5 7 8 8 9 10 
=> 10
*/

void run(){
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    input0(a); input0(b);
    vector<int> v;
    int i=0, j=0;
    while(i<n&&j<m){
        if(a[i]<=b[j])
            v.push_back(a[i++]);
        else    
            v.push_back(b[j++]);
    }
    while(i<n) v.push_back(a[i++]);
    while(j<n) v.push_back(b[j++]);
    cout << v[k-1] << endl;
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