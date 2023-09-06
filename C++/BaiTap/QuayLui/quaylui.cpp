#include <bits/stdc++.h>
using namespace std;

int N, X[100];
void inkq(int N){
    for (int i = 1; i <= N; i++)
        cout << X[i];
    cout << endl;
}
void TryXauNhiPhan(int i){
    //Duyệt các khả năng của X[i]
    for (int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == N)
            inkq(N);
        else 
            TryXauNhiPhan(i + 1);
    }
}
void runXauNhiPhan(){
    cin >> N;
    TryXauNhiPhan(1);
}
//----------------------------------------------------------------
int K;
void TryToHop(int i){
    for (int j = X[i-1] + 1; j <= N - K + i; j++){
        X[i] = j;
        if(i == K)
            inkq(K);  
        else 
            TryToHop(i + 1);
    }
}
void runToHop(){
    cin >> N >> K;
    X[0] = 0;
    //khi i = 1 thì imin = X[0] + 1 = 1
    TryToHop(1);
}
//----------------------------------------------------------------
int used[100];
void TryHoanVi(int i){
    //Duyệt các khả năng của X[i]
    for (int j = 1; j <= N; j++){
        //Xét xem liệu rằng có thể gán X[i]=j hay k
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1;//đánh dấu 
            if(i == N)
                inkq(N);
            else 
                TryHoanVi(i + 1);
            //backtrack 
            used[j] = 0;
        }
    }    
}
void runHoanVi(){
    cin >> N;
    //khởi tạo tất cả giá trị của used = 0;
    memset(used, 0, sizeof(used));
    TryHoanVi(1);
}
//----------------------------------------------------------------
/**Xếp N quân hậu vào N hàng trên bàn cờ N*N sao cho k có 2 quân hậu nào ăn nhau.
 * Xi = j có nghĩa là xếp quân hậu hàng thứ i nằm ở cột j  
*/
int cot[100], d1[100], d2[100];
int a[100][100];
void inViTriQueen(){
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; i++)
        // cout << "Con hau o hang thu " << i << " nam o cot " << X[i] << endl;
        a[i][X[i]] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int cnt;
void TryNQueen(int i){
    for (int j = 1; j <= N; j++){
        //Chuẩn bị gán X[i] = j
        if(cot[j] == 0 && d1[i-j+N] == 0 && d2[i+j-1] == 0){
            X[i] = j;
            cot[j] = d1[i-j+N] = d2[i+j-1] = 1;
            if(i == N){
                inViTriQueen();
                cnt++;
            }
            else
                TryNQueen(i + 1);
            //backtrack
            cot[j] = d1[i-j+N] = d2[i+j-1] = 0;
        } 
    }
}
void runNQueen(){
    N = 8;
    cnt = 0;
    for (int i = 1; i <= 99; i++)
        cot[i] = d1[i] = d2[i] = 0;
    TryNQueen(1);
    cout << cnt << "cau hinh";
}
//----------------------------------------------------------------
/**Xếp 8 quân hậu vào 8 hàng trên bàn cờ 8*8 sao cho k có 2 quân hậu nào ăn nhau.
 * Tổng vị trí đặt lớn nhất.
12 29 80 91 56 46 97 13
54 88 27 84 85 9 32 77
48 80 88 74 30 77 38 98 
6 82 20 95 7 86 12 43
100 82 15 7 95 9 5 84
51 40 65 98 86 38 30 63
96 78 98 76 33 11 2 58 
33 51 35 68 62 87 67 39 
=> 653
Tính tổng 
a[1][1]
a[2][5]
a[3][8]
a[4][6]
a[5][3]
a[6][7]
a[7][2]
a[8][4]
*/
int ans;
void inViTriQueenMax(){
    for (int i = 1; i <= N; i++)
        cout << "vi tri a[" << i << "][" << X[i] << "] = " << a[i][X[i]]<< endl;
    cout << endl;
}
void TryNQueenMax(int i){
    for (int j = 1; j <= N; j++){
        //Chuẩn bị gán X[i] = j
        if(cot[j] == 0 && d1[i-j+N] == 0 && d2[i+j-1] == 0){
            X[i] = j;
            cot[j] = d1[i-j+N] = d2[i+j-1] = 1;
            if(i == N){
                int tong = 0;
                for (int hang = 1; hang <= N; hang++)
                    tong += a[hang][X[hang]];
                cout << tong << endl;
                inViTriQueenMax();
                ans = max(ans, tong);
            }
            else
                TryNQueenMax(i + 1);
            //backtrack
            cot[j] = d1[i-j+N] = d2[i+j-1] = 0;
        } 
    }
}
void runNQueenMax(){
    N = 8;
    ans = 0;
    for (int i = 1; i <= 99; i++)
        cot[i] = d1[i] = d2[i] = 0;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];
    TryNQueenMax(1);
    cout << "Max = " << ans;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    runNQueenMax();
    return 0;
}
