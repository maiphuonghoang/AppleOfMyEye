#include <bits/stdc++.h>
using namespace std;

// PHÂN HOẠCH LOMUTO 

//phân hoạch đoạn l-r
int partition(int a[], int l, int r){
    int pivot = a[r];//chốt là phần tử cuối cùng 
    int i = l-1;
    for (int j = l; j < r; j++){
        if(a[j] <=  pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    //đưa chốt về giữa
    ++i;
    swap(a[i], a[r]);
    return i; //vị trí chốt sau khi phân hoạch
}
void quickSort(int a[], int l, int r){
    if(l>=r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p -1);//k gồm chốt 
    quickSort(a, p + 1, r);
}
/*
8
9 -3 5 2 6 8 -6 1 3 
*/
void run(){
    int n; cin >> n;
    int a[1000];
    for(int i=0; i<n; i++)
        cin >> a[i];
    quickSort(a, 0, n-1);
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