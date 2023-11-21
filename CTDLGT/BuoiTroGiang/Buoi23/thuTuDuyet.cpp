#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Cho preorder và inorder
 * preorder: 1 2 4 5 3 6 7 
 * inorder: 4 2 5 1 6 3 7
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7
=> 4 5 2 6 7 3 1 
*/
int n;
int preOrder[105], inOrder[105];
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int tim(int a[], int x){
    f0(i,n) if(a[i] == x) return i;
    return 0;
}
void buildTree(Node *root, int in_left, int in_right){
    // vị trí của gốc k phải ngoài cùng bên trái/phải => có node con 
    int in_pos = tim(inOrder, root->data);
    int pre_pos = tim(preOrder, root->data);
    if(in_pos > in_left){
        root->left = new Node(preOrder[pre_pos + 1]);
        buildTree(root->left, in_left, in_pos - 1);
    }
    if(in_pos < in_right){
        int soLuongTapTrai = in_pos - in_left;
        root->right = new Node(preOrder[pre_pos + soLuongTapTrai + 1]);
        buildTree(root->right, in_pos + 1, in_right);
    }

}
void postOrder(Node *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void run(){
    cin >> n;
    f0(i, n) cin >> preOrder[i];
    f0(i, n) cin >> inOrder[i];
    Node *root = new Node(preOrder[0]);
    buildTree(root, 0, n-1);
    postOrder(root);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}