#include <bits/stdc++.h>
using namespace std;

// CÀI ĐẶT NGĂM XẾP BẰNG MẢNG 

int n, st[10001];

void push(int x){
    st[n] = x;
    n++;
}
void pop(){
    if(n >= 1) n--;
}
int top(){
    return st[n-1];
    // n là số lượng ptu trong ngăn xếp
    // n-1 là chỉ số cuối cùng của mảng, đỉnh stack 
}
int size(){
    return n;
}
void run(){
    while(1){
        cout << "---------------------MENU----------------------\n";
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. top" << endl;
        cout << "4. size" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------\n";
        cout << "Nhap lua chon : "; 
        int lc; cin >> lc;
        if(lc == 1){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            push(x);
        }else if(lc == 2){
            pop();
        }
        else if(lc == 3){
            if(n==0) cout << "EMPTY" << endl;
            cout << top() << endl;
        }
        else if(lc == 4){
            cout << size() << endl;
        }
        else if(lc = 0){
            break;
        }
    }
}
int main() {
    run();
    return 0;
}