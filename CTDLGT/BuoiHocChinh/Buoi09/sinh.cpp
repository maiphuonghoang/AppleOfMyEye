#include <bits/stdc++.h>
using namespace std;

int n, k,ok, a[100];
void ktaoToHop(){
    for (int i=1; i<=k; i++)
        a[i] = i;
} 
void sinhToHop(){
    int i = k;
    while(i>=1&&a[i] == n-k+i)
        i--;
    if(i==0) 
        ok = 0;
    else {
        a[i]++;
        for (int j=i+1; j<=k; j++)
            a[j] = a[j-1] + 1;
    }
}
vector<vector<int>> v;
void runToHop(){
    cin >> n >> k;
    ok = 1;
    ktaoToHop();
    while(ok){
        vector<int> tmp(a+1, a+k+1);
        v.push_back(tmp);
        sinhToHop();
    }
    //in theo thứ tự thuận 
    for (int i=0; i< v.size(); i++){
        for (int x : v[i])
            cout << x;
        cout << endl;
    }
    //in theo thứ tự ngược 
    for (int i=v.size() - 1; i>=0; i--){
        for (int x : v[i])
            cout << x;    
        cout << endl;
    }
}
//----------------------------------------------------------------
//SINH TẬP CON BẰNG TOÁN TỬ BIT 
//Xét tất cả các số nhị phân từ 0 tới 2^n - 1
//& với 2^k để check bit đó là 0 hay 1 
/**
1
2
1 2
3
1 3
2 3
1 2 3
*/
void toanTuBit(){
    int a[] = {1,2,3};
    int n = 3;
    for (int i = 0; i < (1<<n);i++){
        for (int j = 0; j < n; j++){
            if(i&(1<<j))
                cout << a[j] << " ";
        }
        cout << endl;
    }
}
/**

The outer loop runs from i = 0 to i = (2^3 - 1), which is i = 7 because 1 << 3 equals 8.

i = 0 (binary: 000): No bits are set, so it prints nothing.
i = 1 (binary: 001): Only the last bit is set, so it prints "3 ".
i = 2 (binary: 010): Only the middle bit is set, so it prints "2 ".
i = 3 (binary: 011): The last two bits are set, so it prints "2 3 ".
i = 4 (binary: 100): Only the first bit is set, so it prints "1 ".
i = 5 (binary: 101): The first and last bits are set, so it prints "1 3 ".
i = 6 (binary: 110): The first and middle bits are set, so it prints "1 2 ".
i = 7 (binary: 111): All three bits are set, so it prints "1 2 3 ".
*/
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    toanTuBit();
    return 0;
}