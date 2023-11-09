#include <bits/stdc++.h>
using namespace std;
/**
DSLK : back -> front-> NULL
 * Số lộc phát 
=> 6 8 66 68 86 88 666 668 686 688 866 868 886 888
*/
struct Node {
    int data;
    Node *next;
};
typedef Node* node;
node makeNode(int x){
    node newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node &back, int x){
    node tmp = makeNode(x);
    tmp->next = back;
    back = tmp;   
}
void pop(node &back){
    node truoc = NULL, sau = back;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) back = NULL;
    else
        truoc->next = NULL;  
}
int size(node back){
    int ans = 0;
    while (back != NULL){
        ++ans;
        back = back->next;
    }
    return ans;
}
bool empty(node back){
    return back == NULL;
}
int front(node back){
    while (back->next != NULL){
        back = back->next;
    }
    return back->data;
}

void locPhat(){
    node back = NULL;
    push(back, 6);
    push(back, 8);
    vector<int> lp;
    while(1){
        int top = front(back); pop(back);
        string s = to_string(top);
        if(s.size() == 9) break;
        lp.push_back(top);
        push(back, top*10 + 6);
        push(back, top*10 + 8);
    }
    for (int x : lp) cout << x << " ";
}
int main() {
    locPhat();
    return 0;
}