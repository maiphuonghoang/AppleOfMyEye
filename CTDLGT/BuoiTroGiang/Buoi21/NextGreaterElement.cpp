#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Next greater element (NGE)
 * Phần tử đầu tiên lớn hơn bên phải 
 * Cho mảng a gồm n phần tử, tìm phần tử đầu tiên bên phải lớn hơn
 * mọi phần tử a[i] trong mảng, nếu phần tử nào k có phần tử bên phải
 * lớn hơn thì in ra -1
 * O(n)
8
19 11 11 15 13 18 19 18
=> -1 15 15 18 18 19 -1 -1 
*/
void next_greater_element(int a[], int n, int d[]){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[i] > a[st.top()]){
            d[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        d[st.top()] = -1;
        st.pop();
    }
}
void run(){
    int n; cin >> n;
    int a[n], d[n];
    for (int &x : a) cin >> x;
    next_greater_element(a, n, d);
    for(int x : d) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}