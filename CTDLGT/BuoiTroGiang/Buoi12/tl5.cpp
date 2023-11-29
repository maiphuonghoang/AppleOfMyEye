#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Sắp xếp tham lam
 * Cho mảng a có n phần tử và thực hiện các thao tác:
 * 1. Chọn 1 mảng con sao cho ptu ở giữa của mảng con cũng là phần tử 
 * ở giữa của mảng a (trong trường hợp n lẻ)
 * 2. Đảo ngược mảng con đã chọn trong mảng a.
 * Ta được phép chọn mảng con và phép đảo ngược bao nhiêu lần tùy ý
 * Có thể sắp xếp được mảng a bằng cách thực hiện các thao tác trên k?
 * A = {1,6,3,4,5,2,7} yes
 * Chọn mảng con {3,4,5} và đảo ngược để nhận được {1,6,5,4,3,2,7}
 * Chọn mảng con {6,5,4,3,2} và đảo ngược để nhận được {1,2,3,4,5,6,7}
 * 
5
1 3 8 7 3  
=> NO
5
1 4 3 2 5 
=> YES
*/
int check(int a[], int b[], int n){
    for(int i=0; i<n; i++){
        //check nó và đối xứng của nó có = b[i]
        if(a[i] != b[i] && a[n-i-1] != b[i])
            return 0;
    }
    return 1;
}
void run(){
    int n; cin >> n;
    int a[n], b[n];
    //b là kết quả sau khi sort mảng a 
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }               
    sort(b, b+n);        
    check(a, b, n)? yes : no;                                                       
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
