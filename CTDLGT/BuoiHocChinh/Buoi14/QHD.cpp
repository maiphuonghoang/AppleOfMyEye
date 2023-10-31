#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * Tính N! chia dư cho 10^9+7
 * 1<=T<=10000
 * 0<=N<=10^6
5 
11 6 8 10 13
=> 
39916800
720
40320
3628800
227020758
*/
ll F[1000001];
int mod = 1e9+7;
void modGiaiThua(){
    F[0] = 1;
    for (int i = 1; i <= 1000000; i++){
        F[i] = F[i-1] * i;
        F[i] %= mod;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << F[n] << endl;
    }
}
void modFibo(){
    memset(F, 0, sizeof(F));
    F[0] = 0; F[1] = 1;
    for (int i=2;i<=1000000;i++){
        F[i] = F[i-1]+F[i-2];
        // F[i] %= mod;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << F[n] << endl;
    }
}
//-------------------------------------------------------------
/**
 * Prime 1
 * Đếm xem trong đoạn từ 0 tới N có bao nhiêu số nguyên tố 
5
39 68 26 87 6

*/
const int maxn = (int) 1e6;
int prime[maxn +1];
void seive(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i<=sqrt(maxn); i++){
        if(prime[i]){
            for (int j = i*i; j<= maxn; j += i)
                prime[j] = 0;
        }
    }
}
void prime1(){
    seive();
    memset(F, 0, sizeof(F));
    int dem = 0;
    for (int i = 0; i <= 1000000; i++){
        if(prime[i]) ++dem;
        F[i] = dem;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << F[n] << endl;
    }
}
//----------------------------------------------------------------
/**
 * Đếm xem trong đoạn từ L tới R có bao nhiêu số nguyên tố 
5
3 19
4 65
4 44 
1 17
1 7 
=> 
7 16 12 7 4
*/
void prime2(){
    seive();
    memset(F, 0, sizeof(F));
    int dem = 0;
    for (int i = 0; i <= 1000000; i++){
        if(prime[i]) ++dem;
        F[i] = dem;
    }
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        if(l == 0) cout << F[r] << endl;
        else cout << F[r] - F[l-1]  << endl;
    }
}
/**
 * Tính tích các số nguyên tố trong đoạn từ 0 tới N 
 * Vì kết quả lớn nên hãy chia dư cho 10^9+7
5
20 16 10 22 29
=> 
9699690
30030
210
9699690
469693188
*/
void prime3(){
    seive();
    memset(F, 0, sizeof(F));
    F[2] = 2;
    for (int i = 3; i <= 1000000; i++){
        if(prime[i]) 
            F[i] = F[i-1]*i;
        else
            F[i] = F[i-1];
        F[i] %= mod;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << F[n] << endl;
    }

}
//-----------------------------------------------------------------
/**
 * Tính tổ hợp chập k của n 
 * In ra tam giác Pascal với chiều cao là n. Nếu các giá trị của tam giác Pascal 
 * quá lớn, in ra giá trị trong tam giác lấy dư với 1e9 + 7
 *
10
=> 
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
1 9 36 84 126 126 84 36 9 1
*/
ll C[1005][1005];
//C[i][j]: tính tổ hợp chập j của i 
void toHop(){
    for (int i = 0; i <= 1000; i++){
    //Tam giác Pascal thì dòng thứ i có i số 
    //duyệt từ cột 0 tới cột i
        for (int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                C[i][j] = 1;//C[0][0] C[0][1] C[0][2]...
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j]; //dựa vào kết quả 2 dòng trên đã tính 
                C[i][j] %= mod;
            }
        }
    }
}
void tamGiacPascal(){
    toHop();
    int n; cin >> n;
    for (int i = 0; i<n;i++){
        for (int j = 0; j <= i; j++)
            cout << C[i][j] << ' ';
        cout << endl;
    }
    
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    tamGiacPascal();
    return 0;
}