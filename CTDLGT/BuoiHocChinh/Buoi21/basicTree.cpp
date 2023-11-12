#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    //2 con trỏ 
    node *left; //lưu địa chỉ của node con bên trái
    node *right; //lưu địa chỉ của node con bên phải 

    //constructor
    /*
    node (int x){
        data = x;
        left = right = NULL;
    }   
    */
};
node *makeNode(int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void duyet(node *root){

    
}
void run1(){
    // node *root = new node(1); //constructor 
    node *root = makeNode(1);
    node *node2 = makeNode(2);
    node *node3 = makeNode(3);
    root->left = node2;//lấy địa chỉ của node 2 gán vào con trỏ left của root 
    root->right = node3;
    cout << root << " " << node2 << " " << root-> left << " " << node3 << " " << root->right << endl;
    //0xf219b8 0xf21a28 0xf21a28 0xf21a40 0xf21a40

    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    root->right->left = makeNode(6);
    root->right->right = makeNode(7);

    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run1();
    return 0;
}