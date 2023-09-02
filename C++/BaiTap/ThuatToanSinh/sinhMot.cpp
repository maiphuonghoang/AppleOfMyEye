#include <bits/stdc++.h>
using namespace std;

/**Sinh xâu nhị phân kế tiếp 
2
010101
111111
=> 
010110
000000
*/
void nextXauNhiPhan(string &s){
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if(i != -1) s[i] = '1';
}
void runXauNhiPhan(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        nextXauNhiPhan(s);
        cout << s << endl;
    }
}
//----------------------------------------------------------------
/**Sinh tập con kế tiếp 
2
5 3
1 4 5
5 3 
3 4 5
=>
2 3 4 
1 2 3
*/
int n, k, a[1005];
void nextTapCon(){
    int i = k;
    while(i >= 1 && a[i] == n-k+i)
        i--;
    if(i==0)//là cấu hình cuối cùng
        for(int i=1; i<=k; i++)
            cout << i << " ";
    else{
        a[i]++;
        for (int j=i+1; j<=k; j++)
            a[j] = a[j-1] + 1;
        //in ra cấu hình 
        for (int i=1; i<=k; i++)
            cout << a[i] << " "; 
        cout << endl;
    }       
}
void runSinhTapCon(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i=1; i<=k; i++)
            cin >> a[i];
        nextTapCon();
    }
}
//----------------------------------------------------------------
/**Sinh hoán vị kế tiếp các số khác nhau 
2
5
1 2 3 4 5
5
5 4 3 2 1
=> 
1 2 3 5 4 
1 2 3 4 5
*/
void nextHoanViKhacNhau(){
    int i = n - 1;
    while(i>=1 && a[i] > a[i+1])
        i--;
    if(i==0)
        for (int i=1; i<=n;i++)
            cout << i << " ";
    else{
        int j = n;
        while(a[i] > a[j])
            j--;
        swap(a[i], a[j]);
        reverse(a+i+1, a+n+1);
        for (int i=1; i<=n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
/**
1
13
2 2 7 9 1 3 4 3 9 9 7 4 2
=>
2 2 7 9 1 3 4 4 2 3 7 9 9 
*/
void nextHoanViGiongNhau(){
    int i = n - 1;
    while(i>=1 && a[i] >= a[i+1])
        i--;
    if(i==0)
        for (int i=1; i<=n;i++)
            cout << i << " ";
    else{
        int j = n;
        while(a[i] >= a[j])
            j--;
        swap(a[i], a[j]);
        reverse(a+i+1, a+n+1);
        for (int i=1; i<=n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
void runSinhHoanVi(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        // nextHoanViKhacNhau();
        nextHoanViGiongNhau();
    }    
}
void builtSinhHoanVi(){//áp dụng cả khác và giống nhau 
    int t; cin >> t;
    while(t--){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        if(next_permutation(a+1, a+n+1))//vẫn còn cấu hình đằng sau (chưa là cấu hình cuối cùng)
            for (int i=1; i<=n; i++)
                cout << a[i] << " ";     
        else
            for (int i=1; i<=n; i++)
                cout << i << " ";      
        cout << endl;  
    }      
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    runSinhHoanVi();
    #endif
    return 0;
}
