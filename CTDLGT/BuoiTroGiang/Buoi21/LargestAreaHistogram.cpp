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

/** Largest Area in a Histogram 
 * Cho 1 biểu đồ gồm các cột với chiều cao h[i].
 * Tìm hình chữ nhật có diện tích lớn nhất 
 * che phủ các cột trong biểu đồ 
 * L lỗi -1
 * R lỗi n 
7
6 2 5 4 5 1 6 
=> 12
L[]: -1 -1 1 1 3 -1 5
R[]: 1 5 3 5 5 7 7
*/

// đầu tiên nhỏ hơn bên trái  
void smaller_left(int a[], int n, int L[]){
    //đi từ phải qua trái 
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && a[i] < a[st.top()]){
            L[st.top()] = i;//lưu vị trí 
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        L[st.top()] = -1;
        st.pop();
    }
}
// đầu tiên nhỏ hơn bên phải   
void smaller_right(int a[], int n, int R[]){
    //đi từ trái qua phải 
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            R[st.top()] = i;//lưu vị trí 
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        R[st.top()] = n;
        st.pop();
    }
}
void run(){
    int n; cin >> n;
    int a[n], L[n], R[n];
    for(int &x : a) cin >> x;
    smaller_left(a, n, L);
    smaller_right(a, n, R);
    ll res = 0;
    for (int x : L) cout << x << " "; el;
    for (int x : R) cout << x << " "; el;
    for (int i = 0; i < n; i++){
        int w = R[i] - L[i] - 1;
        ll dt =  1ll * a[i] * w;
        res = max(res, dt);
    }
    cout << res;
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