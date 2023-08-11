#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void mePhaTraSua(){
      
    int* d = new int[200000];std::memset(d, 0, 200000 * sizeof(int));
    int* f = new int[200000];
    int* r = new int[200000];std::fill(r, r + 200000, 0);

    int n, k, q; cin >> n >> k >> q;
    for (int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;
        d[l] += 1;
        d[r+1] -= 1;   
    }
    //xây dựng mảng cộng dồn của d là số lượng đường trong mỗi cốc 
    f[0] = d[0];
    for(int i=1; i<10; i++)
        f[i] = f[i-1] + d[i];
    //for (int i=0; i < 10; i++) cout << f[i] << ' '; 

    int dem = 0;
    for (int i = 1; i <= 10; i++){
        if(f[i] >= k) dem++;
        r[i] = dem;
    }
    
    while(q--){
        int left, right; cin >> left >> right;
        cout << r[right] - r[left-1] << endl;
    }
    delete[] d;
    delete[] f;
    delete[] r;
}


int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mePhaTraSua();
    cout.flush();
    fclose(stdout);
}



