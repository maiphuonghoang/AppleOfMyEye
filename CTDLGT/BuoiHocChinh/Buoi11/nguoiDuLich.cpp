#include <bits/stdc++.h>
using namespace std;
/** Người du lịch
 * Cho n thành phố và các tuyến đường giao thông 2 chiều giữa chúng.
 * Mạng lưới giao thông này được cho bởi mảng C, C[i][j] là chi phí đoạn đường 
 * trực tiếp từ thành phố i đến thành phố j. Người du lịch xuất phát từ 
 * thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần 
 * và cuối cùng quay lại thành phố 1.
 * Hãy tính chi phí ít nhất mà người đó phải bỏ ra.
4
0 85 26 81
85 0 77 97
26 77 0 26
81 97 26 0
=> 234 

12
0 57 67 54 5 42 39 84 49 23 70 82
57 0 51 51 44 44 83 78 89 37 92 8
67 51 0 42 80 90 31 47 90 69 2 69
54 51 42 0 81 60 47 85 41 11 16 54
5 44 80 81 0 43 97 23 89 73 18 60
42 44 90 60 43 0 40 46 67 7 33 21
39 83 31 47 97 40 0 56 51 26 40 32
84 78 47 85 23 46 56 0 21 38 46 81
49 89 90 41 89 67 51 21 0 34 94 18
23 37 69 11 73 7 26 38 34 0 11 65 
70 92 2 16 18 33 40 46 94 11 0 16
82 8 69 54 60 21 32 81 18 65 16 0
=> 225
*/
int n, X[100], c[100][100], res = INT_MAX, dis = 0;
//X[i] = j : Thành phố thứ i đi qua là j 
int visited[100];
int dem;//số lần gọi đệ quy 

void Try1(int i){
    ++dem;
    for(int j=1; j<=n; j++){
        if(!visited[j]){
            X[i] = j;
            visited[j] = 1;
            //chi phí thành phố trước và thành phố đang đi 
            dis += c[X[i-1]][X[i]];
            if(i==n){//đi đủ n thành phố 
                res = min(res, dis + c[X[n]][1]);
                                //từ thành phố thứ n đi về 1
            }else{
                Try1(i+1);
            }
            visited[j] = 0;
            dis -= c[X[i-1]][X[i]];
        }
    }
}

void run1(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin >> c[i][j];
    }
    X[1] = 1; 
    //thành phố 1 đã đi qua 
    visited[1] = 1;
    Try1(2);
    cout << dem << endl;//68588312
    cout << res << endl;
}
//----------------------------------------------------------------
//Quay lui ngắt cành 
int cmin = INT_MAX;//lưu đường đi ngắn nhất giữa 2 thành phố bất kì
void Try2(int i){
    ++dem;
    for(int j=1; j<=n; j++){
        if(!visited[j]){
            X[i] = j;
            visited[j] = 1;
            dis += c[X[i-1]][X[i]];
            if(i==n){
                res = min(res, dis + c[X[n]][1]);
            }
            //ĐÁNH GIÁ CẬN 
            //coi tất cả quãng đường đi đến các thành phố còn lại đi với cmin 
            //số quãng đường phải đi còn lại là n-i+1 đi với chi phí nhỏ nhất 
            else if(dis + (n-i+1)*cmin < res){
                Try2(i+1);
            }
            visited[j] = 0;
            dis -= c[X[i-1]][X[i]];
        }
    }
}
void run2(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
            if(c[i][j])
                cmin = min(cmin, c[i][j]);
                //đường đi nhỏ nhất trong cả mảng
        }
    }
    X[1] = 1; 
    visited[1] = 1;
    Try2(2);
    cout << dem << endl;//181527
    cout << res << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}