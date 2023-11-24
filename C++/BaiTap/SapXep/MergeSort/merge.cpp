#include <bits/stdc++.h>
using namespace std;

// Trộn 2 dãy con: dãy 1 [l,m], dãy 2 [m+1,r]
void merge(int a[], int l, int m, int r){
    //Copy nội dung 
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    // trộn 2 vector x và y thành 1 mảng tăng dần và gán lần lượt vào các ptu trong mảng a 
    // bắt đầu từ chỉ số left 
    int i = 0, j = 0;
    while (i< x.size() && j < y.size()){
        if(x[i]<=y[j]){
            a[l] = x[i]; 
            ++l; ++i;
        }else{
            a[l] = y[j];
            ++l, ++j;
        }
    }
    while(i <x.size()){
        a[l] = x[i]; 
        ++l; ++i;
    }
    while(j <y.size()){
        a[l] = y[j]; 
        ++l; ++j;
    }
}
void mergeSort(int a[], int l, int r){
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}
void run(){
    int n; cin >> n;
    int a[1000];
    for(int i=0; i<n; i++)
        cin >> a[i];
    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout << a[i] << " "; 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}