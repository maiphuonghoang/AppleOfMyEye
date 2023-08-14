#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/**
Tìm phần giao của 2 mảng và hiển thị theo thứ tự xuất hiện 
10 9
7 5 0 0 1 6 2 7 3 3
6 4 9 4 2 8 3 5 3
=> 5 6 2 3
*/
void giaoMang(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    set<int> setB;
    for (int &x : a) cin >> x;
    for (int &x : b) {
        cin >> x;
        setB.insert(x);
    };
    for (int i = 0; i < n; i++) 
        if(setB.count(a[i])){
            cout << a[i] << " ";
            setB.erase(a[i]);
        }
}
/*Tìm phần giao của 2 mảng và hiển thị theo thứ tự tăng dần 
5 6
1 2 1 2 7 
1 3 4 5 2 6
=> Mảng đánh dấu 
1 2
1 2 3 4 5 6 7  
*/
int dA[10000005];
int dB[10000005];
void giaoHopMangDanhDau(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    
    for (int &x : a)  {
        cin >> x;
        dA[x]++;
    };
    for (int &x : b) {
        cin >> x;
        dB[x]++;
    };
    vector<int> giao, hop;
    //mảng đánh dấu: tăng dần và duy nhất 
    for (int val=0; val<= 1e7; val++){
        if(dA[val] && dB[val])
            giao.push_back(val);
        if(dA[val] || dB[val])//chỉ thuộc 1 trong 2
            hop.push_back(val);
    }
    for (int x : giao) cout << x << " ";
    cout << endl;
    for (int x : hop) cout << x << " ";
    
}
/**
 * Cho 2 mảng số nguyên a và b có các phần tử trong mảng là đôi 1 khác nhau 
 * và theo thứ tự tăng dần. Tìm phần giao và hợp 
 * -1e7 < ai <1e7
=> Số âm nên không dùng mảng đánh dấu 
4 5
1 2 3 4
2 3 5 6 7 
=> Hai con trỏ 
2 3 
1 2 3 4 5 6 7  
*/
void giaoHopMang2Pointer(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> giao, hop;
    int i = 0, j = 0;
    //O(n+m)
    while (i<n && j<m){
        if (a[i] == b[j]){
            giao.push_back(a[i]);
            hop.push_back(a[i]);
            i++; j++;
        }
        else if (a[i] < b[j]){
            hop.push_back(a[i]);
            i++;
        }else{
            hop.push_back(b[j]);
            j++;
        }
    }
    while (i<n) hop.push_back(a[i++]);
    while (j<m) hop.push_back(b[j++]);

    for (int x : giao) cout << x << " ";
    cout << endl;
    for (int x : hop) cout << x << " ";
}
//----------------------------------------------------------------
/**
Kiểm tra xem mảng đã cho có tăng chặt hay không, 
tức là các phần tử đứng sau luôn lớn hơn phần tử đứng trước nó 
*/
int tangChat(){
    //thằng đằng sau > thằng đằng trước thì đi từ 1
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    
    for (int i = 1; i < n; i++)
        if(a[i] <= a[i-1])
            return 0;
    return 1;
}
//----------------------------------------------------------------
/**
Số phần tử trong dãy lớn hơn tất cả các số dứng trước nó  
6
2 6 1 3 9 9 
=> 2 6 9
Phần tử này phải lớn hơn max của tất cả những thằng đứng trước  
*/ 
int maxDungTruoc(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int max = -1e9, count = 0;

    for (int i = 0; i < n; i++){
        if(a[i] > max){
            //mỗi lần cập nhật max nghĩa là giá trị đấy > max (> toàn bộ thằng đứng trước)
            cout << a[i] << " " ;
            max = a[i];
        }
    }       
}
//----------------------------------------------------------------
/** Bán vé và trả lại 
5 
25 25 25 50 50
=> Yes 
*/
int dieHard(){
    int n; cin >> n;
    int a[n], d[101] = {0};
    for (int &x : a) cin >> x;
    
    for (int i = 0; i < n; i++){
        if(a[i] == 25)
            d[25]++;
        else if(a[i] == 50){
            if(d[25] == 0) return 0;
            d[25]--;
            d[50]++;
        }else{
            if(d[25] >= 1 && d[50]>=1) {
                d[25]--; 
                d[50]--;
                d[100]++;
            }else if(d[25] >= 3){
                d[25] -= 3;
                d[100]++;
            }
            else return 0;
        }
    }
    return 1;
}
//----------------------------------------------------------------
/**
4
-5 -2 2 7
=> 
3 12
3 9
4 7
5 12
dãy đã tăng dần
min = gửi cho 2 hàng xóm 
max = gửi cho đầu và cuối 
*/
void MiniMaxiRoad(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;    

    //thằng đầu 
    cout << a[1] - a[0] << " "<< a[n-1] - a[0]<< endl;
    //duyệt các phần tử ở giữa 
    for (int i = 1; i < n-1; i++){
        int mini = min(a[i] - a[i-1], a[i+1]-a[i]);
        int maxi = max(a[i] - a[0], a[n-1]-a[i]);
        cout << mini << " " << maxi << endl;
    }
    //thằng cuối 
    cout << a[n-1] - a[n-2] << " "<< a[n-1] - a[0]<< endl;
}
//----------------------------------------------------------------
/* Đếm cặp số nguyên tố cùng nhau trong mảng 
5
2 4 8 3 6
3
*/
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
void nguyenToCungNhau(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;  

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if(gcd(a[i], a[j]) == 1) {
                count++;
                cout << a[i] << " " << a[j] << endl;
            }
    cout << count << endl;
}
//----------------------------------------------------------------
/**
Tần xuất xuất hiện các phần tử theo thứ tự từ nhỏ đến lớn 
8
2 1 2 3 4 8 2 3
=>
1 1 
2 3
3 2
4 1 
8 1   
*/
int d[10000005];
void tanXuat(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        d[x]++;
    }
    //In theo sắp xếp 
    for (int i=0; i<= 1e7; i++)
        if(d[i])
            cout<< i << " " << d[i] << endl; 
    //In theo thứ tự xuất hiện 
    for (int i=0; i< n; i++)
        if(d[a[i]]){
            cout<< a[i] << " "<< d[a[i]] << endl;          
            d[a[i]] = 0;
        }         
}
//----------------------------------------------------------------
/** In ra các số nguyên tố trong dãy theo thứ tự tăng dần kèm theo tần xuất của nó 
Dùng map => thứ tự tăng dần 
thứ tự xuất hiện (vector) + chỉ lưu lần đầu xh 
2 3 5 3 2 5 1
=>
2 2 
3 2 
5 2
*/
void tanXuatPrime(){
    int n;
    vector <int> v;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    giaoHopMang2Pointer();
    return 0;
}