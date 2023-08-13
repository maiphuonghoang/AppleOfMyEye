#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//----------------------------------------------------------------
/* Dãy con liên tiếp dài nhất có tổng <= S 
11 10
3 1 4 1 5 3 4 1 5 2 2 
=> 4
12 10
3 1 4 1 5 3 4 1 5 2 1 1 
=> 5 
*/
void meDayConDaiNhat(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    while ( right < n){
        if(sum + a[right] <= s){
            sum += a[right]; 
            right++; 
        }else{
            sum -= a[left];
            left++;
        }
        res = max(res, right - left);                 
    }
    cout << res << endl;
}
void dayConDaiNhat(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++){
        sum += a[right];
        //nếu sum > s => the hẹp đoạn [l-r] bằng cách tăng left 
        while(sum > s){
            sum -= a[left];
            left++;
        }
        res = max(res, right - left + 1);                 
    }
    cout << res << endl;
}
/**
In meDayConDaiNhat, the condition for including the next element in the subarray 
is checked using an if statement: if (sum + a[right] <= s).
If the sum condition is satisfied, the element is added to the subarray; otherwise, the left pointer is advanced.

In dayConDaiNhat, the condition for removing elements from the left end of the subarray 
is checked using a while loop: while (sum > s). 
This loop keeps removing elements from the left end until the sum condition is satisfied again.
*/
//----------------------------------------------------------------
/* Dãy con liên tiếp ngắn nhất có tổng >= S 

*/
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dayConDaiNhat();
    cout.flush();
    fclose(stdout);
}
