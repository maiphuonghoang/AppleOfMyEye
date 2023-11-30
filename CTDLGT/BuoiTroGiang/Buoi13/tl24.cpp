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

/** String game 
 * 2 người đi theo lượt, Tí là người đi trước
 * Ở mỗi lượt chơi mỗi người có thể lựa chọn 1 trong 2 thao tác 
 * 1. Xóa 1 kí tự bất kì khỏi xâu S
 * 2. Lấy xâu S sau đó sắp đặt lại các kí tự trong xâu sao cho 
 * nó là 1 xâu đối xứng thì người đó sẽ thắng.
 * Biết rằng cả 2 bạn đều chơi tối ưu, xác định người thắng  
Tìm số lượng tần xuất lẻ 
Chỉ cần so_luong_tan_xuat_le <= 1 là thắng 
kpjdpgb
=> 1
aabb
=> 1
abbggg
=> 2

2c4l ___ -l : 3l     số lượng số lẻ luôn lẻ 
     ___ -c : 5l 
2c3l ___ -l : 2l     số lượng số lẻ luôn chẵng  
     ___ -c : 4l 

lúc đầu 5l
A: 4l|6l
B: 3l|5l  5l|7l
A: 2l|4l 4l|6l 4l|6l 6l|8l
A: chan
B: le
A: chan
B: le
A: chan
B: le

Thắng <=> nhận được xâu có số lượng tần xuất lẻ = 1
A: le -> xoa 1 ki tu -> B nhan chan
A: chan -> xoa 1 ki tu ->B nhan le
Lúc đầu có lẻ số lẻ A thắng 
Lúc đầu có chẵn số lẻ B thắng 
*/

void run(){
    string s; cin >> s;
    int d[256];
    for(char c : s) d[c]++;
    int so_luong_tan_xuat_le = 0;
    for(int i=0; i<256; i++){
        if(d[i] % 2 == 1) so_luong_tan_xuat_le++;
    }
    //ngay từ đầu đã thắng aabb
    if(so_luong_tan_xuat_le == 0 || so_luong_tan_xuat_le % 2 == 1)
        cout << 1;
    else
        cout << 2;

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