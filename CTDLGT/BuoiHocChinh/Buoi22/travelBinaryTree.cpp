#include <bits/stdc++.h>
using namespace std;

struct node {
    int data; 
    node *left; 
    node *right;  
    node (int x){
        data = x;
        left = right = NULL;
    }  
};
void makeRoot(node *root, int u, int v, char c){
    if(c == 'L')
        root->left = new node(v);
    else 
        root->right = new node(v);
}
void insertNode(node *root, int u, int v, char c){
    if(root == NULL)
        return;
    if(root->data == u)
        makeRoot(root, u, v, c);
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
// Duyệt trung tố: gốc giữa 
void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Duyệt tiền tố: gốc trước 
void preorder(node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);    
}
// Duyệt hậu tố: gốc cuối 
void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);    
    cout << root->data << " ";
}
// Duyệt theo mức BFS 
void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    cout << root->data << " ";
    while(!q.empty()){
        node *tmp = q.front(); q.pop();
        if(tmp->left != NULL){
            q.push(tmp->left);
            cout << tmp->left->data << " ";
        } 
        if(tmp->right != NULL){
            q.push(tmp->right);
            cout << tmp->right->data << " ";
        } 
    }
}
// Duyệt xoắn ốc 
void spiralOrder(node *root){
/*
Sử dụng 2 ngăn xếp, stack 1 để in các node theo thứ tự từ trái sang phải
stack 2 in các node theo thứ tự từ phải sang trái 
*/
    stack<node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while (!s1.empty()){
            // lấy node trong stack 1 ra thì đưa vào stack 2 node con phải -> trái của nó 
            node *top = s1.top(); s1.pop();
            cout << top->data << " ";
            if(top->right != NULL)
                s2.push(top->right);
            if(top->left != NULL)
                s2.push(top->left);
        }
        while(!s2.empty()){
            // lấy node trong stack 2 ra thì đưa vào stack 1 node con trái -> phải của nó 
            node *top = s2.top(); s2.pop();
            cout << top->data << " ";
            if(top->left != NULL)
                s1.push(top->left);
            if(top->right != NULL)
                s1.push(top->right);
        }        
    }
}

/* 
7
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 L 
=> levelOrder  1 2 3 4 5 6 7 8 
   spiralOrder 1 2 3 7 6 5 4 8 
*/
void run(){
    node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int u, v; char c;
        cin>> u >> v >>c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, u, v, c);
        }else
            insertNode(root, u, v, c);
    }
    spiralOrder(root);
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}