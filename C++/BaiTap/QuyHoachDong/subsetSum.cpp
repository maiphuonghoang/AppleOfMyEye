#include <bits/stdc++.h>
using namespace std;

void subsetSum(){
    int n, S; cin >> n >> S;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> dp(S+1, false);
    for (int i = 0; i < n; i++){
        //duyệt từ S về a[i]
        for (int j = S; j >= a[i]; j--){
        //không cần xét tập con có tổng < a[i] vì chắc chắn k thể cho a[i] vào tập con đấy được 
            //nếu đã có tập con có tổng = j-a[i] rồi 
            if(dp[j - a[i]] == true)
                dp[j] = true;
        }
    }
    if(dp[S]) cout << "Tồn tại tập con có tổng = " << S;
    else cout  << "Không tồn tại tập con có tổng = " << S; 
}

//----------------------------------------------------------------
/*
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.
[1,5,11,5] => true 
[1,2,3,5] => false 
*/
void runPartition(){
    vector<int> a1{1,5,11,5}, a2{1,2,3,5}, a3{1,5,11,5,2};
    cout << canPartition(a1) << " " << canPartition(a2) << " " << canPartition(a3);
}
bool canPartition(vector<int>& a) {
    int n = a.size();
    int totalSum = accumulate(a.begin(), a.end(), 0);
    
    // If the total sum is odd, it can't be partitioned 
    //into two equal subsets.
    if (totalSum % 2 != 0) return false;
    
    //check if there is a subset with a sum equal to half of the total sum
    //which would allow you to partition the array into two equal subsets.
    int S = totalSum / 2;
    vector<bool> dp(S + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = S; j >= a[i]; j--) {
            if (dp[j - a[i]]) 
                dp[j] = true;             
        }
    }
    return dp[S]; 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    subsetSum();
    return 0;
}