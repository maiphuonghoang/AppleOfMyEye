#include <bits/stdc++.h>
using namespace std;
/**
 * Đếm số lượng phần tử khác nhau trong mảng số nguyên 
2
5
1 2 2 2 1
4
1 -2 3 4 
=> 2 4 
*/
void numDifferSet(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            s.insert(x);
        }
        cout <<"dung set " +  s.size() << endl;
    }
        
}
void numDifferMap(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, bool> mp;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            mp[x] = true;
        }
        cout <<"dung map " <<  mp.size() << endl;
    }
}

void numDifferSort(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; 
        for (int &x : a) cin >> x;

        sort(a, a+n);
        int count = 1;
        for (int i = 1; i<n ;i++){
            if(a[i] != a[i-1])
                ++count;
        }
    }  
}
//----------------------------------------------------------------
/**
 * Cho 1 mảng số nguyên có n phần tử, với mỗi truy vấn kiểm tra xem 
 * 1 số nào đó có nằm trong mảng hay không 
Dùng binary_search, set, map 
*/
void checkExistSearch(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; 
        for (int &x : a) cin >> x;

        sort(a, a+n);
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            if(binary_search(a, a+n, x))
                cout << "Yes ";
            else cout << "No ";
            
        }
    }  
}
void checkExistSet(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<int> se;
        for (int i = 0; i<n; i++){
            int x; cin >> x;
            se.insert(x);
        }
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            if(se.count(x) == 1) cout << "Yes ";
            else cout << "No ";
        }
    }  
}
void checkExistMap(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, bool> mp;
        for (int i = 0; i<n; i++){
            int x; cin >> x;
            mp[x] = true;
        }
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            if(mp.count(x) == 1) cout << "Yes ";
            else cout << "No ";
        }
    }  
}
//----------------------------------------------------------------
/**
 * Đếm những phần tử thuộc mảng thứ 1 mà không thuộc mảng thứ 2 
4 5
1 2 2 9
2 0 9 8 3
=> 1
*/
void khongThuoc(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    set<int> se;
    for (int i=0; i<m; i++){
        int x; cin >> x;
        se.insert(x);
    }
    bool ok = false;
    for (int x : a){
        if(se.find(x) == se.end()){
            cout << x << " ";
            ok = true;
        }
    }
    if(!ok) cout << "Not found";
} 
//----------------------------------------------------------------
/**
 * Tìm kí tự xuất hiện nhiều nhất trong chuỗi 
Dùng mảng đếm hoặc map 
abcdzzzzzebcd
=> z
*/
void mangdemKiTuMax(){
    string s; getline(cin, s);
    int a[256] = {0};
    for (char x : s) 
        a[x]++;
    char res; int fre = 0;
    for (int i=0; i<256; i++){
        if(a[i]>fre){
            fre = a[i];
            res = (char)(i);
        }
    }
    cout << res;
}
void mapKiTuMax(){
    string s; getline(cin, s);
    map<char, int> mp;
    for (char x : s) 
        mp[x]++;
    char res; int fre = 0;
    for (auto it : mp){
        if(it.second > fre){
            fre = it.second;
            res = it.first;
        }
    }
    cout << res;
}
//----------------------------------------------------------------
/**
 * Xâu được gọi là paragram nếu có đủ các chữ cái từ a tới z không phân biệt hoa thường.
 * Kiểm tra xâu nhập vào có phải là paragram không ? 
2
Thequickbrownfoxjumpsoverthelazydog
Ihaveadream 
=> Yes No 
*/
void setParagram(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        set<int> se;
        for (char x : s){
            se.insert(tolower(x));
        }
        se.size() == 26 ? cout << "Yes"<<endl : cout << "No"<<endl;
    }
}
void mapParagram(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        map<int, bool> mp;
        for (char x : s){
            mp[tolower(x)] = true;
        }
        mp.size() == 26 ? cout << "Yes"<<endl : cout << "No"<<endl;
    }
}
void mangdanhdauParagram(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        int a[26] = {0};
        for (char x : s)
            a[tolower(x)-'a'] = 1;
        int cnt = 0;
        for (int i = 0; i<26; i++)
            cnt += a[i];
        cnt == 26 ? cout << "Yes"<<endl : cout << "No"<<endl;
    }
}
//----------------------------------------------------------------
/**
 * Tìm từ được lặp lại đầu tiên trong câu 
2
ngon ngu lap lap ngu ngon
abc abc abc zzz zzz cd 
=> lap abc 
*/
void tuLapDauTien(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        stringstream ss(s); string word;
        set<string> se;
        while(ss >> word){
            if(se.find(word) != se.end()){
                cout << word << endl;
                break;
            }
            se.insert(word);
        }
    }
}
//----------------------------------------------------------------
/**
 * Đặt tên người dùng 
 * Xây dựng chương tình đặt tên tài khoản người dùng. Nếu tên người dùng muốn đặt
 * đã xuất hiện trong hệ thống thì sẽ đặt tên tài khoản theo cú pháp 
 * "tên" + (số tài khoản cùng tên trong hệ thống + 1)
 * VD: rech1 rech2 rech3
15
an
binh
an
binh
long
huong
ngoc
thuan
nhung
nhung
ngoc thuan
ngoc thuan
nhung
nhung
nhung
=>
*/
void name(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    map<string, int> mp;
    while(t--){
        string username; getline(cin, username);
        if(mp.find(username) == mp.end())//chưa xuất hiện trong hệ thống 
            cout << username << endl;
        else
            cout << username << mp[username] << endl;
        mp[username]++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    name();
    return 0;
}