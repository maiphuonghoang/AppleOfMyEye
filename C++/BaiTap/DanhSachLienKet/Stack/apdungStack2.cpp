#include <bits/stdc++.h>
using namespace std;

/*
I love this game
=> game this love I
*/
struct Node {
    string data;
    Node *next;
};
typedef struct Node* node;

node makeNode(string x){
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
void push(node &top, string x){
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
string top(node top){
    if(top != NULL) 
        return top->data;
}
void reverse(){
    node st = NULL;
    string s; getline(cin, s);
    stringstream ss(s); string word;
    while(ss >> word){
        push(st, word);
    }
    while(!empty(st)){
        cout << top(st) << " ";
        pop(st);
    }
}
int main() {
    reverse();
    return 0;
}