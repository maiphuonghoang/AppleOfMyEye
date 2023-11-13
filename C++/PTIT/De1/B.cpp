#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 
using namespace std;

/*
6
1 2 3 4 5 6
4
1 1
2 6
3 1
3 6
=>
Yes
No
*/

// multiset: xóa và truy vấn log(n)
void run(){
    multiset<int> ms;
    int n; cin >> n; 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ms.insert(x);
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        //x thao tác, y: gtri phần tử 
        if(x == 1) ms.insert(y);
        else if(x == 2) {
            // tồn tại mới xóa 
            auto it = ms.find(y);
            if(it != ms.end())
                ms.erase(it);//xóa 1, thông qua iterator  
                // ms.erase(y);//xóa hết 
        }else{
            if(ms.find(y) != ms.end()){
                cout << "YES", el;
            }
            else{
                cout << "NO", el;
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}