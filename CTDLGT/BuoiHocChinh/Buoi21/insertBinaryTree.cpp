#include <bits/stdc++.h>
using namespace std;
/*
6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R
=> 4 2 5 1 6 3 7 
*/

struct node {
    int data; 
    node *left; 
    node *right; 

    //constructor
    node (int x){
        data = x;
        left = right = NULL;
    }   
};
// sau khi tìm được node cha 
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
void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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
    inorder(root);
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}