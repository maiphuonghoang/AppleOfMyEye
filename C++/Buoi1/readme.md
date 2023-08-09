
### Số nguyên 
int : 4 byte = 32 bit : -2^31 -> 2^31-1 [-2*10^9 -> 2*10^9-1]
long long : 8 byte = 64 bit : -2^63 -> 2^63-1 [-9*10^18 -> 9*10^18-1]
### Số thực 
float : 4 byte = 32 bit : 6 số thập phân 
double : 8 byte = 64 bit : 15 số thập phân
### Kí tự 
char : 1 byte  
### Đúng sai
bool; true (1), false (0)
Trong C/C++, các số khác 0 được coi là đúng (true), chỉ có 0 được coi là sai (false)

pow(a,b) => a^b, sqrt(a) đều trả về số double 

BT.
1. Doraemon muốn leo lên một cầu thang gồm n bước. Anh ta có thể leo 1 hoặc 2 bước mỗi lần di chuyển.
Doraemon muốn số lần di chuyển là bội số của một số nguyên m.
Tìm số lượng di chuyển tối thiểu làm cho anh ta leo lên đỉnh cầu thang?
    a: số lần di chuyển 1 bước 
    b: số lần di chuyển 2 bước
    |a + 2b = n 
    |a + b = k % m      
    b = n - k    (k <= n && b <= k) 
                  n-k <= k <= n 
                  2k >= n && k <= n (n/2 <= k <= n)
    n=10, m=2 => Output k (min)= 6;
    n=9 thì bắt đầu là 2.5 >= 9 chứ k phải 4<=k <=9 => n/2 + 1 <= k <=n

    2k >= n && k <= n 
    chẵn n/2 <= k <= n 
    lẻ  n/2 + 1 <= k <= n 
=> Tìm số left nhỏ nhất chia hết cho m 