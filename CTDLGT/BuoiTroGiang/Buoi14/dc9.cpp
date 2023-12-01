#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Phần tử khác nhau 
 * Cho 2 mảng đã được sắp xếp a và b gồm n và n-1 phần tử
 * Các phần tử của mảng a chỉ khác mảng b 1 phần tử duy nhất 
 * Tìm vị trí của phần tử khác nhau giữa a và b 
Chặt đôi, nếu như nhau thì nằm ở bên phải 
khác nhau thì ghi nhận đáp án, tìm thêm bên trái
vì phải là vị trí đầu tiên khác nhau 
9
1 2 3 4 5| 6 7 8 9
1 2 3 4 5| 6 8 9
=> 7
*/
int tim(int a[], int b[], int n){
    int l=0, r=n-2, res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==b[mid])  
            l = mid + 1;
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
void run(){
    int n; cin >> n;
    int a[n], b[n-1];
    f0(i, n) cin >> a[i];
    f0(i, n-1) cin >> b[i];    
    //tìm vị trí = chỉ số + 1
    cout << tim(a, b, n) + 1 << endl;
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