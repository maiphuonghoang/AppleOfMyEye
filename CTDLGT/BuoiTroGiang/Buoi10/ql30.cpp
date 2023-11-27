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

/** Cái túi
 * n đồ vật, đồ vật thứ i có trọng lượng w[i] và giá trị v[i]
 * Balo có thể chứa được trọng lượng tối đa là S.
 * Lựa chọn các đồ vật sao cho tổng trọng lượng k vượt quá S
 * và có giá trị lớn nhất. Tên trộm chỉ có thể chọn hoặc k chọn 1 đồ vật 
 * 
12 356
w: 174 153 127 156 156 5 132 161 170 25 181 50 
v: 103 32 102 85 54 166 187 173 137 54 24 91
=> 
*/

int n, S, x[100], w[100], v[100];
int res = -1e9;
void xuly(){
    int totalWeight = 0, totalValue = 0;
    for(int i=1; i<=n; i++){
        if(x[i]){
            totalWeight += w[i];
            totalValue += v[i];
        }
        if(totalWeight <= S)
            res = max(res, totalValue);
    }
}
void ql(int i){
    for(int j=0;j<=1;j++){
        x[i] = j;
        if(i==n) xuly();
        else ql(i+1);
    }
}
void run(){
    cin >> n >> S;
    f1(i, n) cin >> w[i];
    f1(i, n) cin >> v[i];
    ql(1);
    cout << res << endl;
}
//----------------------------------------------------------------
//Tích hợp totalWeight và totalVlue vào quay lui
/**
ql(5, 100, 200);
i = 5, w[5] = 20, v[5] = 40
x[5] = 1
ql(6, 120, 240)

x[5] = 0;
ql(6, 100, 200)
*/
void ql2(int i, int totalWeight, int totalValue){
    for(int j=0; j<=1; j++){
        x[i] = j;
        if(i == n) {//chốt 
            //totalWeight là totalWeight của i-1 bước trước 
            if(x[i] == 1){//chọn đồ vật cuối cùng 
                if(totalWeight + w[i] <= S)
                    res = max(res, totalValue + v[i]);
            }else{
                if(totalWeight <= S)
                    res = max(res, totalValue);
            }
        }
        else{
            //chọn đồ vật x 
            if(x[i] == 1) ql2(i+1, totalWeight + w[i], totalValue + v[i]);
            else //k chọn đồ vật x 
                ql2(i+1, totalWeight, totalValue);
        }
    }
}
void run2(){
    cin >> n >> S;
    f1(i, n) cin >> w[i];
    f1(i, n) cin >> v[i];
    ql2(1, 0, 0);
    cout << res << endl;
}
//----------------------------------------------------------------
//Quay lui ngắt cành 
void ql3(int i, int totalWeight, int totalValue){
    if(totalWeight > S)
        return;
    for(int j=0; j<=1; j++){
        x[i] = j;
        if(i == n) {//chốt 
            //totalWeight là totalWeight của i-1 bước trước 
            if(x[i] == 1){//chọn đồ vật cuối cùng 
                if(totalWeight + w[i] <= S)
                    res = max(res, totalValue + v[i]);
            }else{
                if(totalWeight <= S)
                    res = max(res, totalValue);
            }
        }
        else{
            //chọn đồ vật x 
            if(x[i] == 1) ql2(i+1, totalWeight + w[i], totalValue + v[i]);
            else //k chọn đồ vật x 
                ql2(i+1, totalWeight, totalValue);
        }
    }
}
//----------------------------------------------------------------
//cách trình bày khác ql3
void ql4(int i, int totalWeight, int totalValue){
    for(int j=0; j<=1; j++){
        /*
        lấy     totalWeight + w[i]
        k lấy   totalWeight
        => totalWeight + j*w[i]
        */
        // chỉ cập nhật nếu 
        if(totalWeight + j*w[i] <= S){
            x[i] = j;
            if(i == n) {//chốt 
                //totalWeight là totalWeight của i-1 bước trước 
                if(x[i] == 1){//chọn đồ vật cuối cùng 
                    if(totalWeight + w[i] <= S)
                        res = max(res, totalValue + v[i]);
                }else{
                    if(totalWeight <= S)
                        res = max(res, totalValue);
                }
            }
            else{
                //chọn đồ vật x 
                if(x[i] == 1) ql2(i+1, totalWeight + w[i], totalValue + v[i]);
                else //k chọn đồ vật x 
                    ql2(i+1, totalWeight, totalValue);
            }

        }
        
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}
