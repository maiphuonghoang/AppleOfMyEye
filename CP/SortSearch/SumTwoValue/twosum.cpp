#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/**
 * https://cses.fi/problemset/task/1640
*/
int a[200006];
void run1(){//O(n)
    int n, k; cin >> n >> k;
    map<int, vector<int>> mp; // Use a vector to store all positions of each value
    f1(i, n){
        cin >> a[i];
        mp[a[i]].push_back(i);
    } 
    for(int i = 1; i <= n; i++){
        int complement = k - a[i];
        if(mp.count(complement)){
            // Check if the complement is a different value or the same value
            if(complement != a[i]){
                cout << i << " " << mp[complement][0] << endl;
                return;
            }
            // If the complement is the same value, check if there are at least two occurrences
            else if(mp[complement].size() > 1){
                cout << mp[complement][0] << " " << mp[complement][1] << endl;
                return;
            }
        }
    }  
    cout << "IMPOSSIBLE" << endl;
}
//----------------------------------------------------------------
void run(){
    int n, sum; cin >> n >> sum;
    map<int, int> positionOfValue;
    for(int i = 1; i<= n; i++){
        int x; cin >> x;
        if(positionOfValue.count(sum - x)){
            cout << i << " " << positionOfValue[sum - x] << endl;
            return;
        }
        positionOfValue[x] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}