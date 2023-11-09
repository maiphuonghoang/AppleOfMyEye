#include <bits/stdc++.h>
using namespace std;
/*
PUSH = A[0]
POP = Dịch tất cả ptu sang trái 
*/

int n=0, a[100000], maxn = 100000;
int size(){
    return n;
}
bool empty(){
    return n == 0;
}
void push (int x){
    if (n==maxn) return;
    a[n] = x;
    ++n;
}
void pop (){
    if(n==0) return;
    for (int i=0; i< n-1; ++i) 
        a[i] = a[i+1];
    n--;
}
int front(){
    return a[0];
}
void duyet(){
    for (int i=0; i< n; ++i)
        cout << a[i] << " ";

}
void run(){
    while(1){
        cout << "---------------------MENU----------------------\n";
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. front" << endl;
        cout << "4. size" << endl;
        cout << "5. empty" << endl;
        cout << "6. duyet" << endl;
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
            cout << front() << endl;
        }
        else if(lc == 4){
            cout << size() << endl;
        }
        else if(lc == 5){
            if(empty())
                cout << "EMPTY" << endl;
            else cout << "NOT EMPTY" << endl;
        }
        else if(lc == 6){
            duyet();
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