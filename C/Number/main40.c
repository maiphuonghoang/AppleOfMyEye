// 40.Số Nguyên Dương Nhỏ Nhất Có N Chữ Số Chia Hết Cho Cả X, Y, Z.
#include <stdio.h>
#include <math.h>
#define ll long long

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
ll solve(int n, int x, int y, int z)
{
    // số chia hết cho x,y,z thì chắc chắn chia hết cho bội chung nhỏ nhất của x,y,z
    ll tmp = lcm(lcm(x, y), z);
    // tìm số có n chữ số chia hết cho tmp
    //= tìm số nhỏ nhất lớn hơn hoặc bằng num (10^(n-1)) mà chia hết cho x
    //  [(num+x-1)/x]*x
    ll m = (ll)pow(10, n - 1);
    ll res = (m + tmp - 1) / tmp * tmp;
    if (res < (ll)pow(10, n)) // phải có n chữ số
        return res;
    else
        return -1;
}
int main()
{
    int x, y, z, n;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    printf("%lld", solve(n, x, y, z));
}