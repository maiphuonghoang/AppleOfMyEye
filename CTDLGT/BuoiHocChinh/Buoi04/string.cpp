#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void inhoa(string &s){
    for(int i=0; i<s.size(); i++){
        s[i] = toupper(s[i]);
    }
}
void inthuong(string &s){
    for(int i=0; i<s.size(); i++){
        s[i] = tolower(s[i]);
    }
}
void basicString(){
    string s;
    cin >> s;//dùng khi k có dấu cách/ tab/ xuống dòng 
    
    getchar();
    cin.ignore(1);//loại đi 1 kí tự ở luồng vào cin 
    
    getline(cin, s);//lấy cả dòng 
    //getline dừng nhập khi gặp phím enter (buffer)
    //bỏ qua nhiều phím enter
    while (getline(cin, s)){
        if(s!="") break;
    }
    cout << s << endl;

    //duyệt chuỗi 
    s = "Ngon ngu lap trinh C++";
    for (int i=0; i< s.size(); i++)
        cout << s[i] << ' ';
    for (char x: s) 
        cout << x << ' ';
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
    
    s.push_back('@');//thêm 1 kí tự vào trong xâu
    s.pop_back();//xóa kí tự cuối 
    s.insert(2, "@@");//chèn 1 xâu kí tự vào chỉ số i 
    s.erase(2,3);//xóa 3 kí tự từ chỉ số 2
    s.substr(2, 3);
    s.erase(2); //xóa mọi kí tự từ chỉ số 2 

    //kiểm tra sự tồn tại của xâu con t trong s 
    s = "28tech";
    string t = "28";
    if(s.find(t)!=string::npos)//gtri mặc định 
        cout << "Found";
    else 
        cout << "Not Found";

    inhoa(s);
    transform(s.begin(), s.end(),s.begin(), ::tolower);//áp dụng hàm tolower với tất cả các kí tự trong xâu s rồi gán lại cho s.begin  
    for (char &x:s) x = tolower(x);

    //chuyển xâu thành số 
    s = "123183";
    int n = stoi(s);//string to integer
    long long l = stoll(s);

    //chuyển số thành xâu 
    s = to_string(12345);

    
}
ll my_stoll(string s){
    ll res = 0;
    for (int i=0; i< s.size(); i++)
        res = res*10 + (s[i] - '0'); //49-48
    return res;
}
string my_tostring(ll n){
    string res = "";
    while(n!=0){
        res += (n%10 + '0');//2+48=50 = '2'
    }
    reverse(res.begin(), res.end());
    return res;
}
void sumString(){
    string s = "712562355421252665521582154415444213651452145211145214523";
    int tong = 0;
    for (char x: s)
        tong += x - '0';
    cout << tong;
}
void tanSuatKyTu(){
    string s = "81238dsdfsawwf1e564s5";
    
    map<char, int> mp;
    for (char x: s)
        mp[x]++;
    for (auto it : mp)
        cout << it.first << '-'<< it.second << ' ' ;

    int cnt[256] = {0};
    for (char x : s)
        cnt[x]++;
    for (int i = 0; i < 255; i++){
        if(cnt[i])
            cout << (char)i << '-' << cnt[i] << ' ';
    }

}
void saveToArray(){
    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];   
    sort (a, a+n, greater<string>());
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}
void saveToVector(){
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];   
    sort (a.begin(), a.end(), greater<string>());
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}
/**
Đếm số lượng từ khác nhau trong xâu k phân biệt hoa thường 
28tech 28TECH 28teCH dev 
DEV
dev abc 
=> 4
*/
void saveToSet(){
    set<string> se;
    string s;
    while(cin >> s){
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (char &x: s)
            x = tolower(x);
        se.insert(s);
    }
    cout << se.size() << endl;
}
//tokenize
void tachTu(){
    //tách theo dấu cách 
    string s1 = "Ngon    ngu   lap trinh   C++";
    string word;
    stringstream ss1(s1);
    while (ss1 >> word)
        cout << word << endl;

    //tách theo dấu '-'
    string s2 = "Ngon-ngu-lap-trinh-C++";
    stringstream ss2(s2);
    while (getline(ss2, word, '-'))
        cout << word << endl;
}
//----------------------------------------------------------------
/**
 * Cho 1 xâu có các từ được phân cách bởi dấu ' ', ',',';','!', '?'
 * Hãy liệt kê các từ xuất hiện trong xâu, giữa các từ cách nhau 1 dấu cách, 
 * sau từ cuối cùng không được in thừa dấu cách 
Chuyển hết các dấu kia thành dấu cách 
*/
void tachSpecial(){
    string s1 = "Ngon ,; ngu ?  lap trinh !!  C++  ";
    for (char &x: s1)
        if(x == ','||x == ';'||x == '?'||x == '!')
            x = ' ';
    string word;
    stringstream ss1(s1);
    while (ss1 >> word)
        cout << word << endl;
}
int main() {    
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    // basicString();
    tachSpecial();
    return 0;
}