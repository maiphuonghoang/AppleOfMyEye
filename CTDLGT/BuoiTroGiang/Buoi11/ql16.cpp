#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Điện thoại cục gạch 
 * Cho xâu kí tự S chỉ gồm các số từ 2 tới 9, mỗi chữ số này trên 
 * bàn phím điện thoại tương ứng với 3 chữ cái.
 * In ra các xâu kí tự có thể tạo thành bằng cách ấn mỗi chữ số 
 * trong xâu S đúng 1 lần. In ra các xâu kết quả theo thứ tự từ điển tăng dần 
 * 
        2(abc)   3(def)
4(ghi)  5(jkl)   6(mno)
7(pqrs) 8(tuv)   9(wxyz)

23 
=> ad ae af bd be bf cd ce cf

s[1]=2
miền giá trị abc
kết thúc (i==2)
*/
int n;
string s;
vector<char> v[10];
char x[15];

void xuly(){
    int index = 2;
    for(char c='a'; c<='z'; c++){
        v[index].push_back(c);
        if(index == 7 || index==9){
            if(v[index].size() == 4)
                index++;
        }else{
            if(v[index].size() == 3)
            index++;
        }
    } 
}
void ql(int i, string res){
    int num = s[i] - '0';
    for(char c : v[num]){
        x[i] = c;
        if(i == n){
            cout << res + c << " ";
        }
        else ql(i+1, res + c);
    }
}
void run(){
    xuly();
    for(int i=2; i<=9; i++){
        for(char x : v[i])
            cout << x;
        el;
    }
    cin >> s;
    n = s.length();
    s = '0' + s;
    string tmp = "";
    ql(1, tmp);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
