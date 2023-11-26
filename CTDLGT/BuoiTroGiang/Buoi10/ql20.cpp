#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Xâu nhị phân đối xứng chẵn 
 * Liệt kê các xâu nhị phân thuận nghịch có độ dài chẵn 
 * với chiều dài k quá n kí tự 
 * 2 < n < 30
4
=>
00
0000
0110
11
1001
1111
*/
int m, x[100], ok;

void ql(int i){//vị trí này 
    //gán những giá trị nào 
    for(int j=0; j<=1; j++){
        x[i] = j;
        //điều kiện dừng 
        //Trả lời cho câu hỏi khi nào in ra 
        if(i <= m/2) {//khi độ dài < m 
            for(int u=1; u<=i; u++)
                cout << x[u];
            for(int u=i; u>=1; u--)
                cout << x[u];
            el;
        }
        //nếu chưa là vị trí cuối cùng thì quay lui tiếp 
        if(i < m/2)
            ql(i+1);
    }
}
void run(){
    cin >> m;
    ql(1);
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