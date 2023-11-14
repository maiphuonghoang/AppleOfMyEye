#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 
using namespace std;

/*

*/
struct MH{
    string ma, ten, hang, donvi;
    int nhap, ban;
};
string solve(string s){
    string res = "";
    stringstream ss(s);
    string tmp;
    while (ss>>tmp){
        res += toupper(tmp[0]);
    }
    return res;
    
}
bool cmp(MH a, MH b) {
    int ln1 = a.ban - a.nhap;
    int ln2 = b.ban - b.nhap;
    if(ln1 != ln2) 
        return ln1 > ln2;
    else{
        return a.ma < b.ma;
    }
}
void run(){
    int n; cin >> n;
    vector <MH> v;
    map<string, int> mp;
    for (int i = 0; i < n; i++){
        cin.ignore();//loại bỏ phím enter
        string ten; getline(cin, ten);
        string hang; getline(cin, hang);
        string donvi; getline(cin, donvi);
        int nhap, ban; cin >> nhap >> ban;
        // Cấp mã mặt hàng 
        string ma = solve(ten);
        mp[ma]++;
        string tmp = to_string(mp[ma]);
        while (tmp.size() < 4){
            tmp = "0" + tmp;
        }
        ma = ma + tmp;
        
        MH x {ma, ten, hang, donvi, nhap, ban};
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v)
        cout << it.ma << " " << it.ten << " " << it.hang << " " << it.nhap << " " << it.ban << endl;
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