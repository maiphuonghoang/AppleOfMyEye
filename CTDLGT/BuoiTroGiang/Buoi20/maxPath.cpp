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

/** Đường đi lớn nhất
 * Cho 1 bảng vuông nxn ô. Tìm đường đi từ góc trái trên xuống góc phải dưới 
 * theo nguyên tắc chỉ được dịch chuyển sang phải và xuống dưới sao cho các số 
 * trên đường đi tạo thành 1 số nhị phân có giá trị lớn nhất 
5
1 0 1 1 0
0 0 1 0 1
0 0 1 0 1
1 0 0 1 1
1 1 0 1 0
=> 176
3
0 0 1
0 0 0
0 0 0
=> 4 

//Khởi tạo 
1 10 101 1011 10110 
10
100
1001
10011
*/
int n, a[105][105];
string d[105][105];

char xuly(string s){
    int res = 0, h = 1;
    for (int i=3; i>=0; i--){
        res += (s[i] - '0') * h;
        h*= 2;
    }
    if(res < 10) 
        return (res + '0');
    else 
        return (res - 10 + 'A');
}
string xuly2(string s){//bỏ số 0 ở đầu 
    int k = 0;
    while(k < s.length()-1 && s[k] == '0')
        k++;
    return s.substr(k);
}
string binToHex(string bin){
    // 4 kí tự liên tiếp 
    int mod = bin.length()%4;
    if(mod != 0)
        bin = string(4-mod, '0') + bin;
        string res = "";
        for(int i=0; i< bin.length(); i+=4){
            res += xuly(bin.substr(i,4));
        }
        return xuly2(res);
}
void run(){
    cin >> n;
    f1(i, n) f1(j, n) cin >> a[i][j];
    string s = "";
    f1(j, n){
        s += to_string(a[1][j]);
        d[1][j] = s;
    } 
    s = "";
    f1(i,n){
        s += to_string(a[i][1]);
        d[i][1] = s;
    } 
    f1(i, n){
        f1(j, n) 
            cout << d[i][j] << " ";
        cout << endl;
    } 
    f1(i, n)
        f1(j, n)
            d[i][j] = max(d[i-1][j], d[i][j-1]) + to_string(a[i][j]);
    cout << d[n][n];//101110110
    // chuyển từ nhị phân sang hexa 
    cout << " " <<binToHex(d[n][n]);

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