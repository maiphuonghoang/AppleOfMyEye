#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/**
6 6
1 2 4 4 9 10
4 4 5 6 6 8 
=> 1 2 4 4 4 4 5 6 6 8 9 10 
*/
void tron2Day(){//O(n+m)
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i] <= b[j]){
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
    }
    while(i<n){
        cout << a[i] << " ";
        i++;
    }
    while(j<m){
        cout << b[j] << " ";
        j++;
    }
}
//----------------------------------------------------------------
void smaller(){
    
}
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tron2Day();
    cout.flush();
    fclose(stdout);
}
