#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/**Trộn 2 mảng đã sắp xếp thành 1 mảng và sắp xếp theo thứ tự tăng dần 
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
/* Đối với mỗi phần tử trong mảng b, hãy đếm xem trong mảng a có bao nhiêu phần tử nhỏ hơn nó
7 6
1 2 3 4 8 9 17
3 3 8 9 11
=> 2 2 4 5 6 7 
*/
void smaller(){//O(n+m)
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    int i = 0, j = 0;
    while(i < n && j < m){
        if (a[i] < b[j])
            i++;
        else{
            cout << i << " " ;
            j++;
        }
    }
    while(i<n){
        cout << m << " ";
    }
    while(j<m){
        cout << n << " ";
        j++;
    }
}
//----------------------------------------------------------------
/* Đếm xem trong 2 mảng tồn tại bao nhiêu cặp i,j sao cho a[i] = b[j]
8 10
1 1 2 2 2 3 4 8 
1 1 1 2 2 3 3 4 8 9
=>2*3 + 2*3 + 1*2 + 1*1 + 1*1 = 16
*/
void numberOfEqual(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    int i = 0, j = 0;
    long long ans = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            int dem1 = 0, dem2 = 0;
            //đếm trong mảng a có bn thằng đứng sau = nó 
            while(a[i] == b[j]){
                dem1++;
                i++;
                }
            //đếm trong mảng b có bn thằng bằng thằng đang xét trong a 
            while(b[j] == a[i-1]){
                dem2++;
                j++;
            }                              
            ans += 1ll * dem1 * dem2;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else j++;    
    } 
    cout << ans << endl;   
}
//----------------------------------------------------------------
/* a[i] + a[j] = k 
7 11 
1 3 4 8 9 14 23 
*/
int twoSum(){
    int n, k; cin >> n >> k;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n);

    int l = 0, r = n-1;
    while (l < r){
        if(a[l] + a[r] == k)
            return 1;
        else if(a[l] + a[r] > k)
            r--;
        else l++;
    }
    return 0;
}
//----------------------------------------------------------------
/* a[i] + a[j] + a[k] = s 
Cố định i, xét xem có cặp a[j] + a[k] = s - a[i] không   
*/
int threeSum(){
    int n, s; cin >> n >> s;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n);

    for (int i = 0; i < n - 2 ; i++){
        int l = i + 1, r = n - 1;
        int k = s - a[i];
        while (l < r){
            if(a[l] + a[r] == k)
                return 1;
            else if(a[l] + a[r] > k)
                r--;
            else l++;
        }
    }
    return 0;
}
//----------------------------------------------------------------
/* a[i] + a[j] + a[k] + a[l] = s 
Cố định a[i], a[j]   
*/
int fourSum(){
    int n, s; cin >> n >> s;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n);

    for (int i = 0; i < n - 1 ; i++)
        for (int j = i + 1; j < n; j++){
            int l = j + 1, r = n - 1;
            int k = s - a[i] - a[j];
            while (l < r){
                if(a[l] + a[r] == k)
                    return 1;
                else if(a[l] + a[r] > k)
                    r--;
                else l++;
            }
        }
    
    return 0;
}
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    numberOfEqual();
    cout.flush();
    fclose(stdout);
}
