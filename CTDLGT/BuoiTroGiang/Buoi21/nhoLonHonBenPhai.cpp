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

/** Phần tử nhỏ hơn bên phải 
 * Tìm phần tử đầu tiên nhỏ hơn bên phải của phần tử lớn hơn đầu tiên bên phải của a[i]
A[] = {1,5,3,3,4,1}
1 =>  5 =>  3
5 => -1 => -1
3 =>  4 =>  1 
3 =>  4 =>  1
4 => -1 => -1
1 => -1 => -1
    GR[i]  SR[GR[i]]
in ra a[SR[GR[i]]]
5
11 18 12 18 10
=> 12 -1 10 -1 -1 
*/
// đầu tiên nhỏ hơn bên phải   
void smaller_right(int a[], int n, int SR[]){
    //đi từ trái qua phải 
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            SR[st.top()] = i;//lưu vị trí 
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        SR[st.top()] = -1;
        st.pop();
    }
}
// đầu tiên lớn hơn bên phải   
void greater_right(int a[], int n, int GR[]){
    //đi từ trái qua phải 
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && a[i] > a[st.top()]){
            GR[st.top()] = i;//lưu vị trí 
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        GR[st.top()] = -1;
        st.pop();
    }
}
void run(){
    int n; cin >> n;
    int a[n], GR[n], SR[n];
    for (int &x : a) cin >> x;
    greater_right(a, n, GR);
    smaller_right(a, n, SR);
    f0(i, n){
        if(GR[i] != -1 && SR[GR[i]] != -1)
            cout << a[SR[GR[i]]] << " ";
        else 
            cout << -1 << " ";
    } 

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