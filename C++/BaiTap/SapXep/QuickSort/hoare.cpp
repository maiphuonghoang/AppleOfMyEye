#include <bits/stdc++.h>
using namespace std;

// PHÂN HOẠCH HOARSE 

//phân hoạch đoạn l-r
int partition(int a[], int l, int r){
    int pivot = a[l];//chốt là phần tử bên trái 
    int i = l-1;
    int j = r+1;
    while(1){
        do{
            ++i;
        }while(a[i] < pivot);
        //tìm được phần tử bên trái >= chốt

        do{
            --j;
        }while(a[j] > pivot);
        //tìm được phần tử bên phải <= chốt

        if(i < j)
            swap(a[i], a[j]);
        else return j;
    }
   
}
void quickSort(int a[], int l, int r){
    if(l>=r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p);//gồm luôn cả chốt 
    quickSort(a, p + 1, r);
}

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