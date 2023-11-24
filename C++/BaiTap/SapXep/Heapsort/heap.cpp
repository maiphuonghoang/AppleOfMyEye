#include <bits/stdc++.h>
using namespace std;

// Heapify mảng a có n ptu và bắt đầu từ chỉ số i 
void heapify(int a[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    //i có con trái và gtri con trái lớn hơn i 
    // thì cập nhật chỉ số mới cho largest
    if(l < n && a[l] > a[largest])
        largest = l;

    if(r < n && a[r] > a[largest])
        largest = r;

    // node gốc chưa lớn nhất 
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapsort(int a[], int n){
    // Xây dựng maxheap, bắt đầu từ chỉ số k phải node lá 
    for(int i=n/2-1; i>=0; i--)
        heapify(a, n, i);
    
    for(int i=n-1; i>=0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
void run(){
    int n; cin >> n;
    int a[1000];
    for(int i=0; i<n; i++)
        cin >> a[i];
    heapsort(a, n);
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