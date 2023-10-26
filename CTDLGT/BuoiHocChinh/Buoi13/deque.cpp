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
lopp: O(nk), deque: O(n), multiset: O(nlogn)
n = 9, k=3;
7 3 1 2 8 6 4 1 0 
=> 7 3 8 8 8 6 4
*/
void loopSlidingWindow(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    //duyệt qua k cửa sổ 
    for (int i = 0; i <= n-k; i++){
        int tmp = INT_MIN;
        for (int j = 0; j < k; j++){
            tmp = max(tmp, a[i+j]);
        }
        cout << tmp << " ";
    }
}
void multisetSlidingWindow(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    
    multiset<int> ms;
    for (int i = 0; i < k; i++){
        ms.insert(a[i]);
    }
    cout << *ms.rbegin() << " ";//truy cập vào ptu cuối cùng trong multiset 

    for (int i = k; i <= n-1; i++){
        //cửa sổ mới bị xóa ptu ở vị trí i-k
        //thêm ptu ở chỉ số i hiện tại vào 
        ms.erase(ms.find(a[i-k]));//chỉ xóa iterator trỏ đến ptu
        ms.insert(a[i]); 
        cout << *ms.rbegin() << " ";
    }
}
void dequeSlidingWindow(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    
    deque<int> q;
    for(int i = 0; i < k; i++){
        while(!q.empty() && a[i] > a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << a[q.front()] << " ";
    for (int i = k; i < n; i++){
        if(q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && a[i] > a[q.back()])
            q.pop_back();
        q.push_back(i);
        cout << a[q.front()] << " ";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    dequeSlidingWindow();
    return 0;
}