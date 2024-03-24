#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
3 1 1 3 3 
1 0 1 
1 0 0 
1 1 0 
=> YES 
2 1 1 2 2 
1 1 
1 0 
=> NO 
*/
struct ToaDo{
    int dong, cot;
};
typedef struct ToaDo TOADO; 
void run(){
    int n; cin >> n;
    bool visited[n][n] = {false};
    int dong_start, cot_start, dong_end, cot_end;
    cin >> dong_start >> cot_start >> dong_end >> cot_end;
    dong_start--; cot_start--; dong_end--; cot_end--;    
    vector<vector<int>> mp;
    mp.resize(n);//cấp phát số dòng
    for(int i=0; i<n; i++){
        mp[i].resize(n);//với mỗi dòng cấp phát cột 
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << mp[i][j] << " ";
        el;
    }
    TOADO x;
    x.dong = dong_start;
    x.cot = cot_start;
    queue<TOADO> q;
    q.push(x);
    visited[x.dong][x.cot] = true;
    bool check = false;
    while(!q.empty()){
        //lấy phần tử ra để xét 
        TOADO toado = q.front();
        q.pop();
        //Xét tọa độ vừa lấy ra để xem nó có thể di chuyển tiếp tới 
        //những vị trí nào tiếp theo 
        //1. vị trí đó phải hợp lệ 
        //2. ô đó đang trống 
        //3. nước đó chưa được đi
        if(toado.dong + 1< n && mp[toado.dong+1][toado.cot] == 0 && !visited[toado.dong+1][toado.cot]){
            //khi thỏa 3 điều kiện trên thì sẽ tiến hành đưa vào hàng đợi để chuẩn bị xét cho tương lai 
            TOADO t;
            t.dong = toado.dong + 1;
            t.cot = toado.cot;
            q.push(t);
            visited[t.dong][t.cot] = true;

            //Điều kiện dừng khi vị trí tọa độ mới đưa vào chính là đích đến 
            if(t.dong == dong_end && t.cot == cot_end) {
                check = true;
                break;
            }
        }
        if(toado.dong - 1>= 0 && mp[toado.dong-1][toado.cot] == 0 && !visited[toado.dong-1][toado.cot]){
            TOADO t;
            t.dong = toado.dong - 1;
            t.cot = toado.cot;
            q.push(t);
            visited[t.dong][t.cot] = true;
            if(t.dong == dong_end && t.cot == cot_end) {
                check = true;
                break;
            }
        }
        if(toado.cot + 1< n && mp[toado.dong][toado.cot + 1] == 0 && !visited[toado.dong][toado.cot+1]){
            TOADO t;
            t.dong = toado.dong;
            t.cot = toado.cot + 1;
            q.push(t);
            visited[t.dong][t.cot] = true;
            if(t.dong == dong_end && t.cot == cot_end) {
                check = true;
                break;
            }
        }
        if(toado.cot - 1>= 0 && mp[toado.dong][toado.cot -1] == 0 && !visited[toado.dong][toado.cot-1]){
            TOADO t;
            t.dong = toado.dong;
            t.cot = toado.cot - 1;
            q.push(t);
            visited[t.dong][t.cot] = true;
            if(t.dong == dong_end && t.cot == cot_end) {
                check = true;
                break;
            }
        }
    }
    check? yes : no;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\VNGame\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}