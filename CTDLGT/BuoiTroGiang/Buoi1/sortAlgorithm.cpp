#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        //Dùng 1 biến để lưu chỉ số của phần tử nhỏ nhất 
        int min_pos = i;
        //Duyệt tất cả các ptu đứng sau ptu hiện tại và cập nhật chỉ số của phần tử nhỏ nhất 
        for (int j = i + 1; j < n; j++)
            if(a[j] < a[min_pos])
                min_pos = j;
        swap(a[i], a[min_pos]);
    }
}
void bubbleSort(int a[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n - i - 1; j++)
            if(a[j] > a[j+1])
                swap (a[j], a[j+1]);
}
void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int x = a[i];//lấy ra phần tử ở chỉ số i 
        int pos = i - 1;//pos là vị trí hợp lí để chèn x vào pos này,
            //vị trí tiềm năng đầu tiên là vị trí ptu ngay trước 
        while (pos > 0 && a[pos] > x){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
     }
}
/**
2 8 3 1 4 2 4
1 : 1
2 : 2
3 : 1
4 : 2
*/
int cnt[10000001];
void coutingSort(){
    int a[1000];
    int n; cin >> n;
    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;//tần số xh
        m = max(m, a[i]);//ptu lớn nhất trong mảng 
    }
    for (int i = 0; i <= m; i++){
        if(cnt[i] != 0){
            while (cnt[i]){
                cout << i << " ";
                cnt[i] --;
            }
        }
    }
}
void run(){
    int a[1000], n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    selectionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    bubbleSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";cout << endl;
    insertionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";cout << endl;
    coutingSort();
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}