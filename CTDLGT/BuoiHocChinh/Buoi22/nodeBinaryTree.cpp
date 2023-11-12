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
// Đếm số node con 
int countNode(node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int dem = 0;
    dem += countNode(root->left);
    dem += countNode(root->right);
    return dem;

}
// Tìm độ cao lớn nhất của 1 node trên cây 
// Tìm max(cây con bên trái, cây phải)
int heightNode(node *root){
    if(root == NULL) return -1;
    int heightLeft = heightNode(root->left);
    int heightRight = heightNode(root->right);
    return max(heightLeft + 1, heightRight + 1);
} 
// Cây nhị phân đầy đủ: mỗi node có 0 hoặc 2 node con 
bool checkFullBinaryTree(node *root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->left != NULL && root->right != NULL) //có cả 2 node con 
        return checkFullBinaryTree(root->left) && checkFullBinaryTree(root->right);
    else //chỉ có node con trái / phải    
        return false;
}

// Kiểm tra mọi node lá có cùng mức hay k
set<int> se;
void Preorder(node *root, int cnt){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
        se.insert(cnt);
    Preorder(root->left, cnt + 1);
    Preorder(root->right, cnt + 1);
}

// Cây nhị phân hoàn hảo: mỗi node trung gian đều có 2 con và mọi node lá đều có cùng mức 
int check = 1;
bool checkPerfectBinaryTree(node *root, int cnt){
    if(root == NULL) return;
    if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL )
        check = 0;
    if(root->left == NULL && root->right == NULL)
        se.insert(cnt);
    Preorder(root->left, cnt + 1);
    Preorder(root->right, cnt + 1);
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
    // node lá cùng mức 
    Preorder(root, 0);
    if(se.size() == 1) cout << "yes";
    // perfect binarytree
    checkPerfectBinaryTree(root, 0);
    if(check){
        if(se.size() == 1) cout << "yes";
        else cout << "No";
    }else cout << "No";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}