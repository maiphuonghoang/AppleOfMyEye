#include <bits/stdc++.h>

using namespace std;
void minValue(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int min_val = 1e9;
    //C1: tìm min rồi so sánh min với các ptu trong mảng 
    int cnt = 0;
    for (int x : a)
        min_val = min(min_val,x);
    for (int x : a)
        if(min_val == x) cnt ++;
    
    //C2: nếu có số nhỏ hơn mới thì cập nhật min, set lại count = 1 không thì tăng count
    min_val = 1e9;
    int count = 1;
    for (int x : a)
        if(x<min_val){
            min_val = x;
            count = 1;//lần đầu tiên được cập nhật 
        }
        else if(x == min_val) count++;   
}
//----------------------------------------------------------------
/**
 * Đếm trong mảng A tồn tại bao nhiêu cặp số A[i][j] (i#j) sao cho 
 * tổng của 2 phần tử này bằng số k cho trước 
5 3
1 2 3 1 2
=> 4
*/
void pairSumK(){
    int n, k; cin >> n>>k;
    int d[1001] = {0};//đánh dấu ngay trong lúc nhập 
    int a[n];
    for (int &x : a) {
        cin >> x;
        d[x]++;//đếm số lần xuất hiện 
    }
    int cnt = 0;
    for (int l = 0; l <= k/2; l++){
        int r = k - l;
        if(l!=r)
            cnt += d[l] * d[r];
        else
            cnt += d[l]*(d[l]-1)/2; //tổ hợp chập 2 của d[l]
    }
    cout << cnt;

}
//----------------------------------------------------------------
/**
 * Cho mảng số nguyên gồm n phần tử, tìm độ chênh lệch nhỏ nhất giữa 2 phần tử trong mảng
8 
69 96 93 27 84 32 78 56
=> 3 
*/
void pairMinSub(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int min_val = 1e9;
    //C1: tìm độ chênh lệch rồi cập nhật min 
    for (int i =0; i < n; i++)
        for (int j = i+1; j <n; j++) {
            int cl = abs(a[i]-a[j]);
            min_val = min(min_val, cl);
        }   
    cout << min_val << endl;     

    //C2: Cố định 1 ptu, tìm ptu > và < ngay kề gtri của nó
    //=> sort, khoảng cách là a[i] - a[i-1]
    min_val = 1e9;   
    sort(a, a+n);
    for (int i =1; i < n; i++)
        min_val =  min(min_val,a[i] - a[i-1]);
    cout << min_val;     
}
//----------------------------------------------------------------
/**
 * Liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện, mỗi giá trị chỉ liệt kê 1 lần 
9
1 3 2 4 1 2 3 4 5
=> 1 3 2 4 5
*/
void TanXuatMot(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    //C1: chỉ in ra khi a[i] đầu tiên (khác a[i-1]thằng còn lại)
    for (int i = 0; i < n; i++){
        int ok=0;
        for (int j = 0; j < i; j++){
            if(a[i]==a[j])  {
                ok=1;
                break;
            }
        }
        if(!ok) cout << a[i] << " ";
    }
    //C3: Mảng đánh dấu tăng biến đếm lần xh (áp chụng chỉ số dương)
    int d[1001] = {0};
    for (int i = 0; i < n; i++){
        d[a[i]]++;
        if(d[a[i]] == 1) cout << a[i]<< " ";
    }
    //C2: chỉ in ra khi a[i] đầu tiên, khử các giá trị sau = -1;
    for (int i = 0; i < n; i++){
        if(a[i]>=0){
            cout << a[i] << " ";
            for(int j = i+1; j <n; j++)
                if(a[j] == a[i]) a[j] = -1;
        }
    }

}   
//----------------------------------------------------------------
/**
 * Liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện
 * kèm theo tân tần xuất tương ứng, mỗi giá trị chỉ liệt kê 1 lần 
*/
void TanXuatTuongUng(){

}
int main(){
    int a[] = {-123482634, 0, 0, 0};//khai báo trong main phần tử đầu tiên là rác 
    //chỉ cần khai báo ptu đầu tiên là 0;
    int d[1001] = {0}; //{0, 0, 0, 0}
    TanXuatMot();
}