#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
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
void run8(){
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
//----------------------------------------------------------------
/**Đầu cuối giống nhau
 * Đếm tất cả xâu con của S có kí tự đầu cuối giống nhau  
 * => Đếm số lần xuất hiện của các kí tự giống nhau, tính 2Cn
2
abcda 
aaa
=> 6 6 
*/
void run9(){
    int t; cin >> t; cin.ignore();
    while(t--){ //map O(logn)
        string s; cin >> s;
        map<char, int> mp;
        for(char x : s) mp[x]++;
        ll ans = s.length();//các xâu con có 1 kí tự 
        for(auto it : mp)  //2Cn, 
            ans += it.second*(it.second-1)/2;
        cout << ans << endl;
    }
    while(t--){ //mảng O(1)
        string s;  cin >> s;
        int a[256] = {0};
        for(char x : s) a[x]++;
        ll ans = s.length();//các xâu con có 1 kí tự 
        for(int i=0; i<256; i++)  //2Cn, 
            if(a[i] != 0)
                ans += a[i]*(a[i]-1)/2;
        cout << ans << endl;
    }
}
//----------------------------------------------------------------
/**Kí tự k lặp 
 * In ra tất cả kí tự k lặp khác nhau trong xâu s
2
ABCDEABC
ABC
=> 
DE 
ABC
*/
void run10(){
    int t; cin >> t; cin.ignore();
    while(t--){ 
        string s; getline(cin, s);
        map<char, int> mp;
        for(char x : s) mp[x]++;
        for(char x : s){
            if(mp[x] == 1)
                cout << x ;
        }
        el;
    }
}
//----------------------------------------------------------------
/**Lớn nhất, nhỏ nhất 
 * Cho số tự nhiên m và số nguyên s k âm. Tìm số bé nhất và lớn nhất
 * có m chữ số và tổng chữ số = s
 * m[1-100], s[0-900]
 * 
m chữ số => max s=9*m 
m = 1 chữ số (0,0) <=> s=0

2 15 => 69 96 
4 15 => 1059 9600
4 40 => -1 -1
2 0 => -1 -1
*/
void run11(){
    int m, s; cin >> m >> s;
    //k có đáp án 
    if(s>9*m || s==0 && m >1){
        cout << "-1 -1" << endl;
        return;
    } 
    int lon[m] = {0}, be[m] = {0};
    int tmp = s;
    for(int i=0; i<m; i++){
        if(s>= 9){
            lon[i] = 9;
            s -= 9;
        } else if(s!=0){
            lon[i] = s;
            s = 0;
        }else break;
    }
    --tmp;//để dành 1 đơn vị cho hàng đầu 
    for(int i= m-1; i> 0; i--){
        if(tmp >= 9){
            be[i] = 9; 
            tmp -= 9;
        }
        else if(tmp != 0){
            be[i] = tmp;
            tmp = 0;
        }else break;   
    }
    be[0] = tmp + 1;
    f0(i, m) cout << be[i]; cout << " ";
    f0(i, m) cout << lon[i];
}
//----------------------------------------------------------------
/**Đếm số lượng câu khác nhau 
5
Lap trinh
DSA DSA
Lap trinh
Lap trinh huong doi tuong 
DSA DSA
=> 3
*/
void run12(){
    int n; cin >> n; cin.ignore();
    set<string> se;
    f0(i, n){
        string s; getline(cin, s);
        se.insert(s);
    }
    cout << se.size();
}
//--------------------------------------------------
/** Số đẹp
 * 1 số được coi là đẹp nếu đó là số thuận nghịch và chỉ toàn các số chẵn
 * n k quá 500 chữ số 
4
123456787654321
86442824468
800600004444222200002222444400006008
2353657897876543245678578654356786556
=> NO YES YES NO
*/
bool check(string s){
    //thuận nghịch: reverse và so sánh với string ban đầu
    string t = s;
    reverse(t.begin(), t.end());
    if(s!=t) return false;
    for(char x : s){
        //trừ mã ascii 
        if((x-'0')%2==1)
            return false;
    }
    return true;
}
void run13(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string s; cin >> s;
        check(s) ? yes : no;
    }   
}
//------------------------------------------------------
/**Đổi chỗ chữ số 
 * Cho số tự nhiên n. Bạn chỉ được phép sử dụng nhiều nhất 1 phép đổi chỗ 
 * giữa 2 chữ số để nhận được số lớn nhất nhỏ hơn n 
Tìm cặp a[i] > a[i+1] => chừng nào a[i]<=a[i+1] thì dịch sang trái rồi 
hoán vị với số lớn nhất nhỏ hơn a[i] trong đoạn còn lại 
VD: 124|2355 <--
       đổi 4 với số lớn nhất nhỏ hơn 4 cuối cùng từ phải sang  
    124|23355 => 12324355
4
12435 => 12345 
12345 => -1
1242355 => 1232455
12423355 => 12324355
*/
void run14(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string s; cin >> s;
        int i = s.length()-2;
        //số tăng dần 
        while(i>=0 && s[i]<=s[i+1]) --i;
        if(i==-1){
            cout << -1 << endl;
            continue;
        }
        int j = s.length() - 1;
        // tìm max 
        while(s[i]<=s[j] || s[j-1]==s[j] && s[i] < s[j]) --j;
        swap(s[i], s[j]);
        if(s[0] == '0') cout << "-1" << endl; //kí tự 0 ở đầu 
        else cout << s << endl;
        
    }  
}
//----------------------------------------------------------------
/**Sắp đặt xâu kí tự 
 * Cho xâu kí tự a..z. Các kí tự trong s có thể lặp lại.
 * Sắp đặt lại các kí tự trong s sao cho các kí tự kề nhau đều khác nhau 
 * => Phụ thuộc kí tự có tần xuất xuất hiện nhiều nhất trong xâu
 * so với số lượng kí tự còn lại 
4
geeksforgeeks
bbbabaaacd
bbbbb
aaaabcd
=> YES YES NO YES
*/
void run15(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string s; cin >> s;
        int a[26] = {0};
        for (char x : s){
            a[x-'a']++;
        }
        int max_value = *max_element(a, a+26);
        if(s.length() - max_value >= max_value-1) yes;
        else no;
    }  
}
//--------------------------------------------------
/**Tổng lớn nhất và nhỏ nhất 
 * Cho 2 số nguyên dương x1, x2. Chỉ được phép thay đổi chữ số 5 thành 6, 6 thành 5
 * của các số x1 và x2. Hãy đưa ra tổng nhỏ nhất và tổng lớn nhất của các số x1 và x2
 * được tạo ra theo nguyên tắc kề trên (0<=x1,x2<=10^18)
 * => Lớn nhất thì đổi 5 thành 6, bé nhất thì đổi 6 thành 5
2
645 666
5466 4555
=> 1100 1312 (545 + 555) & (646+666)
10010 11132
*/
void max_val(string a, string b){
    for(char &x : a)
        if(x=='5') x='6';
    for(char &x : b)
        if(x=='5') x='6';
    cout << stoll(a) + stoll(b) << endl;
}
void min_val(string a, string b){
    for(char &x : a)
        if(x=='6') x='5';
    for(char &x : b)
        if(x=='6') x='5';
    cout << stoll(a) + stoll(b) << " ";
}
void run16(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string a; cin >> a;
        string b; cin >> b;
        min_val(a, b); max_val(a,b);
    }
}
//----------------------------------------------------------------
/**Tính tổng các số trong xâu (chữ bỏ qua)
4
1abc23
geeks4geeks
1abc2x30yz67
123abc 
=> 
24 (1 + 23)
4 
100 (1 + 2 + 30 + 67)
123
*/
void run17(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string s; cin >> s;
        int ans = 0;
        int sum = 0;
        for (char x : s){
            if(isdigit(x)) sum = sum * 10 + x - '0';
            else {
                ans += sum;
                sum = 0;
            }
        }
        //cập nhật 
        ans += sum;//cuối cùng phải là chữ thì mới nhảy sang else 
        cout << ans << endl;
    }
}
/**Số lớn nhất trong xâu 
4
100klh564abc365bg
abvhd9sdnkjdfs
abchsd0sdhs
100klh564abc365
=> 564 9 0 365 
*/
void run(){
    int t; cin >> t; cin.ignore();
    while (t--){
        string s; cin >> s;
        s += "a";//thêm kí tự vào cuối
        int ans = INT_MIN;
        int sum = 0;
        for (char x : s){
            if(isdigit(x)) sum = sum * 10 + x - '0';
            else {
                ans = max(ans, sum);
                sum = 0;
            }
        }
        cout << ans << " ";
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