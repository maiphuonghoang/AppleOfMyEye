// DANH SÁCH KỀ SANG MA TRẬN KỀ 
#include <bits/stdc++.h>
using namespace std;
/**
 * Ở mỗi dòng số lượng phần tử là danh sách kề của dòng đấy không biết trước 
 * Cần đọc cả dòng như 1 string rồi tách từng số ra 
*/
/*
5
2 3 4 
1 3 4 5
1 2 4 5
1 2 3 5
2 3 4
=> 
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/
int a[1001][1001];
void run(){
    int n; cin >> n;//số lượng đỉnh 
    cin.ignore();
    for (int i = 1; i <= n; i++){
        string s;//xâu s là các đỉnh kề của đỉnh thứ i 
        getline(cin, s);
        stringstream ss(s); string num;
        while(ss >> num){
            a[i][stoi(num)] = 1;
        }
    }

    //in ra ma trận kề 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}