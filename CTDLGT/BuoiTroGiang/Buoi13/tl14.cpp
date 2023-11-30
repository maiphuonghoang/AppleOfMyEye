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

/** Mua lương thực 
 * Cửa hàng mở cửa tất cả các ngày tỏng tuần ngoại trừ chủ nhật. Cho bộ 3 số n,s,m
 *      - n: số lương thực nhiều nhất bạn có thể mua trong ngày S
 *      - s: số lượng ngày bạn cần được sử dụng lương thực để tồn tại 
 *      - m: số đơn vị lương thực cần có mỗi ngày để bạn tồn tại 
 * Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới.
 * Cho biết số ngày ít nhất bạn cần phải mua lương thực từ cửa hàng để tồn tại 
 * hoặc bạn sẽ bị chết đói trong S ngày tới  
song -> 18 ngay -> tong: 200kg      
di cho 16 ngay -> tong: 190kg    -> chết đói

song -> 18 ngay -> tong: 200kg 
di cho 13 ngay: 190kg 
di cho 14 ngay: 250kg 
di cho 15 ngay: 310kg 

7 5 7
=> 5
60 4 50
=> 4
1: 60
2: 120
3: 180
4: 240
5: 300
*/

void run(){
    /*  n: max kg đi chợ
        s: ngày 
        m: ăn kg/ngày
    */
    int n, s, m; cin >> n >> s >> m;
    int song = s*m;
    int soNgayDiCho = s - s/7;
    int tongDiCho = soNgayDiCho*n;
    if(tongDiCho < song) cout << -1;
    else{
        //Tìm số bé nhất >= sống + chia hết cho n
        cout << (song + n -1)/n << " ngay" << endl;
        cout << (song + n -1)/n * n << " kg" << endl;

        //cách khác
        if(song %n == 0) cout << (song/n) << " ngay" << endl;
        else cout << (song/n + 1) << " ngay" << endl;
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