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

/** Phân số đơn vị (Egyptian fractions)
 * 1 phân số đơn vị nếu tử số của phân số đó là 1
 * Mọi phân số nguyên dương đều có thể biểu diễn thành 
 * tổng các phân số đơn vị  vd 2/3 = 1/2 + 1/6
 * Biểu diễn phân số nguyên dương p/q thành tổng phân số đơn vị 
 * với số hạng tử là ít nhất
11 6
=> 1/1 +1/2 +1/3 
Case đặc biệt code chạy 
199/200 = 1/2 +1/3 +1/7 +1/54 +1/3437 +1/18559800
nhưng có thể viết nhỏ hơn 
199/200 = 1/2 +1/5 +1/5 +1/8 +1/1600

Phân tích 
11/6 = 1/X + ps'
              |
            1/X + ps''
để hạng tử ít nhất thì 1/X max
1/X <= 11/6 => X >= 11/6 => X=1
    11/6 = 1 + 5/6
1/X <= 5/6 => X >= 6/5 => X=2
    5/6 = 1/2 + 1/3
*/
ll gcd(ll a, ll b){
    while(b){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
struct PhanSo{
    ll tu, mau;

    void rutGon(){
        ll uocchung = gcd(this->tu,this->mau);
        this->tu /= uocchung;
        this->mau /= uocchung;
    }

    PhanSo operator - (PhanSo b){
        ll mauchung = this->mau * b.mau;
        ll tuso = this->tu*b.mau - b.tu*this->mau;
        PhanSo res {tuso, mauchung};
        res.rutGon();
        return res;
    }
};
void run(){
    PhanSo a; cin >> a.tu >> a.mau;
    //lặp lại quá trình đến khi phân số về 0
    while(a.tu != 0){
        //bé nhất >= ps
        //x>=6/5
        ll x;
        x = (a.mau%a.tu == 0)? (a.mau/a.tu) : (a.mau/a.tu + 1);
        //phân số còn lại
        PhanSo donvi {1,x};
        cout << 1 << "/" << x << " ";
        a = a - donvi; //gán lại a 
        if(a.tu) cout << "+";
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