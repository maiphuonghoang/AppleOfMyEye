#include <bits/stdc++.h>
#include <deque> 
using namespace std;

int basicDeque(){
    deque<int> dq;
    dq.push_front(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_front(1);
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_front();
    cout << dq.empty() << " " << dq.size() << endl;
}
//----------------------------------------------------------------
/* Sliding window maximum
deque: O(n), multiset: O(nlogn)
*/
void normalSlidingWindow(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    //duyệt qua k cửa sổ 
    for (int i = 0; i <= n-k; i++){
        int tmp = INT_MIN;
        
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    basicDeque();
    return 0;
}