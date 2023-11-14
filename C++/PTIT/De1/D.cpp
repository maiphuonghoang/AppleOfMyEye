#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 
using namespace std;

/*

*/

void run(){
    int n; cin >> n;
    map<string, pair<string,bool>> mp;//boll đánh dấu fail hay k 
    cin.ignore();
    for (int i=0; i<n;i++){
        string s; getline(cin, s);
        vector<string> v;
        string tmp;
        stringstream ss(s);
        while (ss >> tmp){
            v.push_back(tmp);
        }
        string msv = v[0], hoten = "";
        for (int i=1; i<v.size(); i++)
            hoten += v[i] + " ";
        hoten.pop_back();  //xóa dấu cách cuối trong tên 
        mp[msv].first = hoten;
        mp[msv].second = true;//ban đầu cho tất cả đều dự thi 
    }
    int m; cin >> m;
    set<string> duthi;
    for (int i=0; i<m; i++){
        string x, y, z, t; cin >> x >> y >> z >> t;
        if(t != "code.ptit.edu.vn")
            mp[z].second = false;
        if(t == "code.ptit.edu.vn")
            duthi.insert(z);
    }
    for (auto it : mp){
        cout << it.first << " " << it.second.first << " ";
        if(it.second.second == false || duthi.count(it.first) == 0)
            cout << "FAIL\n";
        else 
            cout << "OK\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}