#include <bits/stdc++.h>
using namespace std;
/*
15
=> 1111
*/
struct Node {
    int data;
    Node *next;
};
typedef struct Node* node;

node makeNode(int x){
    node newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
bool empty(node top){
    return top == NULL;
}
int size(node top){
    int ans = 0;
    while(top != NULL){
        ++ans;
        top = top->next;
    }
    return ans;
}
void push(node &top, int x){
    node newNode = makeNode(x);
    if(top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
void pop(node &top){
    if(top == NULL) return;
    top = top->next;
    
}
int top(node top){
    if(top != NULL) 
        return top->data;
}
void binary(){
    node st = NULL;
    long long n; cin >> n;
    while(n){
        int r = n % 2;
        push(st, r);
        n /= 2;
    }
    while(!empty(st)){
        cout << top(st);
        pop(st);
    }
}
int main() {
    binary();
    return 0;
}