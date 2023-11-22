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
void run(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int res = checkSoDayDu(s);
        if(res == -1) cout << "INVALID" << endl;
        else if(res == 0) no;
        else yes;
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