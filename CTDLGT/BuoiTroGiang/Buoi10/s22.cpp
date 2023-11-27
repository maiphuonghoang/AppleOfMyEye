#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** 1 số lộc phát được gọi là đối xứng chẵn nếu
 * - Số chữ số của X là chẵn
 * - Chỉ có 2 chữ số là 6 và 8
 * Liệt kê n số lộc phát đối xứng chẵn đầu tiên tăng dần 
57
=>
66 88 6666 6886 8668 8888 666666 668866 686686 688886 866668 868868 886688 
888888 66666666 66688666 66866866 66888866 68666686 68688686 68866886 68888886 
86666668 86688668 86866868 86888868 88666688 88688688 88866888 88888888 6666666666 
6666886666 6668668666 6668888666 6686666866 6686886866 6688668866 6688888866 6866666686 
6866886686 6868668686 6868888686 6886666886 6886886886 6888668886 6888888886 8666666668 
8666886668 8668668668 8668888668 8686666868 8686886868 8688668868 8688888868 8866666688 
8866886688 8868668688
*/
int n, x[100], ok;
void init(){
    f1(i, n) x[i] = 6;
}
void sinh(){
    int i = n;
    while(i>=1 && x[i] == 8){
        x[i] = 6;
        i--;
    }
    if(i==0) ok = 0;
    x[i] = 8;
}
void run(){
    int k; cin >> k;
    vector<string> v;
    //cứ lặp đến khi số ptu trong vector thỏa mãn yêu cầu 
    for(n=1; v.size() < k; n++){
        init();
        ok = 1;
        while(ok && v.size() < k){
            string s = "";
            for(int i=1; i<=n; i++)
                s += to_string(x[i]);
            for(int i=n; i>=1; i--)
                s += to_string(x[i]);
            v.push_back(s);
            sinh();
        }
    }
    for(string s : v) cout << s << " ";
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