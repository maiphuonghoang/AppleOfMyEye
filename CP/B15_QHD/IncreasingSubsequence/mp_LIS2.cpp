#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void LIS(){
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<int> v;
    for (int i=0; i<n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);//tìm thằng nhỏ nhất >= a[i]
        if(it == v.end())
            v.push_back(a[i]);
        else{
            *it = a[i];
        }
    }
    cout << v.size() << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    LIS();  
    return 0;
}