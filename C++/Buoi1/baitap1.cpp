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

int main()
{
    // convertLetter();
    nextLetter();
}
