#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void basicPriorityQueue(){
    priority_queue<int> pq; //phần tử ở top lớn nhất 
    // priority_queue<int, vector<int>, greater<int>> pq;//phần tử ở top nhỏ nhất 
    pq.push(1);
    pq.push(4);
    pq.push(5);
    pq.push(3);
    cout << pq.top() << endl;
    pq.push(100);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}
//----------------------------------------------------------------
/* Nối dây
Cho N sợi dây với độ dài khác nhau được lưu trong mảng a. Hãy nối n sợi dây 
thành 1 sợi sao cho tổng chii phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây 
thứ i và thứ j là tổng độ dài 2 sợi dây a[i] và a[j]
4
4 3 2 6 
=> 29 (Chi phí min)
38 (Chi phí max)
*/
void noiDay(){
    int n; cin >> n;
    int a[n];
    priority_queue<int, vector<int>, greater<int>> pq;//dùng cho (Chi phí min)
    // priority_queue<int> pq; ////dùng cho (Chi phí max)
    for (int &x : a) {
        cin >> x;
        pq.push(x);
    }
    ll ans = 0; 
    while(pq.size() > 1){//chừng nào trong priority queue chỉ còn 1 sợi dây duy nhất 
        //lấy ra 2 sợi dây ngắn nhất, xóa khỏi queue, cộng tổng lại rồi push tổng vào 
        ll top1 = pq.top(); pq.pop();
        ll top2 = pq.top(); pq.pop();
        ans += top1 + top2;
        pq.push(top1 + top2);
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/* Giá trị nhỏ nhất của xâu 
Cho xâu kí tự S bao gồm các kí tự in hoa [A-Z]. Định nghĩa giá trị của xâu S
là tổng bình phương số lần xuất hiện mỗi kí tự trong xâu. 
VD: S[] = "AABBCD" thì F(S) = 3^2 + 2^2 + 1^2 + 1^2 = 15
Hãy tìm giá trị nhỏ nhất của xâu S sau khi loại bỏ K kí tự trong xâu 
2
0 ABCC 
1 ABCC
=> 6 3 
Xóa những ptu có tần xuất lớn nhất 
*/
void tongBinhPhuongTanXuat(){
    int k; cin >> k;
    string s; cin >> s;
    map<char, int> mp;
    for (char x : s) 
        mp[x]++;
    priority_queue<int> pq;
    for (auto it : mp)
        pq.push(it.second);
    while(k > 0){
        //lấy ra tần xuất lớn nhất trong xâu s
        int top = pq.top();
        pq.pop();
        --top; --k;
        pq.push(max(top, 0));//trong trường hợp k > số ptu thì lấy 0
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += 1ll*pq.top()*pq.top();//tính kqua
        pq.pop();
    }
    cout << ans << endl;

}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    tongBinhPhuongTanXuat();
    return 0;
}