#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
using ll = long long;
using namespace std;

/** Job Scheduling
 * Tìm cách thực hiện nhiều nhất các hành động nhất có thể, biết rằng 2 hành động 
 * phải được thực hiện 1 cách độc lập (thời gian kết thúc của hành động thứ 1 nhỏ hơn 
 * thời gian bắt đàu của hành dộng thứ 2)
để quyết định có lấy/ k lấy 
Số lượng max => kết thúc sớm  <=> 1 job tiếp theo bắt đầu sớm 
16
1 5 
2 7 
2 7 
5 7 
6 7 
10 12
10 13 
1 3 
7 8 
9 14 
5 6 
9 10 
3 5 
8 13
1 6 
3 6 
=> 4
*/
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void run(){
    int n; cin >> n;
    pair<int, int> a[n];
    f0(i,n) cin >> a[i].first >> a[i].second;
    sort(a, a+n, cmp);
    int cnt = 1, t = a[0].second;
    //xét các cviec còn lại  
    for(int i=1; i<n; i++){
        if(a[i].first > t){
            cnt++;//chọn cviec này
            t = a[i].second; //lưa lại tgian kết thúc mới 
        }
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