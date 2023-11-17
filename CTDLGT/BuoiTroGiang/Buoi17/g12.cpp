#include <bits/stdc++.h>
using namespace std;
/* dsk sang dsc có hướng 
5
5 3 4
4 1 3 5
4 2
3 1 2
3 2
=> 
1 3
1 4
1 5
2 1
2 3
2 4
2 5
3 2
3 4
4 1
4 2
4 3
5 2
5 3
*/
void xuly(int i, string s){
    stringstream ss(s);
    string token;
    vector<int> v;
    while(ss >> token){
        int j = stoi(token);
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    for (int j : v)
        cout << i << " " << j << endl;
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