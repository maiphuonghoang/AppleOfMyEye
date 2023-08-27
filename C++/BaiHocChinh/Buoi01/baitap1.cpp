#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void convertLetter()
{
    // khoảng cách
    cout << 'a' - 'A' << endl;
    char c;
    cin >> c;
    if (c >= 'a' && c <= 'z')
        // chữ thường thành chữ hoa
        cout << (char)(c - 32) << endl;
    else if (c >= 'A' && c <= 'Z')
        cout << (char)(c + 32) << endl;
    else
        cout << "Khong phai chu cai" << endl;
}

void nextLetter()
{
    char c;
    cin >> c;

    if(c == 'z' || c == 'Z') cout << 'a';
    if (c >= 'a' && c < 'z')
        cout << (char)(c+1) << endl;
    else if (c >= 'A' && c < 'Z')
        cout << (char)((c+1)+32) << endl;

    //nếu c là chữ hoa thì đưa về chữ thường 
    if (c >= 'A' && c <= 'Z') c += 32;
    if(c == 'z') cout << 'a';
    else if (c >= 'a' && c < 'z')
        cout << (char)(c+1) << endl;
}
void Doraemon(){
    int n, m, l;
    cin >> n >> m;

    //tìm cận trái 
    if(n%2 == 0) l = n/2;
    else l = n/2 + 1;
    
    //tìm trong khoảng [l,n] số k tm k%m 
    if(l%m == 0) cout << l;
    else{
        int res = (l/m+1)*m;
        if (res <= n) cout << res;
        else cout << -1;
    }
}
int main()
{
    // convertLetter();
    // nextLetter();
    Doraemon();
}
