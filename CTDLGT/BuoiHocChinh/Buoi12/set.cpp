#include <bits/stdc++.h>
using namespace std;

void basicSet(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    cout << s.size() << endl;
    cout << s.count(5) << " " << s.count(3) << endl;

    //nhập 
    for (int i = 0; i < 10; i++)
        s.insert(i);
    cout <<"Phan tu dau tien "<< *s.begin() << endl;
    cout <<"Phan tu cuoi cung "<< *s.end()  << " or " << *s.rbegin() << endl;

    set<string> ss;
    for (int i = 0; i < 10; i++){
        string str; 
        getline(cin, str);
        ss.insert(str);
    }
    
    //tìm kiếm
    if(s.find(5) != s.end()) cout << "Found";
    else cout << "Not found";

    //xóa 
    s.erase(5);
    s.erase(s.find(6));
    s.erase(s.begin());

    //duyệt
    for (int x : s) cout << x << " ";
    for (auto x : s) cout << x << " ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    
}
void basicMultiset(){
    multiset<int> ms;
    ms.insert(100);
    ms.insert(200);
    ms.insert(100);   
    ms.insert(200);

    cout << ms.count(100) << endl; 

    ms.erase(100); //xóa hết tất cả các ptu = 100 trong set 
    for (int x : ms) cout << x << " ";

    //xóa trong multi set thì xóa iterator 
}
/**
 * Cho mảng có n phần tử và số nguyên k, đối với mỗi dãy con liên tiếp có chiều dài k 
 * in ra ptu min/max trong cửa sổ đấy 
multiSet lưu các ptu theo tứ tự tăng dần
=> in ra ptu lớn nhất, xóa đi ptu đầu tiên của cửa số vừa rồi, insert thằng tỏng cửa sổ mới 
*/
int multisetSlidingWindow(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x: a) cin >> x;
    multiset<int> ms;
    for (int i = 0; i<k; i++)
        ms.insert(a[i]);
    for (int i = k; i < n; i++){
        cout << *ms.rbegin() << " ";
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
    }
    cout << *ms.rbegin() << endl;
}
void basicUnOrderedSet(){
    unordered_set<int> s;
    for (int i = 0; i < 10; i++)
        s.insert(i);
    for (int x: s)
        cout << x << " ";
    //9 8 7 6 5 4 0 1 2 3 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    basicUnOrderedSet();
    return 0;
} 