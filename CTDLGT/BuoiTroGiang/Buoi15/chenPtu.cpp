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

/** Số bước ít nhất 
 * Sắp xếp lại mảng với số lượng bước là ít nhất. Tại mỗi bước, bạn chỉ được phép 
 * chèn phần tử bất kỳ của mảng vào vị trí bất kì trong mảng.
 * A[] = {2,3,5,1,4,7,6} sẽ cho số chèn ít nhất là 3
 * 1 chèn trước 2, 4 chèn trước 5, 6 chèn trước 7 sẽ nhận được mảng sắp xếp 
di chuyển min <=> ở lại max 
thì ở lại phải được sắp xếp rồi 
dãy con tăng dài nhất 
13
143 340 571 845 211 228 274 443 666 594 491 814 24
=> 6
*/
int F[1000001];
void run(){
    int n; cin >> n;
    int a[n];
    f0(i,n) cin >> a[i];
    int res = 0;
    for(int i=0; i<n; i++){
        F[i]=1;
        for(int j=0; j<=i; j++){
            if(a[j] < a[i])
                F[i] = max(F[i],F[j] + 1);
        }
        res = max(res, F[i]);
    }
    cout << n - res << endl;
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