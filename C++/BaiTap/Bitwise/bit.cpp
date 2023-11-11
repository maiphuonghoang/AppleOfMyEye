#include <bits/stdc++.h>
#define el cout << "\n";
using ll = long long;
using namespace std;

int basicBit(){
    unsigned int a, b;
    a = 8; b = 13;
    cout << (a & b), el; // 1101 & 1000 = 1000 = 8
    cout << (8 | 7), el; // 1000 | 0111 = 1111 = 15
    cout << (8 ^ 6), el; // 1000 ^ 0110 = 1110 = 14
    // biểu thức XOR phụ thuộc vào số bit 1, nếu số bit 1 lẻ thì true mà số bit 1 chẵn là false
    unsigned c = ~a;
    cout << c , el; // 2^32 - 8 //4294967287
    cout << (1ll << 32) - 8 -1, el;//4294967287
    
    // a = a << x = a * 2^x
    cout << (a << 1), el;//16  1000 dịch trái 10000 => nhân lên 2 
    cout << (a << 2), el;//dịch trái 2 bit, nhân lên 4
    cout << (1 << 10), el; //1*2^10=1024

    // a = a >> x = a / 2^x  
    cout << (a >> 1), el;//4, chia cho 2
}
// lũy thừa nhị phân 
int binpow(int a, int b){
    int res = 1;
    while(b){
        if(b%2 == 1) 
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
int binpow2(int a, int b, int m){
    int res = 1;
    while(b){
        if(b & 1){//nếu b là số lẻ & 00...01
            res *= a;
            res %= m;
        } 
        a *= a;
        a %= m;
        b = b >> 1;
    }
    return res;
}
/*
Nếu số là lũy thừa của 2 (2^k) thì bit thứ k là 1
    2^1 10
    2^2 100
    2^3 1000
*/ 
void luythua2(){
    int a = 17;
    for (int i = 31; i >= 0; i--){
    // duyệt từ bit 31 tới bit 0
        if(a & (1 << i))
        // 2^k ngoại trừ bit k = 1 còn lại tất cả = 0
        // nếu 1 & với bit thứ k thì sẽ ra 1, & với các vị trí khác đều là & 0
        // nếu & với 1 ra 1 thì chứng tỏ bit thứ k của a là 1 
            cout << "1";
        else 
            cout << "0";
    }
}
// Số tập con 2^n
/*
{}
{5 }
{7 }
{5 7 }
{3 }
{5 3 }
{7 3 }
{5 7 3 }
{2 }
{5 2 }
{7 2 }
{5 7 2 }
{3 2 }
{5 3 2 }
{7 3 2 }
{5 7 3 2 }

0000
1000
0100
1100
0010
1010
0110
1110
0001
1001
0101
1101
0011
1011
0111
1111
*/
void tapcon(){
    int a[] = {5, 7, 3, 2};
    // Duyệt từ 0, 1, ... 31
    for (int i = 0; i < (1 << 4); i++){
        cout << "{";
        // duyệt từng bit, check xem có được bật k 
        for (int j = 0; j < 4; j++){
            if(i & (1 << j))
                cout << a[j] << " ";
        }
        cout << "}\n";
    }
    for (int i = 0; i < (1 << 4); i++){
        // duyệt từng bit, check xem có được bật k 
        for (int j = 0; j < 4; j++){
            if(i & (1 << j))
                cout << "1";
            else 
                cout << "0";
        }
        el;
    }
}
/**
 * Cho n quả táo biết trước khối lượng 
 * Chia táo thành 2 phần sao cho 
 * độ chênh lệch giữa 2 phần là nhỏ nhất 
 * n = 20 => duyệt nhị phân O(2^20)
 *        => toán tử bit O(20*2^20)    
Sinh ra tất cả các cách chia táo, check min 
Chia thành 2 tập con, 1 tập được chọn, 1 tập k được chọn 
5
3 2 7 4 1
=> 1
(2 3 4) , (1 7)
*/
void chiaTao(){
    int n; cin >> n;
    int w[n];
    ll sum1, sum2;
    ll res = (ll) 1e18+5;
    for (int &x : w) cin >> x;
    for (int i = 0; i < (1 << n); i++){
        sum1 = sum2 = 0;
        for (int j = 0; j < n; j++){
            if (i & (1 << j))
                sum1 += w[j];
            else 
                sum2 += w[j];
        }
        res = min(res, abs(sum1 - sum2));
    }
    cout << res, el;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    chiaTao();
    return 0;
}