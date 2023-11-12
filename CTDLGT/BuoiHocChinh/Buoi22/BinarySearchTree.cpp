/*
Cây nhị phân tìm kiếm 
 - Tất cả node con thuộc cây con bên trái nhỏ hơn node gốc 
 - Tất cả node con thuộc cây con bên phải lớn hơn node gốc 
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data; 
    node *left; 
    node *right;  
};
node *makeNode(node *root, int key){
    node *newNode = new node;
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node *insertNode(node *root, int key){
    if(root == NULL)
        return makeNode(root, key);
    if(key < root->data)
        root->left = insertNode(root->left, key);
    if(key > root->data)
        root->right = insertNode(root->right, key);
    return root;
}
bool search(node *root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if(root->data < key)
        return search(root->right, key);
    else 
        return search(root->left, key);
}
// Node nhỏ nhất lớn hơn node cần xóa 
node* minNode(node *root){
    node *temp = root;
    while(temp != NULL && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
node *deleteNode(node *root, int key){
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{//key = root->data
        if(root->left == NULL)
        //node cần xóa chỉ có con phải 
        {
            node *tmp = root->right;
            delete root;//xóa node đó
            return tmp; //gán node con phải vào root->left/right = deleteNode()
        }
        else if(root->right)
        //node cần xóa chỉ có con trái  
        {
            node *tmp = root->left;
            delete root;
            return tmp; 
        }
        else //node trung gian, có cả 2 con 
        {
            node *tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data); //xóa node dùng để thay 
        }
        return root;
    }
}

int main() {
    return 0;
}