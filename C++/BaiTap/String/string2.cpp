#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Đếm số xâu con 
 * Cho xâu kí tự s và số k. Đếm số xâu con của s có đúng k kí tự khác nhau.
 * Các xâu con k nhất thiết phải khác nhau
2
abc 2
aba 2 
=> 
2 (ab, bc)
3
*/
void run1(){
    int t; cin >> t;
    while(t--){
        string s; int k;
        cin >> s >> k;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            // xét tất cả các xâu con bắt đầu từ từng chỉ số 1 trong xâu s
            int cnt[256];
            memset(cnt, 0, sizeof(cnt));
            int dem = 0;
            for (int j=i; j<s.length(); j++){
                if(cnt[s[j]] == 0) ++dem;//kí tự xh lần đầu 
                if(dem == k) ++ans;
                if(dem > k) break;
                cnt[s[j]] = 1;//đánh dấu đã xh 
            }
        }
        cout << ans << endl;
    }
}
//----------------------------------------------------------------
/**Hiệu của 2 tập từ
 * Tìm các từ chỉ xuất hiện trong s1 mà k xuất hiện trong s2.
 * mỗi từ chỉ liệt kê 1 lần
2
abc ab ab ab abcd
ab abc
aaa xyz ab zzz abc dd dd abc
xyz dd ttt sas cdc 
=>  abcd
    aaa ab zzz abc //theo thứ tự xuất hiện  
    abcd
    aaa ab abc zzz //theo thứ tự từ điển 
*/
void run2(){//lưu tất cả từ trong s2 vào 1 set 
    int t; cin >> t; cin.ignore();
    while(t--){
        string a; getline(cin, a);
        string b; getline(cin, b);
        stringstream ssa(a); string worda;
        stringstream ssb(b); string wordb;
        set<string> se;
        while(ssb >> wordb){
            se.insert(wordb);
        }
        vector<string> v;
        while(ssa >> worda){
            if(se.count(worda) == 0){
                se.insert(worda);
                v.push_back(worda);//theo thứ tự xuất hiện  
            }
        }
        sort(v.begin(), v.end());//theo thứ tự từ điển 
        for (string s : v) cout << s << " ";
        el;
    }
}
set<string> convert(string s){
        stringstream ss(s); string word;
        set<string> se;
        while(ss >> word){
            se.insert(word);
        }
        return se;
}
void run3(){//2 set lưu từ 2 xâu 
    int t; cin >> t; cin.ignore();
    while(t--){
        string s1; getline(cin, s1);
        string s2; getline(cin, s2);
        set<string> se1 = convert(s1);
        set<string> se2 = convert(s2);
        //liệt kê se1 và tìm kiếm trong s2
        for(string x : se1){
            if(se2.find(x) == se2.end())
                cout << x << " ";
        }el;
    }
}
//----------------------------------------------------------------
/**Biển số đẹp 
 * Dãy 5 số của biển xe máy gồm 2 cụm: 3 chữ số đầu và 2 chữ số sau, 
 * phân tách bởi dấu chấm. Các trường hợp sau được coi là đẹp 
 * - Cả 5 chữ số được sắp xếp theo thứ tự tăng chặt từ trái qua phải 
 * - Cả 5 chữ số đều bằng nhau 
 * - 3 chữ số đầu bằng nhau và 2 chữ số cuối bằng nhau
 * - Cả 5 chữ số đều là 6 và/hoặc 8 (số lộc phát )
7
29T1-123.45
29T1-555.55
29T1-222.33
29T1-686.88
29T1-123.33
29T1-555.54
29T1-606.88
=> YES YES YES YES NO NO NO
*/
bool checkTangChat(string s){
    for(int i=0; i<4; i++)
        if(s[i] >= s[i+1])
            return false;
    return true;
}
bool check5Equal(string s){
    for(int i=1; i<5; i++)
        if(s[i] != s[0])
            return false;
    return true;
}
bool check32Equal(string s){
    return s[0] == s[1] && s[1] == s[2] && s[3] == s[4];
}
bool checkLocPhat(string s){
    for(char x : s)
        if(x != '6' && x!='8')
            return false;
    return true;
}
void run4(){
    int t; cin >> t; cin.ignore();
    while(t--){
        string s; cin >> s;
        // tách ra 6 chữ số cuối, bắt đầu từ chỉ số 5, số lượng cắt là 
        string tmp = s.substr(5, 6);
        //xóa dấu .
        tmp.erase(3, 1);
        (checkTangChat(tmp) || check5Equal(tmp) || check32Equal(tmp) || checkLocPhat(tmp)) ? yes : no;
    }
}
//----------------------------------------------------------------
/**Số đầy đủ 
 * Số nguyên dương n có 20-1000 chữ số.
 * Kiểm tra xem số đó có đầy đủ các chữ số từ 0 đến 9 hay k 
 * Invalid khi bắt đầu bằng 0 hoặc chứa kí tự k là số 
3
0123aa
12344456667890
123
=> INVALID YES NO
*/
int checkSoDayDu(string s){
    if(s[0]=='0') return -1;
    set<char> se;
    for (char x : s){
        if(!isdigit(x)) return -1;
        se.insert(x);
    }
    return se.size() == 10;
}
void run5(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int res = checkSoDayDu(s);
        if(res == -1) cout << "INVALID" << endl;
        else if(res == 0) no;
        else yes;
    }
}
//----------------------------------------------------------------
/**Xâu con nhỏ nhất 1
  * Tìm xâu con nhỏ nhất của s1 chứa đầy đủ các kí tự của s2
  * => Tìm cửa sổ xâu 1 chứa tất cả kí tự xâu 2 rồi thu hẹp cửa sổ đó lại 
2
timetopractise
toc
zoomlazapzo
oza
=>  toprac
    apzo 
*/
void run6(){
    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        int dem1[256] = {0}, dem2[256] = {0};
        for(char x: s2) dem2[x]++;
        int ans = INT_MAX, left = 0, index = -1;
        int cnt = 0;//cnt xâu 1 đang chứa bn kí tự của xâu 2
        //cnt chứa đúng bằng chiều dài xâu 2 thì thu nhỏ cửa sổ lại
        
        for (int i=0; i<s1.length(); i++){
            dem1[s1[i]]++;
            if(dem1[s1[i]] <= dem2[s1[i]]) 
                ++cnt;
            if(cnt == s2.length()){//đếm được đầy đủ xâu 2 rồi = timetoprac|tise
                //thu hẹp cửa sổ lại
                //tần xuất ở xâu 1 > xâu 2 hoặc kí tự đó k xh ở xâu 2
                while(dem1[s1[left]] > dem2[s1[left]] || dem2[s1[left]] == 0) {
                    if(dem1[s1[left]] > dem2[s1[left]] ){
                        dem1[s1[left]]--;
                    }
                    left++;//dịch left sang phải để bỏ qua kí tự đó 
                }
                //đến vị trí bắt đầu của cửa sổ đấy
                //lấy vị trí i hiện tại tính chiều dài của cửa sổ 
                if(ans > i-left + 1){
                    ans = i-left+1;
                    index = left;
                }
            }
        }
        if(index == -1) cout << "-1" << endl;
        else cout << s1.substr(index, ans) << endl;
    }  
}
//----------------------------------------------------------------
/** Xâu con nhỏ nhất 2
 * Tìm độ dài xâu con nhỏ nhất của s chứa đầy đủ các kí tự của s mỗi kí tự ít nhất 1 lần.
 * VD s=aabcbcdbca có xâu con min là dbca
2
aabcbcdbca
aaab
=> 4 2 
*/
void run7(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<char, int> mp;
        for (char x : s) mp[x]++;
        int len = mp.size();//số lượng kí tự khác nhau trong xâu s
        int ans = INT_MAX, left = 0, cnt = 0;
        int dem[256] = {0};
        for (int i = 0; i < s.length(); i++){
            dem[s[i]]++;
            if(dem[s[i]] == 1) //gặp lần đầu thì tăng số lượng xuất hiện lên 
                ++cnt;
            if(cnt == len)//tìm được xâu con chứa tất cả thì thu hẹp
            {
                while(dem[s[left]] > 1){
                    dem[s[left]]--;
                    ++left;
                }
                ans = min(ans, i-left+1);
            }
        }
        cout << ans << endl;
    }
}
//----------------------------------------------------------------
/**Sumstring 
 * Xâu s được gọi là sumstring nếu tồn tại 1 số tự nhiên k>2 sao cho
 * ta có thể chia xâu s thành k xâu con khác nhau S=(s1,s2,...sk) 
 * sao cho các số được tạo bởi các xâu con tmdk Si=Si-1+Si-2 (i=3,4..,k)
 * VD S = 123415538 là 1 sumstring khi k = 3
 * S = (123, 415, 538) tm 123 + 415 = 538
 * 3<=length(s)<=10^5
3
123415538
12345
1122335588143
=> YES NO YES
*/
//Cộng 2 xâu là 2 số nguyên lớn 
string add(string a, string b){
    if(a.length() < b.length()) 
        swap(a,b);
    int n = a.length(), m = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    b += string(n-m, '0');//thêm n-m số 0 vào cuối b
                        //cách khởi tạo 1 string: số lượng kí tự của xâu, kí tự muốn tạo 
    string res = "";
    int nho = 0;
    for(int i=0; i<n; i++){
        int tmp = (a[i]-'0')+(b[i]-'0')+nho;
        res += (char)(tmp % 10 + '0');
        nho = tmp/=10;
    }
    if(nho) res += (char)(nho + '0');
    reverse(res.begin(), res.end());
    return res;
}
//Kiểm tra xâu s, xâu 1 bắt đầu từ l, có chiều dài len1
//xâu 2 bắt đầu từ l+len1, có chiều dài len2
bool kt(string s, int l, int len1, int len2){
    string s1 = s.substr(l, len1);
    string s2 = s.substr(l+len1, len2);
    string s3 = add(s1, s2);
    if(s3.length() > (s.length() - len1 - len2 - l))
        return false;
    if(s3 == s.substr(l + len1 + len2, s3.length())){
        //xâu s3 là xâu cuối cùng trong s 
        if(s.length() == l + len1 + len2 + s3.length())
            return true;
        return kt(s, l+len1, len2, s3.length());
    }
    return false;
}
void solve(){
    string s; cin >> s;
    for(int i=1; i<s.length(); i++)
        for (int j=1; j<=s.length()-i; j++)
            if(kt(s, 0, i, j)){
                yes; return;
            }
    no;
}
void run8(){
    int t; cin >> t;
    while(t--){
        solve();
    }

}
//----------------------------------------------------------------
/**Tạo bảng màu 
 * Xâu s độ dài n chỉ gồm R,B,G. Xâu kí tự nhận được có ít nhất r kí tự R, 
 * b kí tự B, g kí tự G. Đếm số xâu kí tự thỏa mãn yêu cầu trên.
 * 
4 1 1 1 => 36
4 2 0 1 => 22
*/
ll giaithua[22];
void init(){
    giaithua[0] = 1;
    for (int i=1; i<=20; i++)
        giaithua[i] = i*giaithua[i-1];
}
void run9(){
    int n, g, r, b; cin >> n >> g  >> r >> b;
    init();
    ll res = 0;
    // R+G+B = n; R>=r; G>=g; B>=b;
    for(int R=n; R>=r; R--){
        for(int G=n-r; G>=g; G--){
            int B = n-R-G;
            if(B>=b)
                res+=giaithua[n]/(giaithua[R] * giaithua[G] * giaithua[B]);
        }
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/** Tính giai thừa các chữ số 
 * F(x) là tích giai thừa các chữ số của x
 * F(135) = 1!*5!*3! = 720
 * Đầu tiên họ chọn 1 số a có n chữ số và có ít nhất 1 chữ số lớn hơn 1,
 * có thể có chữ số 0 ở đầu. Sau đó họ tìm 1 số x lớn nhất thỏa mãn:
 *      1. x k chứa chữ số 0 hoặc 1
 *      2. F(x) = F(a)
1234 = 1!2!3!4!
     = 1!2!3!4*3!
     = 1!2!3!*2!2!*3!
     =>33222
4!=4*3!=2!2!3!
5!
6!=6*5!=3!5!
7!
8!=8*7!=2!2!2!7!
9!=9*8*7!
  =3.3.2.2.2.7!
  =6.6.2.7!
  =3!3!2!7!    
*/
void run10(){
    // chạy từ 2=>9 số nào tách được thành giai thừa thì thay 
    string s; cin >> s;
    string res = "";
    for(char x : s){
        if(x=='4') res+="322";
        else if(x=='6') res+="35";
        else if(x=='8') res+="2227";
        else if(x=='9') res+="3322";
        else if(x!='1'&&x!='0') res+=x;
    }
    sort(res.begin(), res.end(), greater<char>());
    cout << res << endl;
}
//----------------------------------------------------------------
/**Loại bỏ 100
 * 1011110000=>1011100=>1011
01
10
21
31
41
51
1011100
41
1011
6
*/
void run11(){
    string s; cin >> s;
    int ans = 0;
    for (int i=0; i<s.length()-2; i++){
        cout <<i<< s[i] << endl;
        if(s=="") break;
        if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='0'){
            ans+=3;
            s.erase(i, 3);
            cout << s << endl;
            i-=2;
        }
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**Số lặp lại
 * Cho 3 số a, x, y. Tìm ước chung lớn nhất của 2 số P và Q trong đó
 * P lặp lại x lần số a và Q lặp lại y lần số a.
 * VD a=2,x=3,y=2 thì P=222, Q=22
 * 1<=a,x,y<=10^18
 * Số lần lặp lại gcd(x,y)
2
2 2 3
123 5 2
=> 2 123
*/
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
void run12(){
    int t; cin >> t; cin.ignore();
    while(t--){
        ll a, x, y; cin >> a >> x >> y;
        ll g = gcd(x, y);
        for(int i=0; i<g; i++) cout << a;
        cout << endl;
    }
}
//----------------------------------------------------------------
/**Thống kê từ 
 * Liệt kê các từ xh trong xâu theo tần xuất giảm dần,
 * cùng tần xuất thì theo thứ tự từ điển 
2
ngon ngu python, java, c++, javascript duoc su dung nhieu.
python-java-c++ 2021-2022!
=> 
c++ 2
java 2
python 2
2021 1
2022 1
dung 1
duoc 1
javascript 1
ngon 1
ngu 1
nhieu 1
su 1
*/
bool check(char c){
    return c==' '||c=='.'||c==','||c=='!'||c=='?'||c=='-';
}
bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
void run(){
    int t; cin >> t; cin.ignore();
    map<string, int> mp;
    while(t--){
        string s; getline(cin, s);
        string tmp="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') continue;
            while(i<s.length()&&!check(s[i])){
                tmp += (char)s[i];
                ++i;
            }
            // cout << tmp << endl;
            mp[tmp]++;
            tmp = "";
        }
    }
    vector<pair<string, int>> v;
    for (auto it : mp) v.push_back(it);
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.first << " " << it.second << endl;
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