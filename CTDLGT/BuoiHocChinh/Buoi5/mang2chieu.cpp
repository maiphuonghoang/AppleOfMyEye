#include <bits/stdc++.h>
using namespace std;
void nhap(int a[][100], int n, int m){
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            cin >> a[i][j];
            //cin k đọc dấu cách 
}
void xuat (int a[][100], int n, int m){
    for (int i=0; i< n; i++){
        for (int j=0; j< m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
            
}

void basicMangHaiChieu(){
    int n, m; cin >> n >> m;
    int a[100][100];
    nhap(a, n, m); 
    xuat(a, n, m);
}
/** Mảng có 4 dòng, input đầu là số lượng ptu của mỗi vector 
4
2 | 1 2
3 | 2 3 4
2 | 1 4
5 | 1 6 7 8 9 
*/
void mangVector(){
    int n; cin >> n;
    vector<int> a[n];
    for (int i=0; i< n; i++){
        int m; cin >> m;
        for (int j=0; j< m; j++){
            int x; cin >> x;
            a[i].push_back(x);
        }           
    }
    for (int i=0; i< n; i++){
        for (int j=0; j< a[i].size(); j++){
            cout << a[i][j] << " " ;
            //truy cập đến vector thứ i của ma trận a;
            //[j]: truy cập đến chỉ số j của vector a[i] đó 
        }        
        cout << endl;   
    }
}
void mangString(){
    //3
    //abcd
    //abcef
    //gh
    int n; cin >> n;
    string a[n];//mỗi dòng là 1 string
    cin.ignore(); 
    for (int i=0; i< n; i++){
        getline(cin, a[i]);      
    }
    for (int i=0; i< n; i++){
        cout << a[i] << endl; 
    }
}
/**
4 4
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
=>
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
*/
void inTheoCot(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            cin >> a[i][j];
    
    for (int i=0; i< m; i++){
        for (int j=0; j< n; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    inTheoCot();
    return 0;
}