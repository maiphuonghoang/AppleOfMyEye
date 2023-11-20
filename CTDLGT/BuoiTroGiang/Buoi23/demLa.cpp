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

/** Đếm node lá
 * Cho cây nhị phân, đếm số lượng node trên cây là node lá 
6
1 2 L 
1 3 R
2 4 L
2 5 R 
3 6 L
3 7 R 
=> 4
*/
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void makeNode(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}
void insert(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u) makeNode(root, u, v, c);
    else{
        insert(root->left, u, v, c);
        insert(root->right, u, v, c);
    }
}
int cnt = 0;
void inorder(Node *root){
    if(root == NULL) return;
    if(!root->left && !root->right) cnt++;
    inorder(root->left);
    inorder(root->right);
}
void run(){
    Node *root = NULL;
    int n; cin >> n;
    f0(i, n){
        int x, y; char c; cin >> x >> y >> c; 
        if(root == NULL){
            root = new Node(x);
            makeNode(root, x, y, c);
        } 
        else insert(root, x, y, c);
    }
    inorder(root);
    cout << cnt;
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