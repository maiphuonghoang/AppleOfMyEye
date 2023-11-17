// Dsk -> Dsc có hướng
#include <bits/stdc++.h>
using namespace std;
/*
5
4
3 4 5 
2 5
1 2
2 3 
=> 
1 4
2 3
2 4
2 5
3 5
*/
void xuly(int i, string s){
    stringstream ss(s);
    string token;
    while(ss >> token){
        int j = stoi(token);
        if(j>i)
            cout << i << " " << j << endl;
    }
}
void run(){
    int n; cin >> n;
    cin.ignore();
    for (int i=1; i<=n; i++){
        string s; getline(cin, s);
        xuly(i, s);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}