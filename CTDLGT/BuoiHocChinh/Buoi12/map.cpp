#include <bits/stdc++.h>
using namespace std;
void basicMap(){
    map<int, int> mp;
    mp[1] = 10;
    mp[2] = 20;
    mp.insert({3, 30});
    mp.insert({4, 40});
    cout << mp.count(1)<< endl;
    if(mp.find(1) != mp.end()) cout << "Found";

    //duyệt 
    for (pair<int, int> x: mp) 
        cout << x.first << "-" << x.second << endl;
    for (auto x : mp)
        cout << x.first << "-" << x.second << endl;

    for (map<int, int>::iterator it = mp.begin(); it != mp.end();it++){
        cout << it->first << "-" << it->second << endl;
        cout << (*it).first << "-" << (*it).second << endl;
    }
}
//----------------------------------------------------------------
void demTanXuat1(){//theo thứ tự tăng dần 
    map<int, int> mp;
    // map[ptu chưa xuất hiện] = 0
    cout << mp[1];
    int n; cin >> n;
    for (int i=0; i<n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    for (auto p : mp) cout << p.first << "-" << p.second << endl;
}
void demTanXuat2(){//theo thứ tự xuất hiện 
    map<int, int> mp;
    int n; cin >> n;
    int a[1000];
    for (int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i<n; i++)
        if(mp[a[i]] > 0){
            cout << a[i] << "-" << mp[a[i]] << " ";
            mp[a[i]] = 0;
        }
} 
//----------------------------------------------------------------
void tanXuatMax1(){
    map<string, int> mp;
    int n; cin >> n;
    for (int i=0; i<n;i++){
        string s; cin >> s;
        mp[s]++;
    }
    for (auto p : mp) cout << p.first << "-" << p.second << endl;

    int max_fre = 0;
    string res;
    for (auto p : mp)
        if(p.second > max_fre) {
            max_fre = p.second;
            res = p.first;
        }
    cout << "Tu co tan xuat xuat hien max " + res;
    
}
void tanXuatMax2(){//nếu có nhiều từ có cùng tần xuất thì lấy từ có thứ tự từ điển nhỏ/lớn nhất 
    map<string, int> mp;
    int n; cin >> n;
    for (int i=0; i<n;i++){
        string s; cin >> s;
        mp[s]++;
    }
    for (auto p : mp) cout << p.first << "-" << p.second << endl;

    int max_fre = 0;
    string res;
    for (auto p : mp)
        if(p.second > max_fre) {
            max_fre = p.second;
            res = p.first;
        }
    cout << "Tu co tan xuat xuat hien max co thu tu tu dien nho hon " + res << endl;
    for (auto p : mp)
        if(p.second >= max_fre) {
            max_fre = p.second;
            res = p.first;
        }
    cout << "Tu co tan xuat xuat hien max co thu tu tu dien lon hon " + res << endl;
}
//----------------------------------------------------------------
void basicMultimap(){
    multimap<int, int> mp;
    mp.insert({1, 100});
    mp.insert({1, 100});
    mp.insert({1, 200});
    cout << mp.count(1);//đếm 3 thằng có key là 1

    for (auto p : mp) cout << p.first << "-" << p.second << endl;
}
void basicUnorderedMap(){
    unordered_map<int, int> mp;
    mp.insert({1, 100});
    mp.insert({1, 100});//k lưu key trùng 
    mp.insert({5, 200});
    mp.insert({2, 200});
    mp.insert({3, 300});
    cout << mp.count(1);

    for (auto p : mp) cout << p.first << "-" << p.second << endl;
}
int main() {
    basicUnorderedMap();
    return 0;
}