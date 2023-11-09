#include <bits/stdc++.h>
using namespace std;
/*
    PUSH : thêm ptu vào đỉnh stack = INSERT FIRST : thêm 1 node vào đầu trong dslk
    POP : xóa ptu ở đỉnh stack = DELETE FIRST : xóa node ở đầu
    TOP : node đầu tiên trong dslk 
*/
struct node {
    int data;
    struct node *next;
};
node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **top, int x){
    node *newNode = makeNode(x);
    newNode->next = *top;
    *top = newNode;
}
void pop(node **top){
    if(*top != NULL) {
        node *tmp = *top;
        *top = tmp->next;
        delete tmp;
    }
}
int top(node *top){
    if(top != NULL) 
        return top->data;
}
int size(node *top){
    int ans = 0;
    while (top != NULL) {
        ++ans;
        top = top->next;
    }
    return ans;
}
void run(){
    node *st = NULL;
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
            push(&st, x);
        }else if(lc == 2){
            pop(&st);
        }
        else if(lc == 3){
            if(st==NULL) cout << "EMPTY" << endl;
            else cout << top(st) << endl;
        }
        else if(lc == 4){
            cout << size(st) << endl;
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