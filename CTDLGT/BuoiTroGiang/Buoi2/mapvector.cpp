#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
/**
12
Arsenal - Lyon
Fullham - Liverpool
Fullham - Chelsea
Barcelona - Chelsea
Barcelona - Fullham
Chelsea - AC Milan
PSG - Manchester City
Arsenal - Fullham
Fullham - Arsenal
Real Madrid - Barcelona
Arsenal - Manchester City
Manchester United - Liverpool

mp[Arsenal] = Lyon;
mp[Lyon] = Arsenal;
==>
AC Milan : Chelsea
Arsenal : Fullham Fullham Lyon Manchester City
Barcelona : Chelsea Fullham Real Madrid
Chelsea : AC Milan Barcelona Fullham
Fullham : Arsenal Arsenal Barcelona Chelsea Liverpool
Liverpool : Fullham Manchester United
Lyon : Arsenal
Manchester City : Arsenal PSG
Manchester United : Liverpool
PSG : Manchester City
Real Madrid : Barcelona
*/
int tim(string s, char x){
    for (int i=0; i<s.length(); i++)
        if (s[i] == x) return i;
    return -1;
}
void footballOpposingTeam1(){
    int n; cin >> n;
    //trước getline mà là cin thì phải cin.ignore()
    cin.ignore(); // Use cin.ignore() to clear the newline character after reading n
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int pos = tim(s, '-');
        string t1 = s.substr(0, pos - 1); //bắt đầu từ 0, lấy n số 
        string t2 = s.substr(pos + 2);
        //cout << pos << endl;
        //cout << t1 << " " << t2 << endl;
        mp[t1].push_back(t2);
        mp[t2].push_back(t1);
    } 
    for (auto it : mp) {
        vector<string> tmp = it.second;
        sort (tmp.begin(), tmp.end());
        cout << it.first << " : ";
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i];
            if(i<tmp.size() - 1) cout << ", ";
        } 
        cout << endl;
    }
}
void footballOpposingTeam2(){
    int n; cin >> n;
    cin.ignore(); 
    map<string, multiset<string>> mp;
    //dùng multiset để không phải sort 
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int pos = tim(s, '-');
        string t1 = s.substr(0, pos - 1); 
        string t2 = s.substr(pos + 2);
        mp[t1].insert(t2);
        mp[t2].insert(t1);
    } 
    for (auto it : mp) {
        cout << it.first << " : ";
        int i = 0;
        for (string x: it.second) {
            cout << x ;
            if(i<it.second.size() - 1)
                cout << ", ";
            i++;
        }
        cout << endl;
    }
}
//----------------------------------------------------------------
/**
Tín chỉ & điểm 
Lan 4 8
Hanh 4 5
Lan 6 10
Phong 4 10
Nam 4 9
Phong 6 5
Lan 2 4
Phuong 6 1
Nhung 2 7
Nhung 6 9
Nhung 4 10
Lan 3 1
=>
Phuong : 1.00
Phong : 7.00
Nhung : 9.00
Nam : 9.00
Lan : 6.87
Hanh : 5.00
*/
double gpa(vector<pair<int, int>> v){
    int sum1 = 0, sum2 = 0;
    for (auto it : v){
        sum1 += it.first * it.second;
        sum2 += it.first;
    }
    return (double)sum1/sum2;
}

void diemTrungBinh(){
    map<string, vector<pair<int, int>>> mp;
    string ten;
    while(cin >> ten){
        int stc, diem;
        cin >> stc >> diem;
        mp[ten].push_back({stc, diem});
    }
    //Lan {(4,8), (6,10), (2,4), (3,1)} 
    //map có second là vector các pair 
    //print thong tin cua Lan 
    for (pair<int, int> it : mp["Lan"]){
        cout << it.first << " "<< it.second << endl; 
    }
    //duyệt ngược theo thứ tự tên 
    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        cout << (*it).first << " : ";
        cout << fixed << setprecision(2)<< gpa((*it).second) << endl;
    }
}
//----------------------------------------------------------------

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    footballOpposingTeam2();
    return 0;
}
