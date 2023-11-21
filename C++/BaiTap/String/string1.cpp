#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using namespace std;

/** Đếm từ trong xâu 
python   java php  C++
*/
void run1(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word; 
    int cnt = 0;
    while(ss >> word){
        ++cnt;
    } 
    cout << cnt << endl;
}
//----------------------------------------------------------------
/** Xóa từ trong xâu 
lap  trinh python   java c lap trinh 
trinh
=> lap python java c lap
*/
void run2(){
    string s; getline(cin, s);
    string word; cin >> word;
    stringstream ss(s);
    string token;
    vector<string> v;
    while (ss >> token)
    {
        if(token != word) 
            v.push_back(token);
    }
    f0(i,v.size()){
        cout << v[i];
        if(i != v.size() - 1)
            cout << " ";
    }
}
//----------------------------------------
/**Tạo email 
2
NguYEN VAN   maNH
    nGUYEN   thuY LinH
=>
manhnv@gmail.com
linhnt@gmail.com
*/
void run3(){
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s; getline(cin, s);
        f0(i, s.length()){
            s[i] = tolower(s[i]);
        }
        vector<string> v;
        stringstream ss(s); string tmp;
        while(ss >> tmp) {
            v.push_back(tmp);
        }
        string email = v.back();//tên 
        f0(i, v.size() - 1)
            email += v[i][0];//chữ đầu của họ và đệm 
        email += "@gmail.com";
        cout << email, el;
    }
}
/**Tạo email 
5
NguYEN VAN   maNH
    nGUYEN   thuY LinH
nguyen VU MANH
NGUYEN THU linh
Hoang dinh NAM
=>
manhnv@gmail.com
linhnt@gmail.com
manhnv2@gmail.com
linhnt2@gmail.com
namhd@gmail.com
*/
void run4(){
    int t; cin >> t;
    cin.ignore();
    map<string, int> mp;
    while (t--)
    {
        string s; getline(cin, s);
        f0(i, s.length()){
            s[i] = tolower(s[i]);
        }
        vector<string> v;
        stringstream ss(s); string tmp;
        while(ss >> tmp) {
            mp[tmp]++;
            v.push_back(tmp);
        }
        string email = v.back();
        f0(i, v.size() - 1)
            email += v[i][0];
        if(mp[email] == 0)// mp.find(email) == mp.end()  mp.count(email)==0
            cout << email << "@gmail.com" << endl;
        else
            cout << email << mp[email] + 1 << "@gmail.com" << endl;
        mp[email]++;
    }
}
//----------------------------------------------------------------
/**Chuẩn hóa tên 
2
NguYEN VAN   maNH
    nGUYEN   thuY LinH
=>
Nguyen Van, MANH
Nguyen Thuy, LINH
*/
void vietHoa(string &s){
    f0(i, s.length())
        s[i] = toupper(s[i]);
}
void chuanHoa(string &s){
    s[0] = toupper(s[0]);//chữ đầu viết hoa 
    for(int i=1; i<s.length(); i++)//các chữ sau viết thường 
        s[i] = tolower(s[i]);
}
void run5(){
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s; getline(cin, s);
        vector<string> v;
        stringstream ss(s); string tmp;
        while(ss >> tmp) {
            v.push_back(tmp);
        }
        for(int i=0; i<v.size()-1; i++){
            chuanHoa(v[i]);
            cout << v[i];
            if(i==v.size()-2) cout << ", ";
            else cout << " ";
        }
        vietHoa(v.back());
        cout << v[v.size()-1], el;
    }
}
/**Chuẩn hóa tên 
2
NguYEN VAN   maNH
    nGUYEN   thuY LinH
=>
Manh, Nguyen Van
Linh, Nguyen Thuy
*/
void run6(){
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s; getline(cin, s);
        vector<string> v;
        stringstream ss(s); string tmp;
        while(ss >> tmp) v.push_back(tmp);
        chuanHoa(v.back());
        cout << v.back() << ", ";
        for(int i=0; i<v.size()-1; i++){
            chuanHoa(v[i]); cout << v[i];
            if(i!=v.size()-2) 
                cout << " ";
        }
        el;
    }
}
//----------------------------------------------------------------
/**Xâu Pangram (chứa đầy đủ các kí tự thường từ a-z)
 * dùng set hoặc mảng đánh dấu 
thequickbrownfoxjumpsoverthelazydog => YES
abcdefghilkmnopzzutvlt => NO
*/
void run7(){
    string s; cin >> s;
    //c1 O(nlogn)
    set<char> se;
    for(char a : s) se.insert(a);
    se.size() == 26 ? yes : no;

    //c2 O(n)
    int a[26] = {0};
    for(char x : s)
        a[x-'a'] = 1;//chuyển kí tự sang số 0..25 a..z
    for(int i = 0; i < 26; i++)
        if(!a[i]){
            no; return;
        } 
    yes;
}
/** Xác định xem có thể thực hiện nhiều nhất K phép biến đổi các kí tự
 * để S trở thành xâu Pangram không. Mỗi phép biến đổi là 1 phép thay thế
 * kí tự này bằng 1 kí tự khác 
 * 
2
qwqqwqeqqwdsdadsdasadsfsdsdasasas
4
qwqqwqeqqwdsdadsdasadsfsdsdasasas
24
=> NO YES
*/
void run(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int k; cin >> k;
        if(s.length() < 26) no;
        set<char> se;
        for(char x : s) se.insert(x);
        (26 - se.size() <= k)? yes : no;
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