#include <bits/stdc++.h>
using namespace std;

/** Đếm số lượng cặp nghịch thế trong mảng 
 * Phần tử đứng trước lớn hơn phần tử đứng sau 
 * a[i] > a[j] và i<j
8 2 1 9 7 3 
(8,2)(8,1)(8,7)(8,3)(2,1)(9,7)(2,1)(7,3)

Lúc merge, phát hiện ptu thuộc dãy trái > phải thì những ptu sau ptu trái hiện tại đó cũng >
[l-m]   1 8 9 10
[m+1,r] 2 3 4 12
1<2 i=1, j=1; ++i
8>2 (8,2)(9,2)(10,2) ++j, j=2, i=2
8>3 (8,3)(9,3)(10,3) ++j, j=3, i=2
8>4 (8,4)(9,4)(10,4) ++j, j=4, i=2
8<12 ++i, i=3, j=4
9<12 ++i, i=4, j=4
10<12 ++i, i=5, j=4

6
8 7 1 9 2 3 
=> 9
*/
int merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int i = 0, j = 0;
    int cnt = 0;
    while (i< x.size() && j < y.size()){
        if(x[i]<=y[j]){
            a[l] = x[i]; 
            ++l; ++i;
        }else{//tạo thành cặp nghịch thế 
            //từ chỉ số i tới các ptu mảng x
            cnt += x.size() - i; 
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
    return cnt;
}
int mergeSort(int a[], int l, int r){
    int dem = 0;
    if(l < r){
        int m = (l+r)/2;
        dem += mergeSort(a, l, m);//số lượng cặp nghịch thế bên trái 
        dem +=mergeSort(a, m+1, r);//số lượng cặp nghịch thế bên phải 
        dem +=merge(a, l, m, r); //1 ptu bên trái, 1 bên phải 
    }
    return dem;
}
int bruteforce(int a[], int n){
    int cnt = 0;
    for(int i = 0; i <n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] > a[j]) ++cnt;
        }
    }
    return cnt;
}
void run(){
    int n; cin >> n;
    int a[1000];
    for(int i=0; i<n; i++)
        cin >> a[i];
    cout << bruteforce(a, n) << endl;
    cout << mergeSort(a, 0, n-1) << endl;
    
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}