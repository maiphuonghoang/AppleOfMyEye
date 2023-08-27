#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/**
 * Cho 2 xâu s1, s2. In ra các kí tự xuất hiện ở cả 2 xâu theo thứ tự từ điển 
 * (mỗi kí tự chỉ liệt kê 1 lần). Sau đó liệt kê các kí tự xuất hiện 
 * ở 1 trong 2 xâu theo thứ tự từ điển  
*/
void xauGiaoHopRieng(){
    string s, t; cin >> s >> t;
    int cnt1[256] = {0}, cnt2[256] = {0};
    for (char x : s) 
        cnt1[x] = 1;
    for (char x : t)
        cnt2[x] = 1;
    for (int i = 0; i < 256; i++)
        if(cnt1[i] && cnt2[i])
            cout << char(i);
    cout << endl;
    for (int i = 0; i < 256; i++)
        if(cnt1[i] || cnt2[i])
            cout << char(i);
    cout << endl;
    //Kí tự xuất hiện ở chỉ xâu 1
    for (int i = 0; i < 256; i++)
        if(cnt1[i] && cnt2[i] == 0)
            cout << char(i);
}
//----------------------------------------------------------------
/**
 * Xâu pamgram là xâu có chứa đầy đủ các kí tự từ a tới z không phân biệt hoa thường.
*/
int checkPamgram(){
    string s; cin >> s ;
    int cnt[256] = {0};
    for (char x : s) {
        //chuyển hết về dạng on thường 
        cnt[tolower(x)] = 1;  
    }
    for (int i = 97; i<=122; i++) 
        if (cnt[i] == 0)
            return 0;
    return 1;
    
}
//----------------------------------------------------------------
/**
 * Đếm số lượng từ trong xâu
 * stringstream hoặc đếm lúc nhập luôn 
*/
void countWord(){
    string s; 
    int dem = 0, count = 0;
    while(cin >> s)
        ++dem;
    cout << dem << endl;
    
    s = "hjjd ahf jjd fg";
    stringstream ss(s);
    string w;   
    while (getline(ss, w, ' ')) 
        count++;
    cout << count << endl;  
}
/**
 * Liệt kê các từ khác nhau : 
 * theo thứ tự từ điển tăng dần => set 
 * theo thứ tự xuất hiện trong xâu => vector 
python java php php java python
=>
java php python 
python java php
*/
void showString(){
    string s;
    vector <string> v;
    set<string> se;
    while (cin>>s){
        if(se.count(s) == 0) 
            v.push_back(s);//từ khác nhau 
        se.insert(s);
    }
    for (string x : se)
        cout << x << ' ';
    cout << endl;
    for (string x : v)
        cout << x << ' ';

}
//----------------------------------------------------------------
/**
 * Sắp xếp các kí tự trong xâu:
 * theo thứ tự từ điển tăng dần 
 * theo thứ tự chiều dài tăng dần (cùng thì thứ tự từ điển nhỏ hơn in ra trước)
hoc lap trinh php 
=>
hoc lap php trinh 
hoc lap php trinh
*/
bool cmpLong(string a, string b){
    if(a.size() != b.size()) 
        return a.size() < b.size();
    return a < b;
}
void sortString(){
    string s;
    vector<string> v;
    while (cin >> s){
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (string x : v) cout << x << " ";
    cout << endl;
    sort(v.begin(), v.end(), cmpLong);
    for (string x : v) cout << x << " ";
}
//----------------------------------------------------------------
/**
 * Sắp xếp các từ thuận nghịch khác nhau trong xâu theo thứ tự
 * chiều dài tăng dần, nếu 2 từ thuận nghịch có cùng chiều dài 
 * thì từ nào xuất hiện trước sẽ in ra trước 
php aba aaaa nguyen huu hoc pop
=> php aba pop aaaa  
*/
bool cmpSize(string a, string b){
    return a.size() < b.size();
}
bool thuanNghich(string s){
    int l = 0, r = s.size() - 1;
    while (l <= r){
        if (s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}
void sortThuanNghich(){
    string s;
    vector <string> v;
    set<string> se;
    while (cin>>s){
        if(se.count(s) == 0 && thuanNghich(s)) 
            v.push_back(s);//từ khác nhau 
        se.insert(s);
    }
    stable_sort(v.begin(), v.end(), cmpSize);
    for (string x : v) cout << x << ' ';
}
//----------------------------------------------------------------
/**
 * Liệt kê các từ trong xâu kèm theo tần xuất của nó :
 * - theo thứ tự từ điển 
 * - theo thứ tự xuất hiện 
bb aa bb cc aa bb cc
=>
aa 2
bb 3
cc 2

bb 3
aa 2
cc 2 
*/
void tanXuatString(){
    string s;
    vector <string> v;//lưu các từ khác nhau theo thứ tự xuất hiện 
    map<string, int> mp;
    while (cin>>s){
        mp[s]++;
        v.push_back(s);
    }
    for (auto it : mp)
        cout << it.first << ' ' << it.second << endl;
    cout << endl;
    for (string x : v){
        if(mp[x]!=0){
            cout << x << ' ' << mp[x] << endl;
            mp[x]=0;
        }
    }    
}
//----------------------------------------------------------------
/** chuẩn hóa tên và ngày dd/mm/yyyy
hoang dinh HAn
20/5/1999
=>
Hoang Dinh Han
20/05/1999
*/
void chuanHoaTenNgaySinh(){
    string s;
    getline(cin, s);
    string new_name = "";
    stringstream ss(s);
    string word;
    while(ss>>word){
        new_name += toupper(word[0]);
        for (int j=1; j<word.size(); j++)
            new_name += tolower(word[j]);
        new_name += " ";
    }
    new_name.pop_back();//xóa dấu cách cuối
    cout << new_name << endl;

    string ns; cin >> ns;
    stringstream ss1(ns);
    int dem=0;
    while (getline(ss1,word, '/')){
        ++dem;
        //in ra với độ rộng 2 chữ số, nếu k đủ nó sẽ điền đầy với chữ số 0
        cout << setfill('0') << setw(2) << stoi(word);
        if (dem != 3) cout << "/";
    }
}
/** chuẩn hóa tên 
hoang    dINH van NaH
=>
Hoang Dinh Van, NAH
*/
void chuanHoa(string &s){
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i] = tolower(s[i]);
}
void chuanHoaTen(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector <string> v;
    while(ss>>word){
        v.push_back(word);
    }
    for (int i = 0; i < v.size() - 1; i++)
        chuanHoa(v[i]);
    for (char &x : v[v.size()-1])//viết hoa các từ trong tên 
        x = toupper(x);
    
    for (int i = 0; i < v.size()-1; i++){
        //họ 
        if(i!= v.size()-2) cout << v[i] << " ";
        else if(i==v.size()-2) cout << v[i] << ", ";
    }
    cout << v[v.size() - 1];  
     
}
//----------------------------------------------------------------
/**
 * Tên email được tạo bằng cách lấy tên ghép với chữ cái dầu của họ và tên 
 * (Nguyen Van Long có email là longnv@xyz.edu.vn)
 * Mật khẩu là ngày sinh (27/04/2022=>2742002)
1
Nguyen Van Tran Long    27/04/2022
*/
void emailPassword(){
    int t; cin >> t;
    cin.ignore();
    for (int i=0; i<t; i++){
        string s; getline(cin, s);
        for (char &x : s) x = tolower(x);
        stringstream ss(s); string word;

        vector<string> v;
        while(ss>>word){
            v.push_back(word);
        }
        //lấy ra tên từ input 
        int n = v.size();
        string email = v[n-2];
        for (int i=0; i<n-2; i++){
        //chỉ duyệt họ đệm 
            //lấy chữ cái đầu tiên 
            email += v[i][0];
        }
        email += "@xyz.edu.vn";
        cout << email << endl;

        string ns = v[n-1];
        stringstream ss2(ns);
        while(getline(ss2, word, '/')){
            //ép về số rồi in ra 
            cout << stoi(word);
        }
    }
}
/**
 * Có những trường hợp sinh viên bị trùng tên: (Nguyen Van Long có email là longnv@xyz.edu.vn),
 * (Ngo Van Long có email là longnv@xyz.edu.vn). Nếu trùng thì thêm số thứ tự vào tên email 
4
nguyen   van LONg 20/10/2002
ngo Vang Long 20/12/2002
Nguyen Vu Long 22/12/2003
ho van nam 17/09/2002
*/
void emailSTT(){
    int t; cin >> t;
    cin.ignore();
    map<string,int> mp;
    for (int i=0; i<t; i++){
        string s; getline(cin, s);
        for (char &x : s) x = tolower(x);
        stringstream ss(s); string word;

        vector<string> v;
        while(ss>>word)
            v.push_back(word);
        int n = v.size();
        string email = v[n-2];
        for (int i=0; i<n-2; i++)
            email += v[i][0];
        
        mp[email]++;
        cout << email <<"-"<< mp[email];
        if(mp[email] == 1)
            cout << email << "@xyz.edu.vn ";
        else cout << email << mp[email] << "@xyz.edu.vn\n";

        string ns = v[n-1];
        stringstream ss2(ns);
        while(getline(ss2, word, '/'))
            cout << stoi(word); 
        cout << endl;      
    }
}
//----------------------------------------------------------------
/**
 * Xác định xem liệu rằng có thể xóa đi bất kì 1 kí tự nào trong xâu S 
 * ở 1 vị trí bất kì và xâu S trở thành từ "python" được hay k?
 * Biết rằng có thể xóa bất kì 1 kí tự nào nhưng k thể 
 * hóa đổi vị trí các kí tự trong xâu s ban đầu 
sphanytohanthnoan
 x   xx
python
ii
*/
int xoaPython(){
    string s;
    cin >> s;
    int j = 0;
    string p = "python";
    for (int i = 0; i < s.size(); i++){
        if(s[i] == p[j])
            j++;
        if(j==6) {
            cout << "Y";
            return 1;
        }
    }
    cout << "N";
    return 0;
}
//----------------------------------------------------------------
/**Liệt kê các từ xuất hiện ở cả 2 xâu mà k phân biệt hoa thường,
 * Mỗi từ được liệt kê 1 lần theo thứ tự từ điển tăng dần 
abc abc abcd abcd AB
abC CD ZAH abd ABcd
=> abc abcd 
*/
void tapTuChung(){
    string s, t, w;
    getline(cin, s); getline(cin, t);
    for (char &x : s) x = tolower(x);
    for (char &x : t) x = tolower(x);
    stringstream ss(s), tt(t);
    set<string> se1, se2;
    while (ss >> w){
        se1.insert(w);
    }
    while (tt >> w){
        se2.insert(w);
    }
    //duyệt 1 nếu ở 2 xh thì in ra 
    for (string x: se1){
        if(se2.count(x))
            cout << x << ' ';
    }
}
/**Liệt kê các từ xuất hiện ở xâu 1 mà k xh ở xâu 2
 * K phân biệt hoa thường
 * Mỗi từ được liệt kê 1 lần theo thứ tự từ điển tăng dần 
abc abc abcd abcd AB
abC CD ZAH abd ABcd
=> ab 
*/
void tapTuRieng(){
    string s, t, w;
    getline(cin, s); getline(cin, t);
    for (char &x : s) x = tolower(x);
    for (char &x : t) x = tolower(x);
    stringstream ss(s), tt(t);
    set<string> se1, se2;
    while (ss >> w){
        se1.insert(w);
    }
    while (tt >> w){
        se2.insert(w);
    }
    for (string x: se1){
        if(se2.count(x) == 0)
            cout << x << ' ';
    }
}
//----------------------------------------------------------------
/** Cho các từ chỉ bao gồm chữ cái in hoa và in thường, bạn được yêu cầu ghép
 * các từ này lại với nhau sao cho từ được ghéo lại sau cùng có thứ tự từ điển lớn nhất 
4
ab abc abcd aa
=> abcdabcabaa
2
bca bc 
=> k phải bcbca mà bcabc mới đúng
cần nối các từ vào 
*/
bool cmpNoi(string u, string v){
    string uv = u + v;
    string vu = v + u;
    //mục đích khi nối 2 xâu lại với nhau tạo ra thứ tự từ điển lớn hơn  
    return uv > vu;
}
void ghepXau(){
    int n; cin >> n;
    string a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);//sort sai 
    for (string x: a) cout << x <<" ";
    sort(a, a+n, cmpNoi);//sort đúng 
    for (string x: a) cout << x <<" ";

}
//----------------------------------------------------------------
/** Cho xâu S chỉ bao gồm các kí tự in thường, hãy đếm số lượng xâu con 
 * (xâu kí tự chứa các chữ cái liên tiếp) mà kí tự đầu và cuối giống nhau 
abaabczav
a:4=> 2C4
đếm tần xuất xh của các kí tự trong xâu rồi tính tổ hợp chập 2
abcda
=> 6 (a,b,c,d,a,abcda)
*/
void xauGiongDauCuoi(){
    string s; cin >> s;
    map<char, int> mp;
    for(char x : s) mp[x]++;
    long long ans = s.size();
    for (auto it : mp)
        ans += 1ll*it.second*(it.second-1)/2;
    cout << ans << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    xauGiongDauCuoi();
    return 0;
}