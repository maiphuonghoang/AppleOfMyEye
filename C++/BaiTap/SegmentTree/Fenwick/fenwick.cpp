#include <bits/stdc++.h>
using namespace std;

/*
8
1 2 3 4 5 6 7 8 
=> 14
*/

int const maxn = 1000005;
int a[maxn], BIT[maxn], n;

//a[pos] += val
/*
pos = 3
  0011
& 1101
= 0001
+ 0011 
= 0100 
*/
void update (int pos, int val){
    // từ chỉ số pos tới chỉ số n trên cây bit chứa a[pos] sẽ đc update 
    for (; pos <= n; pos += pos & (-pos)){ 
        // pos & (-pos) = Lấy ra bit cuối cùng của pos, đem cộng với pos ban đầu 
        // & pos và âm pos 
        BIT[pos] += val;
    }
}
// Tính tổng các phần tử từ chỉ số 1 đến chỉ số pos 
/*
pos = 12; 
sinh ra những chỉ số trên cây bit nhỏ hơn 
  1100
- 0100
  1000 chỉ số 8
*/
int query(int pos){
    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos)){
        sum += BIT[pos];
    }
    return sum;
}
void run(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(i, a[i]);
    } 
    // tính tổng ptu từ chỉ số 2 tới 5
    cout << query(5) - query(1) << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}