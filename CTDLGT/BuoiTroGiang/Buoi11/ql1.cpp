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

/** Tập hợp có tổng bằng S 
 * Dãy số nguyên dương khác nhau tăng dần và không lớn hơn số n cho trước 
 * Đếm số tập hợp có số lượng phần tử bằng k và tổng của tất cả 
 * phần tử trong tập hợp = S.
 * Các tập hợp là hoán vị của nhau chỉ được tính là 1 
9 3 23
=> 1 {6,8,9} 

16 8 91
=> 
*/
/*
k phần tử 
x[i] <=n
sum = s
quaylui(int i)
    - for(int j =) => miền value 
        j <= n;
    - Khi nào xử lí (i == k)
Hoán vị không lặp lại: đứng trước < đứng sau  
*/
//Phân tích 
int n, k, s, cnt = 0, x[500];
void ql(int i, int bd){
    for(int j= bd; j <= n; j++){
        x[i] = j;
        if(i == k){
            // xuly();
        }
        else ql(i+1, j+1);
    }
}
/*
ql(i=1, bd=1, sum=0)
    x[1] = 3

x[1] = 3
x[2] = 4
x[3] = ...

x[1] = 3
x[2] = 5
x[3] = ...
ql(i=2, bd=4, sum=3){
    for(int j=4, j<=10; j++)
        x[2] = j;
    x[2] = 4 => ql(3, 5, 7)
    x[2] = 5 => ql(3, 6, 8)
    x[2] = 4 => ql(3, 7, 9)
 
}
*/
void ql(int i, int bd, int sum){
    for(int j= bd; j <= n; j++){
        x[i] = j;
        if(i == k){
            // xuly();
        }
        else ql(i+1, j+1, sum + j);
    }
}
//----------------------------------------------------------------
//Solution đếm số cặp 
void ql(int i, int bd, int sum){
    for(int j= bd; j <= n; j++){
        x[i] = j;
        if(i == k){
            if(sum + j == s)
                cnt++;
        }
        else ql(i+1, j+1, sum + j);
    }
}
//Cách viết khác 
void ql(int i, int bd, int sum){
    for(int j= bd; j <= n; j++){
        x[i] = j;
        sum += j;//sum bước này 
        if(i == k){
            if(sum == s)
                cnt++;
        }
        else ql(i+1, j+1, sum);
        sum -= j;
    }
}
//Cách viết khác 
void ql(int i, int bd, int sum){
    if(i == k+1){
        if(sum == s) cnt++;
        return;
    }
    for(int j= bd; j <= n; j++){
        x[i] = j;
        sum += j;//sum bước này 
        if(i == k){
            if(sum == s)
                cnt++;
        }
        else ql(i+1, j+1, sum);
        sum -= j;
    }
}
//----------------------------------------------------------------
//Solution In các cặp 
void ql(int i, int bd, int sum){
    cout << "Bat dau va tham ql(" << i << "," << bd << "," << sum << ")" << endl; 
    for(int j= bd; j <= n; j++){
        cout << "Tai i = "<<i<<" gan x[i] = "<<j<<endl;
        x[i] = j;
        if(i == k){
            if(sum + j == s){
                cout << "OK" << endl;
            }
        }
        else ql(i+1, j+1, sum + j);
    }
}
/*
Bat dau va tham ql(1,1,0)
Tai i = 1 gan x[i] = 1
Bat dau va tham ql(2,2,1)
Tai i = 2 gan x[i] = 2
Bat dau va tham ql(3,3,3)
Tai i = 3 gan x[i] = 3
Tai i = 3 gan x[i] = 4
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 3
Bat dau va tham ql(3,4,4)
Tai i = 3 gan x[i] = 4
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 4
Bat dau va tham ql(3,5,5)
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 5
Bat dau va tham ql(3,6,6)
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 6
Bat dau va tham ql(3,7,7)
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,8)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,9)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,10)
Tai i = 1 gan x[i] = 2
Bat dau va tham ql(2,3,2)
Tai i = 2 gan x[i] = 3
Bat dau va tham ql(3,4,5)
Tai i = 3 gan x[i] = 4
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 4
Bat dau va tham ql(3,5,6)
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 5
Bat dau va tham ql(3,6,7)
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 6
Bat dau va tham ql(3,7,8)
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,9)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,10)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,11)
Tai i = 1 gan x[i] = 3
Bat dau va tham ql(2,4,3)
Tai i = 2 gan x[i] = 4
Bat dau va tham ql(3,5,7)
Tai i = 3 gan x[i] = 5
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 5
Bat dau va tham ql(3,6,8)
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 6
Bat dau va tham ql(3,7,9)
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,10)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,11)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,12)
Tai i = 1 gan x[i] = 4
Bat dau va tham ql(2,5,4)
Tai i = 2 gan x[i] = 5
Bat dau va tham ql(3,6,9)
Tai i = 3 gan x[i] = 6
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 6
Bat dau va tham ql(3,7,10)
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,11)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,12)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,13)
Tai i = 1 gan x[i] = 5
Bat dau va tham ql(2,6,5)
Tai i = 2 gan x[i] = 6
Bat dau va tham ql(3,7,11)
Tai i = 3 gan x[i] = 7
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,12)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,13)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,14)
Tai i = 1 gan x[i] = 6
Bat dau va tham ql(2,7,6)
Tai i = 2 gan x[i] = 7
Bat dau va tham ql(3,8,13)
Tai i = 3 gan x[i] = 8
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,14)
Tai i = 3 gan x[i] = 9
OK
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,15)
Tai i = 1 gan x[i] = 7
Bat dau va tham ql(2,8,7)
Tai i = 2 gan x[i] = 8
Bat dau va tham ql(3,9,15)
Tai i = 3 gan x[i] = 9
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,16)
Tai i = 1 gan x[i] = 8
Bat dau va tham ql(2,9,8)
Tai i = 2 gan x[i] = 9
Bat dau va tham ql(3,10,17)
Tai i = 1 gan x[i] = 9
Bat dau va tham ql(2,10,9)
*/
void run(){
    cin >> n >> k >> s;
    ql(1, 1, 0);
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
