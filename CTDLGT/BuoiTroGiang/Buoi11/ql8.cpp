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

/** Chia mảng
 * Chia mảng a thành k tập con khác rỗng sao cho tổng các phần tử 
 * của mỗi tập con đều bằng nhau. Mỗi ptu của tập con xuất hiện duy nhất 
 * 1 lần trong tất cả các tập con 
 * a[]={2,1,4,5,6}
 * K=3 {2,4} {1,5} {6}
Sang các tập con khác thì bắt đầu lại từ đầu 

5
2 1 4 5 6
=> 1
*/
int n, k, sum=0, a[100], x[100], ok = 0;
bool used[105];

void ql(int i, int bd, int cur_sum, int cnt){
    //thành công khi bắt đầu xây dựng tập thứ 4
    if(cnt == k+1){//cnt là số tập hợp thoả mãn 
        ok = 1;
        return;
    }
    for(int j=bd; i=j<=n; j++){
        if(!used[j] && cur_sum + a[j] <= sum) {
            x[i] = a[j];
            used[j] = true;
            if(cur_sum + a[j] == sum){
                ql(i+1, 1, 0, cnt + 1);
                //quay lui cho tập mới 
            }else{
                // quay lui cho tập hiện tại 
                ql(i+1, j+1, cur_sum + a[j], cnt);
            }
            used[j] = false;
        }
    }
}
void run(){
    cin >> n >> k;
    f1(i,n){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%k == 0){
        sum /= k;
        ql(1,1,0,1);//xây dựng tập thứ 1
        cout << ok;
    }else cout << 0;
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