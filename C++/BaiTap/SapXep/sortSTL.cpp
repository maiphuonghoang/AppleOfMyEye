#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long; 
/**
5
3 6
1 2
3 3
1 9
0 5
=> 
0 5
1 2
1 9
3 3
3 6
*/
void sortVector(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    for (auto it : a) 
        cout << it.first << " " << it.second << endl;
}
//----------------------------------------------------------------
/**
 * Cho mảng a gồm n điểm trong hệ tọa độ Oxy. Hãy sắp xếp các điểm này theo khoảng cách về 
 * gốc tọa độ tăng dần, nếu 2 điểm có cùng khoảng cách thì in ra theo hoàng độ tăng dần,
 * nếu cùng hoành độ thì in theo tung độ tăng dần 
13
-42 -76
47 43
12 7
-62 31
7 64
42 -92
-89 60
45 41
3 54
-41 40
20 -24
88 42
0 12
*/ 
bool cmp(pair<int, int> a, pair<int, int> b){
    //xét khoảng cách tới gốc O
    int kc1 = a.first * a.first + a.second * a.second;
    int kc2 = b.first * b.first + b.second * b.second;
    if(kc1 != kc2) 
        return kc1 < kc2;
    //xét hoành độ
    if(a.first != b.first)
        return a.first < b.first;
    //xét tung độ 
    return a.second < b.second;
}
void pairSortOxy(){
    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort (a, a+n, cmp);
    for (auto it : a)
        cout << it.first << " " << it.second << endl;

}
//----------------------------------------------------------------
/**
 * Cho mảng a gồm n phần tử. Sắp xếp sao cho số nào có nhiều số lẻ hơn thì đứng trước
 * trong trường hợp nhiều số có cùng chữ số lẻ thì số nào nhỏ hơn sẽ đứng trước 
11
4456 10493 23600 32757 6911 15236 14074 22458 32132 28596 15209
 * Cho mảng a gồm n phần tử. Sắp xếp sao cho số nào có nhiều số lẻ hơn thì đứng trước
 * trong trường hợp nhiều số có cùng chữ số lẻ thì giữ nguyên thứ tự xuất hiện 
10
2 4 60 80 888 111 777 333 444 999
*/
int countOdd(int n){
    int cnt = 0;
    while(n){
        if(n%2 == 1) cnt++;
        n /= 10;
    }
    return cnt;
}
bool cmpOdd(int a, int b){
    if(countOdd(a) != countOdd(b)) 
        return countOdd(a) < countOdd(b);
    return a < b;
}
bool cmpLe(int a, int b){ 
    return countOdd(a) < countOdd(b);
}
void sortOdd(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, cmpOdd);
    for (auto it : a) cout << it << ' ';cout << endl;
    stable_sort(a, a+n, cmpLe);
    for (auto it : a) cout << it << ' ';
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    //O(NlogN) = intro sort: quick sort + heap sort
    //sort(a, a+n); => [0, n-1]
    //sort trên mảng sort(a+x, a+y+1)  sắp xếp từ vị trí x đến y 
    //sort(a, a+n, greater<int>()) giảm dần
    //sort(v.begin(), v.end()) 
    //sort trên vector sort(v.begin() + x, v.end() + y + 1)
    sortOdd();
    return 0;
}