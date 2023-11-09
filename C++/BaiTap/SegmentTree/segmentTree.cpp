#include <bits/stdc++.h>
using namespace std;


const int maxn = 10001;
int a[maxn], n;
int t[4*maxn];

//BUILD 
/*
6
1 3 5 7 9 11
=> 36 9 27 4 5 16 11 1 3 0 0 7 9
*/
// t[v] = tổng các phần tử từ chỉ số l tới r 
void build (int v, int l, int r){
    if(l == r)
        t[v] = a[l];
    else{
        int m = (l + r) / 2;
        build(2*v, l, m);
        build(2*v + 1, m + 1, r);
        t[v] = t[2*v] + t[2*v + 1];
    }
}
void run1(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    build(1, 0, n - 1);
    for (int i = 1; i <= 20; i++) cout << t[i] << " ";
}
//----------------------------------------------------------------
// QUERY: Tính tổng các ptu từ chỉ số l tới r 
/*
8 
2 3 1 4 2 7 6 8
1 5
=>
sum[1-5]=17
*/
int sum(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    else{
        int tm = (tl + tr) / 2;
        return sum(2*v, tl, tm, l, min(tm, r)) + sum(2*v+1, tm+1, tr, max(tm + 1, l), r);
    }
}

void run2(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    
    int l, r; cin >> l >> r;
    cout << "sum[" << l <<"-"<<r << "]="<< sum(1, 0, n-1, l, r) << endl;
}
//----------------------------------------------------------------
//UPDATE a[pos] = val
/*
4
1 3 7 4
=> 15 4 11 1 3 7 4 
a[2] = 5
=> 13 4  9 1 3 5 4
*/
void update (int v, int l, int r, int pos, int val){
    if(l == r) 
    //đến node lá đại diện cho 1 ptu trong mảng a có chỉ số là pos 
        t[v] = val;
    else{
        int m = (l + r) / 2;
        if(pos <= m)
        //pos nằm ở nửa bên trái 
            update(2*v, l, m, pos, val);
        else
            update(2*v+1, m + 1, r, pos, val); 

        // Cập nhật node cha nếu node lá thay đổi 
        t[v] = t[2*v] + t[2*v+1];   
    }
}
void run3(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 1; i <= 8; i++) cout << t[i] << " ";
    cout << endl;

    update(1, 0, n - 1, 2, 5);//a[2] = 5
    for (int i = 1; i <= 8; i++) cout << t[i] << " ";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run3();
    return 0;
}